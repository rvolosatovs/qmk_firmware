#define DISABLE_LEADER
#define IGNORE_MOD_TAP_INTERRUPT
#define QMK_KEYS_PER_SCAN 4
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

#define XXX KC_NO

#define LAYOUT_miryoku(\
K00, K01, K02, K03, K04,                         K05, K06, K07, K08, K09,\
K10, K11, K12, K13, K14,                         K15, K16, K17, K18, K19,\
K20, K21, K22, K23, K24,                         K25, K26, K27, K28, K29,\
N30, N31, K32, K33, K34,                         K35, K36, K37, N38, N39\
)\
LAYOUT( \
K35, K00, K01, K02, K03, K04,                         K05, K06, K07, K08, K09, K34,\
K36, K10, K11, K12, K13, K14,                         K15, K16, K17, K18, K19, K33,\
K37, K20, K21, K22, K23, K24,                         K25, K26, K27, K28, K29, K32,\
               N30, N31, K32, K33, K34,     K35, K36, K37, N38, N39,\
                              XXX, XXX,     XXX, XXX\
)
