// KB: Equinox XL
// KM: userspace

#include QMK_KEYBOARD_H
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define __________________FN_EQUINOX_R1____________ LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_EQUINOX_R2____________ LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV
#define __________________FN_EQUINOX_R3____________ LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    RHYPR_TAB,     __________________BASE_L1__________________, KC_LBRC, __________________BASE_R1__________________, KC_BSPC, KC_QUOT,
    LCTL_ESC,      __________________BASE_L2__________________, KC_RBRC, __________________BASE_R2__________________,          RCTL_ENT,
    LSFT_CW,  NAV, __________________BASE_L3__________________, KC_GRV,  __________________BASE_R3__________________,          FN_BSLS,
    FN, XXXXXXX, LGUI_LNG2,                           LSFT_SPC, RCTL_TAB, SYM_ENT,                         RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

  #ifdef ENABLE_MTGAP
    [_MTGAP] = LAYOUT_wrapper(
      RHYPR_TAB,     __________________MTGAP_L1_________________, KC_LBRC, __________________MTGAP_R1_________________, KC_BSPC, MT_Q,
      LCTL_ESC,      __________________MTGAP_L2_________________, KC_RBRC, __________________MTGAP_R2_________________,          RCTL_ENT,
      LSFT_CW,  NAV, __________________MTGAP_L3_________________, KC_GRV,  __________________MTGAP_R3_________________,          FN_BSLS,
      FN, XXXXXXX, LGUI_LNG2,                           LSFT_SPC, RCTL_TAB, SYM_ENT,                         RGUI_LNG1, XXXXXXX, RALT_GRV
    ),
  #endif

  #ifdef ENABLE_BUNA
    [_BUNA1] = LAYOUT_wrapper(
      RHYPR_TAB,     __________________BUNA1_L1_________________, KC_LBRC, __________________BUNA1_R1_________________, KC_BSPC, BN1_QUOT,
      LCTL_ESC,      __________________BUNA1_L2_________________, KC_RBRC, __________________BUNA1_R2_________________,          RCTL_ENT,
      LSFT_CW,  NAV, __________________BUNA1_L3_________________, KC_GRV,  __________________BUNA1_R3_________________,          FN_BSLS,
      FN, XXXXXXX, LGUI_LNG2,                           LSFT_SPC, RCTL_TAB, SYM_ENT,                         RGUI_LNG1, XXXXXXX, RALT_GRV
    ),

    [_BUNA2] = LAYOUT_wrapper(
      RHYPR_TAB,     __________________BUNA2_L1_________________, KC_LBRC, __________________BUNA2_R1_________________, KC_BSPC, BN2_QUOT,
      LCTL_ESC,      __________________BUNA2_L2_________________, KC_RBRC, __________________BUNA2_R2_________________,          RCTL_ENT,
      LSFT_CW,  NAV, __________________BUNA2_L3_________________, KC_GRV,  __________________BUNA2_R3_________________,          FN_BSLS,
      FN, XXXXXXX, LGUI_LNG2,                           LSFT_SPC, RCTL_TAB, SYM_ENT,                         RGUI_LNG1, XXXXXXX, RALT_GRV
    ),

    [_BUNA3] = LAYOUT_wrapper(
      RHYPR_TAB,     __________________BUNA3_L1_________________, KC_LBRC, __________________BUNA3_R1_________________, KC_BSPC, BN3_QUOT,
      LCTL_ESC,      __________________BUNA3_L2_________________, KC_RBRC, __________________BUNA3_R2_________________,          RCTL_ENT,
      LSFT_CW,  NAV, __________________BUNA3_L3_________________, KC_GRV,  __________________BUNA3_R3_________________,          FN_BSLS,
      FN, XXXXXXX, LGUI_LNG2,                           LSFT_SPC, RCTL_TAB, SYM_ENT,                         RGUI_LNG1, XXXXXXX, RALT_GRV
    ),
  #endif

  [_NAV] = LAYOUT_wrapper(
    _______,          __________________NAV_L1___________________, XXXXXXX, __________________NAV_R1___________________, G(KC_UP), G(KC_DOWN),
    _______,          __________________NAV_L2___________________, XXXXXXX, __________________NAV_R2___________________,           _______,
    _______, _______, __________________NAV_L3___________________, XXXXXXX, __________________NAV_R3___________________,           _______,
    _______, XXXXXXX, _______,                            _______, _______, _______,                            _______, XXXXXXX,  _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______,          __________________SYM_L1___________________, XXXXXXX, __________________SYM_R1___________________, _______, KC_QUOT,
    _______,          __________________SYM_L2___________________, XXXXXXX, __________________SYM_R2___________________,          _______,
    _______, _______, __________________SYM_L3___________________, XXXXXXX, __________________SYM_R3___________________,          _______,
    _______, XXXXXXX, _______,                            _______, _______, _______,                            _______, XXXXXXX, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX,          __________________WIN_L1___________________, XXXXXXX, __________________WIN_R1___________________, LCA(KC_BSPC), XXXXXXX,
    XXXXXXX,          __________________WIN_L2___________________, XXXXXXX, __________________WIN_R2___________________,               MEH(KC_ENT),
    XXXXXXX, _______, __________________WIN_L3___________________, XXXXXXX, __________________WIN_R3___________________,               XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, _______,                            XXXXXXX, XXXXXXX,      XXXXXXX
  ),

  #if defined(ENABLE_MTGAP) && defined(ENABLE_BUNA)
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q),         __________________FN_L1____________________, BASE,  __________________FN_EQUINOX_R1____________, XXXXXXX, KC_MNXT,
      XXXXXXX,           __________________FN_L2____________________, MTGAP, __________________FN_EQUINOX_R2____________,          KC_MPLY,
      XXXXXXX,  XXXXXXX, __________________FN_L3____________________, BUNA,  __________________FN_EQUINOX_R3____________,          _______,
      _______,  XXXXXXX, XXXXXXX,                             EE_CLR, QK_BOOT, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX
    ),

  #elif defined(ENABLE_MTGAP)
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q),         __________________FN_L1____________________, BASE,    __________________FN_EQUINOX_R1____________, XXXXXXX, KC_MNXT,
      XXXXXXX,           __________________FN_L2____________________, MTGAP,   __________________FN_EQUINOX_R2____________,          KC_MPLY,
      XXXXXXX,  XXXXXXX, __________________FN_L3____________________, XXXXXXX, __________________FN_EQUINOX_R3____________,          _______,
      _______,  XXXXXXX, XXXXXXX,                             EE_CLR, QK_BOOT, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX
    ),

  #elif defined(ENABLE_BUNA)
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q),         __________________FN_L1____________________, BASE,    __________________FN_EQUINOX_R1____________, XXXXXXX, KC_MNXT,
      XXXXXXX,           __________________FN_L2____________________, XXXXXXX, __________________FN_EQUINOX_R2____________,          KC_MPLY,
      XXXXXXX,  XXXXXXX, __________________FN_L3____________________, BUNA,    __________________FN_EQUINOX_R3____________,          _______,
      _______,  XXXXXXX, XXXXXXX,                             EE_CLR, QK_BOOT, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX
    ),

  #else
    [_FN] = LAYOUT_wrapper(
      LCG(KC_Q),         __________________FN_L1____________________, XXXXXXX, __________________FN_EQUINOX_R1____________, XXXXXXX, KC_MNXT,
      XXXXXXX,           __________________FN_L2____________________, XXXXXXX, __________________FN_EQUINOX_R2____________,          KC_MPLY,
      XXXXXXX,  XXXXXXX, __________________FN_L3____________________, XXXXXXX, __________________FN_EQUINOX_R3____________,          _______,
      _______,  XXXXXXX, XXXXXXX,                             EE_CLR, QK_BOOT, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX
    ),
  #endif

};
