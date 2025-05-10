// KB: Equinox XL
// KM: userspace

#include QMK_KEYBOARD_H
#include "ichichou.h"

// -- Keymaps {{{

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    RHYPR_TAB,          KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_Y, KC_U, KC_I,    KC_O,   KC_P,      KC_BSPC, KC_QUOT,
    LCTL_ESC,           KC_A, KC_S, KC_D, KC_F, KC_G, KC_RBRC, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,            RCTL_ENT,
    LSFT_CW,   NAV,     KC_Z, KC_X, KC_C, KC_V, KC_B, KC_GRV,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,            FN_BSLS,
    FN,        XXXXXXX, LGUI_LNG2,        LSFT_SPC,   RCTL_TAB,      SYM_ENT,               RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

#ifdef ENABLE_MTGAP
  [_MTGAP] = LAYOUT(
    RHYPR_TAB,          MT_Y, MT_P,    MT_O,    MT_U,   MT_SCLN, KC_LBRC, MT_K, MT_D, MT_L, MT_C, MT_W,      KC_BSPC, MT_Q,
    LCTL_ESC,           MT_I, MT_N,    MT_E,    MT_A,   MT_COMM, KC_RBRC, MT_M, MT_H, MT_T, MT_S, MT_R,               RCTL_ENT,
    LSFT_CW,   NAV,     MT_Z, MT_SLSH, MT_QUOT, MT_DOT, MT_X,    KC_GRV,  MT_B, MT_F, MT_G, MT_V, MT_J,               FN_BSLS,
    FN,        XXXXXXX, LGUI_LNG2,              LSFT_SPC,        RCTL_TAB,      SYM_ENT,          RGUI_LNG1, XXXXXXX, RALT_GRV
  ),
#endif

#ifdef ENABLE_BUNA
  [_BUNA1] = LAYOUT(
    RHYPR_TAB,          BN1_Q, BN1_W, BN1_E, BN1_R, BN1_T, KC_LBRC, BN1_Y, BN1_U, BN1_I,    BN1_O,   BN1_P,     KC_BSPC, BN1_QUOT,
    LCTL_ESC,           BN1_A, BN1_S, BUNA2, BN1_F, BN1_G, KC_RBRC, BN1_H, BN1_J, BUNA3,    BN1_L,   BN1_SCLN,           RCTL_ENT,
    LSFT_CW,   NAV,     BN1_Z, BN1_X, BN1_C, BN1_V, BN1_B, KC_GRV,  BN1_N, BN1_M, BN1_COMM, BN1_DOT, BN1_SLSH,           FN_BSLS,
    FN,        XXXXXXX, LGUI_LNG2,           LSFT_SPC,     RCTL_TAB,       SYM_ENT,                  RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

  [_BUNA2] = LAYOUT(
    RHYPR_TAB,          BN2_Q, BN2_W, BN2_E, BN2_R, BN2_T, KC_LBRC, BN2_Y, BN2_U, BN2_I,    BN2_O,   BN2_P,     KC_BSPC, BN2_QUOT,
    LCTL_ESC,           BN2_A, BN2_S, BN2_D, BN2_F, BN2_G, KC_RBRC, BN2_H, BN2_J, BN2_K,    BN2_L,   BN2_SCLN,           RCTL_ENT,
    LSFT_CW,   NAV,     BN2_Z, BN2_X, BN2_C, BN2_V, BN2_B, KC_GRV,  BN2_N, BN2_M, BN2_COMM, BN2_DOT, BN2_SLSH,           FN_BSLS,
    FN,        XXXXXXX, LGUI_LNG2,           LSFT_SPC,     RCTL_TAB,       SYM_ENT,                  RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

  [_BUNA3] = LAYOUT(
    RHYPR_TAB,          BN3_Q, BN3_W, BN3_E, BN3_R, BN3_T, KC_LBRC, BN3_Y, BN3_U, BN3_I,    BN3_O,   BN3_P,     KC_BSPC, BN3_QUOT,
    LCTL_ESC,           BN3_A, BN3_S, BN3_D, BN3_F, BN3_G, KC_RBRC, BN3_H, BN3_J, BN3_K,    BN3_L,   BN3_SCLN,           RCTL_ENT,
    LSFT_CW,   NAV,     BN3_Z, BN3_X, BN3_C, BN3_V, BN3_B, KC_GRV,  BN3_N, BN3_M, BN3_COMM, BN3_DOT, BN3_SLSH,           FN_BSLS,
    FN,        XXXXXXX, LGUI_LNG2,           LSFT_SPC,     RCTL_TAB,       SYM_ENT,                  RGUI_LNG1, XXXXXXX, RALT_GRV
  ),
#endif

  [_NAV] = LAYOUT(
    _______,          LSG(KC_C), KC_LPRN,   KC_RPRN,   C(KC_TAB), LSG(KC_T), XXXXXXX, G(KC_TAB), C(KC_TAB), KC_LCBR, KC_RCBR, G(KC_RBRC), G(KC_UP), G(KC_DOWN),
    _______,          LSG(KC_A), LCTL_LBRC, LSFT_RBRC, LCG(KC_V), LCG(KC_S), XXXXXXX, KC_LEFT,   KC_DOWN,   KC_UP,   KC_RGHT, G(KC_LBRC),           _______,
    _______, _______, LSG(KC_Z), G(KC_X),   G(KC_C),   LSG(KC_V), G(KC_V),   XXXXXXX, KC_BSPC,   KC_DEL,    C(KC_A), C(KC_E), XXXXXXX,              _______,
    _______, XXXXXXX, _______,                         _______,              _______,            _______,                     _______,    XXXXXXX,  _______
  ),

  [_SYM] = LAYOUT(
    _______,          KC_DOT,  KC_PLUS, KC_UNDS, KC_EXLM, KC_PIPE, XXXXXXX, KC_GRV,  KC_QUES, KC_CIRC, KC_DLR,  KC_COMM, _______, KC_QUOT,
    _______,          KC_ASTR, KC_EQL,  KC_MINS, KC_0,    KC_AT,   XXXXXXX, KC_AMPR, KC_1,    KC_PERC, KC_HASH, KC_COLN,          _______,
    _______, _______, KC_8,    KC_6,    KC_4,    KC_2,    KC_BSLS, XXXXXXX, KC_TILD, KC_3,    KC_5,    KC_7,    KC_9,             _______,
    _______, XXXXXXX, _______,                   _______,          _______,          _______,                   _______, XXXXXXX, _______
  ),

  [_WIN] = LAYOUT(
    XXXXXXX,          LCA(KC_U),    LCA(KC_I), XXXXXXX,   MEH(KC_C),    C(KC_1), XXXXXXX, C(KC_4), MEH(KC_C),   A(KC_UP),    XXXXXXX, XXXXXXX, LCA(KC_BSPC), XXXXXXX,
    XXXXXXX,          LCA(KC_LEFT), XXXXXXX,   XXXXXXX,   LCA(KC_RGHT), C(KC_2), XXXXXXX, C(KC_5), LCA(KC_C),   A(KC_DOWN),  XXXXXXX, XXXXXXX,               MEH(KC_ENT),
    XXXXXXX, XXXXXXX, LCA(KC_Z),    LCA(KC_X), LCA(KC_V), LCA(KC_B),    C(KC_3), XXXXXXX, C(KC_6), LCA(KC_ENT), MEH(KC_ENT), XXXXXXX, XXXXXXX,               XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,               XXXXXXX,          XXXXXXX,                           XXXXXXX, XXXXXXX,      XXXXXXX
  ),

#if defined(ENABLE_MTGAP) && defined(ENABLE_BUNA)
  [_FN] = LAYOUT(
    LCG(KC_Q),          KC_F1, KC_F2,  KC_F3,  KC_F4,  XXXXXXX, BASE,    LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT,
    XXXXXXX,            KC_F5, KC_F6,  KC_F7,  KC_F8,  XXXXXXX, MTGAP,   LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,          KC_MPLY,
    XXXXXXX,   XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, BUNA1,   LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
    _______,   XXXXXXX, XXXXXXX,               EE_CLR,          QK_BOOT,            XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
  ),
#elif defined(ENABLE_MTGAP)
  [_FN] = LAYOUT(
    LCG(KC_Q),          KC_F1, KC_F2,  KC_F3,  KC_F4,  XXXXXXX, BASE,    LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT,
    XXXXXXX,            KC_F5, KC_F6,  KC_F7,  KC_F8,  XXXXXXX, MTGAP,   LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,          KC_MPLY,
    XXXXXXX,   XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
    _______,   XXXXXXX, XXXXXXX,               EE_CLR,          QK_BOOT,            XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
  ),
#elif defined(ENABLE_BUNA)
  [_FN] = LAYOUT(
    LCG(KC_Q),          KC_F1, KC_F2,  KC_F3,  KC_F4,  XXXXXXX, BASE,    LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT,
    XXXXXXX,            KC_F5, KC_F6,  KC_F7,  KC_F8,  XXXXXXX, BUNA1,   LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,          KC_MPLY,
    XXXXXXX,   XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
    _______,   XXXXXXX, XXXXXXX,               EE_CLR,          QK_BOOT,            XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
  ),
#else
  [_FN] = LAYOUT(
    LCG(KC_Q),          KC_F1, KC_F2,  KC_F3,  KC_F4,  XXXXXXX, XXXXXXX, LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT,
    XXXXXXX,            KC_F5, KC_F6,  KC_F7,  KC_F8,  XXXXXXX, XXXXXXX, LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,          KC_MPLY,
    XXXXXXX,   XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
    _______,   XXXXXXX, XXXXXXX,               EE_CLR,          QK_BOOT,            XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
  ),
#endif

};

// }}}
