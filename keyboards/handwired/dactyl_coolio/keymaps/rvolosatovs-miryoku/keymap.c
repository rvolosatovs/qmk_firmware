#include QMK_KEYBOARD_H

enum layers { BASE, ALR, MEDR, NAVR, MOUR, ALL, NSSL, NSL, FUNL };

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    LT(FUNL, KC_TAB), KC_Q,         KC_W,             KC_E,              KC_R,             KC_T,                KC_Y,    KC_U,             KC_I,            KC_O,             KC_P,            LT(MEDR, KC_ESC),
    LT(NSL,  KC_SPC), LGUI_T(KC_A), LALT_T(KC_S),     LCTL_T(KC_D),      LSFT_T(KC_F),     KC_G,                KC_H,    RSFT_T(KC_J),     RCTL_T(KC_K),    LALT_T(KC_L),     RGUI_T(KC_QUOT), LT(NAVR, KC_BSPC),
    LT(NSSL, KC_ENT), KC_Z,         ALGR_T(KC_X),     KC_C,              KC_V,             KC_B,                KC_N,    KC_M,             KC_COMM,         ALGR_T(KC_DOT),   KC_SLSH,         LT(MOUR, KC_DEL),
                      XXXXXXX,      LT(MEDR, KC_DEL), LT(NAVR, KC_BSPC), LT(MOUR, KC_ESC), MO(ALR),             MO(ALL), LT(NSSL, KC_ENT), LT(NSL, KC_SPC), LT(FUNL, KC_TAB), XXXXXXX,
                                                                         XXXXXXX,          XXXXXXX,             XXXXXXX, XXXXXXX
  ),
  [ALR] = LAYOUT(
    _______,          _______,      _______,      _______,          _______,           _______,             _______,          _______,         _______,          _______,        _______,         _______,
    _______,          _______,      _______,      _______,          _______,           _______,             _______,          KC_J,            KC_K,             KC_L,           KC_QUOT,         _______,
    _______,          _______,      _______,      _______,          _______,           _______,             _______,          _______,         _______,          KC_DOT,         _______,         _______,
                      _______,      _______,      _______,          _______,           _______,             _______,          _______,         _______,          _______,        _______,
                                                                    _______,           XXXXXXX,             _______,          _______
  ),
  [ALL] = LAYOUT(
    _______,          _______,      _______,      _______,          _______,           _______,             _______,          _______,         _______,          _______,        _______,         _______,
    _______,          KC_A,         KC_S,         KC_D,             KC_F,              _______,             _______,          _______,         _______,          _______,        _______,         _______,
    _______,          _______,      KC_X,         _______,          _______,           _______,             _______,          _______,         _______,          _______,        _______,         _______,
                      _______,      _______,      _______,          _______,           _______,             _______,          _______,         _______,          _______,        _______,
                                                                    _______,           _______,             XXXXXXX,          _______
  ),

  [NAVR] = LAYOUT_miryoku(
    RESET,   U_NA,    U_NA,    U_NA,    U_NA,    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_ENT,  KC_SPC,  KC_TAB,  U_NP,    U_NP
  ),
  [MOUR] = LAYOUT_miryoku(
    RESET,   U_NA,    U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NU,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_BTN1, KC_BTN3, KC_BTN2, U_NP,    U_NP
  ),
  [MEDR] = LAYOUT_miryoku(
    RESET,   U_NA,    U_NA,    U_NA,    U_NA,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NU,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MSTP, KC_MPLY, KC_MUTE, U_NP,    U_NP
  ),

  [FUNL] = LAYOUT_miryoku(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, U_NA,    KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_DEL,  KC_BSPC, KC_APP,  U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [NSL] = LAYOUT_miryoku(
    KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  U_NA,    KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
    KC_LABK, KC_1,    KC_2,    KC_3,    KC_RABK, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_MINS, KC_LBRC, KC_RBRC, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [NSSL] = LAYOUT_miryoku(
    KC_TILD, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, U_NA,    KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
    KC_BSLS, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_UNDS, KC_LCBR, KC_RCBR, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  )
};

#ifdef RETRO_TAPPING_PER_KEY
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return true;
        case LALT_T(KC_S):
            return true;
        case LCTL_T(KC_D):
            return true;
        case LSFT_T(KC_F):
            return true;
        case LSFT_T(KC_J):
            return true;
        case LCTL_T(KC_K):
            return true;
        case LALT_T(KC_L):
            return true;
        case LGUI_T(KC_QUOT):
            return true;
        default:
            return false;
    }
}
#endif

uint16_t last_press = 0;
uint16_t first_press = 0;

void matrix_scan_user(void) {
    if (last_press > 0 && timer_elapsed(last_press) > 2 * 60000) {
        first_press = 0;
        last_press = 0;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    last_press = timer_read();
    if (first_press == 0) {
        first_press = last_press;
    }
    return true;
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case ALR:
            oled_write_ln_P(PSTR("ALR"), false);
            break;
        case ALL:
            oled_write_ln_P(PSTR("ALL"), false);
            break;
        case MEDR:
            oled_write_ln_P(PSTR("MEDR"), false);
            break;
        case NAVR:
            oled_write_ln_P(PSTR("NAVR"), false);
            break;
        case MOUR:
            oled_write_ln_P(PSTR("MOUR"), false);
            break;
        case FUNL:
            oled_write_ln_P(PSTR("FUNL"), false);
            break;
        case NSL:
            oled_write_ln_P(PSTR("NSL"), false);
            break;
        case NSSL:
            oled_write_ln_P(PSTR("NSSL"), false);
            break;
        default:
            oled_write_ln_P(PSTR("???"), false);
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);



    /*uint16_t session_ms = timer_elapsed(first_press);*/
    if (first_press > 0 && timer_elapsed(first_press) > 15 * 60000) {
        oled_write_ln_P(PSTR("BREAK TIME"), false);
    }
}
#endif
