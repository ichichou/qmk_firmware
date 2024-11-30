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

// -- C Macros {{{

// Modifier Keys
#define RHYPR_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)
#define LCG(kc)     (QK_LCTL | QK_LGUI | (kc))
#define SFT_GUI     G(KC_LSFT)

// Tap-Hold Keys
#define HYPR_TAB  RHYPR_T(KC_TAB)
#define HYPR_BSPC RHYPR_T(KC_BSPC)
#define CTL_ESC   CTL_T(KC_ESC)
#define CTL_ENT   CTL_T(KC_ENT)
#define SFT_SPC   SFT_T(KC_SPC)
#define SFT_CW    SFT_T(CW_TOGG)
#define GUI_LNG2  GUI_T(KC_LNG2)
#define RGUI_LNG1 RGUI_T(KC_LNG1)

// -- }}}

// -- Layers {{{

enum layer_names {
  _BASE,
  _MTGAP,
  _FN,
};

// -- }}}

// -- Custom Keycodes {{{

enum my_keycodes {
  TEST_1 = SAFE_RANGE,
};

// -- }}}

// -- Behavior of Any Keycode {{{

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

// -- }}}

// -- Key Overrides {{{

// const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_ALT, KC_ESC, KC_GRV);
// const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_TILD);
// const key_override_t *key_overrides[] = {
//   &grave_esc_override,
//   &tilde_esc_override,
// };

// -- }}}

// -- PERMISSIVE_HOLD_PER_KEY {{{

// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     default:
//       return false;
//   }
// }

// -- }}}

// -- HOLD_ON_OTHER_KEY_PRESS_PER_KEY {{{

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

// -- }}}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_all(
    KC_ESC,            KC_1,     KC_2, KC_3,   KC_4, KC_5,    KC_6,    KC_7,   KC_8, KC_9,    KC_0,      KC_MINS, KC_EQL,  HYPR_BSPC, KC_DEL, KC_DEL,
    HYPR_TAB,          KC_Q,     KC_W, KC_E,   KC_R, KC_T,    KC_LBRC, KC_Y,   KC_U, KC_I,    KC_O,      KC_P,    KC_QUOT, KC_BSLS,           KC_GRV,
    CTL_ESC,           KC_A,     KC_S, KC_D,   KC_F, KC_G,    KC_RBRC, KC_H,   KC_J, KC_K,    KC_L,      KC_SCLN,          CTL_ENT,           KC_TILD,
    SFT_CW,   KC_BSLS, KC_Z,     KC_X, KC_C,   KC_V, KC_B,    SFT_GUI, KC_N,   KC_M, KC_COMM, KC_DOT,    KC_SLSH,          KC_UP,             MO(_FN),
    MO(_FN),  KC_LALT, GUI_LNG2,       KC_SPC,       SFT_SPC,          KC_SPC,       KC_RALT, RGUI_LNG1,          KC_LEFT, KC_DOWN,           KC_RGHT
  ),

  [_MTGAP] = LAYOUT_all(
    KC_ESC,            KC_1,     KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,   KC_8, KC_9,    KC_0,      KC_MINS, KC_EQL,  HYPR_BSPC, KC_DEL, KC_DEL,
    HYPR_TAB,          KC_Y,     KC_P,    KC_O,    KC_U,   KC_SCLN, KC_LBRC, KC_K,   KC_D, KC_L,    KC_C,      KC_W,    KC_Q,    KC_BSLS,           KC_GRV,
    CTL_ESC,           KC_I,     KC_N,    KC_E,    KC_A,   KC_COMM, KC_RBRC, KC_M,   KC_H, KC_T,    KC_S,      KC_R,             CTL_ENT,           KC_TILD,
    SFT_CW,   KC_BSLS, KC_Z,     KC_SLSH, KC_QUOT, KC_DOT, KC_X,    SFT_GUI, KC_B,   KC_F, KC_G,    KC_V,      KC_J,             KC_UP,             MO(_FN),
    MO(_FN),  KC_LALT, GUI_LNG2,          KC_SPC,          SFT_SPC,          KC_SPC,       KC_RALT, RGUI_LNG1,          KC_LEFT, KC_DOWN,           KC_RGHT
  ),

  [_FN] = LAYOUT_all(
    LCG(KC_Q),          KC_F1,     KC_F2,      KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  XXXXXXX, XXXXXXX,
    _______,            XXXXXXX,   A(KC_UP),   KC_PGUP, A(KC_DOWN), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, KC_GRV,           G(KC_UP),
    _______,            XXXXXXX,   KC_HOME,    KC_PGDN, KC_END,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT,          KC_MPLY,          G(KC_DOWN),
    _______,   XXXXXXX, DF(_BASE), DF(_MTGAP), XXXXXXX, XXXXXXX,    XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          KC_PGUP,          _______,
    _______,   _______, _______,               _______,             _______,          _______,          _______, _______,          KC_HOME, KC_PGDN,          KC_END
  ),

};
