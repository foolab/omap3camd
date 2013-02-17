#include "omap3cam.h"
#include <stdlib.h>
#include <stdio.h>

void *cam_library_create() {
  fprintf(stderr, "This library should not be used\n");
  abort();

  return NULL;
}

void cam_library_delete(void *handle) {
  fprintf(stderr, "This library should not be used\n");
  abort();
}

cam_err_t cam_feature_set(void *handle, cam_feature_t feature, ...) {
  fprintf(stderr, "This library should not be used\n");
  abort();

  return CAM_ERR_INTERNAL;
}

cam_err_t cam_feature_get(void *handle, cam_feature_t feature, ...) {
  fprintf(stderr, "This library should not be used\n");
  abort();

  return CAM_ERR_INTERNAL;
}
