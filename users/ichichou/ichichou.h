// ichichou.h

#include QMK_KEYBOARD_H

// Layers {{{

enum layer_names {
  _BASE,
  _NAV,
  _SYM,
  _WIN,
  _FN,

  #ifdef MTGAP_ENABLE
    _MTGAP,
  #endif

  #ifdef BUNA_ENABLE
    _BUNA1,
    _BUNA2,
    _BUNA3
  #endif

};

// }}}

// Custom Keycodes {{{

enum my_keycodes {
  KC_SAMPLE = QK_USER,
};

// }}}

// Macros {{{

// Layers
#define BASE  MO(_BASE)
#define NAV   MO(_NAV)
#define SYM   MO(_SYM)
#define WIN   MO(_WIN)
#define FN    MO(_FN)

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

// Wrappers {{{

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

#define __________________SYM_R1___________________ KC_GRV,  KC_QUES, KC_CIRC, KC_DLR,  KC_COMM
#define __________________SYM_R2___________________ KC_AMPR, KC_1,    KC_PERC, KC_HASH, KC_COLN
#define __________________SYM_R3___________________ KC_TILD, KC_3,    KC_5,    KC_7,    KC_9

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

// }}}

// Includes {{{

#ifdef MTGAP_ENABLE
  #include "mtgap.h"
#endif

#ifdef BUNA_ENABLE
  #include "buna.h"
#endif

// }}}
