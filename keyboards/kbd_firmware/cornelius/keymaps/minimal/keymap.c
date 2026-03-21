// KB: Cornelius Rev 2
// KM: minimal

// Copyright {{{

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

// }}}

#include QMK_KEYBOARD_H

// Layers {{{

enum layer_names {
  _BASE,
  _NAV,
  _SYM,
  _WIN,
  _FN,
};

// }}}

// Macros {{{

// Layers
#define NAV  MO(_NAV)
#define SYM  MO(_SYM)
#define WIN  MO(_WIN)
#define FN   MO(_FN)

// Modifiers
#define LCG(kc) (QK_LCTL | QK_LGUI | (kc))

// Layer-Tap
#define NAV_ESC  LT(_NAV, KC_ESC)
#define SYM_BSPC LT(_SYM, KC_BSPC)
#define FN_GRV   LT(_FN,  KC_GRV)

// Mod-Tap
#define HYPR_TAB  MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, KC_TAB)
#define LSFT_SPC  SFT_T(KC_SPC)
#define LCTL_ESC  CTL_T(KC_ESC)
#define RCTL_ENT  RCTL_T(KC_ENT)
#define LGUI_LNG2 GUI_T(KC_LNG2)
#define RGUI_LNG1 RGUI_T(KC_LNG1)

// Home Row Mods
#define LCTL_LBRC CTL_T(KC_LBRC)
#define LSFT_RBRC SFT_T(KC_RBRC)

// Otherwise
#define OS_LOCK LCG(KC_Q)

// }}}

// Wrappers {{{

#define __________________BASE_L1__________________ KC_Q, KC_W, KC_E, KC_R, KC_T
#define __________________BASE_L2__________________ KC_A, KC_S, KC_D, KC_F, KC_G
#define __________________BASE_L3__________________ KC_Z, KC_X, KC_C, KC_V, KC_B

#define __________________BASE_R1__________________ KC_Y, KC_U, KC_I,    KC_O,   KC_P
#define __________________BASE_R2__________________ KC_H, KC_J, KC_K,    KC_L,   KC_SCLN
#define __________________BASE_R3__________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

#define __________________NAV_L1___________________ LSG(KC_C), KC_LPRN,   KC_RPRN,   C(KC_TAB), LSG(KC_T)
#define __________________NAV_L2___________________ LSG(KC_A), LCTL_LBRC, LSFT_RBRC, LCG(KC_V), LCG(KC_S)
#define __________________NAV_L3___________________ LSG(KC_Z), G(KC_X),   G(KC_C),   LSG(KC_V), G(KC_V)

#define __________________NAV_R1___________________ G(KC_TAB), C(KC_TAB), KC_LCBR, KC_RCBR, G(KC_RBRC)
#define __________________NAV_R2___________________ KC_LEFT,   KC_DOWN,   KC_UP,   KC_RGHT, G(KC_LBRC)
#define __________________NAV_R3___________________ KC_BSPC,   KC_DEL,    C(KC_A), C(KC_E), G(KC_GRV)

#define __________________SYM_L1___________________ KC_DOT,  KC_PLUS, KC_UNDS, KC_EXLM, KC_PIPE
#define __________________SYM_L2___________________ KC_ASTR, KC_EQL,  KC_MINS, KC_0,    KC_AT
#define __________________SYM_L3___________________ KC_8,    KC_6,    KC_4,    KC_2,    KC_BSLS

#define __________________SYM_R1___________________ KC_SLSH, KC_AMPR, KC_CIRC, KC_DLR,  KC_COMM
#define __________________SYM_R2___________________ KC_TILD, KC_1,    KC_PERC, KC_HASH, KC_COLN
#define __________________SYM_R3___________________ KC_GRV,  KC_3,    KC_5,    KC_7,    KC_9

#define __________________WIN_L1___________________ XXXXXXX,      LCA(KC_U), LCA(KC_I), MEH(KC_C),    C(KC_1)
#define __________________WIN_L2___________________ LCA(KC_LEFT), LCA(KC_J), LCA(KC_K), LCA(KC_RGHT), C(KC_2)
#define __________________WIN_L3___________________ LCA(KC_Z),    LCA(KC_X), LCA(KC_V), LCA(KC_B),    C(KC_3)

#define __________________WIN_R1___________________ C(KC_4), MEH(KC_C),   A(KC_UP),    LCA(KC_UP),   XXXXXXX
#define __________________WIN_R2___________________ C(KC_5), LCA(KC_C),   A(KC_DOWN),  LCA(KC_DOWN), XXXXXXX
#define __________________WIN_R3___________________ C(KC_6), LCA(KC_ENT), MEH(KC_ENT), XXXXXXX,      XXXXXXX

#define __________________FN_L1____________________ KC_F1,      KC_F2,      XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_L2____________________ RCTL(KC_U), XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_L3____________________ G(KC_LBRC), G(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX

#define __________________FN_R1____________________ LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_R2____________________ LSG(KC_3), XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT
#define __________________FN_R3____________________ LSG(KC_4), XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU

// }}}

// Tap-Hold Configuration {{{

// Quick Tap
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYM_BSPC:
      return TAPPING_TERM;
    default:
      return QUICK_TAP_TERM;
  }
}

// }}}

// Tri Layers {{{

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _SYM, _WIN);
}

// }}}

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    HYPR_TAB,    __________________BASE_L1__________________, __________________BASE_R1__________________,     KC_BSPC,
    LCTL_ESC,    __________________BASE_L2__________________, __________________BASE_R2__________________,     KC_QUOT,
    KC_LSFT,     __________________BASE_L3__________________, __________________BASE_R3__________________,     KC_BSLS,
    FN,       KC_RCTL, KC_LALT, LGUI_LNG2, NAV_ESC, LSFT_SPC, RCTL_ENT, SYM_BSPC, RGUI_LNG1, KC_RALT, KC_RCTL, FN_GRV
  ),

  [_NAV] = LAYOUT_wrapper(
    _______, __________________NAV_L1___________________, __________________NAV_R1___________________, G(KC_UP),
    _______, __________________NAV_L2___________________, __________________NAV_R2___________________, G(KC_DOWN),
    _______, __________________NAV_L3___________________, __________________NAV_R3___________________, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______, __________________SYM_L1___________________, __________________SYM_R1___________________, XXXXXXX,
    _______, __________________SYM_L2___________________, __________________SYM_R2___________________, XXXXXXX,
    _______, __________________SYM_L3___________________, __________________SYM_R3___________________, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX, __________________WIN_L1___________________, __________________WIN_R1___________________, LCA(KC_BSPC),
    XXXXXXX, __________________WIN_L2___________________, __________________WIN_R2___________________, MEH(KC_ENT),
    XXXXXXX, __________________WIN_L3___________________, __________________WIN_R3___________________, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_FN] = LAYOUT_wrapper(
    OS_LOCK, __________________FN_L1____________________, __________________FN_R1____________________, OS_LOCK,
    XXXXXXX, __________________FN_L2____________________, __________________FN_R2____________________, KC_MPLY,
    XXXXXXX, __________________FN_L3____________________, __________________FN_R3____________________, KC_MUTE,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),

};
