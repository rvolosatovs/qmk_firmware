/* Copyright 2015-2017 Jack Humbert
 * Copyright 2018      Roman Volosatovs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _EXTRA
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRA MO(_EXTRA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_planck_grid( \
      LGUI_T(KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,           KC_Y,           KC_U,    KC_I,    KC_O,    KC_P,    RGUI_T(KC_BSPC), \
      LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,           KC_H,           KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT), \
      LSFT_T(KC_LSFT), KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,           KC_N,           KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),  \
      RAISE,           KC_LCTL, KC_LALT, KC_LGUI, LOWER,    RALT_T(KC_SPC), RSFT_T(KC_SPC), RAISE,   KC_RGUI, KC_RALT, KC_RCTL, LOWER            \
      ),

  [_LOWER] = LAYOUT_planck_grid( \
      KC_TILD,         KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,        KC_CIRC,        KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,         \
      _______,         _______, KC_WH_L, KC_WH_U, KC_WH_D,  KC_WH_R,        KC_UNDS,        KC_LBRC, KC_RBRC, KC_EQL,  KC_PIPE, _______,         \
      _______,         _______, _______, KC_ACL0, KC_ACL1,  KC_ACL2,        _______,        _______, KC_LT,   KC_GT,   KC_BSLS, _______,         \
      _______,         _______, _______, _______, _______,  RALT_T(KC_ENT), RSFT_T(KC_ENT), _______, _______, _______, _______, _______          \
      ),

  [_RAISE] = LAYOUT_planck_grid( \
      KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,     KC_5,           KC_6,           KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,         \
      _______,         _______, KC_MS_L, KC_MS_U, KC_MS_D,  KC_MS_R,        KC_MINS,        KC_LCBR, KC_RCBR, KC_PLUS, KC_COLN, _______,         \
      _______,         KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2,  KC_BTN1,        _______,        _______, _______, _______, _______, _______,         \
      _______,         _______, _______, _______, _______,  RALT_T(KC_ENT), RSFT_T(KC_ENT), _______, _______, _______, _______, _______          \
      ),

  [_ADJUST] = LAYOUT_planck_grid( \
      _______,         KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,          KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,          \
      _______,         KC_F11,  KC_F12,  KC_F13,  KC_F14,   KC_F15,         KC_LEFT,        KC_DOWN, KC_UP,   KC_RGHT, _______, _______,         \
      _______,         KC_PSCR, _______, KC_VOLD, KC_VOLU,  _______,        _______,        KC_PGDN, KC_PGUP, _______, _______, _______,         \
      EXTRA,           _______, _______, _______, _______,  _______,        _______,        _______, _______, _______, _______, EXTRA            \
      ),

  [_EXTRA] = LAYOUT_planck_grid( \
      _______,         RESET,   DEBUG,   RGB_TOG, RGB_MOD,  RGB_HUI,        RGB_HUD,        RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,          \
      _______,         AU_ON,   AU_OFF,  TERM_ON, TERM_OFF, AG_SWAP,        AG_NORM,        _______, _______, _______, _______, _______,         \
      _______,         MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,   MI_ON,          MI_OFF,         _______, _______, _______, _______, _______,         \
      _______,         _______, _______, _______, _______,  KC_ESC,         KC_ESC,         _______, _______, _______, _______, _______          \
      )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
};

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
