/*!
 *
 * Copyright (C) 2013 Mohammed Sameer <msameer@foolab.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

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
