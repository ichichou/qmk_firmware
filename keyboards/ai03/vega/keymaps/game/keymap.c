// KB: Vega
// KM: game

// -- Copyright {{{

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

// }}}

#include QMK_KEYBOARD_H

// -- Macros {{{

// Layers
#define MAC      DF(_MAC)
#define WINDOWS  DF(_WINDOWS)
#define GAME     DF(_GAME)
#define FN       MO(_FN)

// Modifiers
#define RHYPR_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)
#define LCG(kc)     (QK_LCTL | QK_LGUI | (kc))

// Mod-Tap
#define RHYPR_TAB RHYPR_T(KC_TAB)
#define LSFT_SPC  SFT_T(KC_SPC)
#define LSFT_CW   SFT_T(CW_TOGG)
#define LCTL_ESC  CTL_T(KC_ESC)
#define LCTL_INT5 CTL_T(KC_INT5)
#define RCTL_ENT  RCTL_T(KC_ENT)
#define LGUI_LNG2 GUI_T(KC_LNG2)
#define RGUI_LNG1 RGUI_T(KC_LNG1)
#define RGUI_INT4 RGUI_T(KC_INT4)

// Otherwise
#define LOCK_MAC LCG(KC_Q)
#define LOCK_WIN G(KC_L)

// }}}

enum layer_names {
  _MAC,
  _WINDOWS,
  _GAME,
  _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAC] = LAYOUT_all(
    KC_ESC,             KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC, KC_DEL,  KC_DEL,
    RHYPR_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,          KC_GRV,
    LCTL_ESC,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, RCTL_ENT,                   KC_TILD,
    LSFT_CW,   XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                    KC_UP,   FN,
    FN,        KC_LALT, LGUI_LNG2,                 XXXXXXX, LSFT_SPC, XXXXXXX,                   XXXXXXX, RGUI_LNG1,                  KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_WINDOWS] = LAYOUT_all(
    KC_ESC,             KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC, KC_DEL,  KC_DEL,
    RHYPR_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,          KC_GRV,
    LCTL_ESC,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, RCTL_ENT,                   KC_TILD,
    LSFT_CW,   XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                    KC_UP,   FN,
    FN,        KC_LALT, LCTL_INT5,                 XXXXXXX, LSFT_SPC, XXXXXXX,                   XXXXXXX, RGUI_INT4,                  KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_GAME] = LAYOUT_all(
    KC_ESC,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  KC_DEL,
    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
    KC_RCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGDN,
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   FN,
    FN,      KC_LALT, KC_LGUI,                   XXXXXXX, KC_SPC,   XXXXXXX,                   XXXXXXX, KC_RGUI,                   KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN] = LAYOUT_all(
    LOCK_WIN,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  XXXXXXX, LOCK_MAC,
    XXXXXXX,           GAME,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
    XXXXXXX,           MAC,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY,                   XXXXXXX,
    XXXXXXX,  XXXXXXX, WINDOWS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,                   KC_PGUP, _______,
    _______,  XXXXXXX, XXXXXXX,                   EE_CLR,  QK_BOOT,  XXXXXXX,                   XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_END
  ),

};
