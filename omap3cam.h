#ifndef __OMAP3_CAM_H__
#define __OMAP3_CAM_H__


#define CAM_IMAGE_INFO             39
#define CAM_VIEWFINDER_MODE_VIDEO_RECORD 1
#define CAM_VIEWFINDER_MODE_STILL_CAPTURE 0
#define CAM_MOTION_DETECTION 33
#define CAM_ENGINE_CONTROL 35
#define CAM_MAKER_NOTE 38
#define CAM_IPP_PARAMETERS 41
#define CAM_EXPOSURE_SHAKE_RISK 14
#define CAM_LIGHT_FLASH_STATUS 43
#define CAM_FOCUS_STATUS 23
#define CAM_EXPOSURE_MODE_AUTO 0

#define OBJECT_TRACKING_MAX_COUNT 16

typedef enum {
  CAM_ENGINE_VIEWFINDER = 0,
  CAM_ENGINE_STILL_CAPTURE = 1,
  CAM_ENGINE_SNAP_SHOT = 2,
} cam_engine_t;

typedef enum {
  CAM_EXPOSURE_ISO_VALUE_800 = 4,
  CAM_EXPOSURE_ISO_VALUE_400 = 3,
  CAM_EXPOSURE_ISO_VALUE_200 = 2,
  CAM_EXPOSURE_ISO_VALUE_100 = 1,
  CAM_EXPOSURE_ISO_VALUE_AUTO = 0,
} cam_exposure_iso_value_t;

typedef enum {
  CAM_FRAME_FORMAT_YUYV = 0,
  CAM_FRAME_FORMAT_UYVY = 1,
  CAM_FRAME_FORMAT_BAYER10 = 2,
  CAM_PIXEL_FORMAT_YUYV = 0,
  CAM_PIXEL_FORMAT_UYVY = 1,
  CAM_PIXEL_FORMAT_BAYER10 = 2,
} cam_pixel_format_t;

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
  CAM_STILL_CAPTURE_START = 6,
  CAM_STILL_CAPTURE_DONE = 7,
  CAM_ALGO_WHITE_BALANCE = 0,
  CAM_ALGO_EXPOSURE = 1,
  CAM_ALGO_FOCUS_SINGLE = 2,
  CAM_ALGO_FOCUS_CONTINUOUS = 5,
  CAM_ALGO_SHAKE_RISK = 9,
  CAM_ALGO_LINE_FREQ_DETECTED = 8,
  CAM_ALGO_FLASHLIGHT_CONTROL = 10,
  CAM_ALGO_FLASHLIGHT_REQUIRED = 11,
} cam_algo_id_t;

typedef enum {
  CAM_CAMERA_DEVICE = 1,
  CAM_EXPOSURE_MODE = 12,
  CAM_AWB_MODE = 25,
  CAM_FOCUS_MODE = 20,
  CAM_LIGHT_PRIVACY_MODE = 11,
  CAM_LIGHT_ASSIST_MODE = 10,
  CAM_GENERAL_FLICKER_REDUCTION_MODE = 8,
  CAM_GENERAL_SCENE_MODE = 2,
  CAM_STILL_CAPTURE_MODE = 28,
  CAM_FRAME_FORMAT = 30,
  CAM_ALGO_CONTROL = 34,
  CAM_STATUS_CHANGED = 36,
  CAM_BUFFER = 40,
  CAM_RESOLUTION = 31,
  CAM_PIXEL_FORMAT = 30,
  CAM_DIGITAL_ZOOM = 37,
  CAM_VIEWFINDER_MODE = 29,
  CAM_GENERAL_EFFECT_TYPE = 3,
  CAM_LIGHT_FLASH_MODE = 9,
  CAM_EXPOSURE_MANUAL_TIME = 15,
  CAM_EXPOSURE_MANUAL_APERTURE = 18,
  CAM_EXPOSURE_COMPENSATION = 16,
  CAM_EXPOSURE_ISO_VALUE = 17,
  CAM_FOCUS_INFO = 24,
  CAM_OBJECT_TRACING = 32,
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
  CAM_CONTROL_RUN = 0,
  CAM_CONTROL_STOPED = 1,
} cam_algo_control_t;

typedef enum {
  CAM_STILL_CAPTURE_MODE_HIGH_QUALITY_NO_POSTPROCESS = 0,
  CAM_STILL_CAPTURE_MODE_PERFORMANCE = 4,
} cam_still_capture_mode_t;

typedef enum {
  CAM_LIGHT_PRIVACY_MODE_AUTO = 2,
  CAM_LIGHT_PRIVACY_MODE_ON = 1,
  CAM_LIGHT_PRIVACY_MODE_OFF = 0,
} cam_light_privacy_mode_t;

typedef enum {
  CAM_LIGHT_ASSIST_MODE_AUTO = 0,
  CAM_LIGHT_ASSIST_MODE_ON = 2,
  CAM_LIGHT_ASSIST_MODE_OFF = 1,
} cam_light_assist_mode_t;

typedef enum {
  CAM_EXPOSURE_SHAKE_RISK_LOW = 0,
  CAM_EXPOSURE_SHAKE_RISK_MEDIUM = 1,
  CAM_EXPOSURE_SHAKE_RISK_HIGH = 2,
} cam_exposure_shake_risk_t;

typedef enum { /* 1:1 mapping */
  CAM_FLASH_STATUS_READY = 0,
  CAM_FLASH_STATUS_COOLDOWN = 1,
} cam_light_flash_status_t;

typedef enum {
  CAM_FOCUS_STATUS_IDLE = 0,
  CAM_FOCUS_STATUS_RUNNING = 1,
  CAM_FOCUS_STATUS_SUCCESS = 2,
  CAM_FOCUS_STATUS_FAIL = 3,
} cam_focus_status_t;

typedef enum {
  CAM_GENERAL_FLICKER_REDUCTION_MODE_OFF = 0,
  CAM_GENERAL_FLICKER_REDUCTION_MODE_50HZ = 1,
  CAM_GENERAL_FLICKER_REDUCTION_MODE_60HZ = 2,
  CAM_GENERAL_FLICKER_REDUCTION_MODE_AUTO = 3,
} cam_general_flicker_reduction_mode_t;

typedef enum {
  CAM_OBJECT_ORIENTATION_UNKNOWN = 0,
  CAM_OBJECT_ORIENTATION_0 = 1,
  CAM_OBJECT_ORIENTATION_90 = 2,
  CAM_OBJECT_ORIENTATION_270 = 3,
} cam_object_orientation_t;

typedef enum {
  CAM_IPP_VERSION_1_8 = 0,
  CAM_IPP_VERSION_1_9 = 1,
} cam_ipp_version_t;

typedef enum {
  UNKNOWN = 0,
  AVERAGE = 1,
  CENTER_WEIGHTED_AVERAGE = 2,
  SPOT = 3,
  MULTI_SPOT = 4,
  PATTERN = 5,
  PARTIAL = 6,
} cam_metering_mode_t;

typedef enum {
  NOT_EXIST = 0,
  Y_COMPONENT = 1,
  CB_COMPONENT = 2,
  CR_COMPONENT = 3,
  R_COMPONENT = 4,
  G_COMPONENT = 5,
  B_COMPONENT = 6,
} cam_components_configuration_t;

typedef enum {
  AUTO_EXPOSURE = 0,
  MANUAL_EXPOSURE = 1,
  AUTO_BRACKET = 2,
} cam_exposure_mode_t;

typedef enum {
  AUTO_WHITE_BALANCE = 0,
  MANUAL_WHITE_BALANCE = 1,
} cam_white_balance_t;

typedef enum {
  STANDART = 0,
  LANDSCAPE = 1,
  PORTRAIT = 2,
  NIGHT_SCENE = 3,
  MACRO = 4,
  ACTION = 5,
} cam_scene_capture_type_t;

void *cam_library_create();
void cam_library_delete(void *handle);
cam_err_t cam_feature_set(void *handle, cam_feature_t feature, ...);
cam_err_t cam_feature_get(void *handle, cam_feature_t feature, ...);

typedef struct {
  void (*callback)(void *);
  void *argument;
} cam_status_changed_t;

typedef struct {
  unsigned int coverage;
  unsigned int zones_vertical;
  unsigned int zones_horizontal;
  unsigned int zone;
  unsigned int lens_position;
} cam_focus_info_t;

typedef struct {
  unsigned int numenator;
  unsigned int denumenator;
} cam_fractional_t;

typedef struct {
  cam_fractional_t exposure_time;
  cam_fractional_t fnumber;
  unsigned int iso_speed_ratings;
  cam_components_configuration_t components_configuration[4];
  cam_fractional_t shutter_speed_value;
  cam_fractional_t aperture_value;
  cam_metering_mode_t metering_mode;
  unsigned int light_source;
  unsigned int flash;
  cam_fractional_t focal_length;
  unsigned int pixel_x_dimension;
  unsigned int pixel_linesize;
  unsigned int pixel_y_dimension;
  cam_exposure_mode_t exposure_mode;
  cam_white_balance_t white_balance;
  cam_fractional_t digital_zoom_ratio;
  cam_scene_capture_type_t scene_capture_type;
  unsigned int gain;
  int contrast;
  int saturation;
  int sharpness;
  unsigned int sensor_gain_ev;
  unsigned int lens_position;
  unsigned int reserved[4];
} frame_info_t;

typedef struct {
  void *b_address;
  unsigned int b_size;
  cam_err_t status;
  cam_status_changed_t notify;
  unsigned int index;
} cam_frame_buffer_t;

typedef struct {
  int top;
  int left;
  int width;
  int height;
  int bytesperline;
  int size;
} cam_window_rect_t;

typedef struct {
  float x_vector;
  float y_vector;
  int d_time;
} cam_motion_vector_t;

typedef struct {
  cam_window_rect_t frame_size;
  cam_window_rect_t objects[OBJECT_TRACKING_MAX_COUNT];
  int priority[OBJECT_TRACKING_MAX_COUNT];
  cam_object_orientation_t rotation;
} cam_object_tracking_t;

// break gst_subdevsrc_libomap3camd_get_makernote
// break g_malloc
// info registers -> r0
unsigned char maker_note_t[4096];

typedef struct {
  unsigned int low;
  unsigned int mid;
  unsigned int high;
} cam_filter_strength_t;

typedef struct {
  unsigned int luma_noise_filter;
  unsigned int chroma_noise_filter;
  unsigned int edge_enhancement_strength;
  unsigned int weak_edge_threshold;
  unsigned int strong_edge_threshold;
} cam_ipp_paramters_1_8;

typedef struct {
  unsigned int edge_enhancement_strength;
  unsigned int weak_edge_threshold;
  unsigned int strong_edge_threshold;
  cam_filter_strength_t freq_luma_noise;
  cam_filter_strength_t freq_cb_noise;
  cam_filter_strength_t freq_cr_noise;
  unsigned int shading_vert_param1;
  unsigned int shading_vert_param2;
  unsigned int shading_horz_param1;
  unsigned int shading_horz_param2;
  unsigned int shading_gain_scale;
  unsigned int shading_gain_offset;
  unsigned int shading_gain_maxvalue;
  unsigned int ratio_downsample_cb_cr;
} cam_ipp_paramters_1_9;

typedef struct {
  cam_ipp_version_t version;
  union {
    cam_ipp_paramters_1_8 ipp_1_8;
    cam_ipp_paramters_1_9 ipp_1_9;
  } info;
} cam_ipp_parameters_t;

#endif /* __OMAP3_CAM_H__ */
