// ichichou.h

#pragma once
#include QMK_KEYBOARD_H

// -- Layers {{{

enum layer_names {
  _BASE,

  #ifdef MTGAP_ENABLE
    _MTGAP,
  #endif

  #ifdef BUNA_ENABLE
    _BUNA1,
    _BUNA2,
    _BUNA3,
  #endif

  #ifdef SHINGETA_ENABLE
    _SHINGETA,
    _JSYM,
  #endif

  _NAV,
  _SYM,
  _WIN,
  _FN,
};

// }}}

// -- Custom Keycodes {{{

enum my_keycodes {
  KC_SAMPLE = QK_USER,
  // MTGAP {{{
  #ifdef MTGAP_ENABLE
    MT_A,
    MT_B,
    MT_C,
    MT_D,
    MT_E,
    MT_F,
    MT_G,
    MT_H,
    MT_I,
    MT_J,
    MT_K,
    MT_L,
    MT_M,
    MT_N,
    MT_O,
    MT_P,
    MT_Q,
    MT_R,
    MT_S,
    MT_T,
    MT_U,
    MT_V,
    MT_W,
    MT_X,
    MT_Y,
    MT_Z,
    MT_SCLN,
    MT_QUOT,
    MT_COMM,
    MT_DOT,
    MT_SLSH,
  #endif
  // }}}
  // Buna {{{
  #ifdef BUNA_ENABLE
    // _BN1 {{{
    BN1_A,
    BN1_B,
    BN1_C,
    BN1_D,
    BN1_E,
    BN1_F,
    BN1_G,
    BN1_H,
    BN1_I,
    BN1_J,
    BN1_K,
    BN1_L,
    BN1_M,
    BN1_N,
    BN1_O,
    BN1_P,
    BN1_Q,
    BN1_R,
    BN1_S,
    BN1_T,
    BN1_U,
    BN1_V,
    BN1_W,
    BN1_X,
    BN1_Y,
    BN1_Z,
    BN1_SCLN,
    BN1_QUOT,
    BN1_COMM,
    BN1_DOT,
    BN1_SLSH,
    // }}}
    // _BN2 {{{
    BN2_A,
    BN2_B,
    BN2_C,
    BN2_D,
    BN2_E,
    BN2_F,
    BN2_G,
    BN2_H,
    BN2_I,
    BN2_J,
    BN2_K,
    BN2_L,
    BN2_M,
    BN2_N,
    BN2_O,
    BN2_P,
    BN2_Q,
    BN2_R,
    BN2_S,
    BN2_T,
    BN2_U,
    BN2_V,
    BN2_W,
    BN2_X,
    BN2_Y,
    BN2_Z,
    BN2_SCLN,
    BN2_QUOT,
    BN2_COMM,
    BN2_DOT,
    BN2_SLSH,
    // }}}
    // _BN3 {{{
    BN3_A,
    BN3_B,
    BN3_C,
    BN3_D,
    BN3_E,
    BN3_F,
    BN3_G,
    BN3_H,
    BN3_I,
    BN3_J,
    BN3_K,
    BN3_L,
    BN3_M,
    BN3_N,
    BN3_O,
    BN3_P,
    BN3_Q,
    BN3_R,
    BN3_S,
    BN3_T,
    BN3_U,
    BN3_V,
    BN3_W,
    BN3_X,
    BN3_Y,
    BN3_Z,
    BN3_SCLN,
    BN3_QUOT,
    BN3_COMM,
    BN3_DOT,
    BN3_SLSH,
    // }}}
  #endif
  // }}}
  // Shingeta {{{
  #ifdef SHINGETA_ENABLE
    // 制御用キーコード {{{
    SG_ON,
    SG_OFF,
    // }}}
    // 配置用キーコード {{{
    SG_A,
    SG_B,
    SG_C,
    SG_D,
    SG_E,
    SG_F,
    SG_G,
    SG_H,
    SG_I,
    SG_J,
    SG_K,
    SG_L,
    SG_M,
    SG_N,
    SG_O,
    SG_P,
    SG_Q,
    SG_R,
    SG_S,
    SG_T,
    SG_U,
    SG_V,
    SG_W,
    SG_X,
    SG_Y,
    SG_Z,
    SG_SCLN,
    SG_QUOT,
    SG_COMM,
    SG_DOT,
    SG_SLSH,
    // }}}
    // 出力用キーコード {{{
    // 清音 {{{
    OUT_A,
    OUT_I,
    OUT_U,
    OUT_E,
    OUT_O,
    OUT_KA,
    OUT_KI,
    OUT_KU,
    OUT_KE,
    OUT_KO,
    OUT_SA,
    OUT_SI,
    OUT_SU,
    OUT_SE,
    OUT_SO,
    OUT_TA,
    OUT_TI,
    OUT_TU,
    OUT_TE,
    OUT_TO,
    OUT_NA,
    OUT_NI,
    OUT_NU,
    OUT_NE,
    OUT_NO,
    OUT_HA,
    OUT_HI,
    OUT_HU,
    OUT_HE,
    OUT_HO,
    OUT_MA,
    OUT_MI,
    OUT_MU,
    OUT_ME,
    OUT_MO,
    OUT_YA,
    OUT_YU,
    OUT_YO,
    OUT_RA,
    OUT_RI,
    OUT_RU,
    OUT_RE,
    OUT_RO,
    OUT_WA,
    OUT_WO,
    OUT_NN,
    // }}}
    // 濁音・半濁音 {{{
    OUT_GA,
    OUT_GI,
    OUT_GU,
    OUT_GE,
    OUT_GO,
    OUT_ZA,
    OUT_ZI,
    OUT_ZU,
    OUT_ZE,
    OUT_ZO,
    OUT_DA,
    OUT_DI,
    OUT_DU,
    OUT_DE,
    OUT_DO,
    OUT_BA,
    OUT_BI,
    OUT_BU,
    OUT_BE,
    OUT_BO,
    OUT_PA,
    OUT_PI,
    OUT_PU,
    OUT_PE,
    OUT_PO,
    // }}}
    // 拗音 {{{
    OUT_KYA,
    OUT_KYU,
    OUT_KYO,
    OUT_SYA,
    OUT_SYU,
    OUT_SYO,
    OUT_TYA,
    OUT_TYU,
    OUT_TYO,
    OUT_NYA,
    OUT_NYU,
    OUT_NYO,
    OUT_HYA,
    OUT_HYU,
    OUT_HYO,
    OUT_MYA,
    OUT_MYU,
    OUT_MYO,
    OUT_RYA,
    OUT_RYU,
    OUT_RYO,
    OUT_GYA,
    OUT_GYU,
    OUT_GYO,
    OUT_ZYA,
    OUT_ZYU,
    OUT_ZYO,
    OUT_DYA,
    OUT_DYU,
    OUT_DYO,
    OUT_BYA,
    OUT_BYU,
    OUT_BYO,
    OUT_PYA,
    OUT_PYU,
    OUT_PYO,
    // }}}
    // 外来音 {{{
    OUT_WI,
    OUT_WE,
    OUT_WHO,
    OUT_FA,
    OUT_FI,
    OUT_FE,
    OUT_FO,
    OUT_SYE,
    OUT_ZYE,
    OUT_TYE,
    OUT_THI,
    OUT_DHI,
    OUT_TWU,
    OUT_DWU,
    OUT_VU,
    // }}}
    // 捨て仮名 {{{
    OUT_XTU,
    OUT_XYA,
    OUT_XYU,
    OUT_XYO,
    OUT_XA,
    OUT_XI,
    OUT_XU,
    OUT_XE,
    OUT_XO,
    OUT_XWA,
    // }}}
    // 記号 {{{
    OUT_COMM,
    OUT_DOT,
    OUT_LONG,
    OUT_MDOT,
    OUT_SLSH,
    OUT_EXLM,
    OUT_QUES,
    OUT_SCLN,
    OUT_COLN,
    OUT_LBRC,
    OUT_RBRC,
    OUT_LPRN,
    OUT_RPRN,
    OUT_LCBR,
    OUT_RCBR,
    OUT_BRCS,
    OUT_PRNS,
    OUT_CBRS,
    // }}}
    // }}}
    // Japanese Symbol {{{
    JSYM_Y,
    JSYM_U,
    JSYM_I,
    JSYM_O,
    JSYM_P,
    JSYM_H,
    JSYM_J,
    JSYM_K,
    JSYM_L,
    JSYM_SCLN,
    JSYM_QUOT,
    JSYM_N,
    JSYM_M,
    JSYM_COMM,
    JSYM_DOT,
    JSYM_SLSH,
    // }}}
  #endif
  // }}}
  // Inverted Number Row {{{
  #ifdef INVERTED_NUM_ROW
    INV_1,
    INV_2,
    INV_3,
    INV_4,
    INV_5,
    INV_6,
    INV_7,
    INV_8,
    INV_9,
    INV_0,
  #endif
  // }}}
};

// }}}

// -- Macros {{{

// Layers
#define BASE DF(_BASE)
#define NAV  MO(_NAV)
#define SYM  MO(_SYM)
#define WIN  MO(_WIN)
#define FN   MO(_FN)

// Modifiers
#define RHYPR_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)
#define LCG(kc)     (QK_LCTL | QK_LGUI | (kc))

// Layer-Tap
#define NAV_ESC LT(_NAV, KC_ESC)
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_TAB LT(_SYM, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define FN_BSLS LT(_FN,  KC_BSLS)
#define FN_GRV  LT(_FN,  KC_GRV)

// Mod-Tap
#define RHYPR_TAB  RHYPR_T(KC_TAB)
#define RHYPR_BSPC RHYPR_T(KC_BSPC)
#define LSFT_SPC   SFT_T(KC_SPC)
#define LSFT_CW    SFT_T(CW_TOGG)
#define RSFT_SLSH  RSFT_T(KC_SLSH)
#define RSFT_BSLS  RSFT_T(KC_BSLS)
#define LCTL_ESC   CTL_T(KC_ESC)
#define RCTL_ENT   RCTL_T(KC_ENT)
#define RCTL_QUOT  RCTL_T(KC_QUOT)
#define RCTL_TAB   RCTL_T(KC_TAB)
#define RALT_GRV   RALT_T(KC_GRV)
#define LGUI_LNG2  GUI_T(KC_LNG2)
#define RGUI_LNG1  RGUI_T(KC_LNG1)

// Home Row Mods
#define LCTL_LBRC CTL_T(KC_LBRC)
#define LSFT_RBRC SFT_T(KC_RBRC)
#define LGUI_GRV  GUI_T(KC_GRV)

// }}}

// -- Wrappers {{{

#define __________________BASE_L1__________________ KC_Q, KC_W, KC_E,    KC_R,   KC_T
#define __________________BASE_L2__________________ KC_A, KC_S, KC_D,    KC_F,   KC_G
#define __________________BASE_L3__________________ KC_Z, KC_X, KC_C,    KC_V,   KC_B

#define __________________BASE_R1__________________ KC_Y, KC_U, KC_I,    KC_O,   KC_P
#define __________________BASE_R2__________________ KC_H, KC_J, KC_K,    KC_L,   KC_SCLN
#define __________________BASE_R3__________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

#define __________________NAV_L1___________________ LSG(KC_C), KC_LPRN,   KC_RPRN,   C(KC_TAB), LSG(KC_T)
#define __________________NAV_L2___________________ LSG(KC_A), LCTL_LBRC, LSFT_RBRC, LCG(KC_V), LCG(KC_S)
#define __________________NAV_L3___________________ LSG(KC_Z), G(KC_X),   G(KC_C),   LSG(KC_V), G(KC_V)

#define __________________NAV_R1___________________ G(KC_TAB), C(KC_TAB), KC_LCBR,   KC_RCBR,   G(KC_RBRC)
#define __________________NAV_R2___________________ KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   G(KC_LBRC)
#define __________________NAV_R3___________________ KC_BSPC,   KC_DEL,    C(KC_A),   C(KC_E),   XXXXXXX

#define __________________SYM_L1___________________ KC_DOT,  KC_PLUS, KC_UNDS, KC_EXLM, KC_PIPE
#define __________________SYM_L2___________________ KC_ASTR, KC_EQL,  KC_MINS, KC_0,    KC_AT
#define __________________SYM_L3___________________ KC_8,    KC_6,    KC_4,    KC_2,    KC_BSLS

#define __________________SYM_R1___________________ KC_TILD, KC_QUES, KC_CIRC, KC_DLR,  KC_COMM
#define __________________SYM_R2___________________ KC_AMPR, KC_1,    KC_PERC, KC_HASH, KC_COLN
#define __________________SYM_R3___________________ KC_GRV,  KC_3,    KC_5,    KC_7,    KC_9

#define __________________WIN_L1___________________ LCA(KC_U),    LCA(KC_I),   XXXXXXX,     MEH(KC_C),    C(KC_1)
#define __________________WIN_L2___________________ LCA(KC_LEFT), XXXXXXX,     XXXXXXX,     LCA(KC_RGHT), C(KC_2)
#define __________________WIN_L3___________________ LCA(KC_Z),    LCA(KC_X),   LCA(KC_V),   LCA(KC_B),    C(KC_3)

#define __________________WIN_R1___________________ C(KC_4),      MEH(KC_C),   A(KC_UP),    XXXXXXX,      XXXXXXX
#define __________________WIN_R2___________________ C(KC_5),      LCA(KC_C),   A(KC_DOWN),  XXXXXXX,      XXXXXXX
#define __________________WIN_R3___________________ C(KC_6),      LCA(KC_ENT), MEH(KC_ENT), XXXXXXX,      XXXXXXX

#define __________________FN_L1____________________ KC_F1,     KC_F2,   KC_F3,   KC_F4,   XXXXXXX
#define __________________FN_L2____________________ KC_F5,     KC_F6,   KC_F7,   KC_F8,   XXXXXXX
#define __________________FN_L3____________________ KC_F9,     KC_F10,  KC_F11,  KC_F12,  XXXXXXX

#define __________________FN_R1____________________ LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_R2____________________ LSG(KC_3), XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT
#define __________________FN_R3____________________ LSG(KC_4), XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU

#define __________________1_TO_5___________________ KC_1, KC_2, KC_3, KC_4, KC_5
#define __________________7_TO_MINS________________ KC_7, KC_8, KC_9, KC_0, KC_MINS

#define __________________F1_TO_F5_________________ KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5
#define __________________F7_TO_F11________________ KC_F7, KC_F8, KC_F9, KC_F10, KC_F11

#define __________________NONE_____________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __________________F1_TO_F4________ KC_F1, KC_F2,  KC_F3,  KC_F4
#define __________________F5_TO_F8________ KC_F5, KC_F6,  KC_F7,  KC_F8
#define __________________F9_TO_F12_______ KC_F9, KC_F10, KC_F11, KC_F12

// }}}

// -- Includes {{{

#ifdef MTGAP_ENABLE
  #include "mtgap.h"
#endif

#ifdef BUNA_ENABLE
  #include "buna.h"
#endif

#ifdef SHINGETA_ENABLE
  #include "shingeta.h"
#endif

#ifdef INVERTED_NUM_ENABLE
  #include "inverted_num.h"
#endif

// }}}
