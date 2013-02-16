#include <gst/gst.h>
#include <glib.h>
#include <dlfcn.h>
#include <stdarg.h>

// Launch app under gdb.
// Wait for OK then set a breakpoint on cam_feature_set
// info registers:
// r0 -> libomap3camd handle
// r1 -> first argument passed to cam_feature_set
// r2 -> get that and match from subdevsrc maps.

#if 0
#define LIB "/usr/lib/libomap3camd.so.0.0.0"

//  gcc -o app app.c `pkg-config gstreamer-0.10 --cflags --libs`

void *lib = NULL;
void *(*_cam_library_create)();
int (*_cam_feature_set)(void *handle, int feature, ...);

void init_dl() {
  lib = dlopen(LIB, RTLD_LAZY);
  if (!lib) {
    puts(dlerror());
  }

  _cam_library_create = dlsym(lib, "cam_library_create");
  _cam_feature_set = dlsym(lib, "cam_feature_set");
}

void *cam_library_create() {
  void *handle = _cam_library_create();

  fprintf(stderr, "%s = 0x%x\n", __FUNCTION__, handle);

  return handle;
}

int cam_feature_set(void *handle, int feature, ...) {
  va_list args;
  va_start (args, feature);
  int ret = _cam_feature_set(handle, feature, args);
  va_end (args);

  fprintf(stderr, "%s %d => %d\n", __FUNCTION__, feature, ret);

  return ret;
}

int cam_feature_get(void *handle, int feature, ...) {

}
#endif

typedef struct {
  const gchar *id;
  const char *prop;
  const char *name;
  int max_val;
  gboolean (*func)(void *test_data);
} test;

typedef struct {
  GstElement *src;
  test *t;
  GMainLoop *loop;
} test_data;

gboolean video_scene(test_data *data) {
  g_object_set(data->src, "viewfinder-mode", 1, NULL);

  return do_test(data);
}

gboolean video_torch(test_data *data) {
  puts("Video torch");
  g_object_set(data->src, "viewfinder-mode", 1, NULL);

  puts("Enabling");
  g_object_set(data->src, "video-torch", TRUE, NULL);

  puts("Disabling");
  g_object_set(data->src, "video-torch", FALSE, NULL);

  g_main_loop_quit(data->loop);

  return FALSE; // bye!
}

test tests[] = {
  {"wb", "white-balance-mode", "White balance", 5, NULL},
  {"flash", "flash-mode", "Flash", 4, NULL},
  {"tone", "colour-tone-mode", "color tone", 11, NULL},
  {"flicker", "flicker-mode", "flicker mode", 3, NULL},
  {"focus", "focus-mode", "Focus mode", 8, NULL},
  {"scene", "scene-mode", "Image scene", 6, NULL},
  {"vs", "scene-mode", "Video scene", 6, video_scene},
  {"torch", "", "", -1, video_torch},
  //  {"scene", "noise-reduction", "noise reduction", 
  //	{"
  //	  {"

  {NULL, NULL, NULL, 0},
};

gboolean do_test(test_data *data) {
  int x = 0;

  puts(data->t->name);

  for (x = 0; x < data->t->max_val + 1; x++) {
    printf("Setting %s to %d\n", data->t->prop, x);
    g_object_set(data->src, data->t->prop, x, NULL);
  }

  g_main_loop_quit(data->loop);

  return FALSE; // bye!
}

int get_test(int argc, char *argv[]) {
  int x = 0;
  if (argc != 2) {
    return -1;
  }

  int len = sizeof(tests) / sizeof(test);
  for (x = 0; x < len; x++) {
    if (!strcmp(tests[x].id, argv[1])) {
      return x;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  int index = get_test(argc, argv);
  if (index == -1) {
    printf("Test required\n");
    return 1;
  }

  gst_init(&argc, &argv);

  //  init_dl();

  GMainLoop *loop = g_main_loop_new(NULL, FALSE);

  GstElement *pipe = gst_pipeline_new(NULL);
  GstElement *src = gst_element_factory_make("subdevsrc", NULL);
  GstElement *sink = gst_element_factory_make("fakesink", NULL);

  gst_bin_add_many(GST_BIN(pipe), src, sink, NULL);
  gst_element_link(src, sink);

  gst_element_set_state(pipe, GST_STATE_PLAYING);

  puts("OK");

  test *t = &tests[index];

  test_data data;
  data.src = src;
  data.t = t;
  data.loop = loop;

  if (t->func) {
    g_timeout_add(2000, (GSourceFunc)t->func, &data);
  }
  else {
    g_timeout_add(2000, (GSourceFunc)do_test, &data);
  }

  g_main_loop_run(loop);

  gst_element_set_state(pipe, GST_STATE_NULL);

  return 0;
}
