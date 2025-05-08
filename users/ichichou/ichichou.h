// FILE: ichichou.h

#include QMK_KEYBOARD_H

// -- Macros {{{

// Layers
#define BASE  MO(_BASE)
#define MTGAP MO(_MTGAP)
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

// MTGAP
#define RCTL_MT_Q RCTL_T(MT_Q)

// }}}

// -- Layers {{{

enum layer_names {
  _BASE,
  _MTGAP,
  _NAV,
  _SYM,
  _WIN,
  _FN,
};

// }}}

// -- Custom Keycodes {{{

enum my_keycodes {
  SAMPLE = QK_USER,

  // MTGAP {{{
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
  // }}}

};

// }}}

// -- Prototypes {{{

// MTGAP
static bool process_mtgap_key(uint8_t mtgap_key,
                              uint8_t qwerty_key,
                              bool *mtgap_registered,
                              bool *qwerty_registered,
                              keyrecord_t *record,
                              uint8_t mod_state);

// }}}
