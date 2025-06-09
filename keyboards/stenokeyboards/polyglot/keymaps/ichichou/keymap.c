// KB: Polyglot
// KM: ichichou

// Copyright {{{

/*
Copyright 2023 StenoKeyboards

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

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    RHYPR_TAB, __________________BASE_L1__________________, __________________BASE_R1__________________, KC_BSPC,
    LCTL_ESC,  __________________BASE_L2__________________, __________________BASE_R2__________________, RCTL_QUOT,
    LSFT_CW,   __________________BASE_L3__________________, __________________BASE_R3__________________, FN_BSLS,
                              LGUI_LNG2, NAV_ESC, LSFT_SPC, RCTL_ENT, SYM_TAB, RGUI_LNG1
  ),

  [_MTGAP] = LAYOUT_wrapper(
    RHYPR_TAB, __________________MTGAP_L1_________________, __________________MTGAP_R1_________________, KC_BSPC,
    LCTL_ESC,  __________________MTGAP_L2_________________, __________________MTGAP_R2_________________, RCTL_MT_QUOT,
    LSFT_CW,   __________________MTGAP_L3_________________, __________________MTGAP_R3_________________, FN_BSLS,
                              LGUI_LNG2, NAV_ESC, LSFT_SPC, RCTL_ENT, SYM_TAB, RGUI_LNG1
  ),

  [_GEMINI] = LAYOUT_wrapper(
    STN_N3, __________________GEMINI_L1________________, __________________GEMINI_R1________________, STN_DR,
    STN_N4, __________________GEMINI_L2________________, __________________GEMINI_R2________________, STN_ZR,
    QWERTY, __________________GEMINI_L3________________, __________________GEMINI_R3________________, FN,
                                   STN_N1, STN_A, STN_O, STN_E, STN_U, STN_N2
  ),

  [_PLOVER] = LAYOUT_wrapper(
    KC_3,   __________________PLOVER_L1________________, __________________PLOVER_R1________________, KC_RBRC,
    KC_4,   __________________PLOVER_L2________________, __________________PLOVER_R2________________, KC_QUOT,
    QWERTY, __________________PLOVER_L3________________, __________________PLOVER_R3________________, FN,
                                       KC_1, KC_C, KC_V, KC_N, KC_M, KC_2
  ),

  [_NAV] = LAYOUT_wrapper(
    _______, __________________NAV_L1___________________, __________________NAV_R1___________________, G(KC_UP),
    _______, __________________NAV_L2___________________, __________________NAV_R2___________________, G(KC_DOWN),
    _______, __________________NAV_L3___________________, __________________NAV_R3___________________, XXXXXXX,
                               _______, _______, _______, _______, _______, _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______, __________________SYM_L1___________________, __________________SYM_R1___________________, KC_RPRN,
    _______, __________________SYM_L2___________________, __________________SYM_R2___________________, KC_RBRC,
    _______, __________________SYM_L3___________________, __________________SYM_R3___________________, XXXXXXX,
                               _______, _______, _______, _______, _______, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX, __________________WIN_L1___________________, __________________WIN_R1___________________, LCA(KC_BSPC),
    XXXXXXX, __________________WIN_L2___________________, __________________WIN_R2___________________, MEH(KC_ENT),
    XXXXXXX, __________________WIN_L3___________________, __________________WIN_R3___________________, XXXXXXX,
                               XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX
  ),

  [_FN] = LAYOUT_wrapper(
    OS_LOCK, KC_F1,   KC_F2,   XXXXXXX, XXXXXXX, QWERTY,    LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OS_LOCK,
    DM_REC1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MTGAP,     LSG(KC_3), XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY,
    DM_PLY1, XXXXXXX, XXXXXXX, XXXXXXX, PLOVER,  GEMINI,    LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, _______,
                               KC_LALT, XXXXXXX, EE_CLR,    QK_BOOT,   XXXXXXX, KC_RALT
  ),

};
