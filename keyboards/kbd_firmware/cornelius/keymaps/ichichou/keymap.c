/* Copyright 2020 foostan
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

#define RHYPR_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)
#define LCG(kc) (QK_LCTL | QK_LGUI | (kc))

#define LOWR_ESC  LT(_LOWER, KC_ESC)
#define UPPR_TAB  LT(_RAISE, KC_TAB)
#define FN_GRV    LT(_FN, KC_GRV)
#define HYPR_TAB  RHYPR_T(KC_TAB)
#define HYPR_BSPC RHYPR_T(KC_BSPC)
#define CTL_ESC   CTL_T(KC_ESC)
#define CTL_ENT   CTL_T(KC_ENT)
#define CTL_QUOT  CTL_T(KC_QUOT)
#define CTL_LBRC  CTL_T(KC_LBRC)
#define SFT_SPC   SFT_T(KC_SPC)
#define SFT_RBRC  SFT_T(KC_RBRC)
#define SFT_CW    SFT_T(CW_TOGG)
#define GUI_LNG2  GUI_T(KC_LNG2)
#define RGUI_LNG1 RGUI_T(KC_LNG1)

enum layer_names {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN,
};

// Tri Layers
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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

// // Key Overrides
// const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_ALT, KC_ESC, KC_GRV);
// const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_TILD);
// const key_override_t *key_overrides[] = {
//   &grave_esc_override,
//   &tilde_esc_override,
// };

// // Combos
// const uint16_t PROGMEM ab_combo[] = {KC_A, KC_B, COMBO_END};
// combo_t key_combos[] = {
//   COMBO(ab_combo, KC_ESC),
// };

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
    case LOWR_ESC:
      return true;
    case UPPR_TAB:
      return true;
    case FN_GRV:
      return true;
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

  [_BASE] = LAYOUT(
    HYPR_TAB, KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,      KC_O,    KC_P,    HYPR_BSPC,
    CTL_ESC,  KC_A,    KC_S,    KC_D,     KC_F,     KC_G,    KC_H,    KC_J,     KC_K,      KC_L,    KC_SCLN, CTL_QUOT,
    SFT_CW,   KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,    KC_N,    KC_M,     KC_COMM,   KC_DOT,  KC_SLSH, KC_BSLS,
    MO(_FN),  KC_RCTL, KC_LALT, GUI_LNG2, LOWR_ESC, SFT_SPC, CTL_ENT, UPPR_TAB, RGUI_LNG1, KC_DOWN, KC_UP,   FN_GRV
  ),

  [_LOWER] = LAYOUT(
    _______, LSG(KC_S), KC_LPRN,      KC_RPRN,      MEH(KC_C), LSG(KC_T), G(KC_TAB), C(KC_TAB), KC_LCBR, KC_RCBR, G(KC_RGHT), G(KC_UP),
    _______, LSG(KC_A), CTL_LBRC,     SFT_RBRC,     LCG(KC_V), LCG(KC_S), KC_LEFT,   KC_DOWN,   KC_UP,   KC_RGHT, G(KC_LEFT), G(KC_DOWN),
    _______, LSG(KC_Z), LCA(KC_LEFT), LCA(KC_RGHT), LSG(KC_V), G(KC_V),   KC_BSPC,   KC_DEL,    C(KC_A), C(KC_E), XXXXXXX,    XXXXXXX,
    _______, _______,   _______,      _______,      _______,   _______,   _______,   _______,   _______, _______, _______,    _______
  ),

  [_RAISE] = LAYOUT(
    _______, KC_DOT,  KC_PLUS, KC_UNDS, KC_EXLM, KC_PIPE, KC_GRV,  KC_QUES, KC_CIRC, KC_DLR,  KC_COMM, XXXXXXX,
    _______, KC_ASTR, KC_EQL,  KC_MINS, KC_0,    KC_AT,   KC_AMPR, KC_1,    KC_PERC, KC_HASH, KC_COLN, XXXXXXX,
    _______, KC_8,    KC_6,    KC_4,    KC_2,    KC_BSLS, KC_TILD, KC_3,    KC_5,    KC_7,    KC_9,    XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
    XXXXXXX, LCA(KC_U),    LCA(KC_I), XXXXXXX,   MEH(KC_C),    C(KC_3), C(KC_6), LCA(KC_BSPC), XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX,
    XXXXXXX, LCA(KC_LEFT), LCA(KC_D), LCA(KC_G), LCA(KC_RGHT), C(KC_2), C(KC_5), LCA(KC_C),    XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX,
    XXXXXXX, LCA(KC_Z),    LCA(KC_X), LCA(KC_V), LCA(KC_B),    C(KC_1), C(KC_4), LCA(KC_ENT),  A(KC_UP), A(KC_DOWN), XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,      XXXXXXX,   XXXXXXX,   _______,      XXXXXXX, XXXXXXX, _______,      XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX
  ),

  [_FN] = LAYOUT(
    LCG(KC_Q), KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, LSG(KC_4), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCG(KC_Q),
    XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, LSG(KC_3), XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY,
    XXXXXXX,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, LSG(KC_2), XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,
    _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,   XXXXXXX, XXXXXXX, KC_LEFT, KC_RGHT, _______
  ),

};
