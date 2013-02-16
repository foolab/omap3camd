#ifndef __OMAP3_CAM_H__
#define __OMAP3_CAM_H__


#define CAM_IMAGE_INFO             0
#define CAM_VIEWFINDER_MODE_VIDEO_RECORD 0
#define CAM_VIEWFINDER_MODE_STILL_CAPTURE 0
#define OBJECT_TRACKING_MAX_COUNT 0
#define CAM_OBJECT_ORIENTATION_UNKNOWN 0
#define CAM_MOTION_DETECTION 0
#define CAM_ENGINE_CONTROL 0
#define CAM_MAKER_NOTE 0
#define CAM_IPP_VERSION_1_9 0
#define CAM_IPP_PARAMETERS 0
#define CAM_EXPOSURE_SHAKE_RISK 0
#define CAM_LIGHT_FLASH_STATUS 0
#define CAM_FOCUS_STATUS 0
#define CAM_EXPOSURE_MODE_AUTO 0

#define CAM_ALGO_WHITE_BALANCE 0
#define CAM_ALGO_EXPOSURE 1

typedef enum {
  CAM_ENGINE_VIEWFINDER,
  CAM_ENGINE_STILL_CAPTURE,
  CAM_ENGINE_SNAP_SHOT,
} cam_engine_t;

typedef enum {
  CAM_EXPOSURE_ISO_VALUE_800 = 800,
  CAM_EXPOSURE_ISO_VALUE_400 = 400,
  CAM_EXPOSURE_ISO_VALUE_200 = 200,
  CAM_EXPOSURE_ISO_VALUE_100 = 100,
  CAM_EXPOSURE_ISO_VALUE_AUTO = 0,
} cam_exposure_iso_value_t;

typedef enum {
  CAM_PIXEL_FORMAT_UYVY,
  CAM_PIXEL_FORMAT_BAYER10,
} cam_pixel_format_t;

typedef enum {
  CAM_FRAME_FORMAT_YUYV,
  CAM_FRAME_FORMAT_UYVY,
} cam_frame_format_t;

typedef enum {
  CAM_ERR_NONE = 0,
  CAM_ERR_PARAM = 1,
  CAM_ERR_UNSUPP = 2,
  CAM_ERR_HW = 3,
  CAM_ERR_SYS = 4,
  CAM_ERR_LEXIT = 5,
  CAM_ERR_DEPRECATED = 6,
  CAM_ERR_INVALID_STATE = 7,
  CAM_ERR_INTERNAL = 8
} cam_err_t;

typedef enum {
  CAM_STILL_CAPTURE_START,
  CAM_STILL_CAPTURE_DONE,
  CAM_ALGO_FOCUS_SINGLE = 2,
  CAM_ALGO_FOCUS_CONTINUOUS,
  CAM_ALGO_SHAKE_RISK,
  CAM_ALGO_LINE_FREQ_DETECTED,
  CAM_ALGO_FLASHLIGHT_CONTROL,
  CAM_ALGO_FLASHLIGHT_REQUIRED,
} cam_algo_id_t;

typedef enum {
  CAM_CAMERA_DEVICE = 1,
  CAM_EXPOSURE_MODE,
  CAM_AWB_MODE = 25,
  CAM_FOCUS_MODE = 20,
  CAM_LIGHT_PRIVACY_MODE = 11,
  CAM_LIGHT_ASSIST_MODE = 10,
  CAM_GENERAL_FLICKER_REDUCTION_MODE = 8,
  CAM_GENERAL_SCENE_MODE = 2,
  CAM_STILL_CAPTURE_MODE,
  CAM_FRAME_FORMAT,
  CAM_ALGO_CONTROL = 34,
  CAM_STATUS_CHANGED,
  CAM_BUFFER,
  CAM_RESOLUTION,
  CAM_PIXEL_FORMAT,
  CAM_DIGITAL_ZOOM,
  CAM_VIEWFINDER_MODE,
  CAM_GENERAL_EFFECT_TYPE = 3,
  CAM_LIGHT_FLASH_MODE = 9,
  CAM_EXPOSURE_MANUAL_TIME,
  CAM_EXPOSURE_MANUAL_APERTURE,
  CAM_EXPOSURE_COMPENSATION,
  CAM_EXPOSURE_ISO_VALUE,
  CAM_FOCUS_INFO,
  CAM_OBJECT_TRACING,
} cam_feature_t;

typedef enum {
  CAM_AWB_MODE_AUTO = 0,
  CAM_AWB_MODE_DAYLIGHT = 1,
  CAM_AWB_MODE_CLOUDY = 3,
  CAM_AWB_MODE_SUNSET = 2,
  CAM_AWB_MODE_TUNGSTEN = 4,
  CAM_AWB_MODE_FLUORESCENT = 5,
} cam_awb_mode_t;

typedef enum {
  CAM_GENERAL_EFFECT_TYPE_NORMAL = 0,
  CAM_GENERAL_EFFECT_TYPE_SEPIA = 1,
  CAM_GENERAL_EFFECT_TYPE_NEGATIVE = 2,
  CAM_GENERAL_EFFECT_TYPE_GRAYSCALE = 3,
  CAM_GENERAL_EFFECT_TYPE_NATURAL = 4,
  CAM_GENERAL_EFFECT_TYPE_VIVID = 5,
  CAM_GENERAL_EFFECT_TYPE_COLORSWAP = 6,
  CAM_GENERAL_EFFECT_TYPE_SOLARIZE = 7,
  CAM_GENERAL_EFFECT_TYPE_OUT_OF_FOCUS = 8,
} cam_general_effect_type_t;

typedef enum {
  CAM_GENERAL_SCENE_MODE_AUTO = 4,
  CAM_GENERAL_SCENE_MODE_CLOSEUP = 0,
  CAM_GENERAL_SCENE_MODE_PORTRAIT = 1,
  CAM_GENERAL_SCENE_MODE_LANDSCAPE = 2,
  CAM_GENERAL_SCENE_MODE_SPORT = 3,
  CAM_GENERAL_SCENE_MODE_NIGHT_PORTRAIT = 10,
  CAM_GENERAL_SCENE_MODE_VIDEO_AUTO = 5,
  CAM_GENERAL_SCENE_MODE_VIDEO_NIGHT = 6,
} cam_general_scene_mode_t;

typedef enum {
  CAM_LIGHT_FLASH_MODE_AUTO = 0,
  CAM_LIGHT_FLASH_MODE_OFF = 1,
  CAM_LIGHT_FLASH_MODE_ON = 2,
  CAM_LIGHT_FLASH_MODE_FILL_IN = 3,
  CAM_LIGHT_FLASH_MODE_RED_EYE = 4,
} cam_light_flash_mode_t;

typedef enum {
  CAM_FOCUS_MODE_AUTO = 0,
  CAM_FOCUS_MODE_MACRO = 1,
  CAM_FOCUS_MODE_PORTRAIT = 2,
  CAM_FOCUS_MODE_INFINITY = 3,
  CAM_FOCUS_MODE_HYPERFOCAL = 4,
  CAM_FOCUS_MODE_EXTENDED = 5,
  CAM_FOCUS_MODE_SPORT = 6,
} cam_focus_mode_t;

typedef enum {
  CAM_CONTROL_RUN,
  CAM_CONTROL_STOPED = 1,
} cam_algo_control_t;

typedef enum {
  CAM_STILL_CAPTURE_MODE_HIGH_QUALITY_NO_POSTPROCESS,
  CAM_STILL_CAPTURE_MODE_PERFORMANCE,
} cam_still_capture_mode_t;

typedef enum {
  CAM_LIGHT_PRIVACY_MODE_AUTO,
  CAM_LIGHT_PRIVACY_MODE_ON,
  CAM_LIGHT_PRIVACY_MODE_OFF = 0,
} cam_light_privacy_mode_t;

typedef enum {
  CAM_LIGHT_ASSIST_MODE_AUTO,
  CAM_LIGHT_ASSIST_MODE_ON,
  CAM_LIGHT_ASSIST_MODE_OFF = 1,
} cam_light_assist_mode_t;

typedef enum {
  CAM_EXPOSURE_SHAKE_RISK_LOW,
  CAM_EXPOSURE_SHAKE_RISK_MEDIUM,
  CAM_EXPOSURE_SHAKE_RISK_HIGH,
} cam_exposure_shake_risk_t;

typedef enum { /* 1:1 mapping */
  CAM_FLASH_STATUS_READY = 0,
  CAM_FLASH_STATUS_COOLDOWN = 1,
} cam_light_flash_status_t;

typedef enum {
  CAM_FOCUS_STATUS_IDLE,
  CAM_FOCUS_STATUS_RUNNING,
  CAM_FOCUS_STATUS_SUCCESS,
  CAM_FOCUS_STATUS_FAIL,
} cam_focus_status_t;

typedef enum {
  CAM_GENERAL_FLICKER_REDUCTION_MODE_OFF = 0,
  CAM_GENERAL_FLICKER_REDUCTION_MODE_50HZ = 1,
  CAM_GENERAL_FLICKER_REDUCTION_MODE_60HZ = 2,
  CAM_GENERAL_FLICKER_REDUCTION_MODE_AUTO = 3,
} cam_general_flicker_reduction_mode_t;

void *cam_library_create();
void cam_library_delete(void *handle);
cam_err_t cam_feature_set(void *handle, cam_feature_t feature, ...);
cam_err_t cam_feature_get(void *handle, cam_feature_t feature, ...);

typedef struct {
  void *(*callback)(void *);
  void *argument;
} cam_status_changed_t;

typedef struct {
  int coverage;
  int zones_vertical;
  int zones_horizontal;
  int zone;
  int lens_position;
} cam_focus_info_t;

typedef struct {
  int numenator;
  int denumenator;
} cam_fractional_t;

typedef struct {
  cam_fractional_t aperture_value;
  cam_fractional_t shutter_speed_value;
  cam_fractional_t exposure_time;
  cam_fractional_t fnumber;
  cam_fractional_t focal_length;
  cam_fractional_t iso_speed_ratings;
  int flash; // TODO:
  int contrast;
  int saturation;
  int exposure_mode;
  int gain;
  int scene_capture_type;
  int sharpness;
  int metering_mode;
  int sensor_gain_ev;
  int lens_position;
} frame_info_t;

typedef struct {
  void *b_address;
  int b_size;
  int index;
  cam_err_t status;
  cam_status_changed_t notify;
} cam_frame_buffer_t;

typedef struct {
  unsigned int top;
  unsigned int left;
  unsigned int width;
  unsigned int height;
  unsigned int size;
} cam_window_rect_t;

typedef struct {
  float x_vector;
  float y_vector;
  unsigned long long d_time;
} cam_motion_vector_t;

typedef struct {
  cam_window_rect_t frame_size;
  int rotation; // TODO:
  cam_window_rect_t objects[OBJECT_TRACKING_MAX_COUNT];
  int priority[OBJECT_TRACKING_MAX_COUNT];
} cam_object_tracking_t;

char maker_note_t[100]; // TODO:

typedef struct {
  unsigned int low;
  unsigned int mid;
  unsigned int high;
} cam_freq_t;

typedef struct {
  unsigned int edge_enhancement_strength;
  unsigned int weak_edge_threshold;
  unsigned int strong_edge_threshold;
  unsigned int shading_horz_param1;
  unsigned int shading_horz_param2;
  unsigned int shading_vert_param1;
  unsigned int shading_vert_param2;
  unsigned int shading_gain_scale;
  unsigned int shading_gain_offset;
  unsigned int shading_gain_maxvalue;
  unsigned int ratio_downsample_cb_cr;
  cam_freq_t freq_luma_noise;
  cam_freq_t freq_cb_noise;
  cam_freq_t freq_cr_noise;
} cam_ipp_parameters_t_1_9;

typedef struct { // TODO: union??
  cam_ipp_parameters_t_1_9 ipp_1_9;
} cam_ipp_parameters_info_t;

typedef struct { // TODO:
  int version; // TODO:
  cam_ipp_parameters_info_t info; // TODO: looks like a union of some sort...
} cam_ipp_parameters_t;

#endif /* __OMAP3_CAM_H__ */
