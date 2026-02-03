// KB: Equinox XL
// KM: ichichou

#include QMK_KEYBOARD_H
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    RHYPR_TAB,     __________________BASE_L1__________________, KC_LBRC, __________________BASE_R1__________________, KC_BSPC, KC_QUOT,
    LCTL_ESC,      __________________BASE_L2__________________, KC_RBRC, __________________BASE_R2__________________,          KC_ENT,
    KC_LSFT,  NAV, __________________BASE_L3__________________, KC_BSLS, __________________BASE_R3__________________,          FN_BSLS,
    KC_LALT, XXXXXXX, LGUI_LNG2,                      LSFT_SPC, KC_RCTL, SYM_ENT,                          RGUI_LNG1, XXXXXXX, FN_GRV
  ),

  [_MTGAP] = LAYOUT_wrapper(
    RHYPR_TAB,     __________________MTGAP_L1_________________, KC_LBRC, __________________MTGAP_R1_________________, KC_BSPC, MT_QUOT,
    LCTL_ESC,      __________________MTGAP_L2_________________, KC_RBRC, __________________MTGAP_R2_________________,          KC_ENT,
    KC_LSFT,  NAV, __________________MTGAP_L3_________________, KC_BSLS, __________________MTGAP_R3_________________,          FN_BSLS,
    KC_LALT, XXXXXXX, LGUI_LNG2,                      LSFT_SPC, KC_RCTL, SYM_ENT,                          RGUI_LNG1, XXXXXXX, FN_GRV
  ),

  [_NAV] = LAYOUT_wrapper(
    _______,          __________________NAV_L1___________________, XXXXXXX, __________________NAV_R1___________________, G(KC_UP), G(KC_DOWN),
    _______,          __________________NAV_L2___________________, XXXXXXX, __________________NAV_R2___________________,           _______,
    _______, _______, __________________NAV_L3___________________, XXXXXXX, __________________NAV_R3___________________,           _______,
    _______, XXXXXXX, _______,                            _______, _______, _______,                            _______, XXXXXXX,  _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______,          __________________SYM_L1___________________, XXXXXXX, __________________SYM_R1___________________, KC_RPRN, KC_RBRC,
    _______,          __________________SYM_L2___________________, XXXXXXX, __________________SYM_R2___________________,          _______,
    _______, _______, __________________SYM_L3___________________, XXXXXXX, __________________SYM_R3___________________,          _______,
    _______, XXXXXXX, _______,                            _______, _______, _______,                            _______, XXXXXXX, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX,          __________________WIN_L1___________________, XXXXXXX, __________________WIN_R1___________________, LCA(KC_BSPC), XXXXXXX,
    XXXXXXX,          __________________WIN_L2___________________, XXXXXXX, __________________WIN_R2___________________,               MEH(KC_ENT),
    XXXXXXX, _______, __________________WIN_L3___________________, XXXXXXX, __________________WIN_R3___________________,               XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX,      XXXXXXX
  ),

  [_FN] = LAYOUT_wrapper(
    OS_LOCK,          __________________FN_L1____________________, BASE,    LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT,
    XXXXXXX,          __________________FN_L2____________________, MTGAP,   LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,          KC_MPLY,
    XXXXXXX, XXXXXXX, __________________FN_L3____________________, XXXXXXX, LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
    XXXXXXX, XXXXXXX, XXXXXXX,                             EE_CLR, XXXXXXX, QK_BOOT,                              XXXXXXX, XXXXXXX, _______
  ),

};
