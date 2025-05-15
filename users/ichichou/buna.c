// buna.c

#include "buna.h"

// kana_* {{{

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

bool process_buna_key(uint8_t qwerty_key,
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

static bool key_registered[93];

bool process_record_buna(uint16_t keycode,
                         keyrecord_t *record,
                         uint8_t mod_state) {
  switch(keycode) {
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
    default:
      return true;
  }
}
