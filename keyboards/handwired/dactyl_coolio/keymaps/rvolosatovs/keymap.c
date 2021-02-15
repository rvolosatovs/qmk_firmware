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

	[_QWERTY] = LAYOUT_wrapper(
      _____________________QWERTY_L1______________________,       _____________________QWERTY_R1______________________,
      _____________________QWERTY_L2______________________,       _____________________QWERTY_R2______________________,
      _____________________QWERTY_L3______________________,	      _____________________QWERTY_R3______________________,
      _____________________THUMBS_LF1_____________________,       KC_LEFT, TD(TD_TABC), KC_BSPC, KC_RIGHT, TO(_COLEMAK),
	  _____________________THUMBS_LF2_____________________,       _____________________THUMBS_RG2_____________________
    ),
	[_GAMING] = LAYOUT_wrapper(
      _____________________GAMING_LF1_____________________,       _____________________GAMING_RT1_____________________,
      _____________________GAMING_LF2_____________________,       _____________________GAMING_RT2_____________________,
      _____________________GAMING_LF3_____________________,       _____________________GAMING_RT3_____________________,
      _____________________GAME_TMB_L_____________________,       _____________________GAME_TMB_R_____________________,
	  _____________________GAME_TM_L2_____________________,       _____________________GAME_TM_R2_____________________
    ),
	[_SHORTCUT] = LAYOUT_wrapper(
      _____________________SHORTCT_L1_____________________,       _____________________SHORTCT_R1_____________________,
      _____________________SHORTCT_L2_____________________,       _____________________SHORTCT_R2_____________________,
      _____________________SHORTCT_L3_____________________,       _____________________SHORTCT_R3_____________________,
      _____________________SHRT_TH_L1_____________________,       _____________________SHRT_TH_R1_____________________,
	  _____________________SHRT_TH_L2_____________________,       _____________________SHRT_TH_R2_____________________
    ),

	[_SYMNUM] = LAYOUT_wrapper(
      _____________________SYMNUM_LF1_____________________,       _____________________SYMNUM_RT1_____________________,
      _____________________SYMNUM_LF2_____________________,       _____________________SYMNUM_RT2_____________________,
      _____________________SYMNUM_LF3_____________________,	 	  _____________________SYMNUM_RT3_____________________,
      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
	  _______, _______,                                  _______,_______
    ),
	[_NAVIGATION] = LAYOUT(
      _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP,        _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_CAPS,
      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,        _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11, KC_SLCK,
      _______, _______,_______,C(KC_MINS),C(KC_EQL), _______,	       _______,   KC_F1,   KC_F2,   KC_F3,  KC_F12, KC_NLCK,
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
	  _______,                                                                                                  _______
    ),


	#ifdef DICE_ROLLER_ENABLE
	[_RPG] = LAYOUT(
      KC_GRAVE, _______, _______, _______, _______, ROLL_D100,        _______, _______, _______, _______, _______, _______,
      ROLL_D3, ROLL_D4, ROLL_D6, ROLL_D10, ROLL_D12, ROLL_D20,        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,	       _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
	  _______,                                                                                                  _______
    )
	#endif

	/*[_BLANK] = LAYOUT(
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,	       _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
	  _______,                                                                                                  _______
    )
	*/

};
