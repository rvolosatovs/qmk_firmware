#include QMK_KEYBOARD_H

#define _BASE 0
#define _LOWER 1
#define _RAISE 2

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

//void encoder_update_user(uint8_t index, bool clockwise) {
//    if (index == 0) { /* First encoder */
//        if (clockwise) {
//            tap_code(KC_PGDN);
//        } else {
//            tap_code(KC_PGUP);
//        }
//    } else if (index == 1) { /* Second encoder */
//        if (clockwise) {
//            tap_code(KC_DOWN);
//        } else {
//            tap_code(KC_UP);
//        }
//    }
//}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
    LALT_T(KC_GRV),  KC_Q,   KC_W,    KC_E,    KC_R,   KC_T,                                                KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    RGUI_T(KC_EQL),    \
    LCTL_T(KC_ESC),  KC_A,   KC_S,    KC_D,    KC_F,   KC_G,                                                KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, RCTL_T(KC_QUOT),   \
    KC_LSFT,         KC_Z,   KC_X,    KC_C,    KC_V,   KC_B,                                                KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSLASH), \
                             _______, KC_LEAD,                                                                              KC_MINS, _______,                            \
                                      LGUI_T(KC_TAB),  LOWER,           RAISE,             LOWER,           RAISE,  RALT_T(KC_ENT),                                      \
                                                       LSFT_T(KC_BSPC), LCTL_T(KC_ESC),    RCTL_T(KC_ESC),  RSFT_T(KC_SPC)                                               \
),

[_LOWER] = LAYOUT( \
    LALT_T(KC_TILD), KC_1,   KC_2,   KC_3,     KC_4,   KC_5,                                                KC_6,   KC_7,   KC_8,    KC_9,   KC_0,   RGUI_T(KC_PLUS),    \
    _______,         KC_A,   KC_S,   KC_D,    KC_F,   KC_G,                                                KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, RCTL_T(KC_QUOT),    \
    _______,         KC_Z,   KC_X,   KC_C,    KC_V,   KC_B,                                                KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSLASH),  \
                             _______, KC_LEAD,                                                                              KC_MINS, _______,                            \
                                      LGUI_T(KC_TAB),  LOWER,           RAISE,             LOWER,           RAISE,  RALT_T(KC_ENT),                                      \
                                                       LSFT_T(KC_BSPC), LCTL_T(KC_ESC),    RCTL_T(KC_ESC),  RSFT_T(KC_SPC)                                               \
),

};
