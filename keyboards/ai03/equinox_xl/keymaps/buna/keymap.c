// KB: Equinox XL
// KM: buna

// ぶな配列（v2.0 改変2）の実装テスト
// ベース面、シフト面はレイヤーとして実装
// シフトキーには OSL を使う
// Tap-dance は必要ないだろう

// 【ベース】
// こ に は て も　り っ し の き
// で か 　 な た　く ん 　 い と ー
// だ が ま す ょ　る う れ ら 。
//
// 【左シフト】
// づ 　 ぢ ぷ ぅ　ぬ ぱ げ じ ゃ
// ば さ 。 ゅ ぜ　ひ を め ー ぶ
// ぴ ぞ 　 ゆ ヴ　ず む ぎ ぐ ぽ
//
// 【右シフト】
// べ ぼ ほ そ へ　　 ぺ ぇ え や
// わ せ け ど あ　び つ 、 お ろ
// ふ ざ ご ね よ　み ち ぉ ぃ ぁ

// -- Copyright {{{

// Copyright 2024 ai03
// SPDX-License-Identifier: GPL-2.0-or-later

// }}}

// -- #include {{{

#include QMK_KEYBOARD_H

// }}}

// -- #define {{{

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

// Buna Layout

#define BUNA_KEYCODE(name, qwerty_key, buna_kana, qwerty_var) \
  case name: \
    { \
      static bool qwerty_var##_registered; \
      \
      if (record->event.pressed) { \
        if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) { \
          send_string_P(buna_kana); \
          return false; \
        } else { \
          register_code(qwerty_key); \
          qwerty_var##_registered = true; \
          return false; \
        } \
      } else { \
        if (qwerty_var##_registered) { \
          unregister_code(qwerty_key); \
          qwerty_var##_registered = false; \
          return false; \
        } \
      } \
      return false; \
    }

// static bool process_buna_key(uint16_t keycode, uint8_t qwerty_key, const char *kana, bool *registered, keyrecord_t *record) {
//   if (record->event.pressed) {
//     if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) {
//       send_string_P(kana);
//       return false;
//     } else {
//       register_code(qwerty_key);
//       *registered = true;
//       return false;
//     }
//   } else {
//     if (*registered) {
//       unregister_code(qwerty_key);
//       *registered = false;
//       return false;
//     }
//   }
//   return false;
// }

#define BUNA_UNDEFINED(name, qwerty_key, qwerty_var) \
  case name: \
    { \
      static bool qwerty_var##_registered; \
      \
      if (record->event.pressed) { \
        if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) { \
          return false; \
        } else { \
          register_code(qwerty_key); \
          qwerty_var##_registered = true; \
          return false; \
        } \
      } else { \
        if (qwerty_var##_registered) { \
          unregister_code(qwerty_key); \
          qwerty_var##_registered = false; \
          return false; \
        } \
      } \
      return false; \
    }

#define BUNA2 OSL(_BUNA2)
#define BUNA3 OSL(_BUNA3)

// }}}

// -- Layers {{{

enum layer_names {
  _BASE,
  _BUNA1,
  _BUNA2,
  _BUNA3,
  _NAV,
  _SYM,
  _FN,
};

// }}}

// -- Custom Keycodes {{{

enum my_keycodes {
  SAMPLE = QK_USER,

  // Buna Layout {{{

  // _BN1
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

  // _BN2
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

  // _BN3
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

};

// }}}

// -- buna_kana {{{

const char buna_a[]    PROGMEM = "a";
const char buna_i[]    PROGMEM = "i";
const char buna_u[]    PROGMEM = "u";
const char buna_e[]    PROGMEM = "e";
const char buna_o[]    PROGMEM = "o";

const char buna_ka[]   PROGMEM = "ka";
const char buna_ki[]   PROGMEM = "ki";
const char buna_ku[]   PROGMEM = "ku";
const char buna_ke[]   PROGMEM = "ke";
const char buna_ko[]   PROGMEM = "ko";

const char buna_sa[]   PROGMEM = "sa";
const char buna_si[]   PROGMEM = "si";
const char buna_su[]   PROGMEM = "su";
const char buna_se[]   PROGMEM = "se";
const char buna_so[]   PROGMEM = "so";

const char buna_ta[]   PROGMEM = "ta";
const char buna_ti[]   PROGMEM = "ti";
const char buna_tu[]   PROGMEM = "tu";
const char buna_te[]   PROGMEM = "te";
const char buna_to[]   PROGMEM = "to";

const char buna_na[]   PROGMEM = "na";
const char buna_ni[]   PROGMEM = "ni";
const char buna_nu[]   PROGMEM = "nu";
const char buna_ne[]   PROGMEM = "ne";
const char buna_no[]   PROGMEM = "no";

const char buna_ha[]   PROGMEM = "ha";
const char buna_hi[]   PROGMEM = "hi";
const char buna_hu[]   PROGMEM = "hu";
const char buna_he[]   PROGMEM = "he";
const char buna_ho[]   PROGMEM = "ho";

const char buna_ma[]   PROGMEM = "ma";
const char buna_mi[]   PROGMEM = "mi";
const char buna_mu[]   PROGMEM = "mu";
const char buna_me[]   PROGMEM = "me";
const char buna_mo[]   PROGMEM = "mo";

const char buna_ya[]   PROGMEM = "ya";
const char buna_yu[]   PROGMEM = "yu";
const char buna_yo[]   PROGMEM = "yo";

const char buna_ra[]   PROGMEM = "ra";
const char buna_ri[]   PROGMEM = "ri";
const char buna_ru[]   PROGMEM = "ru";
const char buna_re[]   PROGMEM = "re";
const char buna_ro[]   PROGMEM = "ro";

const char buna_wa[]   PROGMEM = "wa";
const char buna_wo[]   PROGMEM = "wo";
const char buna_nn[]   PROGMEM = "nn";

const char buna_ga[]   PROGMEM = "ga";
const char buna_gi[]   PROGMEM = "gi";
const char buna_gu[]   PROGMEM = "gu";
const char buna_ge[]   PROGMEM = "ge";
const char buna_go[]   PROGMEM = "go";

const char buna_za[]   PROGMEM = "za";
const char buna_zi[]   PROGMEM = "zi";
const char buna_zu[]   PROGMEM = "zu";
const char buna_ze[]   PROGMEM = "ze";
const char buna_zo[]   PROGMEM = "zo";

const char buna_da[]   PROGMEM = "da";
const char buna_di[]   PROGMEM = "di";
const char buna_du[]   PROGMEM = "du";
const char buna_de[]   PROGMEM = "de";
const char buna_do[]   PROGMEM = "do";

const char buna_ba[]   PROGMEM = "ba";
const char buna_bi[]   PROGMEM = "bi";
const char buna_bu[]   PROGMEM = "bu";
const char buna_be[]   PROGMEM = "be";
const char buna_bo[]   PROGMEM = "bo";

const char buna_pa[]   PROGMEM = "pa";
const char buna_pi[]   PROGMEM = "pi";
const char buna_pu[]   PROGMEM = "pu";
const char buna_pe[]   PROGMEM = "pe";
const char buna_po[]   PROGMEM = "po";

const char buna_xtu[]  PROGMEM = "xtu";
const char buna_xya[]  PROGMEM = "xya";
const char buna_xyu[]  PROGMEM = "xyu";
const char buna_xyo[]  PROGMEM = "xyo";
const char buna_xa[]   PROGMEM = "xa";
const char buna_xi[]   PROGMEM = "xi";
const char buna_xu[]   PROGMEM = "xu";
const char buna_xe[]   PROGMEM = "xe";
const char buna_xo[]   PROGMEM = "xo";

const char buna_vu[]   PROGMEM = "vu";

const char buna_comm[] PROGMEM = ",";
const char buna_dot[]  PROGMEM = ".";
const char buna_slsh[] PROGMEM = "/";
const char buna_scln[] PROGMEM = ";";
const char buna_quot[] PROGMEM = "'";

// }}}

// -- process_record_user {{{

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  switch (keycode) {

    case SFT_T(CW_TOGG):
      if (record->tap.count && record->event.pressed) {
        caps_word_on();
        return false;
      }
      return true;

    // Buna Layout {{{

    // _BUNA1 {{{
    BUNA_KEYCODE(BN1_A,    KC_A,    buna_de,   akey)
    BUNA_KEYCODE(BN1_B,    KC_B,    buna_xyo,  bkey)
    BUNA_KEYCODE(BN1_C,    KC_C,    buna_ma,   ckey)
    // BUNA_KEYCODE(BN1_D,    KC_D,    buna_,     dkey)
    BUNA_KEYCODE(BN1_E,    KC_E,    buna_ha,   ekey)
    BUNA_KEYCODE(BN1_F,    KC_F,    buna_na,   fkey)
    BUNA_KEYCODE(BN1_G,    KC_G,    buna_ta,   gkey)
    BUNA_KEYCODE(BN1_H,    KC_H,    buna_ku,   hkey)
    BUNA_KEYCODE(BN1_I,    KC_I,    buna_si,   ikey)
    BUNA_KEYCODE(BN1_J,    KC_J,    buna_nn,   jkey)
    // BUNA_KEYCODE(BN1_K,    KC_K,    buna_,     kkey)
    BUNA_KEYCODE(BN1_L,    KC_L,    buna_i,    lkey)
    BUNA_KEYCODE(BN1_M,    KC_M,    buna_u,    mkey)
    BUNA_KEYCODE(BN1_N,    KC_N,    buna_ru,   nkey)
    BUNA_KEYCODE(BN1_O,    KC_O,    buna_no,   okey)
    BUNA_KEYCODE(BN1_P,    KC_P,    buna_ki,   pkey)
    BUNA_KEYCODE(BN1_Q,    KC_Q,    buna_ko,   qkey)
    BUNA_KEYCODE(BN1_R,    KC_R,    buna_te,   rkey)
    BUNA_KEYCODE(BN1_S,    KC_S,    buna_ka,   skey)
    BUNA_KEYCODE(BN1_T,    KC_T,    buna_mo,   tkey)
    BUNA_KEYCODE(BN1_U,    KC_U,    buna_xtu,  ukey)
    BUNA_KEYCODE(BN1_V,    KC_V,    buna_su,   vkey)
    BUNA_KEYCODE(BN1_W,    KC_W,    buna_ni,   wkey)
    BUNA_KEYCODE(BN1_X,    KC_X,    buna_ga,   xkey)
    BUNA_KEYCODE(BN1_Y,    KC_Y,    buna_ri,   ykey)
    BUNA_KEYCODE(BN1_Z,    KC_Z,    buna_da,   zkey)
    BUNA_KEYCODE(BN1_SCLN, KC_SCLN, buna_to,   sclnkey)
    BUNA_KEYCODE(BN1_QUOT, KC_QUOT, buna_quot, quotkey)
    BUNA_KEYCODE(BN1_COMM, KC_COMM, buna_re,   commkey)
    BUNA_KEYCODE(BN1_DOT,  KC_DOT,  buna_ra,   dotkey)
    BUNA_KEYCODE(BN1_SLSH, KC_SLSH, buna_dot,  slshkey)
    // }}}

    // _BUNA2 {{{
    BUNA_KEYCODE(BN2_A,    KC_A,    buna_ba,   akey)
    BUNA_KEYCODE(BN2_B,    KC_B,    buna_vu,   bkey)
    // BUNA_KEYCODE(BN2_C,    KC_C,    buna_,     ckey)  // 動作を要検証
    BUNA_KEYCODE(BN2_D,    KC_D,    buna_dot,  dkey)
    BUNA_KEYCODE(BN2_E,    KC_E,    buna_di,   ekey)
    BUNA_KEYCODE(BN2_F,    KC_F,    buna_xyu,  fkey)
    BUNA_KEYCODE(BN2_G,    KC_G,    buna_ze,   gkey)
    BUNA_KEYCODE(BN2_H,    KC_H,    buna_hi,   hkey)
    BUNA_KEYCODE(BN2_I,    KC_I,    buna_ge,   ikey)
    BUNA_KEYCODE(BN2_J,    KC_J,    buna_wo,   jkey)
    BUNA_KEYCODE(BN2_K,    KC_K,    buna_me,   kkey)
    BUNA_KEYCODE(BN2_L,    KC_L,    buna_quot, lkey)
    BUNA_KEYCODE(BN2_M,    KC_M,    buna_mu,   mkey)
    BUNA_KEYCODE(BN2_N,    KC_N,    buna_zu,   nkey)
    BUNA_KEYCODE(BN2_O,    KC_O,    buna_zi,   okey)
    BUNA_KEYCODE(BN2_P,    KC_P,    buna_xya,  pkey)
    BUNA_KEYCODE(BN2_Q,    KC_Q,    buna_du,   qkey)
    BUNA_KEYCODE(BN2_R,    KC_R,    buna_pu,   rkey)
    BUNA_KEYCODE(BN2_S,    KC_S,    buna_sa,   skey)
    BUNA_KEYCODE(BN2_T,    KC_T,    buna_xu,   tkey)
    BUNA_KEYCODE(BN2_U,    KC_U,    buna_pa,   ukey)
    BUNA_KEYCODE(BN2_V,    KC_V,    buna_yu,   vkey)
    // BUNA_KEYCODE(BN2_W,    KC_W,    buna_,     wkey)  // 動作を要検証
    BUNA_KEYCODE(BN2_X,    KC_X,    buna_zo,   xkey)
    BUNA_KEYCODE(BN2_Y,    KC_Y,    buna_nu,   ykey)
    BUNA_KEYCODE(BN2_Z,    KC_Z,    buna_pi,   zkey)
    BUNA_KEYCODE(BN2_SCLN, KC_SCLN, buna_bu,   sclnkey)
    // BUNA_KEYCODE(BN2_QUOT, KC_QUOT, buna_,     quotkey)  // 動作を要検証
    BUNA_KEYCODE(BN2_COMM, KC_COMM, buna_gi,   commkey)
    BUNA_KEYCODE(BN2_DOT,  KC_DOT,  buna_gu,   dotkey)
    BUNA_KEYCODE(BN2_SLSH, KC_SLSH, buna_po,   slshkey)

    // BUNA_UNDEFINED(BN2_C,    KC_C,    ckey)
    // BUNA_UNDEFINED(BN2_W,    KC_W,    wkey)
    // BUNA_UNDEFINED(BN2_QUOT, KC_QUOT, quotkey)
    // }}}

    // _BUNA3 {{{
    BUNA_KEYCODE(BN3_A,    KC_A,    buna_wa,   akey)
    BUNA_KEYCODE(BN3_B,    KC_B,    buna_yo,   bkey)
    BUNA_KEYCODE(BN3_C,    KC_C,    buna_go,   ckey)
    BUNA_KEYCODE(BN3_D,    KC_D,    buna_ke,   dkey)
    BUNA_KEYCODE(BN3_E,    KC_E,    buna_ho,   ekey)
    BUNA_KEYCODE(BN3_F,    KC_F,    buna_do,   fkey)
    BUNA_KEYCODE(BN3_G,    KC_G,    buna_a,    gkey)
    BUNA_KEYCODE(BN3_H,    KC_H,    buna_bi,   hkey)
    BUNA_KEYCODE(BN3_I,    KC_I,    buna_xe,   ikey)
    BUNA_KEYCODE(BN3_J,    KC_J,    buna_tu,   jkey)
    BUNA_KEYCODE(BN3_K,    KC_K,    buna_comm, kkey)
    BUNA_KEYCODE(BN3_L,    KC_L,    buna_o,    lkey)
    BUNA_KEYCODE(BN3_M,    KC_M,    buna_ti,   mkey)
    BUNA_KEYCODE(BN3_N,    KC_N,    buna_mi,   nkey)
    BUNA_KEYCODE(BN3_O,    KC_O,    buna_e,    okey)
    BUNA_KEYCODE(BN3_P,    KC_P,    buna_ya,   pkey)
    BUNA_KEYCODE(BN3_Q,    KC_Q,    buna_be,   qkey)
    BUNA_KEYCODE(BN3_R,    KC_R,    buna_so,   rkey)
    BUNA_KEYCODE(BN3_S,    KC_S,    buna_se,   skey)
    BUNA_KEYCODE(BN3_T,    KC_T,    buna_he,   tkey)
    BUNA_KEYCODE(BN3_U,    KC_U,    buna_pe,   ukey)
    BUNA_KEYCODE(BN3_V,    KC_V,    buna_ne,   vkey)
    BUNA_KEYCODE(BN3_W,    KC_W,    buna_bo,   wkey)
    BUNA_KEYCODE(BN3_X,    KC_X,    buna_za,   xkey)
    // BUNA_KEYCODE(BN3_Y,    KC_Y,    buna_,     ykey)  // 動作を要検証
    BUNA_KEYCODE(BN3_Z,    KC_Z,    buna_hu,   zkey)
    BUNA_KEYCODE(BN3_SCLN, KC_SCLN, buna_ro,   sclnkey)
    // BUNA_KEYCODE(BN3_QUOT, KC_QUOT, buna_,     quotkey)  // 動作を要検証
    BUNA_KEYCODE(BN3_COMM, KC_COMM, buna_xo,   commkey)
    BUNA_KEYCODE(BN3_DOT,  KC_DOT,  buna_xi,   dotkey)
    BUNA_KEYCODE(BN3_SLSH, KC_SLSH, buna_xa,   slshkey)

    // BUNA_UNDEFINED(BN3_Y,    KC_Y,    ykey)
    // BUNA_UNDEFINED(BN3_QUOT, KC_QUOT, quotkey)
    // }}}

    // }}}

    // Otherwise
    default:
      return true;

  }
}

// }}}

// -- Tap-Hold Configuration {{{

// 'Hold on other key press' と 'permissive hold' を併用するには、
// HOLD_ON_OTHER_KEY_PRESS_PER_KEY と PERMISSIVE_HOLD_PER_KEY の組み合わせが必要。
//
// HOLD_ON_OTHER_KEY_PRESS と PERMISSIVE_HOLD_PER_KEY の組み合わせはうまく動作しない。
// Tap-hold キーの基本動作を 'hold on other key press' としながら、
// 個別に指定したキーの動作を 'permissive hold' とすることを意図しているが、
// そのように指定しても 'permissive hold' とはならず、すべて 'hold on other key press' になってしまう。
// 'hold on other key press' と 'permissive hold' の両方が設定されていると、'hold on...' が優先されるのだろう。

// Hold On Other Key Press Mode
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Layer-Tap
    case NAV_ESC: return true;
    case NAV_TAB: return true;
    case SYM_TAB: return true;
    case SYM_ENT: return true;
    case FN_BSLS: return true;
    case FN_GRV:  return true;

    // Mod-Tap
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

    // Home Row Mods
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

// -- Keymaps {{{

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    RHYPR_TAB,           KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_Y, KC_U, KC_I,    KC_O,   KC_P,      KC_BSPC, KC_QUOT,
    LCTL_ESC,            KC_A, KC_S, KC_D, KC_F, KC_G, KC_RBRC, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,            RCTL_ENT,
    LSFT_CW,   MO(_NAV), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_GRV,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,            FN_BSLS,
    MO(_FN),   XXXXXXX,  LGUI_LNG2,        LSFT_SPC,   RCTL_TAB,      SYM_ENT,               RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

  [_BUNA1] = LAYOUT(
    RHYPR_TAB,           BN1_Q, BN1_W, BN1_E, BN1_R, BN1_T, KC_LBRC, BN1_Y, BN1_U, BN1_I,    BN1_O,   BN1_P,     KC_BSPC, BN1_QUOT,
    LCTL_ESC,            BN1_A, BN1_S, BUNA2, BN1_F, BN1_G, KC_RBRC, BN1_H, BN1_J, BUNA3,    BN1_L,   BN1_SCLN,           RCTL_ENT,
    LSFT_CW,   MO(_NAV), BN1_Z, BN1_X, BN1_C, BN1_V, BN1_B, KC_GRV,  BN1_N, BN1_M, BN1_COMM, BN1_DOT, BN1_SLSH,           FN_BSLS,
    MO(_FN),   XXXXXXX,  LGUI_LNG2,           LSFT_SPC,     RCTL_TAB,       SYM_ENT,                  RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

  [_BUNA2] = LAYOUT(
    RHYPR_TAB,           BN2_Q, BN2_W, BN2_E, BN2_R, BN2_T, KC_LBRC, BN2_Y, BN2_U, BN2_I,    BN2_O,   BN2_P,     KC_BSPC, BN2_QUOT,
    LCTL_ESC,            BN2_A, BN2_S, BN2_D, BN2_F, BN2_G, KC_RBRC, BN2_H, BN2_J, BN2_K,    BN2_L,   BN2_SCLN,           RCTL_ENT,
    LSFT_CW,   MO(_NAV), BN2_Z, BN2_X, BN2_C, BN2_V, BN2_B, KC_GRV,  BN2_N, BN2_M, BN2_COMM, BN2_DOT, BN2_SLSH,           FN_BSLS,
    MO(_FN),   XXXXXXX,  LGUI_LNG2,           LSFT_SPC,     RCTL_TAB,       SYM_ENT,                  RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

  [_BUNA3] = LAYOUT(
    RHYPR_TAB,           BN3_Q, BN3_W, BN3_E, BN3_R, BN3_T, KC_LBRC, BN3_Y, BN3_U, BN3_I,    BN3_O,   BN3_P,     KC_BSPC, BN3_QUOT,
    LCTL_ESC,            BN3_A, BN3_S, BN3_D, BN3_F, BN3_G, KC_RBRC, BN3_H, BN3_J, BN3_K,    BN3_L,   BN3_SCLN,           RCTL_ENT,
    LSFT_CW,   MO(_NAV), BN3_Z, BN3_X, BN3_C, BN3_V, BN3_B, KC_GRV,  BN3_N, BN3_M, BN3_COMM, BN3_DOT, BN3_SLSH,           FN_BSLS,
    MO(_FN),   XXXXXXX,  LGUI_LNG2,           LSFT_SPC,     RCTL_TAB,       SYM_ENT,                  RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

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

  [_FN] = LAYOUT(
    LCG(KC_Q),          KC_F1, KC_F2,  KC_F3,  KC_F4,  XXXXXXX, DF(_BASE),  LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT,
    XXXXXXX,            KC_F5, KC_F6,  KC_F7,  KC_F8,  XXXXXXX, DF(_BUNA1), LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,          KC_MPLY,
    XXXXXXX,   XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX,    LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
    _______,   XXXXXXX, XXXXXXX,               EE_CLR,          QK_BOOT,               XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
  ),

};

// }}}
