// KB: Equinox XL
// KM: ichichou

#include QMK_KEYBOARD_H
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    HYPR_TAB,          __________________BASE_L1__________________, KC_LBRC, __________________BASE_R1__________________, KC_QUOT, KC_BSPC,
    LCTL_ESC,           __________________BASE_L2__________________, KC_RBRC, __________________BASE_R2__________________,          KC_ENT,
    KC_LSFT,   XXXXXXX, __________________BASE_L3__________________, XXXXXXX, __________________BASE_R3__________________,          FN_BSLS,
    KC_LALT,   XXXXXXX, LGUI_LNG2,                         LSFT_SPC, XXXXXXX, SYM_ENT,                          RGUI_LNG1, XXXXXXX, RCTL_GRV
  ),

  [_NAV] = LAYOUT_wrapper(
    _______,          __________________NAV_L1___________________, XXXXXXX, __________________NAV_R1___________________, LCS(KC_LBRC), LCS(KC_RBRC),
    _______,          __________________NAV_L2___________________, XXXXXXX, __________________NAV_R2___________________,               _______,
    _______, _______, __________________NAV_L3___________________, XXXXXXX, __________________NAV_R3___________________,               _______,
    _______, _______, _______,                            _______, _______, _______,                            _______, _______,      _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______,          __________________SYM_L1___________________, KC_LPRN, __________________SYM_R1___________________, XXXXXXX, XXXXXXX,
    _______,          __________________SYM_L2___________________, KC_RPRN, __________________SYM_R2___________________,          _______,
    _______, _______, __________________SYM_L3___________________, XXXXXXX, __________________SYM_R3___________________,          _______,
    _______, _______, _______,                            _______, _______, _______,                            _______, _______, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX,          __________________WIN_L1___________________, XXXXXXX, __________________WIN_R1___________________, XXXXXXX, LCA(KC_BSPC),
    XXXXXXX,          __________________WIN_L2___________________, XXXXXXX, __________________WIN_R2___________________,          MEH(KC_ENT),
    XXXXXXX, XXXXXXX, __________________WIN_L3___________________, XXXXXXX, __________________WIN_R3___________________,          XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_FN] = LAYOUT_wrapper(
    OS_LOCK,          __________________FN_L1____________________, XXXXXXX, LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT,
    XXXXXXX,          __________________FN_L2____________________, XXXXXXX, LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,          KC_MPLY,
    XXXXXXX, XXXXXXX, __________________FN_L3____________________, XXXXXXX, LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
    XXXXXXX, XXXXXXX, XXXXXXX,                             EE_CLR, XXXXXXX, QK_BOOT,                              XXXXXXX, XXXXXXX, XXXXXXX
  ),

};
