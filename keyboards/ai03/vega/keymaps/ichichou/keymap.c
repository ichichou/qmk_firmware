/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

#define RHYPR_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)
#define LCG(kc) (QK_LCTL | QK_LGUI | (kc))

#define HYPR_TAB  RHYPR_T(KC_TAB)
#define HYPR_BSPC RHYPR_T(KC_BSPC)
#define CTL_ESC   CTL_T(KC_ESC)
#define CTL_ENT   CTL_T(KC_ENT)
#define CTL_LBRC  CTL_T(KC_LBRC)
#define SFT_SPC   SFT_T(KC_SPC)
#define SFT_RBRC  SFT_T(KC_RBRC)
#define SFT_CW    SFT_T(CW_TOGG)
#define GUI_LNG2  GUI_T(KC_LNG2)
#define RGUI_LNG1 RGUI_T(KC_LNG1)

enum layer_names {
  _BASE,
  _FN,
};

// // Custom Keycodes
// enum my_keycodes {
//   TEST_1 = SAFE_RANGE,
//   TEST_2,
// };

// Behavior of Any Keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SFT_CW:
      if (record->tap.count && record->event.pressed) {
        caps_word_toggle();
        return false;
      }
      return true;
    default:
      return true;
  }
  return true;
}

// Key Overrides
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_ALT, KC_ESC, KC_GRV);
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_TILD);
const key_override_t *key_overrides[] = {
  &grave_esc_override,
  &tilde_esc_override,
};

// // PERMISSIVE_HOLD_PER_KEY
// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     default:
//       return false;
//   }
// }

// HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case HYPR_TAB:
      return true;
    case HYPR_BSPC:
      return true;
    case CTL_ESC:
      return true;
    case CTL_ENT:
      return true;
    case SFT_SPC:
      return true;
    case SFT_CW:
      return true;
    case GUI_LNG2:
      return true;
    case RGUI_LNG1:
      return true;
    default:
      return false;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_all(
    KC_ESC,   KC_1,    KC_2,     KC_3, KC_4,   KC_5, KC_6,    KC_7,    KC_8,   KC_9, KC_0,      KC_MINS, KC_EQL,  HYPR_BSPC, KC_DEL,  KC_DEL,
    HYPR_TAB, KC_Q,    KC_W,     KC_E, KC_R,   KC_T, KC_RBRC, KC_Y,    KC_U,   KC_I, KC_O,      KC_P,    KC_QUOT, KC_BSLS,            KC_GRV,
    CTL_ESC,  KC_A,    KC_S,     KC_D, KC_F,   KC_G, KC_QUOT, KC_H,    KC_J,   KC_K, KC_L,      KC_SCLN,          CTL_ENT,            KC_TILD,
    SFT_CW,   KC_BSLS, KC_Z,     KC_X, KC_C,   KC_V, KC_B,    KC_LBRC, KC_N,   KC_M, KC_COMM,   KC_DOT,  KC_SLSH,            KC_UP,   MO(_FN),
    MO(_FN),  KC_LALT, GUI_LNG2,       KC_SPC,       SFT_SPC,          KC_SPC,       RGUI_LNG1, KC_RCTL,          KC_LEFT,   KC_DOWN, KC_RGHT
  ),

  [_FN] = LAYOUT_all(
    LCG(KC_Q), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,   XXXXXXX, XXXXXXX,
    _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, KC_GRV,            G(KC_UP),
    _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT,          KC_MPLY,           G(KC_DOWN),
    _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,           XXXXXXX, _______,
    _______,   _______, _______,          _______,          _______,          _______,          _______, _______,          A(KC_UP), XXXXXXX, A(KC_DOWN)
  ),

};
