// KB: Cornelius
// KM: ichichou

// -- Copyright {{{

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
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    RHYPR_TAB, __________________BASE_L1__________________,    __________________BASE_L1__________________,  KC_BSPC,
    LCTL_ESC,  __________________BASE_L2__________________,    __________________BASE_L2__________________,  RCTL_QUOT,
    LSFT_CW,   __________________BASE_L3__________________,    __________________BASE_L3__________________,  RSFT_BSLS,
    FN, KC_RCTL, KC_LALT,     LGUI_LNG2, NAV_ESC, LSFT_SPC,    RCTL_ENT, SYM_TAB, RGUI_LNG1, KC_DOWN, KC_UP, FN_GRV
  ),

  [_NAV] = LAYOUT_wrapper(
    _______, __________________NAV_L1___________________,    __________________NAV_R1___________________, G(KC_UP),
    _______, __________________NAV_L2___________________,    __________________NAV_R2___________________, G(KC_DOWN),
    _______, __________________NAV_L3___________________,    __________________NAV_R3___________________, XXXXXXX,
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______, __________________SYM_L1___________________,    __________________SYM_R1___________________, XXXXXXX,
    _______, __________________SYM_L2___________________,    __________________SYM_R2___________________, KC_QUOT,
    _______, __________________SYM_L3___________________,    __________________SYM_R3___________________, XXXXXXX,
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX, __________________WIN_L1___________________,    __________________WIN_R1___________________, LCA(KC_BSPC),
    XXXXXXX, __________________WIN_L2___________________,    __________________WIN_R2___________________, MEH(KC_ENT),
    XXXXXXX, __________________WIN_L3___________________,    __________________WIN_R3___________________, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_FN] = LAYOUT_wrapper(
    LCG(KC_Q), __________________FN_L1____________________,    __________________FN_R1____________________, LCG(KC_Q),
    XXXXXXX,   __________________FN_L2____________________,    __________________FN_R2____________________, KC_MPLY,
    XXXXXXX,   __________________FN_L3____________________,    __________________FN_R3____________________, KC_MUTE,
    _______,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, EE_CLR,    QK_BOOT, XXXXXXX, XXXXXXX, KC_LEFT, KC_RGHT, _______
  ),

};
