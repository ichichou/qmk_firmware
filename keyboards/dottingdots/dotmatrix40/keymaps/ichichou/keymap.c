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
    RHYPR_TAB, __________________BASE_L1__________________, __________________BASE_R1__________________, KC_BSPC,
    LCTL_ESC,  __________________BASE_L2__________________, __________________BASE_R2__________________, RCTL_QUOT,
    LSFT_CW,   __________________BASE_L3__________________, __________________BASE_R3__________________, RSFT_BSLS,
    FN, KC_LALT, LGUI_LNG2, NAV_ESC,          LSFT_SPC, XXXXXXX, RCTL_ENT,  SYM_TAB, RGUI_LNG1, KC_RCTL, FN_GRV
  ),

  #ifdef MTGAP_ENABLE
    [_MTGAP] = LAYOUT_wrapper(
      RHYPR_TAB, __________________MTGAP_L1_________________, __________________MTGAP_R1_________________, KC_BSPC,
      LCTL_ESC,  __________________MTGAP_L2_________________, __________________MTGAP_R2_________________, RCTL_MT_QUOT,
      LSFT_CW,   __________________MTGAP_L3_________________, __________________MTGAP_R3_________________, RSFT_BSLS,
      FN, KC_LALT, LGUI_LNG2, NAV_ESC,          LSFT_SPC, XXXXXXX, RCTL_ENT,  SYM_TAB, RGUI_LNG1, KC_RCTL, FN_GRV
    ),
  #endif

  [_NAV] = LAYOUT_wrapper(
    _______, __________________NAV_L1___________________, __________________NAV_R1___________________, G(KC_UP),
    _______, __________________NAV_L2___________________, __________________NAV_R2___________________, G(KC_DOWN),
    _______, __________________NAV_L3___________________, __________________NAV_R3___________________, XXXXXXX,
    _______, _______, _______, _______,      _______, XXXXXXX, _______,     _______, _______, _______, _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______, __________________SYM_L1___________________, __________________SYM_R1___________________, XXXXXXX,
    _______, __________________SYM_L2___________________, __________________SYM_R2___________________, KC_QUOT,
    _______, __________________SYM_L3___________________, __________________SYM_R3___________________, XXXXXXX,
    _______, _______, _______, _______,      _______, XXXXXXX, _______,     _______, _______, _______, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX, __________________WIN_L1___________________, __________________WIN_R1___________________, LCA(KC_BSPC),
    XXXXXXX, __________________WIN_L2___________________, __________________WIN_R2___________________, MEH(KC_ENT),
    XXXXXXX, __________________WIN_L3___________________, __________________WIN_R3___________________, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, _______,      XXXXXXX, XXXXXXX, XXXXXXX,     _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  #if defined(MTGAP_ENABLE)
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q), __________________F1_TO_F4________, BASE,    __________________FN_R1____________________, LCG(KC_Q),
      XXXXXXX,   __________________F5_TO_F8________, MTGAP,   __________________FN_R2____________________, KC_MPLY,
      XXXXXXX,   __________________F9_TO_F12_______, XXXXXXX, __________________FN_R3____________________, KC_MUTE,
      _______, XXXXXXX, XXXXXXX, XXXXXXX,         EE_CLR, XXXXXXX, QK_BOOT,     XXXXXXX, XXXXXXX, XXXXXXX, _______
    ),

  #else
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q), __________________FN_L1____________________, __________________FN_R1____________________, LCG(KC_Q),
      XXXXXXX,   __________________FN_L2____________________, __________________FN_R2____________________, KC_MPLY,
      XXXXXXX,   __________________FN_L3____________________, __________________FN_R3____________________, KC_MUTE,
      _______, XXXXXXX, XXXXXXX, XXXXXXX,         EE_CLR, XXXXXXX, QK_BOOT,     XXXXXXX, XXXXXXX, XXXXXXX, _______
    ),
  #endif

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
  #ifdef MTGAP_ENABLE
    [_MTGAP] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
  #endif
  [_NAV]  = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR) },
  [_SYM]  = { ENCODER_CCW_CW(KC_NO,   KC_NO)   },
  [_WIN]  = { ENCODER_CCW_CW(KC_NO,   KC_NO)   },
  [_FN]   = { ENCODER_CCW_CW(BL_DOWN, BL_UP)   },
};
#endif
