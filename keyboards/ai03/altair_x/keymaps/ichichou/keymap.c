// KB: Altair-X
// KM: ichichou

// -- Copyright {{{

/* Copyright 2024 ai03 Design Studio */
/* SPDX-License-Identifier: GPL-2.0-or-later */

// }}}

#include QMK_KEYBOARD_H
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    RHYPR_TAB, __________________BASE_L1__________________, C(KC_1),    C(KC_4), __________________BASE_R1__________________, KC_BSPC,
    LCTL_ESC,  __________________BASE_L2__________________, C(KC_2),    C(KC_5), __________________BASE_R2__________________, RCTL_QUOT,
    LSFT_CW,   __________________BASE_L3__________________, C(KC_3),    C(KC_6), __________________BASE_R3__________________, RSFT_BSLS,
                               KC_LALT, LGUI_LNG2, NAV_ESC, LSFT_SPC,   RCTL_ENT, SYM_TAB, RGUI_LNG1, FN_GRV
  ),

  #ifdef MTGAP_ENABLE
    [_MTGAP] = LAYOUT_wrapper(
      RHYPR_TAB, __________________MTGAP_L1_________________, C(KC_1),    C(KC_4), __________________MTGAP_R1_________________, KC_BSPC,
      LCTL_ESC,  __________________MTGAP_L2_________________, C(KC_2),    C(KC_5), __________________MTGAP_R2_________________, RCTL_MT_QUOT,
      LSFT_CW,   __________________MTGAP_L3_________________, C(KC_3),    C(KC_6), __________________MTGAP_R3_________________, RSFT_BSLS,
                                 KC_LALT, LGUI_LNG2, NAV_ESC, LSFT_SPC,   RCTL_ENT, SYM_TAB, RGUI_LNG1, FN_GRV
    ),
  #endif

  #ifdef BUNA_ENABLE
    [_BUNA1] = LAYOUT_wrapper(
      RHYPR_TAB, __________________BUNA1_L1_________________, XXXXXXX,    XXXXXXX, __________________BUNA1_R1_________________, KC_BSPC,
      LCTL_ESC,  __________________BUNA1_L2_________________, XXXXXXX,    XXXXXXX, __________________BUNA1_R2_________________, RCTL_QUOT,
      LSFT_CW,   __________________BUNA1_L3_________________, XXXXXXX,    XXXXXXX, __________________BUNA1_R3_________________, RSFT_BSLS,
                                 KC_LALT, LGUI_LNG2, NAV_ESC, LSFT_SPC,   RCTL_ENT, SYM_TAB, RGUI_LNG1, FN_GRV
    ),

    [_BUNA2] = LAYOUT_wrapper(
      RHYPR_TAB, __________________BUNA2_L1_________________, XXXXXXX,    XXXXXXX, __________________BUNA2_R1_________________, KC_BSPC,
      LCTL_ESC,  __________________BUNA2_L2_________________, XXXXXXX,    XXXXXXX, __________________BUNA2_R2_________________, RCTL_QUOT,
      LSFT_CW,   __________________BUNA2_L3_________________, XXXXXXX,    XXXXXXX, __________________BUNA2_R3_________________, RSFT_BSLS,
                                 KC_LALT, LGUI_LNG2, NAV_ESC, LSFT_SPC,   RCTL_ENT, SYM_TAB, RGUI_LNG1, FN_GRV
    ),

    [_BUNA3] = LAYOUT_wrapper(
      RHYPR_TAB, __________________BUNA3_L1_________________, XXXXXXX,    XXXXXXX, __________________BUNA3_R1_________________, KC_BSPC,
      LCTL_ESC,  __________________BUNA3_L2_________________, XXXXXXX,    XXXXXXX, __________________BUNA3_R2_________________, RCTL_QUOT,
      LSFT_CW,   __________________BUNA3_L3_________________, XXXXXXX,    XXXXXXX, __________________BUNA3_R3_________________, RSFT_BSLS,
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
    _______, __________________SYM_L1___________________, XXXXXXX,    XXXXXXX, __________________SYM_R1___________________, XXXXXXX,
    _______, __________________SYM_L2___________________, XXXXXXX,    XXXXXXX, __________________SYM_R2___________________, KC_QUOT,
    _______, __________________SYM_L3___________________, XXXXXXX,    XXXXXXX, __________________SYM_R3___________________, XXXXXXX,
                               _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX, __________________WIN_L1___________________, XXXXXXX,    XXXXXXX, __________________WIN_R1___________________, LCA(KC_BSPC),
    XXXXXXX, __________________WIN_L2___________________, XXXXXXX,    XXXXXXX, __________________WIN_R2___________________, MEH(KC_ENT),
    XXXXXXX, __________________WIN_L3___________________, XXXXXXX,    XXXXXXX, __________________WIN_R3___________________, XXXXXXX,
                               XXXXXXX, XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX, XXXXXXX
  ),

  #if defined(MTGAP_ENABLE) && defined(BUNA_ENABLE)
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q), __________________FN_R1____________________, BASE,     LSG(KC_2), __________________FN_L1____________________, LCG(KC_Q),
      XXXXXXX,   __________________FN_R2____________________, MTGAP,    LSG(KC_3), __________________FN_L2____________________, KC_MPLY,
      XXXXXXX,   __________________FN_R3____________________, BUNA,     LSG(KC_4), __________________FN_L3____________________, KC_MUTE,
                                   XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,   QK_BOOT, XXXXXXX, XXXXXXX, _______
    ),

  #elif defined(MTGAP_ENABLE)
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q), __________________FN_R1____________________, BASE,       LSG(KC_2), __________________FN_L1____________________, LCG(KC_Q),
      XXXXXXX,   __________________FN_R2____________________, MTGAP,      LSG(KC_3), __________________FN_L2____________________, KC_MPLY,
      XXXXXXX,   __________________FN_R3____________________, XXXXXXX,    LSG(KC_4), __________________FN_L3____________________, KC_MUTE,
                                   XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,     QK_BOOT, XXXXXXX, XXXXXXX, _______
    ),

  #elif defined(BUNA_ENABLE)
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q), __________________FN_R1____________________, BASE,       LSG(KC_2), __________________FN_L1____________________, LCG(KC_Q),
      XXXXXXX,   __________________FN_R2____________________, XXXXXXX,    LSG(KC_3), __________________FN_L2____________________, KC_MPLY,
      XXXXXXX,   __________________FN_R3____________________, BUNA,       LSG(KC_4), __________________FN_L3____________________, KC_MUTE,
                                   XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,     QK_BOOT, XXXXXXX, XXXXXXX, _______
    ),

  #else
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q), __________________FN_R1____________________, XXXXXXX,    LSG(KC_2), __________________FN_L1____________________, LCG(KC_Q),
      XXXXXXX,   __________________FN_R2____________________, XXXXXXX,    LSG(KC_3), __________________FN_L2____________________, KC_MPLY,
      XXXXXXX,   __________________FN_R3____________________, XXXXXXX,    LSG(KC_4), __________________FN_L3____________________, KC_MUTE,
                                   XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,     QK_BOOT, XXXXXXX, XXXXXXX, _______
    ),
  #endif

};
