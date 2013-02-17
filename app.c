#include <gst/gst.h>
#include <glib.h>
#include <dlfcn.h>
#include <stdarg.h>
#define GST_USE_UNSTABLE_API
#include <gst/interfaces/photography.h>

// Launch app under gdb.
// Wait for OK then set a breakpoint on cam_feature_set
// info registers:
// r0 -> libomap3camd handle
// r1 -> first argument passed to cam_feature_set
// r2 -> get that and match from subdevsrc maps.

//  gcc -o app app.c `pkg-config gstreamer-0.10 gstreamer-plugins-bad-0.10 --cflags --libs`

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
  GstPhotography *photo;
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

gboolean capture(test_data *data) {
  puts("Capture");

  GstCaps *mode_caps = gst_caps_new_simple ("video/x-raw-yuv",
				   "format", GST_TYPE_FOURCC, GST_MAKE_FOURCC ('U', 'Y', 'V', 'Y'),
				   "width", G_TYPE_INT, 640,
				   "height", G_TYPE_INT, 480,
				   "framerate", GST_TYPE_FRACTION, 2406, 100,
				   NULL);

  GstOperationMode op_mode = GST_PHOTOGRAPHY_OPERATION_MODE_IMAGE_CAPTURE;
  gst_photography_set_format(data->photo, op_mode, mode_caps);

  g_main_loop_quit(data->loop);

  return FALSE; // bye!
}

gboolean autofocus(test_data *data) {
  puts("autofocus");

  puts("Enabling");
  gst_photography_set_autofocus(data->photo, TRUE);

  puts("Disabling");
  gst_photography_set_autofocus(data->photo, FALSE);

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
  {"zoom", "zoom", "Zoom", 3, NULL},
  {"capture", "", "", -1, capture},
  {"af", "", "", -1, autofocus},

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

  GMainLoop *loop = g_main_loop_new(NULL, FALSE);

  GstElement *pipe = gst_pipeline_new(NULL);
  GstElement *src = gst_element_factory_make("subdevsrc", NULL);
  GstElement *sink = gst_element_factory_make("fakesink", NULL);

  gst_bin_add_many(GST_BIN(pipe), src, sink, NULL);
  gst_element_link(src, sink);

  gst_element_set_state(pipe, GST_STATE_PLAYING);

  puts("Set break point now!");

  test *t = &tests[index];

  test_data data;
  data.src = src;
  data.t = t;
  data.loop = loop;
  data.photo = GST_PHOTOGRAPHY(src);

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
