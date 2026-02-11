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
    RHYPR_TAB, __________________BASE_L1__________________, G(KC_LBRC), XXXXXXX,  __________________BASE_R1__________________, KC_BSPC,
    LCTL_ESC,  __________________BASE_L2__________________, G(KC_RBRC), XXXXXXX,  __________________BASE_R2__________________, KC_QUOT,
    KC_LSFT,   __________________BASE_L3__________________, FN,         FN,       __________________BASE_R3__________________, KC_BSLS,
                               KC_LALT, LGUI_LNG2, NAV_ESC, LSFT_SPC,   RCTL_ENT, SYM_TAB, RGUI_LNG1, FN_GRV
  ),

  [_MTGAP] = LAYOUT_wrapper(
    RHYPR_TAB, __________________MTGAP_L1_________________, G(KC_LBRC), XXXXXXX,  __________________MTGAP_R1_________________, KC_BSPC,
    LCTL_ESC,  __________________MTGAP_L2_________________, G(KC_RBRC), XXXXXXX,  __________________MTGAP_R2_________________, MT_QUOT,
    KC_LSFT,   __________________MTGAP_L3_________________, FN,         FN,       __________________MTGAP_R3_________________, MT_BSLS,
                               KC_LALT, LGUI_LNG2, NAV_ESC, LSFT_SPC,   RCTL_ENT, SYM_TAB, RGUI_LNG1, FN_GRV
  ),

  [_NAV] = LAYOUT_wrapper(
    _______, __________________NAV_L1___________________, XXXXXXX, XXXXXXX, __________________NAV_R1___________________, G(KC_UP),
    _______, __________________NAV_L2___________________, XXXXXXX, XXXXXXX, __________________NAV_R2___________________, G(KC_DOWN),
    _______, __________________NAV_L3___________________, _______, _______, __________________NAV_R3___________________, XXXXXXX,
                               _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______, __________________SYM_L1___________________, XXXXXXX, XXXXXXX, __________________SYM_R1___________________, XXXXXXX,
    _______, __________________SYM_L2___________________, XXXXXXX, XXXXXXX, __________________SYM_R2___________________, XXXXXXX,
    _______, __________________SYM_L3___________________, _______, _______, __________________SYM_R3___________________, XXXXXXX,
                               _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX, __________________WIN_L1___________________, C(KC_1), C(KC_4), __________________WIN_R1___________________, LCA(KC_BSPC),
    XXXXXXX, __________________WIN_L2___________________, C(KC_2), C(KC_5), __________________WIN_R2___________________, MEH(KC_ENT),
    XXXXXXX, __________________WIN_L3___________________, C(KC_3), C(KC_6), __________________WIN_R3___________________, XXXXXXX,
                               XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX
  ),

  [_FN] = LAYOUT_wrapper(
    OS_LOCK, __________________FN_L1____________________, BASE,    XXXXXXX, __________________FN_R1____________________, OS_LOCK,
    XXXXXXX, __________________FN_L2____________________, MTGAP,   XXXXXXX, __________________FN_R2____________________, KC_MPLY,
    XXXXXXX, __________________FN_L3____________________, _______, _______, __________________FN_R3____________________, KC_MUTE,
                                XXXXXXX, XXXXXXX, EE_CLR, QK_BOOT, QK_BOOT, EE_CLR, XXXXXXX, _______
  ),

};
