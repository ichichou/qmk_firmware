// KB: Altair-X
// KM: ichichou

// -- Copyright {{{

/* Copyright 2024 ai03 Design Studio */
/* SPDX-License-Identifier: GPL-2.0-or-later */

// }}}

#include QMK_KEYBOARD_H
#include "ichichou.h"

#define __________________FN_ALTAIR_R1_____________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_ALTAIR_R2_____________ XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT
#define __________________FN_ALTAIR_R3_____________ XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    RHYPR_TAB, __________________BASE_L1__________________, C(KC_1),    C(KC_4), __________________BASE_R1__________________, KC_BSPC,
    LCTL_ESC,  __________________BASE_L2__________________, C(KC_2),    C(KC_5), __________________BASE_R2__________________, RCTL_QUOT,
    LSFT_CW,   __________________BASE_L3__________________, C(KC_3),    C(KC_6), __________________BASE_R3__________________, RSFT_BSLS,
                               KC_LALT, LGUI_LNG2, NAV_ESC, LSFT_SPC,   RCTL_ENT, SYM_TAB, RGUI_LNG1, FN_GRV
  ),

  // [_BASE] = LAYOUT_wrapper(
  //   RHYPR_TAB, __________________BASE_L1__________________, C(KC_1),    C(KC_4), __________________BASE_R1__________________, KC_BSPC,
  //   LCTL_ESC,  __________________BASE_L2__________________, C(KC_2),    C(KC_5), __________________BASE_R2__________________, RCTL_QUOT,
  //   LSFT_CW,   __________________BASE_L3__________________, C(KC_3),    C(KC_6), __________________BASE_R3__________________, FN_BSLS,
  //                                   FN, LGUI_LNG2, NAV_ESC, LSFT_SPC,   RCTL_ENT, SYM_TAB, RGUI_LNG1, RALT_GRV
  // ),

  #ifdef MTGAP
    [_MTGAP] = LAYOUT_wrapper(
      RHYPR_TAB, __________________MTGAP_L1_________________, C(KC_1),    C(KC_4), __________________MTGAP_R1_________________, KC_BSPC,
      LCTL_ESC,  __________________MTGAP_L2_________________, C(KC_2),    C(KC_5), __________________MTGAP_R2_________________, RCTL_MT_QUOT,
      LSFT_CW,   __________________MTGAP_L3_________________, C(KC_3),    C(KC_6), __________________MTGAP_R3_________________, RSFT_BSLS,
                                 KC_LALT, LGUI_LNG2, NAV_ESC, LSFT_SPC,   RCTL_ENT, SYM_TAB, RGUI_LNG1, FN_GRV
    ),
  #endif

  [_NAV] = LAYOUT_wrapper(
    _______, __________________NAV_L1___________________, XXXXXXX,    XXXXXXX, __________________NAV_R1___________________, G(KC_UP),
    _______, __________________NAV_L2___________________, XXXXXXX,    XXXXXXX, __________________NAV_R2___________________, G(KC_DOWN),
    _______, __________________NAV_L3___________________, XXXXXXX,    XXXXXXX, __________________NAV_R3___________________, XXXXXXX,
                               _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______, __________________SYM_L1___________________, XXXXXXX,    XXXXXXX, __________________SYM_R1___________________, KC_RPRN,
    _______, __________________SYM_L2___________________, XXXXXXX,    XXXXXXX, __________________SYM_R2___________________, KC_COMM,
    _______, __________________SYM_L3___________________, XXXXXXX,    XXXXXXX, __________________SYM_R3___________________, XXXXXXX,
                               _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX, __________________WIN_L1___________________, XXXXXXX,    XXXXXXX, __________________WIN_R1___________________, LCA(KC_BSPC),
    XXXXXXX, __________________WIN_L2___________________, XXXXXXX,    XXXXXXX, __________________WIN_R2___________________, MEH(KC_ENT),
    XXXXXXX, __________________WIN_L3___________________, XXXXXXX,    XXXXXXX, __________________WIN_R3___________________, XXXXXXX,
                               XXXXXXX, XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX, XXXXXXX
  ),

  #ifdef MTGAP
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q), __________________FN_R1____________________, BASE,       LSG(KC_2), __________________FN_ALTAIR_R1_____________, LCG(KC_Q),
      DM_REC1,   __________________FN_R2____________________, MTGAP,      LSG(KC_3), __________________FN_ALTAIR_R2_____________, KC_MPLY,
      DM_PLY1,   __________________FN_R3____________________, XXXXXXX,    LSG(KC_4), __________________FN_ALTAIR_R3_____________, KC_MUTE,
                                   XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,     QK_BOOT,   XXXXXXX, XXXXXXX, _______
    ),
  #else
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q), __________________FN_R1____________________, XXXXXXX,    LSG(KC_2), __________________FN_ALTAIR_R1_____________, LCG(KC_Q),
      DM_REC1,   __________________FN_R2____________________, XXXXXXX,    LSG(KC_3), __________________FN_ALTAIR_R2_____________, KC_MPLY,
      DM_PLY1,   __________________FN_R3____________________, XXXXXXX,    LSG(KC_4), __________________FN_ALTAIR_R3_____________, KC_MUTE,
                                   XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,     QK_BOOT,   XXXXXXX, XXXXXXX, _______
    ),
  #endif

  // #ifdef MTGAP
  //   [_FN] = LAYOUT_wrapper(
  //     LCG(KC_Q), __________________FN_R1____________________, BASE,       LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCG(KC_Q),
  //     DM_REC1,   __________________FN_R2____________________, MTGAP,      LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY,
  //     DM_PLY1,   __________________FN_R3____________________, XXXXXXX,    LSG(KC_4), XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, _______,
  //                                  _______, XXXXXXX, XXXXXXX, EE_CLR,     QK_BOOT,   XXXXXXX, XXXXXXX, XXXXXXX
  //   ),
  // #else
  //   [_FN] = LAYOUT_wrapper(
  //     LCG(KC_Q), __________________FN_R1____________________, XXXXXXX,    LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCG(KC_Q),,
  //     DM_REC1,   __________________FN_R2____________________, XXXXXXX,    LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY,
  //     DM_PLY1,   __________________FN_R3____________________, XXXXXXX,    LSG(KC_4), XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, _______,
  //                                  _______, XXXXXXX, XXXXXXX, EE_CLR,     QK_BOOT,   XXXXXXX, XXXXXXX, XXXXXXX
  //   ),
  // #endif

};
