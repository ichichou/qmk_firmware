// Copyright 2024 ai03
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// -- Define Macros {{{

// Modifier Keycodes
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
#define LSFT_CW    SFT_T(CW_TOGG)  // マクロではなくカスタムキーコードで実装してみる
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

    // [Tap] Caps Word, [Hold] Shift
    //
    // マクロの上書きではなくカスタムキーコードで実装してみる
    case LSFT_CW:
      if (record->tap.count && record->event.pressed) {
        caps_word_toggle();
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

// -- Key Overrides {{{

// Key Overrides は Karabiner との相性が悪いため、併用できない。
// 例えば QMK 側で LCmd-H -> Left とオーバーライドしたなら、Karabiner が干渉して LCmd-H -> LCmd-Left と出力されてしまう。
// これは Karabiner の Complex Modifications に何もルールを登録していなかったとしても同じである。
// 唯一の手段として、Key Overrides を使用したいキーボードを Karabiner の管理対象から外せば、Karabiner の干渉を免れることができる。
// （当然 Karabiner と Key Overrides の併用はできなくなる）

// const key_override_t lgui_h_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_H, KC_LEFT);
// const key_override_t lgui_j_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_J, KC_DOWN);
// const key_override_t lgui_k_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_K, KC_UP);
// const key_override_t lgui_l_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_L, KC_RGHT);
// const key_override_t *key_overrides[] = {
//   &lgui_h_override,
//   &lgui_j_override,
//   &lgui_k_override,
//   &lgui_l_override,
// };

// }}}

// -- Combos {{{

// コンボは Karabiner の同時押しと干渉するため、すべて Karabiner 側に担当させる。

// enum combos {
//   SD,
//   KL,
//   WE,
//   IO,
// };
//
// const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
// const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
//
// combo_t key_combos[] = {
//   [SD] = COMBO(sd_combo, MO(_NAV)),
//   [KL] = COMBO(kl_combo, MO(_NAV)),
//   [WE] = COMBO(we_combo, MO(_WIN)),
//   [IO] = COMBO(io_combo, MO(_WIN)),
// };

// }}}

// -- Combo Configuration {{{

// // COMBO_TERM_PER_COMBO (Default: 50)
// //
// // Karabiner 側の閾値が 50 ms の場合、COMBO_TERM は 20 ms 程度でないと、Karabiner での同時押し判定に支障が出る。
// // Karabiner 側の閾値が 70 ms なら、COMBO_TERM を 50 ms にしても実用に耐える。
// // 新下駄配列の同時押しに絡まないキーでのコンボなら関係ないと思われる。
// uint16_t get_combo_term(uint16_t index, combo_t *combo) {
//   switch (index) {
//     case SD: return 20;
//     case KL: return 20;
//     case WE: return 20;
//     case IO: return 20;
//   }
//   return COMBO_TERM;
// }
//
// // COMBO_MUST_TAP_PER_COMBO
// bool get_combo_must_tap(uint16_t index, combo_t *combo) {
//   switch (index) {
//   }
//   return false;
// }
//
// // COMBO_MUST_HOLD_PER_COMBO
// bool get_combo_must_hold(uint16_t index, combo_t *combo) {
//   switch (index) {
//     case SD: return true;
//     case KL: return true;
//     case WE: return true;
//     case IO: return true;
//   }
//   return false;
// }

// }}}

// -- Tap-Hold Configuration {{{

// 'Hold on other key press' と 'permissive hold' を併用するには、
// HOLD_ON_OTHER_KEY_PRESS_PER_KEY と PERMISSIVE_HOLD_PER_KEY を設定することが必要。
//
// HOLD_ON_OTHER_KEY_PRESS と PERMISSIVE_HOLD_PER_KEY の組み合わせはうまく動作しない。
// Tap-hold キーの基本動作を 'hold on other key press' としながら、
// 個別に指定したキーを 'permissive hold' とすることを意図しているが、
// 指定しても 'permissive hold' とはならず、すべて 'hold on other key press' になってしまう。

// Hold On Other Key Press Mode
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // -- Layer Keys
    case NAV_ESC: return true;
    case NAV_TAB: return true;
    case SYM_TAB: return true;
    case SYM_ENT: return true;
    case FN_BSLS: return true;
    case FN_GRV:  return true;

    // -- Mod Keys
    case RHYPR_TAB:  return true;
    case RHYPR_BSPC: return true;
    case LSFT_SPC:   return true;
    case LSFT_CW:    return true;
    case RSFT_SLSH:  return true;
    case RSFT_BSLS:  return true;
    case LCTL_ESC:   return true;
    case RCTL_ENT:   return true;
    case RCTL_QUOT:  return true;
    case RCTL_TAB:   return true;
    case RALT_GRV:   return true;
    case LGUI_LNG2:  return true;
    case RGUI_LNG1:  return true;

    // -- Home Row Mods
    case LCTL_LBRC: return true;
    case LSFT_RBRC: return true;
    case LGUI_GRV:  return true;

    // Otherwise
    default:
      return false;

  }
}

// Permissive Hold Mode
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Otherwise
    default:
      return false;

  }
}

// }}}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    RHYPR_TAB,           KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_Y, KC_U, KC_I,    KC_O,   KC_P,      KC_BSPC, KC_QUOT,
    LCTL_ESC,            KC_A, KC_S, KC_D, KC_F, KC_G, KC_RBRC, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,            RCTL_ENT,
    LSFT_CW,   MO(_NAV), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_GRV,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,            FN_BSLS,
    MO(_FN),   XXXXXXX,  LGUI_LNG2,        LSFT_SPC,   RCTL_TAB,      SYM_ENT,               RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

  [_NAV] = LAYOUT(
    _______,          LSG(KC_C), KC_LPRN,   KC_RPRN,   MEH(KC_C), LSG(KC_T), XXXXXXX, G(KC_TAB), C(KC_TAB), KC_LCBR, KC_RCBR, G(KC_RBRC), G(KC_UP), G(KC_DOWN),
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

  [_FN] = LAYOUT(
    LCG(KC_Q),          KC_F1, KC_F2,  KC_F3,  KC_F4,  XXXXXXX, XXXXXXX, LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT,
    XXXXXXX,            KC_F5, KC_F6,  KC_F7,  KC_F8,  XXXXXXX, XXXXXXX, LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,          KC_MPLY,
    XXXXXXX,   XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
    _______,   XXXXXXX, XXXXXXX,               EE_CLR,          QK_BOOT,            XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
  ),

};
