// Copyright 2024 ai03
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// -- Define Macros {{{

// Modifier Keycodes
#define RHYPR_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)
#define LCG(kc)     (QK_LCTL | QK_LGUI | (kc))
#define GUI_SFT     G(KC_LSFT)
#define GUI_SFT_GRV MT(MOD_RGUI | MOD_RSFT, KC_GRV)

// Layer-Tap
#define NAV_ESC  LT(_NAV, KC_ESC)
#define NAV_SLSH LT(_NAV, KC_SLSH)
#define SYM_TAB  LT(_SYM, KC_TAB)
#define SYM_ENT  LT(_SYM, KC_ENT)
#define FN_BSLS  LT(_FN,  KC_BSLS)
#define FN_GRV   LT(_FN,  KC_GRV)

// Mod-Tap
#define HYPR_TAB  RHYPR_T(KC_TAB)
#define HYPR_BSPC RHYPR_T(KC_BSPC)
#define SFT_SPC   SFT_T(KC_SPC)
#define SFT_CW    SFT_T(CW_TOGG)
#define RSFT_SLSH RSFT_T(KC_SLSH)
#define RSFT_BSLS RSFT_T(KC_BSLS)
#define CTL_ENT   CTL_T(KC_ENT)
#define CTL_ESC   CTL_T(KC_ESC)
#define RCTL_ENT  RCTL_T(KC_ENT)
#define RCTL_QUOT RCTL_T(KC_QUOT)
#define GUI_LNG2  GUI_T(KC_LNG2)
#define RGUI_LNG1 RGUI_T(KC_LNG1)
#define RGUI_GRV  RGUI_T(KC_GRV)

// Home Row Mods
#define SFT_RBRC  SFT_T(KC_RBRC)
#define CTL_LBRC  CTL_T(KC_LBRC)
#define ALT_LSG_A ALT_T(LSG(KC_A))

// }}}

// -- Layers {{{

enum layer_names {
  _BASE,
  _NAV,
  _SYM,
  _WIN,
  _FN,
};

// }}}

// -- Custom Keycodes {{{

// enum my_keycodes {
//   SAMPLE = QK_USER,
// };

// }}}

// -- Behavior of Any Keycode {{{

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // TAP:  Caps Word
    // HOLD: Shift
    case SFT_CW:
      if (record->tap.count && record->event.pressed) {
        caps_word_toggle();
        return false;
      }
      return true;

    // TAP:  Shift-Command-A
    // HOLD: Option
    case ALT_LSG_A:
      if (record->tap.count && record->event.pressed) {
        tap_code16(LSG(KC_A));
        return false;
      }
      return true;

    // Otherwise
    default:
      return true;

  }
  return true;
}

// }}}

// -- Tap-Hold Configuration {{{

// Hold On Other Key Press Mode
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // -- Layer Keys
    case NAV_ESC:
      return true;
    case SYM_TAB:
      return true;
    case SYM_ENT:
      return true;
    case FN_GRV:
      return true;

    // -- Mod Keys
    case HYPR_TAB:
      return true;
    case HYPR_BSPC:
      return true;
    case SFT_SPC:
      return true;
    case SFT_CW:
      return true;
    case RSFT_BSLS:
      return true;
    case CTL_ESC:
      return true;
    case CTL_ENT:
      return true;
    case RCTL_ENT:
      return true;
    case GUI_LNG2:
      return true;
    case RGUI_LNG1:
      return true;
    case RGUI_GRV:
      return true;
    case GUI_SFT_GRV:
      return true;

    // -- Home Row Mods
    case SFT_RBRC:
      return true;
    case CTL_LBRC:
      return true;
    case ALT_LSG_A:
      return true;

    // Otherwise
    default:
      return false;

  }
}

// Permissive Hold Mode
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NAV_SLSH:
      return true;
    case RSFT_SLSH:
      return true;
    case RCTL_QUOT:
      return true;
    default:
      return false;
  }
}

// }}}

// -- Combos {{{

enum combos {
  DF,
  JK,
  SD,
  KL,
  WE,
  IO,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
  [DF] = COMBO(df_combo, KC_LNG2),
  [JK] = COMBO(jk_combo, KC_LNG1),
  [SD] = COMBO(sd_combo, MO(_NAV)),
  [KL] = COMBO(kl_combo, MO(_NAV)),
  [WE] = COMBO(we_combo, LT(_WIN, KC_ESC)),
  [IO] = COMBO(io_combo, LT(_WIN, KC_TAB)),
};

// COMBO_TERM_PER_COMBO (Default: 50)
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
    case DF:
      return 20;
    case JK:
      return 20;
    case SD:
      return 20;
    case KL:
      return 20;
    case WE:
      return 20;
    case IO:
      return 20;
  }
  return COMBO_TERM;
}

// COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  switch (index) {
    case DF:
      return true;
    case JK:
      return true;
  }
  return false;
}

// COMBO_MUST_HOLD_PER_COMBO
bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  switch (index) {
    case SD:
      return true;
    case KL:
      return true;
  }
  return false;
}

// }}}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    HYPR_TAB,           KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,  KC_Y, KC_U, KC_I,    KC_O,   KC_P,      HYPR_BSPC, RCTL_QUOT,
    CTL_ESC,            KC_A, KC_S, KC_D, KC_F, KC_G, KC_RBRC,  KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,              RCTL_ENT,
    SFT_CW,   MO(_NAV), KC_Z, KC_X, KC_C, KC_V, KC_B, RGUI_GRV, KC_N, KC_M, KC_COMM, KC_DOT, NAV_SLSH,             FN_BSLS,
    MO(_FN),  XXXXXXX,  GUI_LNG2,         SFT_SPC,    NAV_ESC,        SYM_ENT,               RGUI_LNG1, XXXXXXX,   KC_RALT
  ),

  [_NAV] = LAYOUT(
    _______,          G(KC_Z),   KC_LPRN,  KC_RPRN,  MEH(KC_C), LSG(KC_T), XXXXXXX, G(KC_TAB), C(KC_TAB), KC_LCBR, KC_RCBR, G(KC_RBRC), G(KC_UP), G(KC_DOWN),
    _______,          ALT_LSG_A, CTL_LBRC, SFT_RBRC, LCG(KC_V), LCG(KC_S), XXXXXXX, KC_LEFT,   KC_DOWN,   KC_UP,   KC_RGHT, G(KC_LBRC),           XXXXXXX,
    _______, _______, LSG(KC_Z), G(KC_X),  G(KC_C),  LSG(KC_V), G(KC_V),   XXXXXXX, KC_BSPC,   KC_DEL,    C(KC_A), C(KC_E), XXXXXXX,              _______,
    _______, _______, _______,                       _______,              _______,            _______,                     _______,    _______,  _______
  ),

  [_SYM] = LAYOUT(
    _______,          KC_DOT,  KC_PLUS, KC_UNDS, KC_EXLM, KC_PIPE, KC_LPRN, KC_GRV,  KC_QUES, KC_CIRC, KC_DLR,  KC_COMM, XXXXXXX, KC_QUOT,
    _______,          KC_ASTR, KC_EQL,  KC_MINS, KC_0,    KC_AT,   KC_RPRN, KC_AMPR, KC_1,    KC_PERC, KC_HASH, KC_COLN,          XXXXXXX,
    _______, _______, KC_8,    KC_6,    KC_4,    KC_2,    KC_BSLS, XXXXXXX, KC_TILD, KC_3,    KC_5,    KC_7,    KC_9,             _______,
    _______, _______, _______,                   _______,          _______,          _______,                   _______, _______, _______
  ),

  [_WIN] = LAYOUT(
    XXXXXXX,          LCA(KC_U),    LCA(KC_I), XXXXXXX,   MEH(KC_C),    C(KC_1), XXXXXXX, C(KC_4), MEH(KC_C),   A(KC_UP),   XXXXXXX, XXXXXXX, LCA(KC_BSPC), XXXXXXX,
    XXXXXXX,          LCA(KC_LEFT), LCA(KC_D), LCA(KC_G), LCA(KC_RGHT), C(KC_2), XXXXXXX, C(KC_5), LCA(KC_C),   A(KC_DOWN), XXXXXXX, XXXXXXX,               MEH(KC_ENT),
    XXXXXXX, _______, LCA(KC_Z),    LCA(KC_X), LCA(KC_V), LCA(KC_B),    C(KC_3), XXXXXXX, C(KC_6), LCA(KC_ENT), XXXXXXX,    XXXXXXX, _______,               XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,               _______,          _______,                          XXXXXXX, XXXXXXX,      XXXXXXX
  ),

  [_FN] = LAYOUT(
    LCG(KC_Q),          KC_F1, KC_F2,  KC_F3,  KC_F4,  XXXXXXX, XXXXXXX, LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT,
    XXXXXXX,            KC_F5, KC_F6,  KC_F7,  KC_F8,  XXXXXXX, XXXXXXX, LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,          KC_MPLY,
    XXXXXXX,   XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
    _______,   XXXXXXX, XXXXXXX,               XXXXXXX,         QK_BOOT,            XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
  ),

};
