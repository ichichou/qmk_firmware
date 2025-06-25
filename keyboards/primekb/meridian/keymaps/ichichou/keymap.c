// KB: Meridian (KTR1010 LED)
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

// void keyboard_post_init_user(void) {
//   rgblight_disable();
// }
// // RGB ライトをオフにするための関数だが、これを有効化せずとも
// // ユーザースペースからキーマップをコンパイルすると RGB ライトはオフになる

#define LAYOUT_wrapper(...) LAYOUT_split_bs_rshift(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    KC_ESC,    __________________1_TO_5___________________, KC_6,   __________________7_TO_MINS________________, KC_EQL,  KC_BSPC, KC_DEL,
    RHYPR_TAB, __________________BASE_L1__________________,         __________________BASE_R1__________________, KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_ESC,  __________________BASE_L2__________________,         __________________BASE_R2__________________, KC_QUOT,          RCTL_ENT,
    LSFT_CW,   __________________BASE_L3__________________, KC_GRV, __________________BASE_R3__________________,          KC_UP,   FN,
    FN,        KC_LALT,                LGUI_LNG2, LSFT_SPC,         SYM_ENT, RGUI_LNG1,                          KC_LEFT, KC_DOWN, KC_RGHT
  ),

  // [_BASE] = LAYOUT_wrapper(
  //   KC_ESC,    __________________1_TO_5___________________, KC_6,   __________________7_TO_MINS________________, KC_EQL,  KC_BSPC, KC_DEL,
  //   RHYPR_TAB, __________________BASE_L1__________________,         __________________BASE_R1__________________, KC_LBRC, KC_RBRC, KC_BSLS,
  //   LCTL_ESC,  __________________BASE_L2__________________,         __________________BASE_R2__________________, KC_QUOT,          RCTL_ENT,
  //   LSFT_CW,   __________________BASE_L3__________________, KC_GRV, __________________BASE_R3__________________,          KC_RSFT, FN,
  //   FN,        KC_RCTL,                LGUI_LNG2, LSFT_SPC,         SYM_ENT, RGUI_LNG1,                          KC_RALT, KC_RCTL, FN
  // ),

  [_MTGAP] = LAYOUT_wrapper(
    KC_ESC,    __________________1_TO_5___________________, KC_6,   __________________7_TO_MINS________________, KC_EQL,  KC_BSPC, KC_DEL,
    RHYPR_TAB, __________________MTGAP_L1_________________,         __________________MTGAP_R1_________________, KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_ESC,  __________________MTGAP_L2_________________,         __________________MTGAP_R2_________________, MT_QUOT,          RCTL_ENT,
    LSFT_CW,   __________________MTGAP_L3_________________, KC_GRV, __________________MTGAP_R3_________________,          KC_UP,   FN,
    FN,        KC_LALT,                LGUI_LNG2, LSFT_SPC,         SYM_ENT, RGUI_LNG1,                          KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_NAV] = LAYOUT_wrapper(
    _______, __________________NONE_____________________, XXXXXXX, __________________NONE_____________________, XXXXXXX,    XXXXXXX, XXXXXXX,
    _______, __________________NAV_L1___________________,          __________________NAV_R1___________________, G(KC_UP),   XXXXXXX, XXXXXXX,
    _______, __________________NAV_L2___________________,          __________________NAV_R2___________________, G(KC_DOWN),          XXXXXXX,
    _______, __________________NAV_L3___________________, XXXXXXX, __________________NAV_R3___________________,             XXXXXXX, XXXXXXX,
    _______, _______,                   _______, _______,          _______, _______,                            XXXXXXX,    XXXXXXX, XXXXXXX
  ),

  [_SYM] = LAYOUT_wrapper(
    _______, __________________NONE_____________________, XXXXXXX, __________________NONE_____________________, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, __________________SYM_L1___________________,          __________________SYM_R1___________________, KC_RPRN, XXXXXXX, XXXXXXX,
    _______, __________________SYM_L2___________________,          __________________SYM_R2___________________, KC_RBRC,          XXXXXXX,
    _______, __________________SYM_L3___________________, XXXXXXX, __________________SYM_R3_WITHOUT_NAV_______,          XXXXXXX, XXXXXXX,
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
    OS_LOCK, __________________F1_TO_F5_________________, KC_F6,   __________________F7_TO_F11________________, KC_F12,  OS_LOCK, OS_LOCK,
    XXXXXXX, __________________NONE____________, BASE,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    DM_REC1, __________________NONE____________, MTGAP,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT,          KC_MPLY,
    DM_PLY1, __________________NONE____________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU,          KC_MUTE, _______,
    _______, XXXXXXX,                   XXXXXXX, EE_CLR,           QK_BOOT, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX
  ),

};
