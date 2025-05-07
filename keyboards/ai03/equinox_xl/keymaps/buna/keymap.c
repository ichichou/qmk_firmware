// KB: Equinox XL
// KM: buna

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
#define BUNA2 OSL(_BUNA2)
#define BUNA3 OSL(_BUNA3)

// }}}

// -- Functions {{{

// MTGAP
static bool process_buna_key(uint8_t qwerty_key,
                             const char *kana,
                             bool *registered,
                             keyrecord_t *record,
                             uint8_t mod_state) {

  if (record->event.pressed) {
    if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) {
      if (kana != NULL) {
        send_string_P(kana);
      }
      return false;
    } else {
      register_code(qwerty_key);
      *registered = true;
      return false;
    }
  } else {
    if (*registered) {
      unregister_code(qwerty_key);
      *registered = false;
      return false;
    }
  }
  return false;
}

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

// -- kana_* {{{

const char kana_a[]    PROGMEM = "a";
const char kana_i[]    PROGMEM = "i";
const char kana_u[]    PROGMEM = "u";
const char kana_e[]    PROGMEM = "e";
const char kana_o[]    PROGMEM = "o";

const char kana_ka[]   PROGMEM = "ka";
const char kana_ki[]   PROGMEM = "ki";
const char kana_ku[]   PROGMEM = "ku";
const char kana_ke[]   PROGMEM = "ke";
const char kana_ko[]   PROGMEM = "ko";

const char kana_sa[]   PROGMEM = "sa";
const char kana_si[]   PROGMEM = "si";
const char kana_su[]   PROGMEM = "su";
const char kana_se[]   PROGMEM = "se";
const char kana_so[]   PROGMEM = "so";

const char kana_ta[]   PROGMEM = "ta";
const char kana_ti[]   PROGMEM = "ti";
const char kana_tu[]   PROGMEM = "tu";
const char kana_te[]   PROGMEM = "te";
const char kana_to[]   PROGMEM = "to";

const char kana_na[]   PROGMEM = "na";
const char kana_ni[]   PROGMEM = "ni";
const char kana_nu[]   PROGMEM = "nu";
const char kana_ne[]   PROGMEM = "ne";
const char kana_no[]   PROGMEM = "no";

const char kana_ha[]   PROGMEM = "ha";
const char kana_hi[]   PROGMEM = "hi";
const char kana_hu[]   PROGMEM = "hu";
const char kana_he[]   PROGMEM = "he";
const char kana_ho[]   PROGMEM = "ho";

const char kana_ma[]   PROGMEM = "ma";
const char kana_mi[]   PROGMEM = "mi";
const char kana_mu[]   PROGMEM = "mu";
const char kana_me[]   PROGMEM = "me";
const char kana_mo[]   PROGMEM = "mo";

const char kana_ya[]   PROGMEM = "ya";
const char kana_yu[]   PROGMEM = "yu";
const char kana_yo[]   PROGMEM = "yo";

const char kana_ra[]   PROGMEM = "ra";
const char kana_ri[]   PROGMEM = "ri";
const char kana_ru[]   PROGMEM = "ru";
const char kana_re[]   PROGMEM = "re";
const char kana_ro[]   PROGMEM = "ro";

const char kana_wa[]   PROGMEM = "wa";
const char kana_wo[]   PROGMEM = "wo";
const char kana_nn[]   PROGMEM = "nn";

const char kana_ga[]   PROGMEM = "ga";
const char kana_gi[]   PROGMEM = "gi";
const char kana_gu[]   PROGMEM = "gu";
const char kana_ge[]   PROGMEM = "ge";
const char kana_go[]   PROGMEM = "go";

const char kana_za[]   PROGMEM = "za";
const char kana_zi[]   PROGMEM = "zi";
const char kana_zu[]   PROGMEM = "zu";
const char kana_ze[]   PROGMEM = "ze";
const char kana_zo[]   PROGMEM = "zo";

const char kana_da[]   PROGMEM = "da";
const char kana_di[]   PROGMEM = "di";
const char kana_du[]   PROGMEM = "du";
const char kana_de[]   PROGMEM = "de";
const char kana_do[]   PROGMEM = "do";

const char kana_ba[]   PROGMEM = "ba";
const char kana_bi[]   PROGMEM = "bi";
const char kana_bu[]   PROGMEM = "bu";
const char kana_be[]   PROGMEM = "be";
const char kana_bo[]   PROGMEM = "bo";

const char kana_pa[]   PROGMEM = "pa";
const char kana_pi[]   PROGMEM = "pi";
const char kana_pu[]   PROGMEM = "pu";
const char kana_pe[]   PROGMEM = "pe";
const char kana_po[]   PROGMEM = "po";

const char kana_xtu[]  PROGMEM = "xtu";
const char kana_xya[]  PROGMEM = "xya";
const char kana_xyu[]  PROGMEM = "xyu";
const char kana_xyo[]  PROGMEM = "xyo";
const char kana_xa[]   PROGMEM = "xa";
const char kana_xi[]   PROGMEM = "xi";
const char kana_xu[]   PROGMEM = "xu";
const char kana_xe[]   PROGMEM = "xe";
const char kana_xo[]   PROGMEM = "xo";

const char kana_vu[]   PROGMEM = "vu";

const char kana_comm[] PROGMEM = ",";
const char kana_dot[]  PROGMEM = ".";
const char kana_slsh[] PROGMEM = "/";
const char kana_scln[] PROGMEM = ";";
const char kana_quot[] PROGMEM = "'";

// }}}

// -- process_record_user {{{

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t mod_state = get_mods();
  switch (keycode) {

    case SFT_T(CW_TOGG):
      if (record->tap.count && record->event.pressed) {
        caps_word_on();
        return false;
      }
      return true;

    // Buna Layout {{{

    static bool key_registered[93];

    // _BUNA1 {{{
    case BN1_A:    return process_buna_key(KC_A,    kana_de,   &key_registered[0],  record, mod_state);
    case BN1_B:    return process_buna_key(KC_B,    kana_xyo,  &key_registered[1],  record, mod_state);
    case BN1_C:    return process_buna_key(KC_C,    kana_ma,   &key_registered[2],  record, mod_state);
    // case BN1_D:    return process_buna_key(KC_D,    NULL,      &key_registered[3],  record, mod_state);
    case BN1_E:    return process_buna_key(KC_E,    kana_ha,   &key_registered[4],  record, mod_state);
    case BN1_F:    return process_buna_key(KC_F,    kana_na,   &key_registered[5],  record, mod_state);
    case BN1_G:    return process_buna_key(KC_G,    kana_ta,   &key_registered[6],  record, mod_state);
    case BN1_H:    return process_buna_key(KC_H,    kana_ku,   &key_registered[7],  record, mod_state);
    case BN1_I:    return process_buna_key(KC_I,    kana_si,   &key_registered[8],  record, mod_state);
    case BN1_J:    return process_buna_key(KC_J,    kana_nn,   &key_registered[9],  record, mod_state);
    // case BN1_K:    return process_buna_key(KC_K,    NULL,      &key_registered[10], record, mod_state);
    case BN1_L:    return process_buna_key(KC_L,    kana_i,    &key_registered[11], record, mod_state);
    case BN1_M:    return process_buna_key(KC_M,    kana_u,    &key_registered[12], record, mod_state);
    case BN1_N:    return process_buna_key(KC_N,    kana_ru,   &key_registered[13], record, mod_state);
    case BN1_O:    return process_buna_key(KC_O,    kana_no,   &key_registered[14], record, mod_state);
    case BN1_P:    return process_buna_key(KC_P,    kana_ki,   &key_registered[15], record, mod_state);
    case BN1_Q:    return process_buna_key(KC_Q,    kana_ko,   &key_registered[16], record, mod_state);
    case BN1_R:    return process_buna_key(KC_R,    kana_te,   &key_registered[17], record, mod_state);
    case BN1_S:    return process_buna_key(KC_S,    kana_ka,   &key_registered[18], record, mod_state);
    case BN1_T:    return process_buna_key(KC_T,    kana_mo,   &key_registered[19], record, mod_state);
    case BN1_U:    return process_buna_key(KC_U,    kana_xtu,  &key_registered[20], record, mod_state);
    case BN1_V:    return process_buna_key(KC_V,    kana_su,   &key_registered[21], record, mod_state);
    case BN1_W:    return process_buna_key(KC_W,    kana_ni,   &key_registered[22], record, mod_state);
    case BN1_X:    return process_buna_key(KC_X,    kana_ga,   &key_registered[23], record, mod_state);
    case BN1_Y:    return process_buna_key(KC_Y,    kana_ri,   &key_registered[24], record, mod_state);
    case BN1_Z:    return process_buna_key(KC_Z,    kana_da,   &key_registered[25], record, mod_state);
    case BN1_SCLN: return process_buna_key(KC_SCLN, kana_to,   &key_registered[26], record, mod_state);
    case BN1_QUOT: return process_buna_key(KC_QUOT, kana_quot, &key_registered[27], record, mod_state);
    case BN1_COMM: return process_buna_key(KC_COMM, kana_re,   &key_registered[28], record, mod_state);
    case BN1_DOT:  return process_buna_key(KC_DOT,  kana_ra,   &key_registered[29], record, mod_state);
    case BN1_SLSH: return process_buna_key(KC_SLSH, kana_dot,  &key_registered[30], record, mod_state);
    // }}}

    // _BUNA2 {{{
    case BN2_A:    return process_buna_key(KC_A,    kana_ba,   &key_registered[31], record, mod_state);
    case BN2_B:    return process_buna_key(KC_B,    kana_vu,   &key_registered[32], record, mod_state);
    case BN2_C:    return process_buna_key(KC_C,    NULL,      &key_registered[33], record, mod_state);
    case BN2_D:    return process_buna_key(KC_D,    kana_dot,  &key_registered[34], record, mod_state);
    case BN2_E:    return process_buna_key(KC_E,    kana_di,   &key_registered[35], record, mod_state);
    case BN2_F:    return process_buna_key(KC_F,    kana_xyu,  &key_registered[36], record, mod_state);
    case BN2_G:    return process_buna_key(KC_G,    kana_ze,   &key_registered[37], record, mod_state);
    case BN2_H:    return process_buna_key(KC_H,    kana_hi,   &key_registered[38], record, mod_state);
    case BN2_I:    return process_buna_key(KC_I,    kana_ge,   &key_registered[39], record, mod_state);
    case BN2_J:    return process_buna_key(KC_J,    kana_wo,   &key_registered[40], record, mod_state);
    case BN2_K:    return process_buna_key(KC_K,    kana_me,   &key_registered[41], record, mod_state);
    case BN2_L:    return process_buna_key(KC_L,    kana_quot, &key_registered[42], record, mod_state);
    case BN2_M:    return process_buna_key(KC_M,    kana_mu,   &key_registered[43], record, mod_state);
    case BN2_N:    return process_buna_key(KC_N,    kana_zu,   &key_registered[44], record, mod_state);
    case BN2_O:    return process_buna_key(KC_O,    kana_zi,   &key_registered[45], record, mod_state);
    case BN2_P:    return process_buna_key(KC_P,    kana_xya,  &key_registered[46], record, mod_state);
    case BN2_Q:    return process_buna_key(KC_Q,    kana_du,   &key_registered[47], record, mod_state);
    case BN2_R:    return process_buna_key(KC_R,    kana_pu,   &key_registered[48], record, mod_state);
    case BN2_S:    return process_buna_key(KC_S,    kana_sa,   &key_registered[49], record, mod_state);
    case BN2_T:    return process_buna_key(KC_T,    kana_xu,   &key_registered[50], record, mod_state);
    case BN2_U:    return process_buna_key(KC_U,    kana_pa,   &key_registered[51], record, mod_state);
    case BN2_V:    return process_buna_key(KC_V,    kana_yu,   &key_registered[52], record, mod_state);
    case BN2_W:    return process_buna_key(KC_W,    NULL,      &key_registered[53], record, mod_state);
    case BN2_X:    return process_buna_key(KC_X,    kana_zo,   &key_registered[54], record, mod_state);
    case BN2_Y:    return process_buna_key(KC_Y,    kana_nu,   &key_registered[55], record, mod_state);
    case BN2_Z:    return process_buna_key(KC_Z,    kana_pi,   &key_registered[56], record, mod_state);
    case BN2_SCLN: return process_buna_key(KC_SCLN, kana_bu,   &key_registered[57], record, mod_state);
    case BN2_QUOT: return process_buna_key(KC_QUOT, NULL,      &key_registered[58], record, mod_state);
    case BN2_COMM: return process_buna_key(KC_COMM, kana_gi,   &key_registered[59], record, mod_state);
    case BN2_DOT:  return process_buna_key(KC_DOT,  kana_gu,   &key_registered[60], record, mod_state);
    case BN2_SLSH: return process_buna_key(KC_SLSH, kana_po,   &key_registered[61], record, mod_state);
    // }}}

    // _BUNA3 {{{
    case BN3_A:    return process_buna_key(KC_A,    kana_wa,   &key_registered[62], record, mod_state);
    case BN3_B:    return process_buna_key(KC_B,    kana_yo,   &key_registered[63], record, mod_state);
    case BN3_C:    return process_buna_key(KC_C,    kana_go,   &key_registered[64], record, mod_state);
    case BN3_D:    return process_buna_key(KC_D,    kana_ke,   &key_registered[65], record, mod_state);
    case BN3_E:    return process_buna_key(KC_E,    kana_ho,   &key_registered[66], record, mod_state);
    case BN3_F:    return process_buna_key(KC_F,    kana_do,   &key_registered[67], record, mod_state);
    case BN3_G:    return process_buna_key(KC_G,    kana_a,    &key_registered[68], record, mod_state);
    case BN3_H:    return process_buna_key(KC_H,    kana_bi,   &key_registered[69], record, mod_state);
    case BN3_I:    return process_buna_key(KC_I,    kana_xe,   &key_registered[70], record, mod_state);
    case BN3_J:    return process_buna_key(KC_J,    kana_tu,   &key_registered[71], record, mod_state);
    case BN3_K:    return process_buna_key(KC_K,    kana_comm, &key_registered[72], record, mod_state);
    case BN3_L:    return process_buna_key(KC_L,    kana_o,    &key_registered[73], record, mod_state);
    case BN3_M:    return process_buna_key(KC_M,    kana_ti,   &key_registered[74], record, mod_state);
    case BN3_N:    return process_buna_key(KC_N,    kana_mi,   &key_registered[75], record, mod_state);
    case BN3_O:    return process_buna_key(KC_O,    kana_e,    &key_registered[76], record, mod_state);
    case BN3_P:    return process_buna_key(KC_P,    kana_ya,   &key_registered[77], record, mod_state);
    case BN3_Q:    return process_buna_key(KC_Q,    kana_be,   &key_registered[78], record, mod_state);
    case BN3_R:    return process_buna_key(KC_R,    kana_so,   &key_registered[79], record, mod_state);
    case BN3_S:    return process_buna_key(KC_S,    kana_se,   &key_registered[80], record, mod_state);
    case BN3_T:    return process_buna_key(KC_T,    kana_he,   &key_registered[81], record, mod_state);
    case BN3_U:    return process_buna_key(KC_U,    kana_pe,   &key_registered[82], record, mod_state);
    case BN3_V:    return process_buna_key(KC_V,    kana_ne,   &key_registered[83], record, mod_state);
    case BN3_W:    return process_buna_key(KC_W,    kana_bo,   &key_registered[84], record, mod_state);
    case BN3_X:    return process_buna_key(KC_X,    kana_za,   &key_registered[85], record, mod_state);
    case BN3_Y:    return process_buna_key(KC_Y,    NULL,      &key_registered[86], record, mod_state);
    case BN3_Z:    return process_buna_key(KC_Z,    kana_hu,   &key_registered[87], record, mod_state);
    case BN3_SCLN: return process_buna_key(KC_SCLN, kana_ro,   &key_registered[88], record, mod_state);
    case BN3_QUOT: return process_buna_key(KC_QUOT, NULL,      &key_registered[89], record, mod_state);
    case BN3_COMM: return process_buna_key(KC_COMM, kana_xo,   &key_registered[90], record, mod_state);
    case BN3_DOT:  return process_buna_key(KC_DOT,  kana_xi,   &key_registered[91], record, mod_state);
    case BN3_SLSH: return process_buna_key(KC_SLSH, kana_xa,   &key_registered[92], record, mod_state);
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
