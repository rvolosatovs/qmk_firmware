#include QMK_KEYBOARD_H

enum layers { BASE, MBO, MEDR, NAVR, MOUR, NSSL, NSL, FUNL };

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

[BASE] = LAYOUT( \
    LALT_T(KC_GRV), KC_Q,         KC_W,         KC_E,         KC_R,           KC_T,                                                KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    RGUI_T(KC_EQL),    \
    LCTL_T(KC_ESC), LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),   KC_G,                                                KC_H,   LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_SCLN), RCTL_T(KC_QUOT),   \
    KC_LSFT,        KC_Z,         KC_X,         KC_C,         KC_V,           KC_B,                                                KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSLASH), \
                                  _______,      _______,      LGUI_T(KC_TAB), LOWER, RAISE,                                        KC_MINS, _______,                            \
                                                              RAISE,          LOWER,           RAISE,  RALT_T(KC_ENT),                                      \
                                                            LSFT_T(KC_BSPC), LCTL_T(KC_ESC),    RCTL_T(KC_ESC),  RSFT_T(KC_SPC)                                               \
),

[LOWER] = LAYOUT( \
    LALT_T(KC_TILD), KC_1,   KC_2,   KC_3,     KC_4,   KC_5,                                                KC_6,   KC_7,   KC_8,    KC_9,   KC_0,   RGUI_T(KC_PLUS),    \
    _______,         KC_A,   KC_S,   KC_D,    KC_F,   KC_G,                                                KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, RCTL_T(KC_QUOT),    \
    _______,         KC_Z,   KC_X,   KC_C,    KC_V,   KC_B,                                                KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSLASH),  \
                             _______, KC_LEAD,                                                                              KC_MINS, _______,                            \
                                      LGUI_T(KC_TAB),  LOWER,           RAISE,             LOWER,           RAISE,  RALT_T(KC_ENT),                                      \
                                                       LSFT_T(KC_BSPC), LCTL_T(KC_ESC),    RCTL_T(KC_ESC),  RSFT_T(KC_SPC)                                               \
),

};
