// shingeta.c

#include "shingeta.h"

// -- Strings {{{

// Kana {{{
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

const char kana_kya[]  PROGMEM = "kya";
const char kana_kyu[]  PROGMEM = "kyu";
const char kana_kyo[]  PROGMEM = "kyo";

const char kana_sya[]  PROGMEM = "sya";
const char kana_syu[]  PROGMEM = "syu";
const char kana_syo[]  PROGMEM = "syo";

const char kana_tya[]  PROGMEM = "tya";
const char kana_tyu[]  PROGMEM = "tyu";
const char kana_tyo[]  PROGMEM = "tyo";

const char kana_nya[]  PROGMEM = "nya";
const char kana_nyu[]  PROGMEM = "nyu";
const char kana_nyo[]  PROGMEM = "nyo";

const char kana_hya[]  PROGMEM = "hya";
const char kana_hyu[]  PROGMEM = "hyu";
const char kana_hyo[]  PROGMEM = "hyo";

const char kana_mya[]  PROGMEM = "mya";
const char kana_myu[]  PROGMEM = "myu";
const char kana_myo[]  PROGMEM = "myo";

const char kana_rya[]  PROGMEM = "rya";
const char kana_ryu[]  PROGMEM = "ryu";
const char kana_ryo[]  PROGMEM = "ryo";

const char kana_gya[]  PROGMEM = "gya";
const char kana_gyu[]  PROGMEM = "gyu";
const char kana_gyo[]  PROGMEM = "gyo";

const char kana_zya[]  PROGMEM = "zya";
const char kana_zyu[]  PROGMEM = "zyu";
const char kana_zyo[]  PROGMEM = "zyo";

const char kana_dya[]  PROGMEM = "dya";
const char kana_dyu[]  PROGMEM = "dyu";
const char kana_dyo[]  PROGMEM = "dyo";

const char kana_bya[]  PROGMEM = "bya";
const char kana_byu[]  PROGMEM = "byu";
const char kana_byo[]  PROGMEM = "byo";

const char kana_pya[]  PROGMEM = "pya";
const char kana_pyu[]  PROGMEM = "pyu";
const char kana_pyo[]  PROGMEM = "pyo";

const char kana_wi[]   PROGMEM = "wi";
const char kana_we[]   PROGMEM = "we";
const char kana_who[]  PROGMEM = "who";

const char kana_fa[]   PROGMEM = "fa";
const char kana_fi[]   PROGMEM = "fi";
const char kana_fe[]   PROGMEM = "fe";
const char kana_fo[]   PROGMEM = "fo";

const char kana_sye[]  PROGMEM = "sye";
const char kana_zye[]  PROGMEM = "zye";

const char kana_tye[]  PROGMEM = "tye";

const char kana_thi[]  PROGMEM = "thi";
const char kana_dhi[]  PROGMEM = "dhi";

const char kana_twu[]  PROGMEM = "twu";
const char kana_dwu[]  PROGMEM = "dwu";

const char kana_vu[]   PROGMEM = "vu";

const char kana_xtu[]  PROGMEM = "xtu";
const char kana_xya[]  PROGMEM = "xya";
const char kana_xyu[]  PROGMEM = "xyu";
const char kana_xyo[]  PROGMEM = "xyo";
const char kana_xa[]   PROGMEM = "xa";
const char kana_xi[]   PROGMEM = "xi";
const char kana_xu[]   PROGMEM = "xu";
const char kana_xe[]   PROGMEM = "xe";
const char kana_xo[]   PROGMEM = "xo";
const char kana_xwa[]  PROGMEM = "xwa";
// }}}

// Symbols {{{
const char kana_scln[] PROGMEM = ";";
const char kana_coln[] PROGMEM = ":";
const char kana_quot[] PROGMEM = "'";
const char kana_dquo[] PROGMEM = "\"";
const char kana_comm[] PROGMEM = ",";
const char kana_dot[]  PROGMEM = ".";
const char kana_slsh[] PROGMEM = "/";
const char kana_ques[] PROGMEM = "?";
const char kana_exlm[] PROGMEM = "!";

const char kana_lbrc[] PROGMEM = "[";
const char kana_rbrc[] PROGMEM = "]";
const char kana_lprn[] PROGMEM = "(";
const char kana_rprn[] PROGMEM = ")";
const char kana_lcbr[] PROGMEM = "{";
const char kana_rcbr[] PROGMEM = "}";
// }}}

// Japanese Symbols {{{
const char jsym_y[]    PROGMEM = "\\y";
const char jsym_u[]    PROGMEM = "\\u";
const char jsym_i[]    PROGMEM = "\\i";
const char jsym_o[]    PROGMEM = "\\o";
const char jsym_p[]    PROGMEM = "\\p";
const char jsym_h[]    PROGMEM = "\\h";
const char jsym_j[]    PROGMEM = "\\j";
const char jsym_k[]    PROGMEM = "\\k";
const char jsym_l[]    PROGMEM = "\\l";
const char jsym_scln[] PROGMEM = "\\;";
const char jsym_quot[] PROGMEM = "\\'";
const char jsym_n[]    PROGMEM = "\\n";
const char jsym_m[]    PROGMEM = "\\m";
const char jsym_comm[] PROGMEM = "\\,";
const char jsym_dot[]  PROGMEM = "\\.";
const char jsym_slsh[] PROGMEM = "\\/";
// }}}

// }}}

// -- Functions {{{

bool process_shingeta_key(uint8_t qwerty_key,
                          const char *kana,
                          bool *registered,
                          keyrecord_t *record,
                          uint8_t mod_state) {
  if (record->event.pressed) {
    if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) {
      send_string_P(kana);
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

bool process_output_key(const char *kana,
                        keyrecord_t *record) {
  if (record->event.pressed) {
    send_string_P(kana);
    return false;
  }
  return false;
}

bool process_jsym_key(const char *symbol,
                      keyrecord_t *record) {
  if (record->event.pressed) {
    send_string_P(symbol);
    return false;
  }
  return false;
}

// }}}

// -- process_record_shingeta {{{

static bool key_registered[31];

bool process_record_shingeta(uint16_t keycode,
                             keyrecord_t *record,
                             uint8_t mod_state) {
  switch(keycode) {
    // 制御用キーコード {{{
    case IME_SG_ON:
      if (record->event.pressed) {
        tap_code(KC_LNG1);
        set_single_default_layer(_SHINGETA);
        return false;
      }
      return false;

    case IME_SG_OFF:
      if (record->event.pressed) {
        tap_code(KC_LNG2);
        set_single_default_layer(_BASE);
        return false;
      }
      return false;

    case EN_KATAKANA:
      if (record->event.pressed) {
        tap_code(KC_LNG1);
        tap_code16(RCS(KC_SCLN));
        return false;
      }
      return false;

    case JA_KATAKANA:
      if (record->event.pressed) {
        tap_code16(RCS(KC_SCLN));
        return false;
      }
      return false;

    case EN_BRCS_SPC:
      if (record->event.pressed) {
        SEND_STRING("[] ");
        return false;
      }
      return false;

    case JA_BRCS_SPC:
      if (record->event.pressed) {
        tap_code(KC_LNG2);
        SEND_STRING("[] ");
        tap_code(KC_LNG1);
        return false;
      }
      return false;
    // }}}
    // 配置用キーコード {{{
    case SG_A:    return process_shingeta_key(KC_A,    kana_no,   &key_registered[0],  record, mod_state);  // の
    case SG_B:    return process_shingeta_key(KC_B,    kana_tu,   &key_registered[1],  record, mod_state);  // つ
    case SG_C:    return process_shingeta_key(KC_C,    kana_ki,   &key_registered[2],  record, mod_state);  // き
    case SG_D:    return process_shingeta_key(KC_D,    kana_ka,   &key_registered[3],  record, mod_state);  // か
    case SG_E:    return process_shingeta_key(KC_E,    kana_ha,   &key_registered[4],  record, mod_state);  // は
    case SG_F:    return process_shingeta_key(KC_F,    kana_nn,   &key_registered[5],  record, mod_state);  // ん
    case SG_G:    return process_shingeta_key(KC_G,    kana_xtu,  &key_registered[6],  record, mod_state);  // っ
    case SG_H:    return process_shingeta_key(KC_H,    kana_ku,   &key_registered[7],  record, mod_state);  // く
    case SG_I:    return process_shingeta_key(KC_I,    kana_ko,   &key_registered[8],  record, mod_state);  // こ
    case SG_J:    return process_shingeta_key(KC_J,    kana_u,    &key_registered[9],  record, mod_state);  // う
    case SG_K:    return process_shingeta_key(KC_K,    kana_i,    &key_registered[10], record, mod_state);  // い
    case SG_L:    return process_shingeta_key(KC_L,    kana_si,   &key_registered[11], record, mod_state);  // し
    case SG_M:    return process_shingeta_key(KC_M,    kana_ta,   &key_registered[12], record, mod_state);  // た
    case SG_N:    return process_shingeta_key(KC_N,    kana_te,   &key_registered[13], record, mod_state);  // て
    case SG_O:    return process_shingeta_key(KC_O,    kana_ga,   &key_registered[14], record, mod_state);  // が
    case SG_P:    return process_shingeta_key(KC_P,    kana_hi,   &key_registered[15], record, mod_state);  // ひ
    case SG_Q:    return process_shingeta_key(KC_Q,    kana_quot, &key_registered[16], record, mod_state);  // ー
    case SG_R:    return process_shingeta_key(KC_R,    kana_comm, &key_registered[17], record, mod_state);  // 、
    case SG_S:    return process_shingeta_key(KC_S,    kana_to,   &key_registered[18], record, mod_state);  // と
    case SG_T:    return process_shingeta_key(KC_T,    kana_ti,   &key_registered[19], record, mod_state);  // ち
    case SG_U:    return process_shingeta_key(KC_U,    kana_ba,   &key_registered[20], record, mod_state);  // ば
    case SG_V:    return process_shingeta_key(KC_V,    kana_ru,   &key_registered[21], record, mod_state);  // る
    case SG_W:    return process_shingeta_key(KC_W,    kana_ni,   &key_registered[22], record, mod_state);  // に
    case SG_X:    return process_shingeta_key(KC_X,    kana_ma,   &key_registered[23], record, mod_state);  // ま
    case SG_Y:    return process_shingeta_key(KC_Y,    kana_gu,   &key_registered[24], record, mod_state);  // ぐ
    case SG_Z:    return process_shingeta_key(KC_Z,    kana_su,   &key_registered[25], record, mod_state);  // す
    case SG_SCLN: return process_shingeta_key(KC_SCLN, kana_na,   &key_registered[26], record, mod_state);  // な
    case SG_QUOT: return process_shingeta_key(KC_QUOT, kana_ge,   &key_registered[27], record, mod_state);  // げ
    case SG_COMM: return process_shingeta_key(KC_COMM, kana_de,   &key_registered[28], record, mod_state);  // で
    case SG_DOT:  return process_shingeta_key(KC_DOT,  kana_dot,  &key_registered[29], record, mod_state);  // 。
    case SG_SLSH: return process_shingeta_key(KC_SLSH, kana_bu,   &key_registered[30], record, mod_state);  // ぶ
    // }}}
    // 出力用キーコード {{{
    // 清音 {{{
    case OUT_A:  return process_output_key(kana_a,  record);  // あ
    case OUT_I:  return process_output_key(kana_i,  record);  // い
    case OUT_U:  return process_output_key(kana_u,  record);  // う
    case OUT_E:  return process_output_key(kana_e,  record);  // え
    case OUT_O:  return process_output_key(kana_o,  record);  // お
    case OUT_KA: return process_output_key(kana_ka, record);  // か
    case OUT_KI: return process_output_key(kana_ki, record);  // き
    case OUT_KU: return process_output_key(kana_ku, record);  // く
    case OUT_KE: return process_output_key(kana_ke, record);  // け
    case OUT_KO: return process_output_key(kana_ko, record);  // こ
    case OUT_SA: return process_output_key(kana_sa, record);  // さ
    case OUT_SI: return process_output_key(kana_si, record);  // し
    case OUT_SU: return process_output_key(kana_su, record);  // す
    case OUT_SE: return process_output_key(kana_se, record);  // せ
    case OUT_SO: return process_output_key(kana_so, record);  // そ
    case OUT_TA: return process_output_key(kana_ta, record);  // た
    case OUT_TI: return process_output_key(kana_ti, record);  // ち
    case OUT_TU: return process_output_key(kana_tu, record);  // つ
    case OUT_TE: return process_output_key(kana_te, record);  // て
    case OUT_TO: return process_output_key(kana_to, record);  // と
    case OUT_NA: return process_output_key(kana_na, record);  // な
    case OUT_NI: return process_output_key(kana_ni, record);  // に
    case OUT_NU: return process_output_key(kana_nu, record);  // ぬ
    case OUT_NE: return process_output_key(kana_ne, record);  // ね
    case OUT_NO: return process_output_key(kana_no, record);  // の
    case OUT_HA: return process_output_key(kana_ha, record);  // は
    case OUT_HI: return process_output_key(kana_hi, record);  // ひ
    case OUT_HU: return process_output_key(kana_hu, record);  // ふ
    case OUT_HE: return process_output_key(kana_he, record);  // へ
    case OUT_HO: return process_output_key(kana_ho, record);  // ほ
    case OUT_MA: return process_output_key(kana_ma, record);  // ま
    case OUT_MI: return process_output_key(kana_mi, record);  // み
    case OUT_MU: return process_output_key(kana_mu, record);  // む
    case OUT_ME: return process_output_key(kana_me, record);  // め
    case OUT_MO: return process_output_key(kana_mo, record);  // も
    case OUT_YA: return process_output_key(kana_ya, record);  // や
    case OUT_YU: return process_output_key(kana_yu, record);  // ゆ
    case OUT_YO: return process_output_key(kana_yo, record);  // よ
    case OUT_RA: return process_output_key(kana_ra, record);  // ら
    case OUT_RI: return process_output_key(kana_ri, record);  // り
    case OUT_RU: return process_output_key(kana_ru, record);  // る
    case OUT_RE: return process_output_key(kana_re, record);  // れ
    case OUT_RO: return process_output_key(kana_ro, record);  // ろ
    case OUT_WA: return process_output_key(kana_wa, record);  // わ
    case OUT_WO: return process_output_key(kana_wo, record);  // を
    case OUT_NN: return process_output_key(kana_nn, record);  // ん
    // }}}
    // 濁音・半濁音 {{{
    case OUT_GA: return process_output_key(kana_ga, record);  // が
    case OUT_GI: return process_output_key(kana_gi, record);  // ぎ
    case OUT_GU: return process_output_key(kana_gu, record);  // ぐ
    case OUT_GE: return process_output_key(kana_ge, record);  // げ
    case OUT_GO: return process_output_key(kana_go, record);  // ご
    case OUT_ZA: return process_output_key(kana_za, record);  // ざ
    case OUT_ZI: return process_output_key(kana_zi, record);  // じ
    case OUT_ZU: return process_output_key(kana_zu, record);  // ず
    case OUT_ZE: return process_output_key(kana_ze, record);  // ぜ
    case OUT_ZO: return process_output_key(kana_zo, record);  // ぞ
    case OUT_DA: return process_output_key(kana_da, record);  // だ
    case OUT_DI: return process_output_key(kana_di, record);  // ぢ
    case OUT_DU: return process_output_key(kana_du, record);  // づ
    case OUT_DE: return process_output_key(kana_de, record);  // で
    case OUT_DO: return process_output_key(kana_do, record);  // ど
    case OUT_BA: return process_output_key(kana_ba, record);  // ば
    case OUT_BI: return process_output_key(kana_bi, record);  // び
    case OUT_BU: return process_output_key(kana_bu, record);  // ぶ
    case OUT_BE: return process_output_key(kana_be, record);  // べ
    case OUT_BO: return process_output_key(kana_bo, record);  // ぼ
    case OUT_PA: return process_output_key(kana_pa, record);  // ぱ
    case OUT_PI: return process_output_key(kana_pi, record);  // ぴ
    case OUT_PU: return process_output_key(kana_pu, record);  // ぷ
    case OUT_PE: return process_output_key(kana_pe, record);  // ぺ
    case OUT_PO: return process_output_key(kana_po, record);  // ぽ
    // }}}
    // 拗音 {{{
    case OUT_KYA: return process_output_key(kana_kya, record);  // きゃ
    case OUT_KYU: return process_output_key(kana_kyu, record);  // きゅ
    case OUT_KYO: return process_output_key(kana_kyo, record);  // きょ
    case OUT_SYA: return process_output_key(kana_sya, record);  // しゃ
    case OUT_SYU: return process_output_key(kana_syu, record);  // しゅ
    case OUT_SYO: return process_output_key(kana_syo, record);  // しょ
    case OUT_TYA: return process_output_key(kana_tya, record);  // ちゃ
    case OUT_TYU: return process_output_key(kana_tyu, record);  // ちゅ
    case OUT_TYO: return process_output_key(kana_tyo, record);  // ちょ
    case OUT_NYA: return process_output_key(kana_nya, record);  // にゃ
    case OUT_NYU: return process_output_key(kana_nyu, record);  // にゅ
    case OUT_NYO: return process_output_key(kana_nyo, record);  // にょ
    case OUT_HYA: return process_output_key(kana_hya, record);  // ひゃ
    case OUT_HYU: return process_output_key(kana_hyu, record);  // ひゅ
    case OUT_HYO: return process_output_key(kana_hyo, record);  // ひょ
    case OUT_MYA: return process_output_key(kana_mya, record);  // みゃ
    case OUT_MYU: return process_output_key(kana_myu, record);  // みゅ
    case OUT_MYO: return process_output_key(kana_myo, record);  // みょ
    case OUT_RYA: return process_output_key(kana_rya, record);  // りゃ
    case OUT_RYU: return process_output_key(kana_ryu, record);  // りゅ
    case OUT_RYO: return process_output_key(kana_ryo, record);  // りょ
    case OUT_GYA: return process_output_key(kana_gya, record);  // ぎゃ
    case OUT_GYU: return process_output_key(kana_gyu, record);  // ぎゅ
    case OUT_GYO: return process_output_key(kana_gyo, record);  // ぎょ
    case OUT_ZYA: return process_output_key(kana_zya, record);  // じゃ
    case OUT_ZYU: return process_output_key(kana_zyu, record);  // じゅ
    case OUT_ZYO: return process_output_key(kana_zyo, record);  // じょ
    case OUT_DYA: return process_output_key(kana_dya, record);  // ぢゃ
    case OUT_DYU: return process_output_key(kana_dyu, record);  // ぢゅ
    case OUT_DYO: return process_output_key(kana_dyo, record);  // ぢょ
    case OUT_BYA: return process_output_key(kana_bya, record);  // びゃ
    case OUT_BYU: return process_output_key(kana_byu, record);  // びゅ
    case OUT_BYO: return process_output_key(kana_byo, record);  // びょ
    case OUT_PYA: return process_output_key(kana_pya, record);  // ぴゃ
    case OUT_PYU: return process_output_key(kana_pyu, record);  // ぴゅ
    case OUT_PYO: return process_output_key(kana_pyo, record);  // ぴょ
    // }}}
    // 外来音 {{{
    case OUT_WI:  return process_output_key(kana_wi,  record);  // うぃ
    case OUT_WE:  return process_output_key(kana_we,  record);  // うぇ
    case OUT_WHO: return process_output_key(kana_who, record);  // うぉ
    case OUT_FA:  return process_output_key(kana_fa,  record);  // ふぁ
    case OUT_FI:  return process_output_key(kana_fi,  record);  // ふぃ
    case OUT_FE:  return process_output_key(kana_fe,  record);  // ふぇ
    case OUT_FO:  return process_output_key(kana_fo,  record);  // ふぉ
    case OUT_SYE: return process_output_key(kana_sye, record);  // しぇ
    case OUT_ZYE: return process_output_key(kana_zye, record);  // じぇ
    case OUT_TYE: return process_output_key(kana_tye, record);  // ちぇ
    case OUT_THI: return process_output_key(kana_thi, record);  // てぃ
    case OUT_DHI: return process_output_key(kana_dhi, record);  // でぃ
    case OUT_TWU: return process_output_key(kana_twu, record);  // とぅ
    case OUT_DWU: return process_output_key(kana_dwu, record);  // どぅ
    case OUT_VU:  return process_output_key(kana_vu,  record);  // ヴ
    // }}}
    // 捨て仮名 {{{
    case OUT_XTU: return process_output_key(kana_xtu, record);  // っ
    case OUT_XYA: return process_output_key(kana_xya, record);  // ゃ
    case OUT_XYU: return process_output_key(kana_xyu, record);  // ゅ
    case OUT_XYO: return process_output_key(kana_xyo, record);  // ょ
    case OUT_XA:  return process_output_key(kana_xa,  record);  // ぁ
    case OUT_XI:  return process_output_key(kana_xi,  record);  // ぃ
    case OUT_XU:  return process_output_key(kana_xu,  record);  // ぅ
    case OUT_XE:  return process_output_key(kana_xe,  record);  // ぇ
    case OUT_XO:  return process_output_key(kana_xo,  record);  // ぉ
    case OUT_XWA: return process_output_key(kana_xwa, record);  // ゎ
    // }}}
    // 記号 {{{
    case OUT_COMM: return process_output_key(kana_comm, record);  // 、
    case OUT_DOT:  return process_output_key(kana_dot,  record);  // 。
    case OUT_LONG: return process_output_key(kana_quot, record);  // ー
    case OUT_MDOT: return process_output_key(kana_dquo, record);  // ・
    case OUT_SLSH: return process_output_key(kana_slsh, record);  // ／
    case OUT_EXLM: return process_output_key(kana_exlm, record);  // ！
    case OUT_QUES: return process_output_key(kana_ques, record);  // ？
    case OUT_SCLN: return process_output_key(kana_scln, record);  // ；
    case OUT_COLN: return process_output_key(kana_coln, record);  // ：
    // }}}
    // 括弧 {{{
    case OUT_LBRC: return process_output_key(kana_lbrc, record);  // 「
    case OUT_RBRC: return process_output_key(kana_rbrc, record);  // 」
    case OUT_LPRN: return process_output_key(kana_lprn, record);  // （
    case OUT_RPRN: return process_output_key(kana_rprn, record);  // ）
    case OUT_LCBR: return process_output_key(kana_lcbr, record);  // 『
    case OUT_RCBR: return process_output_key(kana_rcbr, record);  // 』

    case OUT_BRCS:
      if (record->event.pressed) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
        return false;
      }
      return false;

    case OUT_PRNS:
      if (record->event.pressed) {
        SEND_STRING("()" SS_TAP(X_LEFT));
        return false;
      }
      return false;

    case OUT_CBRS:
      if (record->event.pressed) {
        SEND_STRING("{}" SS_TAP(X_LEFT));
        return false;
      }
      return false;
    // }}}
    // }}}
    // Japanese Symbols {{{
    case JSYM_Y:    return process_jsym_key(jsym_y,    record);
    case JSYM_U:    return process_jsym_key(jsym_u,    record);
    case JSYM_I:    return process_jsym_key(jsym_i,    record);
    case JSYM_O:    return process_jsym_key(jsym_o,    record);
    case JSYM_P:    return process_jsym_key(jsym_p,    record);
    case JSYM_H:    return process_jsym_key(jsym_h,    record);
    case JSYM_J:    return process_jsym_key(jsym_j,    record);
    case JSYM_K:    return process_jsym_key(jsym_k,    record);
    case JSYM_L:    return process_jsym_key(jsym_l,    record);
    case JSYM_SCLN: return process_jsym_key(jsym_scln, record);
    case JSYM_QUOT: return process_jsym_key(jsym_quot, record);
    case JSYM_N:    return process_jsym_key(jsym_n,    record);
    case JSYM_M:    return process_jsym_key(jsym_m,    record);
    case JSYM_COMM: return process_jsym_key(jsym_comm, record);
    case JSYM_DOT:  return process_jsym_key(jsym_dot,  record);
    case JSYM_SLSH: return process_jsym_key(jsym_slsh, record);
    // }}}
    default:
      return true;
  }
}

// }}}
