// KB: dotmatrix40
// KM: ichichou

// -- Copyright {{{

// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// }}}

#include QMK_KEYBOARD_H
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    RHYPR_TAB, __________________BASE_L1__________________,          __________________BASE_R1__________________, KC_BSPC,
    LCTL_ESC,  __________________BASE_L2__________________,          __________________BASE_R2__________________, RCTL_QUOT,
    LSFT_CW,   __________________BASE_L3__________________,          __________________BASE_R3__________________, RSFT_BSLS,
    FN,        KC_LALT, LGUI_LNG2, NAV_ESC,       LSFT_SPC, XXXXXXX, RCTL_ENT,       SYM_TAB, RGUI_LNG1, KC_RCTL, FN_GRV
  ),

  [_MTGAP] = LAYOUT_wrapper(
    RHYPR_TAB, __________________MTGAP_L1_________________,          __________________MTGAP_R1_________________, KC_BSPC,
    LCTL_ESC,  __________________MTGAP_L2_________________,          __________________MTGAP_R2_________________, RCTL_MT_QUOT,
    LSFT_CW,   __________________MTGAP_L3_________________,          __________________MTGAP_R3_________________, RSFT_BSLS,
    FN,        KC_LALT, LGUI_LNG2, NAV_ESC,       LSFT_SPC, XXXXXXX, RCTL_ENT,       SYM_TAB, RGUI_LNG1, KC_RCTL, FN_GRV
  ),

  [_NAV] = LAYOUT_wrapper(
    _______, __________________NAV_L1___________________,          __________________NAV_R1___________________, G(KC_UP),
    _______, __________________NAV_L2___________________,          __________________NAV_R2___________________, G(KC_DOWN),
    _______, __________________NAV_L3___________________,          __________________NAV_R3___________________, XXXXXXX,
    _______, _______, _______, _______,          _______, XXXXXXX, _______,          _______, _______, _______, _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______, __________________SYM_L1___________________,          __________________SYM_R1___________________, XXXXXXX,
    _______, __________________SYM_L2___________________,          __________________SYM_R2___________________, XXXXXXX,
    _______, __________________SYM_L3___________________,          __________________SYM_R3___________________, XXXXXXX,
    _______, _______, _______, _______,          _______, XXXXXXX, _______,          _______, _______, _______, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX, __________________WIN_L1___________________,          __________________WIN_R1___________________, LCA(KC_BSPC),
    XXXXXXX, __________________WIN_L2___________________,          __________________WIN_R2___________________, MEH(KC_ENT),
    XXXXXXX, __________________WIN_L3___________________,          __________________WIN_R3___________________, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_FN] = LAYOUT_wrapper(
    OS_LOCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   BASE,             __________________FN_R1____________________, OS_LOCK,
    DM_REC1, UG_HUED, UG_HUEU, XXXXXXX, XXXXXXX, MTGAP,            __________________FN_R2____________________, KC_MPLY,
    DM_PLY1, UG_VALD, UG_VALU, XXXXXXX, XXXXXXX, XXXXXXX,          __________________FN_R3____________________, KC_MUTE,
    _______, XXXXXXX, XXXXXXX, XXXXXXX,          EE_CLR,  XXXXXXX, QK_BOOT,          XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE]  = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
  [_MTGAP] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
  [_NAV]   = { ENCODER_CCW_CW(KC_UP,   KC_DOWN) },
  [_SYM]   = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
  [_WIN]   = { ENCODER_CCW_CW(KC_NO,   KC_NO)   },
  [_FN]    = { ENCODER_CCW_CW(BL_DOWN, BL_UP)   },
};
#endif

// BL_UP:   フィラメント LED の光量アップ
// BL_DOWN: フィラメント LED の光量ダウン
// UG_VALU: アンダーグロウ LED の光量アップ
// UG_VALD: アンダーグロウ LED の光量ダウン
// UG_HUEU: アンダーグロウ LED の hue アップ
// UG_HUED: アンダーグロウ LED の hue ダウン
