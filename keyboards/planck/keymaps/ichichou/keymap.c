// KB: Planck Rev 6 (Drop)
// KM: ichichou

// To compile:
// >_ qmk compile -c -kb planck/rev6_drop

// -- Copyright {{{

/* Copyright 2015-2021 Jack Humbert
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

#define LAYOUT_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    RHYPR_TAB, __________________BASE_L1__________________, __________________BASE_R1__________________,    KC_BSPC,
    LCTL_ESC,  __________________BASE_L2__________________, __________________BASE_R2__________________,    RCTL_QUOT,
    LSFT_CW,   __________________BASE_L3__________________, __________________BASE_R3__________________,    RSFT_BSLS,
    FN, KC_RCTL, KC_LALT,     LGUI_LNG2, NAV_ESC, LSFT_SPC, RCTL_ENT, SYM_TAB, RGUI_LNG1, KC_RALT, KC_RCTL, FN_GRV
  ),

  [_MTGAP] = LAYOUT_wrapper(
    RHYPR_TAB, __________________MTGAP_L1_________________, __________________MTGAP_R1_________________,    KC_BSPC,
    LCTL_ESC,  __________________MTGAP_L2_________________, __________________MTGAP_R2_________________,    RCTL_MT_QUOT,
    LSFT_CW,   __________________MTGAP_L3_________________, __________________MTGAP_R3_________________,    RSFT_BSLS,
    FN, KC_RCTL, KC_LALT,     LGUI_LNG2, NAV_ESC, LSFT_SPC, RCTL_ENT, SYM_TAB, RGUI_LNG1, KC_RALT, KC_RCTL, FN_GRV
  ),

  [_GEMINI] = LAYOUT_wrapper(
    STN_N3,  __________________GEMINI_L1________________, __________________GEMINI_R1________________, STN_DR,
    STN_N4,  __________________GEMINI_L2________________, __________________GEMINI_R2________________, STN_ZR,
    XXXXXXX, __________________GEMINI_L3________________, __________________GEMINI_R3________________, XXXXXXX,
    FN,      XXXXXXX, XXXXXXX,      STN_N1, STN_A, STN_O, STN_E, STN_U, STN_N2,      XXXXXXX, XXXXXXX, XXXXXXX
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
    OS_LOCK, __________________F1_TO_F4________, QWERTY,    __________________FN_R1____________________, OS_LOCK,
    DM_REC1, __________________F5_TO_F8________, MTGAP,     __________________FN_R2____________________, KC_MPLY,
    DM_PLY1, __________________F9_TO_F12_______, GEMINI,    __________________FN_R3____________________, KC_MUTE,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),

};
