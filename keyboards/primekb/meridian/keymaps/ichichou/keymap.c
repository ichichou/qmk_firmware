// KB: Meridian
// KM: ichichou

// To compile:
// >_ qmk compile -c -kb primekb/meridian/ktr1010

// -- Copyright {{{

/*
Copyright 2020 Holten Campbell

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
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT_split_bs_rshift(__VA_ARGS__)

#define __________________FN_MERIDIAN_R1___________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_MERIDIAN_R2___________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV
#define __________________FN_MERIDIAN_R3___________ XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    KC_ESC,    __________________1_TO_5___________________, KC_6,   __________________7_TO_MINS________________, KC_EQL,  KC_BSPC, KC_DEL,
    RHYPR_TAB, __________________BASE_L1__________________,         __________________BASE_L1__________________, KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_ESC,  __________________BASE_L2__________________,         __________________BASE_L2__________________, KC_QUOT,          RCTL_ENT,
    LSFT_CW,   __________________BASE_L3__________________, KC_GRV, __________________BASE_L3__________________,          KC_UP,   FN_BSLS,
    FN, KC_LALT,                       LGUI_LNG2, LSFT_SPC,         SYM_ENT, RGUI_LNG1,                          KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_NAV] = LAYOUT_wrapper(
    XXXXXXX, __________________NONE_____________________, XXXXXXX, __________________NONE_____________________, XXXXXXX,   XXXXXXX, XXXXXXX,
    _______, __________________NAV_L1___________________,          __________________NAV_R1___________________, G(KC_UP),  XXXXXXX, XXXXXXX,
    _______, __________________NAV_L2___________________,          __________________NAV_R2___________________, G(KC_DOWN),         XXXXXXX,
    _______, __________________NAV_L3___________________, XXXXXXX, __________________NAV_R3___________________,            XXXXXXX, XXXXXXX,
    _______, _______,                   _______, _______,          _______, _______,                            XXXXXXX,   XXXXXXX, XXXXXXX
  ),

  [_SYM] = LAYOUT_wrapper(
    XXXXXXX, __________________NONE_____________________, XXXXXXX, __________________NONE_____________________, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, __________________SYM_L1___________________,          __________________SYM_R1___________________, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, __________________SYM_L2___________________,          __________________SYM_R2___________________, KC_QUOT,          XXXXXXX,
    _______, __________________SYM_L3___________________, XXXXXXX, __________________SYM_R3___________________,          XXXXXXX, XXXXXXX,
    _______, _______,                   _______, _______,          _______, _______,                            XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX, __________________NONE_____________________, XXXXXXX, __________________NONE_____________________, XXXXXXX, LCA(KC_BSPC), XXXXXXX,
    XXXXXXX, __________________WIN_L1___________________,          __________________WIN_R1___________________, XXXXXXX, XXXXXXX,      MEH(KC_ENT),
    XXXXXXX, __________________WIN_L2___________________,          __________________WIN_R2___________________, XXXXXXX,               XXXXXXX,
    XXXXXXX, __________________WIN_L3___________________, XXXXXXX, __________________WIN_R3___________________,          XXXXXXX,      XXXXXXX,
    XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX,      XXXXXXX
  ),

  [_FN] = LAYOUT_wrapper(
    LCG(KC_Q), __________________F1_TO_F5_________________, KC_F6,   __________________F7_TO_F11________________, KC_F12,  LCG(KC_Q), XXXXXXX,
    XXXXXXX,   __________________FN_L1____________________,          __________________FN_MERIDIAN_R1___________, XXXXXXX, KC_TILD,   KC_GRV,
    XXXXXXX,   __________________FN_L2____________________,          __________________FN_MERIDIAN_R2___________, KC_MNXT,            KC_MPLY,
    XXXXXXX,   __________________FN_L3____________________, QK_BOOT, __________________FN_MERIDIAN_R3___________,          KC_MUTE,   _______,
    _______,   XXXXXXX,                    XXXXXXX, EE_CLR,          XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX,   XXXXXXX
  ),

};
