// KB: Vega
// KM: ichichou

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
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT_all(__VA_ARGS__)

#define __________________FN_VEGA_R1_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_VEGA_R2_______________ XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT
#define __________________FN_VEGA_R3_______________ XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    KC_ESC,            __________________1_TO_5___________________, KC_6,    __________________7_TO_MINS________________, KC_EQL,  KC_BSPC, KC_DEL,  KC_DEL,
    RHYPR_TAB,         __________________BASE_L1__________________, KC_LBRC, __________________BASE_L1__________________, KC_QUOT, KC_BSLS,          KC_GRV,
    LCTL_ESC,          __________________BASE_L2__________________, KC_RBRC, __________________BASE_L2__________________, RCTL_ENT,                  KC_TILD,
    LSFT_CW,  XXXXXXX, __________________BASE_L3__________________, KC_GRV,  __________________BASE_L3__________________,                   KC_UP,   FN_BSLS,
    FN,       KC_LALT, LGUI_LNG2,                          XXXXXXX, LSFT_SPC, XXXXXXX,                XXXXXXX, RGUI_LNG1,          KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_NAV] = LAYOUT_wrapper(
    _______,          __________________NONE_____________________, XXXXXXX, __________________NONE_____________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,          __________________NAV_L1___________________, XXXXXXX, __________________NAV_R1___________________, XXXXXXX, XXXXXXX,          XXXXXXX,
    _______,          __________________NAV_L2___________________, XXXXXXX, __________________NAV_R2___________________, XXXXXXX,                   XXXXXXX,
    _______, XXXXXXX, __________________NAV_L3___________________, XXXXXXX, __________________NAV_R3___________________,                   XXXXXXX, XXXXXXX,
    _______, _______, _______,                            XXXXXXX, _______, XXXXXXX,                   XXXXXXX, _______,          XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SYM] = LAYOUT_wrapper(
    _______,          __________________NONE_____________________, XXXXXXX, __________________NONE_____________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,          __________________SYM_L1___________________, XXXXXXX, __________________SYM_R1___________________, KC_QUOT, XXXXXXX,          XXXXXXX,
    _______,          __________________SYM_L2___________________, XXXXXXX, __________________SYM_R2___________________, XXXXXXX,                   XXXXXXX,
    _______, XXXXXXX, __________________SYM_L3___________________, XXXXXXX, __________________SYM_R3___________________,                   XXXXXXX, XXXXXXX,
    _______, _______, _______,                            XXXXXXX, _______, XXXXXXX,                   XXXXXXX, _______,          XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX,          __________________NONE_____________________, XXXXXXX, __________________NONE_____________________, XXXXXXX, LCA(KC_BSPC), XXXXXXX, XXXXXXX,
    XXXXXXX,          __________________WIN_L1___________________, XXXXXXX, __________________WIN_R1___________________, XXXXXXX, MEH(KC_ENT),           XXXXXXX,
    XXXXXXX,          __________________WIN_L2___________________, XXXXXXX, __________________WIN_R2___________________, XXXXXXX,                        XXXXXXX,
    XXXXXXX, XXXXXXX, __________________WIN_L3___________________, XXXXXXX, __________________WIN_R3___________________,                        XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,          XXXXXXX,      XXXXXXX, XXXXXXX
  ),

  [_FN] = LAYOUT_wrapper(
    LCG(KC_Q),        __________________F1_TO_F5_________________, KC_F6,   __________________F7_TO_F11________________, KC_F12,  KC_DEL,  XXXXXXX, XXXXXXX,
    XXXXXXX,          __________________FN_L1____________________, XXXXXXX, __________________FN_VEGA_R1_______________, XXXXXXX, XXXXXXX,          G(KC_UP),
    XXXXXXX,          __________________FN_L2____________________, XXXXXXX, __________________FN_VEGA_R2_______________, KC_MPLY,                   G(KC_DOWN),
    XXXXXXX, XXXXXXX, __________________FN_L3____________________, QK_BOOT, __________________FN_VEGA_R3_______________,                   KC_PGUP, _______,
    _______, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,          KC_HOME, KC_PGDN, KC_END
  ),

};
