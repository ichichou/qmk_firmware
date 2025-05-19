// shingeta.c

#include "shingeta.h"

// -- Kana {{{

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

const char kana_kya[]   PROGMEM = "kya";
const char kana_kyu[]   PROGMEM = "kyu";
const char kana_kyo[]   PROGMEM = "kyo";

const char kana_sya[]   PROGMEM = "sya";
const char kana_syu[]   PROGMEM = "syu";
const char kana_syo[]   PROGMEM = "syo";

const char kana_tya[]   PROGMEM = "tya";
const char kana_tyu[]   PROGMEM = "tyu";
const char kana_tyo[]   PROGMEM = "tyo";

const char kana_nya[]   PROGMEM = "nya";
const char kana_nyu[]   PROGMEM = "nyu";
const char kana_nyo[]   PROGMEM = "nyo";

const char kana_hya[]   PROGMEM = "hya";
const char kana_hyu[]   PROGMEM = "hyu";
const char kana_hyo[]   PROGMEM = "hyo";

const char kana_mya[]   PROGMEM = "mya";
const char kana_myu[]   PROGMEM = "myu";
const char kana_myo[]   PROGMEM = "myo";

const char kana_rya[]   PROGMEM = "rya";
const char kana_ryu[]   PROGMEM = "ryu";
const char kana_ryo[]   PROGMEM = "ryo";

const char kana_gya[]   PROGMEM = "gya";
const char kana_gyu[]   PROGMEM = "gyu";
const char kana_gyo[]   PROGMEM = "gyo";

const char kana_zya[]   PROGMEM = "zya";
const char kana_zyu[]   PROGMEM = "zyu";
const char kana_zyo[]   PROGMEM = "zyo";

const char kana_dya[]   PROGMEM = "dya";
const char kana_dyu[]   PROGMEM = "dyu";
const char kana_dyo[]   PROGMEM = "dyo";

const char kana_bya[]   PROGMEM = "bya";
const char kana_byu[]   PROGMEM = "byu";
const char kana_byo[]   PROGMEM = "byo";

const char kana_pya[]   PROGMEM = "pya";
const char kana_pyu[]   PROGMEM = "pyu";
const char kana_pyo[]   PROGMEM = "pyo";

const char kana_wi[]   PROGMEM = "wi";
const char kana_we[]   PROGMEM = "we";
const char kana_who[]  PROGMEM = "who";

const char kana_fa[]   PROGMEM = "fa";
const char kana_fi[]   PROGMEM = "fi";
const char kana_fe[]   PROGMEM = "fe";
const char kana_fo[]   PROGMEM = "fo";

const char kana_sye[]   PROGMEM = "sye";
const char kana_zye[]   PROGMEM = "zye";

const char kana_tye[]   PROGMEM = "tye";

const char kana_thi[]   PROGMEM = "thi";
const char kana_dhi[]   PROGMEM = "dhi";

const char kana_twu[]   PROGMEM = "twu";
const char kana_dwu[]   PROGMEM = "dwu";

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

const char kana_comm[] PROGMEM = ",";
const char kana_dot[]  PROGMEM = ".";
const char kana_slsh[] PROGMEM = "/";
const char kana_scln[] PROGMEM = ";";
const char kana_coln[] PROGMEM = ":";
const char kana_quot[] PROGMEM = "'";
const char kana_dquo[] PROGMEM = "\""
const char kana_exlm[] PROGMEM = "!"
const char kana_ques[] PROGMEM = "?"

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
                        keyrecord_t *record,
                        uint8_t mod_state) {
  if (record->event.pressed) {
    send_string_P(kana);
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
    case SG_ON:
      if (record->event.pressed) {
        tap_code(KC_LNG1);
        set_single_default_layer(_SHINGETA);
        return false;
      }
      return false;

    case SG_OFF:
      if (record->event.pressed) {
        tap_code(KC_LNG2);
        set_single_default_layer(_BASE);
        return false;
      }
      return false;
    // }}}
    // 配置用キーコード {{{
    case SG_A:    return process_shingeta_key(KC_A,    kana_no,   &key_registerd[0],  record, mod_state);  // の
    case SG_B:    return process_shingeta_key(KC_B,    kana_tu,   &key_registerd[1],  record, mod_state);  // つ
    case SG_C:    return process_shingeta_key(KC_C,    kana_ki,   &key_registerd[2],  record, mod_state);  // き
    case SG_D:    return process_shingeta_key(KC_D,    kana_ka,   &key_registerd[3],  record, mod_state);  // か
    case SG_E:    return process_shingeta_key(KC_E,    kana_ha,   &key_registerd[4],  record, mod_state);  // は
    case SG_F:    return process_shingeta_key(KC_F,    kana_nn,   &key_registerd[5],  record, mod_state);  // ん
    case SG_G:    return process_shingeta_key(KC_G,    kana_xtu,  &key_registerd[6],  record, mod_state);  // っ
    case SG_H:    return process_shingeta_key(KC_H,    kana_ku,   &key_registerd[7],  record, mod_state);  // く
    case SG_I:    return process_shingeta_key(KC_I,    kana_ko,   &key_registerd[8],  record, mod_state);  // こ
    case SG_J:    return process_shingeta_key(KC_J,    kana_u,    &key_registerd[9],  record, mod_state);  // う
    case SG_K:    return process_shingeta_key(KC_K,    kana_i,    &key_registerd[10], record, mod_state);  // い
    case SG_L:    return process_shingeta_key(KC_L,    kana_si,   &key_registerd[11], record, mod_state);  // し
    case SG_M:    return process_shingeta_key(KC_M,    kana_ta,   &key_registerd[12], record, mod_state);  // た
    case SG_N:    return process_shingeta_key(KC_N,    kana_te,   &key_registerd[13], record, mod_state);  // て
    case SG_O:    return process_shingeta_key(KC_O,    kana_ga,   &key_registerd[14], record, mod_state);  // が
    case SG_P:    return process_shingeta_key(KC_P,    kana_hi,   &key_registerd[15], record, mod_state);  // ひ
    case SG_Q:    return process_shingeta_key(KC_Q,    kana_quot, &key_registerd[16], record, mod_state);  // ー
    case SG_R:    return process_shingeta_key(KC_R,    kana_comm, &key_registerd[17], record, mod_state);  // 、
    case SG_S:    return process_shingeta_key(KC_S,    kana_to,   &key_registerd[18], record, mod_state);  // と
    case SG_T:    return process_shingeta_key(KC_T,    kana_ti,   &key_registerd[19], record, mod_state);  // ち
    case SG_U:    return process_shingeta_key(KC_U,    kana_ba,   &key_registerd[20], record, mod_state);  // ば
    case SG_V:    return process_shingeta_key(KC_V,    kana_ru,   &key_registerd[21], record, mod_state);  // る
    case SG_W:    return process_shingeta_key(KC_W,    kana_ni,   &key_registerd[22], record, mod_state);  // に
    case SG_X:    return process_shingeta_key(KC_X,    kana_ma,   &key_registerd[23], record, mod_state);  // ま
    case SG_Y:    return process_shingeta_key(KC_Y,    kana_gu,   &key_registerd[24], record, mod_state);  // ぐ
    case SG_Z:    return process_shingeta_key(KC_Z,    kana_su,   &key_registerd[25], record, mod_state);  // す
    case SG_SCLN: return process_shingeta_key(KC_SCLN, kana_na,   &key_registerd[26], record, mod_state);  // な
    case SG_QUOT: return process_shingeta_key(KC_QUOT, kana_ge,   &key_registerd[27], record, mod_state);  // げ
    case SG_COMM: return process_shingeta_key(KC_COMM, kana_de,   &key_registerd[28], record, mod_state);  // で
    case SG_DOT:  return process_shingeta_key(KC_DOT,  kana_dot,  &key_registerd[29], record, mod_state);  // 。
    case SG_SLSH: return process_shingeta_key(KC_SLSH, kana_bu,   &key_registerd[30], record, mod_state);  // ぶ
    // }}}
    // 出力用キーコード {{{
    // 清音 {{{
    case OUT_A:  return process_output_key(kana_a,  record, mod_state);  // あ
    case OUT_I:  return process_output_key(kana_i,  record, mod_state);  // い
    case OUT_U:  return process_output_key(kana_u,  record, mod_state);  // う
    case OUT_E:  return process_output_key(kana_e,  record, mod_state);  // え
    case OUT_O:  return process_output_key(kana_o,  record, mod_state);  // お
    case OUT_KA: return process_output_key(kana_ka, record, mod_state);  // か
    case OUT_KI: return process_output_key(kana_ki, record, mod_state);  // き
    case OUT_KU: return process_output_key(kana_ku, record, mod_state);  // く
    case OUT_KE: return process_output_key(kana_ke, record, mod_state);  // け
    case OUT_KO: return process_output_key(kana_ko, record, mod_state);  // こ
    case OUT_SA: return process_output_key(kana_sa, record, mod_state);  // さ
    case OUT_SI: return process_output_key(kana_si, record, mod_state);  // し
    case OUT_SU: return process_output_key(kana_su, record, mod_state);  // す
    case OUT_SE: return process_output_key(kana_se, record, mod_state);  // せ
    case OUT_SO: return process_output_key(kana_so, record, mod_state);  // そ
    case OUT_TA: return process_output_key(kana_ta, record, mod_state);  // た
    case OUT_TI: return process_output_key(kana_ti, record, mod_state);  // ち
    case OUT_TU: return process_output_key(kana_tu, record, mod_state);  // つ
    case OUT_TE: return process_output_key(kana_te, record, mod_state);  // て
    case OUT_TO: return process_output_key(kana_to, record, mod_state);  // と
    case OUT_NA: return process_output_key(kana_na, record, mod_state);  // な
    case OUT_NI: return process_output_key(kana_ni, record, mod_state);  // に
    case OUT_NU: return process_output_key(kana_nu, record, mod_state);  // ぬ
    case OUT_NE: return process_output_key(kana_ne, record, mod_state);  // ね
    case OUT_NO: return process_output_key(kana_no, record, mod_state);  // の
    case OUT_HA: return process_output_key(kana_ha, record, mod_state);  // は
    case OUT_HI: return process_output_key(kana_hi, record, mod_state);  // ひ
    case OUT_HU: return process_output_key(kana_hu, record, mod_state);  // ふ
    case OUT_HE: return process_output_key(kana_he, record, mod_state);  // へ
    case OUT_HO: return process_output_key(kana_ho, record, mod_state);  // ほ
    case OUT_MA: return process_output_key(kana_ma, record, mod_state);  // ま
    case OUT_MI: return process_output_key(kana_mi, record, mod_state);  // み
    case OUT_MU: return process_output_key(kana_mu, record, mod_state);  // む
    case OUT_ME: return process_output_key(kana_me, record, mod_state);  // め
    case OUT_MO: return process_output_key(kana_mo, record, mod_state);  // も
    case OUT_YA: return process_output_key(kana_ya, record, mod_state);  // や
    case OUT_YU: return process_output_key(kana_yu, record, mod_state);  // ゆ
    case OUT_YO: return process_output_key(kana_yo, record, mod_state);  // よ
    case OUT_RA: return process_output_key(kana_ra, record, mod_state);  // ら
    case OUT_RI: return process_output_key(kana_ri, record, mod_state);  // り
    case OUT_RU: return process_output_key(kana_ru, record, mod_state);  // る
    case OUT_RE: return process_output_key(kana_re, record, mod_state);  // れ
    case OUT_RO: return process_output_key(kana_ro, record, mod_state);  // ろ
    case OUT_WA: return process_output_key(kana_wa, record, mod_state);  // わ
    case OUT_WO: return process_output_key(kana_wo, record, mod_state);  // を
    case OUT_NN: return process_output_key(kana_nn, record, mod_state);  // ん
    // }}}
    // 濁音・半濁音 {{{
    case OUT_GA: return process_output_key(kana_ga, record, mod_state);  // が
    case OUT_GI: return process_output_key(kana_gi, record, mod_state);  // ぎ
    case OUT_GU: return process_output_key(kana_gu, record, mod_state);  // ぐ
    case OUT_GE: return process_output_key(kana_ge, record, mod_state);  // げ
    case OUT_GO: return process_output_key(kana_go, record, mod_state);  // ご
    case OUT_ZA: return process_output_key(kana_za, record, mod_state);  // ざ
    case OUT_ZI: return process_output_key(kana_zi, record, mod_state);  // じ
    case OUT_ZU: return process_output_key(kana_zu, record, mod_state);  // ず
    case OUT_ZE: return process_output_key(kana_ze, record, mod_state);  // ぜ
    case OUT_ZO: return process_output_key(kana_zo, record, mod_state);  // ぞ
    case OUT_DA: return process_output_key(kana_da, record, mod_state);  // だ
    case OUT_DI: return process_output_key(kana_di, record, mod_state);  // ぢ
    case OUT_DU: return process_output_key(kana_du, record, mod_state);  // づ
    case OUT_DE: return process_output_key(kana_de, record, mod_state);  // で
    case OUT_DO: return process_output_key(kana_do, record, mod_state);  // ど
    case OUT_BA: return process_output_key(kana_ba, record, mod_state);  // ば
    case OUT_BI: return process_output_key(kana_bi, record, mod_state);  // び
    case OUT_BU: return process_output_key(kana_bu, record, mod_state);  // ぶ
    case OUT_BE: return process_output_key(kana_be, record, mod_state);  // べ
    case OUT_BO: return process_output_key(kana_bo, record, mod_state);  // ぼ
    case OUT_PA: return process_output_key(kana_pa, record, mod_state);  // ぱ
    case OUT_PI: return process_output_key(kana_pi, record, mod_state);  // ぴ
    case OUT_PU: return process_output_key(kana_pu, record, mod_state);  // ぷ
    case OUT_PE: return process_output_key(kana_pe, record, mod_state);  // ぺ
    case OUT_PO: return process_output_key(kana_po, record, mod_state);  // ぽ
    // }}}
    // 拗音 {{{
    case OUT_KYA: return process_output_key(kana_kya, record, mod_state);  // きゃ
    case OUT_KYU: return process_output_key(kana_kyu, record, mod_state);  // きゅ
    case OUT_KYO: return process_output_key(kana_kyo, record, mod_state);  // きょ
    case OUT_SYA: return process_output_key(kana_sya, record, mod_state);  // しゃ
    case OUT_SYU: return process_output_key(kana_syu, record, mod_state);  // しゅ
    case OUT_SYO: return process_output_key(kana_syo, record, mod_state);  // しょ
    case OUT_TYA: return process_output_key(kana_tya, record, mod_state);  // ちゃ
    case OUT_TYU: return process_output_key(kana_tyu, record, mod_state);  // ちゅ
    case OUT_TYO: return process_output_key(kana_tyo, record, mod_state);  // ちょ
    case OUT_NYA: return process_output_key(kana_nya, record, mod_state);  // にゃ
    case OUT_NYU: return process_output_key(kana_nyu, record, mod_state);  // にゅ
    case OUT_NYO: return process_output_key(kana_nyo, record, mod_state);  // にょ
    case OUT_HYA: return process_output_key(kana_hya, record, mod_state);  // ひゃ
    case OUT_HYU: return process_output_key(kana_hyu, record, mod_state);  // ひゅ
    case OUT_HYO: return process_output_key(kana_hyo, record, mod_state);  // ひょ
    case OUT_MYA: return process_output_key(kana_mya, record, mod_state);  // みゃ
    case OUT_MYU: return process_output_key(kana_myu, record, mod_state);  // みゅ
    case OUT_MYO: return process_output_key(kana_myo, record, mod_state);  // みょ
    case OUT_RYA: return process_output_key(kana_rya, record, mod_state);  // りゃ
    case OUT_RYU: return process_output_key(kana_ryu, record, mod_state);  // りゅ
    case OUT_RYO: return process_output_key(kana_ryo, record, mod_state);  // りょ
    case OUT_GYA: return process_output_key(kana_gya, record, mod_state);  // ぎゃ
    case OUT_GYU: return process_output_key(kana_gyu, record, mod_state);  // ぎゅ
    case OUT_GYO: return process_output_key(kana_gyo, record, mod_state);  // ぎょ
    case OUT_ZYA: return process_output_key(kana_zya, record, mod_state);  // じゃ
    case OUT_ZYU: return process_output_key(kana_zyu, record, mod_state);  // じゅ
    case OUT_ZYO: return process_output_key(kana_zyo, record, mod_state);  // じょ
    case OUT_DYA: return process_output_key(kana_dya, record, mod_state);  // ぢゃ
    case OUT_DYU: return process_output_key(kana_dyu, record, mod_state);  // ぢゅ
    case OUT_DYO: return process_output_key(kana_dyo, record, mod_state);  // ぢょ
    case OUT_BYA: return process_output_key(kana_bya, record, mod_state);  // びゃ
    case OUT_BYU: return process_output_key(kana_byu, record, mod_state);  // びゅ
    case OUT_BYO: return process_output_key(kana_byo, record, mod_state);  // びょ
    case OUT_PYA: return process_output_key(kana_pya, record, mod_state);  // ぴゃ
    case OUT_PYU: return process_output_key(kana_pyu, record, mod_state);  // ぴゅ
    case OUT_PYO: return process_output_key(kana_pyo, record, mod_state);  // ぴょ
    // }}}
    // 外来音 {{{
    case OUT_WI:  return process_output_key(kana_wi,  record, mod_state);  // うぃ
    case OUT_WE:  return process_output_key(kana_we,  record, mod_state);  // うぇ
    case OUT_WHO: return process_output_key(kana_who, record, mod_state);  // うぉ
    case OUT_FA:  return process_output_key(kana_fa,  record, mod_state);  // ふぁ
    case OUT_FI:  return process_output_key(kana_fi,  record, mod_state);  // ふぃ
    case OUT_FE:  return process_output_key(kana_fe,  record, mod_state);  // ふぇ
    case OUT_FO:  return process_output_key(kana_fo,  record, mod_state);  // ふぉ
    case OUT_SYE: return process_output_key(kana_sye, record, mod_state);  // しぇ
    case OUT_ZYE: return process_output_key(kana_zye, record, mod_state);  // じぇ
    case OUT_TYE: return process_output_key(kana_tye, record, mod_state);  // ちぇ
    case OUT_THI: return process_output_key(kana_thi, record, mod_state);  // てぃ
    case OUT_DHI: return process_output_key(kana_dhi, record, mod_state);  // でぃ
    case OUT_TWU: return process_output_key(kana_twu, record, mod_state);  // とぅ
    case OUT_DWU: return process_output_key(kana_dwu, record, mod_state);  // どぅ
    case OUT_VU:  return process_output_key(kana_vu,  record, mod_state);  // ヴ
    // }}}
    // 捨て仮名 {{{
    case OUT_XTU: return process_output_key(kana_xtu, record, mod_state);  // っ
    case OUT_XYA: return process_output_key(kana_xya, record, mod_state);  // ゃ
    case OUT_XYU: return process_output_key(kana_xyu, record, mod_state);  // ゅ
    case OUT_XYO: return process_output_key(kana_xyo, record, mod_state);  // ょ
    case OUT_XA:  return process_output_key(kana_xa,  record, mod_state);  // ぁ
    case OUT_XI:  return process_output_key(kana_xi,  record, mod_state);  // ぃ
    case OUT_XU:  return process_output_key(kana_xu,  record, mod_state);  // ぅ
    case OUT_XE:  return process_output_key(kana_xe,  record, mod_state);  // ぇ
    case OUT_XO:  return process_output_key(kana_xo,  record, mod_state);  // ぉ
    case OUT_XWA: return process_output_key(kana_xwa, record, mod_state);  // ゎ
    // }}}
    // 記号 {{{
    case OUT_COMM: return process_output_key(kana_comm, record, mod_state);  // 、
    case OUT_DOT:  return process_output_key(kana_dot,  record, mod_state);  // 。
    case OUT_LONG: return process_output_key(kana_quot, record, mod_state);  // ー
    case OUT_MDOT: return process_output_key(kana_dquo, record, mod_state);  // ・
    case OUT_SLSH: return process_output_key(kana_slsh, record, mod_state);  // ／
    case OUT_EXLM: return process_output_key(kana_exlm, record, mod_state);  // ！
    case OUT_QUES: return process_output_key(kana_ques, record, mod_state);  // ？
    // }}}
    // }}}

    default:
      return true;
  }
}

// }}}

// -- Combos {{{

// const {{{
// 制御キー {{{
const uint16_t PROGMEM base_df_combo[]     = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM base_jk_combo[]     = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM shingeta_df_combo[] = {SG_D, SG_F, COMBO_END};
const uint16_t PROGMEM shingeta_jk_combo[] = {SG_J, SG_K, COMBO_END};
// }}}
// 中指シフト (左) {{{
const uint16_t PROGMEM d_y_combo[]    = {SG_D, SG_Y,    COMBO_END};
const uint16_t PROGMEM d_u_combo[]    = {SG_D, SG_U,    COMBO_END};
const uint16_t PROGMEM d_i_combo[]    = {SG_D, SG_I,    COMBO_END};
const uint16_t PROGMEM d_o_combo[]    = {SG_D, SG_O,    COMBO_END};
const uint16_t PROGMEM d_p_combo[]    = {SG_D, SG_P,    COMBO_END};
const uint16_t PROGMEM d_h_combo[]    = {SG_D, SG_H,    COMBO_END};
const uint16_t PROGMEM d_j_combo[]    = {SG_D, SG_J,    COMBO_END};
const uint16_t PROGMEM d_k_combo[]    = {SG_D, SG_K,    COMBO_END};
const uint16_t PROGMEM d_l_combo[]    = {SG_D, SG_L,    COMBO_END};
const uint16_t PROGMEM d_scln_combo[] = {SG_D, SG_SCLN, COMBO_END};
const uint16_t PROGMEM d_quot_combo[] = {SG_D, SG_QUOT, COMBO_END};
const uint16_t PROGMEM d_n_combo[]    = {SG_D, SG_N,    COMBO_END};
const uint16_t PROGMEM d_m_combo[]    = {SG_D, SG_M,    COMBO_END};
const uint16_t PROGMEM d_comm_combo[] = {SG_D, SG_COMM, COMBO_END};
const uint16_t PROGMEM d_dot_combo[]  = {SG_D, SG_DOT,  COMBO_END};
const uint16_t PROGMEM d_slsh_combo[] = {SG_D, SG_SLSH, COMBO_END};
// }}}
// 中指シフト (右) {{{
const uint16_t PROGMEM k_q_combo[] = {SG_K, SG_Q, COMBO_END};
const uint16_t PROGMEM k_w_combo[] = {SG_K, SG_W, COMBO_END};
const uint16_t PROGMEM k_e_combo[] = {SG_K, SG_E, COMBO_END};
const uint16_t PROGMEM k_r_combo[] = {SG_K, SG_R, COMBO_END};
const uint16_t PROGMEM k_t_combo[] = {SG_K, SG_T, COMBO_END};
const uint16_t PROGMEM k_a_combo[] = {SG_K, SG_A, COMBO_END};
const uint16_t PROGMEM k_s_combo[] = {SG_K, SG_S, COMBO_END};
// const uint16_t PROGMEM k_d_combo[] = {SG_K, SG_D, COMBO_END};
const uint16_t PROGMEM k_f_combo[] = {SG_K, SG_F, COMBO_END};
const uint16_t PROGMEM k_g_combo[] = {SG_K, SG_G, COMBO_END};
const uint16_t PROGMEM k_z_combo[] = {SG_K, SG_Z, COMBO_END};
const uint16_t PROGMEM k_x_combo[] = {SG_K, SG_X, COMBO_END};
const uint16_t PROGMEM k_c_combo[] = {SG_K, SG_C, COMBO_END};
const uint16_t PROGMEM k_v_combo[] = {SG_K, SG_V, COMBO_END};
const uint16_t PROGMEM k_b_combo[] = {SG_K, SG_B, COMBO_END};
// }}}
// 薬指シフト (左) {{{
const uint16_t PROGMEM s_y_combo[]    = {SG_S, SG_Y,    COMBO_END};
const uint16_t PROGMEM s_u_combo[]    = {SG_S, SG_U,    COMBO_END};
const uint16_t PROGMEM s_i_combo[]    = {SG_S, SG_I,    COMBO_END};
const uint16_t PROGMEM s_o_combo[]    = {SG_S, SG_O,    COMBO_END};
const uint16_t PROGMEM s_p_combo[]    = {SG_S, SG_P,    COMBO_END};
const uint16_t PROGMEM s_h_combo[]    = {SG_S, SG_H,    COMBO_END};
const uint16_t PROGMEM s_j_combo[]    = {SG_S, SG_J,    COMBO_END};
// const uint16_t PROGMEM s_k_combo[]    = {SG_S, SG_K,    COMBO_END};
const uint16_t PROGMEM s_l_combo[]    = {SG_S, SG_L,    COMBO_END};
const uint16_t PROGMEM s_scln_combo[] = {SG_S, SG_SCLN, COMBO_END};
const uint16_t PROGMEM s_n_combo[]    = {SG_S, SG_N,    COMBO_END};
const uint16_t PROGMEM s_m_combo[]    = {SG_S, SG_M,    COMBO_END};
const uint16_t PROGMEM s_comm_combo[] = {SG_S, SG_COMM, COMBO_END};
const uint16_t PROGMEM s_dot_combo[]  = {SG_S, SG_DOT,  COMBO_END};
const uint16_t PROGMEM s_slsh_combo[] = {SG_S, SG_SLSH, COMBO_END};
// }}}
// 薬指シフト (右) {{{
const uint16_t PROGMEM l_q_combo[] = {SG_L, SG_Q, COMBO_END};
const uint16_t PROGMEM l_w_combo[] = {SG_L, SG_W, COMBO_END};
const uint16_t PROGMEM l_e_combo[] = {SG_L, SG_E, COMBO_END};
const uint16_t PROGMEM l_r_combo[] = {SG_L, SG_R, COMBO_END};
const uint16_t PROGMEM l_t_combo[] = {SG_L, SG_T, COMBO_END};
const uint16_t PROGMEM l_a_combo[] = {SG_L, SG_A, COMBO_END};
// const uint16_t PROGMEM l_s_combo[] = {SG_L, SG_S, COMBO_END};
// const uint16_t PROGMEM l_d_combo[] = {SG_L, SG_D, COMBO_END};
const uint16_t PROGMEM l_f_combo[] = {SG_L, SG_F, COMBO_END};
const uint16_t PROGMEM l_g_combo[] = {SG_L, SG_G, COMBO_END};
const uint16_t PROGMEM l_z_combo[] = {SG_L, SG_Z, COMBO_END};
const uint16_t PROGMEM l_x_combo[] = {SG_L, SG_X, COMBO_END};
const uint16_t PROGMEM l_c_combo[] = {SG_L, SG_C, COMBO_END};
const uint16_t PROGMEM l_v_combo[] = {SG_L, SG_V, COMBO_END};
const uint16_t PROGMEM l_b_combo[] = {SG_L, SG_B, COMBO_END};
// }}}
// 中指上段シフト {{{
const uint16_t PROGMEM i_q_combo[] = {SG_I, SG_Q, COMBO_END};
const uint16_t PROGMEM i_w_combo[] = {SG_I, SG_W, COMBO_END};
const uint16_t PROGMEM i_e_combo[] = {SG_I, SG_E, COMBO_END};
const uint16_t PROGMEM i_r_combo[] = {SG_I, SG_R, COMBO_END};
const uint16_t PROGMEM i_t_combo[] = {SG_I, SG_T, COMBO_END};
const uint16_t PROGMEM i_a_combo[] = {SG_I, SG_A, COMBO_END};
const uint16_t PROGMEM i_f_combo[] = {SG_I, SG_F, COMBO_END};
const uint16_t PROGMEM i_g_combo[] = {SG_I, SG_G, COMBO_END};
const uint16_t PROGMEM i_z_combo[] = {SG_I, SG_Z, COMBO_END};
const uint16_t PROGMEM i_x_combo[] = {SG_I, SG_X, COMBO_END};
const uint16_t PROGMEM i_c_combo[] = {SG_I, SG_C, COMBO_END};
const uint16_t PROGMEM i_v_combo[] = {SG_I, SG_V, COMBO_END};
const uint16_t PROGMEM i_b_combo[] = {SG_I, SG_B, COMBO_END};
// }}}
// 薬指上段シフト {{{
const uint16_t PROGMEM o_q_combo[] = {SG_O, SG_Q, COMBO_END};
const uint16_t PROGMEM o_w_combo[] = {SG_O, SG_W, COMBO_END};
const uint16_t PROGMEM o_e_combo[] = {SG_O, SG_E, COMBO_END};
const uint16_t PROGMEM o_r_combo[] = {SG_O, SG_R, COMBO_END};
const uint16_t PROGMEM o_t_combo[] = {SG_O, SG_T, COMBO_END};
const uint16_t PROGMEM o_a_combo[] = {SG_O, SG_A, COMBO_END};
const uint16_t PROGMEM o_f_combo[] = {SG_O, SG_F, COMBO_END};
const uint16_t PROGMEM o_g_combo[] = {SG_O, SG_G, COMBO_END};
const uint16_t PROGMEM o_z_combo[] = {SG_O, SG_Z, COMBO_END};
const uint16_t PROGMEM o_x_combo[] = {SG_O, SG_X, COMBO_END};
const uint16_t PROGMEM o_c_combo[] = {SG_O, SG_C, COMBO_END};
const uint16_t PROGMEM o_v_combo[] = {SG_O, SG_V, COMBO_END};
const uint16_t PROGMEM o_b_combo[] = {SG_O, SG_B, COMBO_END};
// }}}
// 小指上段シフト (右) {{{
const uint16_t PROGMEM p_q_combo[] = {SG_P, SG_Q, COMBO_END};
const uint16_t PROGMEM p_w_combo[] = {SG_P, SG_W, COMBO_END};
const uint16_t PROGMEM p_e_combo[] = {SG_P, SG_E, COMBO_END};
const uint16_t PROGMEM p_r_combo[] = {SG_P, SG_R, COMBO_END};
const uint16_t PROGMEM p_t_combo[] = {SG_P, SG_T, COMBO_END};
const uint16_t PROGMEM p_a_combo[] = {SG_P, SG_A, COMBO_END};
const uint16_t PROGMEM p_f_combo[] = {SG_P, SG_F, COMBO_END};
const uint16_t PROGMEM p_g_combo[] = {SG_P, SG_G, COMBO_END};
const uint16_t PROGMEM p_z_combo[] = {SG_P, SG_Z, COMBO_END};
const uint16_t PROGMEM p_c_combo[] = {SG_P, SG_C, COMBO_END};
const uint16_t PROGMEM p_v_combo[] = {SG_P, SG_V, COMBO_END};
const uint16_t PROGMEM p_b_combo[] = {SG_P, SG_B, COMBO_END};
// }}}
// 小指上段シフト (左) {{{
const uint16_t PROGMEM q_y_combo[]    = {SG_Q, SG_Y,    COMBO_END};
const uint16_t PROGMEM q_u_combo[]    = {SG_Q, SG_U,    COMBO_END};
const uint16_t PROGMEM q_h_combo[]    = {SG_Q, SG_H,    COMBO_END};
const uint16_t PROGMEM q_j_combo[]    = {SG_Q, SG_J,    COMBO_END};
const uint16_t PROGMEM q_n_combo[]    = {SG_Q, SG_N,    COMBO_END};
const uint16_t PROGMEM q_m_combo[]    = {SG_Q, SG_M,    COMBO_END};
const uint16_t PROGMEM q_comm_combo[] = {SG_Q, SG_COMM, COMBO_END};
const uint16_t PROGMEM q_dot_combo[]  = {SG_Q, SG_DOT,  COMBO_END};
const uint16_t PROGMEM q_slsh_combo[] = {SG_Q, SG_SLSH, COMBO_END};
// }}}
// }}}

// key_combos {{{
combo_t key_combos[] = {
  // 制御キー {{{
  COMBO(base_df_combo,     SG_OFF)
  COMBO(base_jk_combo,     SG_ON)
  COMBO(shingeta_df_combo, SG_OFF)
  COMBO(shingeta_jk_combo, SG_ON)
  // }}}
  // 中指シフト (左) {{{
  COMBO(d_y_combo,    OUT_WI)   // うぃ
  COMBO(d_u_combo,    OUT_PA)   // ぱ
  COMBO(d_i_combo,    OUT_YO)   // よ
  COMBO(d_o_combo,    OUT_MI)   // み
  COMBO(d_p_combo,    OUT_WE)   // うぇ
  COMBO(d_h_combo,    OUT_HE)   // へ
  COMBO(d_j_combo,    OUT_A)    // あ
  COMBO(d_k_combo,    OUT_RE)   // れ
  COMBO(d_l_combo,    OUT_O)    // お
  COMBO(d_scln_combo, OUT_E)    // え
  COMBO(d_quot_combo, OUT_WHO)  // うぉ
  COMBO(d_n_combo,    OUT_SE)   // せ
  COMBO(d_m_combo,    OUT_NE)   // ね
  COMBO(d_comm_combo, OUT_BE)   // べ
  COMBO(d_dot_combo,  OUT_PU)   // ぷ
  COMBO(d_slsh_combo, OUT_VU)   // ヴ
  // }}}
  // 中指シフト (右) {{{
  COMBO(k_q_combo, OUT_FA)  // ふぁ
  COMBO(k_w_combo, OUT_GO)  // ご
  COMBO(k_e_combo, OUT_HU)  // ふ
  COMBO(k_r_combo, OUT_FI)  // ふぃ
  COMBO(k_t_combo, OUT_FE)  // ふぇ
  COMBO(k_a_combo, OUT_HO)  // ほ
  COMBO(k_s_combo, OUT_ZI)  // じ
  // COMBO(k_d_combo, OUT_RE)  // れ
  COMBO(k_f_combo, OUT_MO)  // も
  COMBO(k_g_combo, OUT_YU)  // ゆ
  COMBO(k_z_combo, OUT_DU)  // づ
  COMBO(k_x_combo, OUT_ZO)  // ぞ
  COMBO(k_c_combo, OUT_BO)  // ぼ
  COMBO(k_v_combo, OUT_MU)  // む
  COMBO(k_b_combo, OUT_FO)  // ふぉ
  // }}}
  // 薬指シフト (左) {{{
  COMBO(s_y_combo,    OUT_SYE)  // しぇ
  COMBO(s_u_combo,    OUT_PE)   // ぺ
  COMBO(s_i_combo,    OUT_DO)   // ど
  COMBO(s_o_combo,    OUT_YA)   // や
  COMBO(s_p_combo,    OUT_ZYE)  // じぇ
  COMBO(s_h_combo,    OUT_BI)   // び
  COMBO(s_j_combo,    OUT_RA)   // ら
  // COMBO(s_k_combo,    OUT_ZI)   // じ
  COMBO(s_l_combo,    OUT_SA)   // さ
  COMBO(s_scln_combo, OUT_SO)   // そ
  COMBO(s_n_combo,    OUT_WA)   // わ
  COMBO(s_m_combo,    OUT_DA)   // だ
  COMBO(s_comm_combo, OUT_PI)   // ぴ
  COMBO(s_dot_combo,  OUT_PO)   // ぽ
  COMBO(s_slsh_combo, OUT_TYE)  // ちぇ
  // }}}
  // 薬指シフト (右) {{{
  COMBO(l_q_combo, OUT_DI)   // ぢ
  COMBO(l_w_combo, OUT_ME)   // め
  COMBO(l_e_combo, OUT_KE)   // け
  COMBO(l_r_combo, OUT_THI)  // てぃ
  COMBO(l_t_combo, OUT_DHI)  // でぃ
  COMBO(l_a_combo, OUT_WO)   // を
  // COMBO(l_s_combo, OUT_SA)   // さ
  // COMBO(l_d_combo, OUT_O)    // お
  COMBO(l_f_combo, OUT_RI)   // り
  COMBO(l_g_combo, OUT_ZU)   // ず
  COMBO(l_z_combo, OUT_ZE)   // ぜ
  COMBO(l_x_combo, OUT_ZA)   // ざ
  COMBO(l_c_combo, OUT_GI)   // ぎ
  COMBO(l_v_combo, OUT_RO)   // ろ
  COMBO(l_b_combo, OUT_NU)   // ぬ
  // }}}
  // 中指上段シフト {{{
  COMBO(i_q_combo, OUT_HYU)  // ひゅ
  COMBO(i_w_combo, OUT_SYU)  // しゅ
  COMBO(i_e_combo, OUT_SYO)  // しょ
  COMBO(i_r_combo, OUT_KYU)  // きゅ
  COMBO(i_t_combo, OUT_TYU)  // ちゅ
  COMBO(i_a_combo, OUT_HYO)  // ひょ
  COMBO(i_f_combo, OUT_KYO)  // きょ
  COMBO(i_g_combo, OUT_TYO)  // ちょ
  COMBO(i_z_combo, OUT_HYA)  // ひゃ
  COMBO(i_x_combo, OUT_TWU)  // とぅ
  COMBO(i_c_combo, OUT_SYA)  // しゃ
  COMBO(i_v_combo, OUT_KYA)  // きゃ
  COMBO(i_b_combo, OUT_TYA)  // ちゃ
  // }}}
  // 薬指上段シフト {{{
  COMBO(o_q_combo, OUT_RYU)  // りゅ
  COMBO(o_w_combo, OUT_ZYU)  // じゅ
  COMBO(o_e_combo, OUT_ZYO)  // じょ
  COMBO(o_r_combo, OUT_GYU)  // ぎゅ
  COMBO(o_t_combo, OUT_NYU)  // にゅ
  COMBO(o_a_combo, OUT_RYO)  // りょ
  COMBO(o_f_combo, OUT_GYO)  // ぎょ
  COMBO(o_g_combo, OUT_NYO)  // にょ
  COMBO(o_z_combo, OUT_RYA)  // りゃ
  COMBO(o_x_combo, OUT_DWU)  // どぅ
  COMBO(o_c_combo, OUT_ZYA)  // じゃ
  COMBO(o_v_combo, OUT_GYA)  // ぎゃ
  COMBO(o_b_combo, OUT_NYA)  // にゃ
  // }}}
  // 小指上段シフト (右) {{{
  COMBO(p_q_combo, OUT_PYU)  // ぴゅ
  COMBO(p_w_combo, OUT_MYU)  // みゅ
  COMBO(p_e_combo, OUT_MYO)  // みょ
  COMBO(p_r_combo, OUT_BYU)  // びゅ
  COMBO(p_t_combo, OUT_DYU)  // ぢゅ
  COMBO(p_a_combo, OUT_PYO)  // ぴょ
  COMBO(p_f_combo, OUT_BYO)  // びょ
  COMBO(p_g_combo, OUT_DYO)  // ぢょ
  COMBO(p_z_combo, OUT_PYA)  // ぴゃ
  COMBO(p_c_combo, OUT_MYA)  // みゃ
  COMBO(p_v_combo, OUT_BYA)  // びゃ
  COMBO(p_b_combo, OUT_DYA)  // ぢゃ
  // }}}
  // 小指上段シフト (左) {{{
  COMBO(q_y_combo,    OUT_XYA)  // ゃ
  COMBO(q_u_combo,    OUT_XA)   // ぁ
  COMBO(q_h_combo,    OUT_XYU)  // ゅ
  COMBO(q_j_combo,    OUT_XI)   // ぃ
  COMBO(q_n_combo,    OUT_XYO)  // ょ
  COMBO(q_m_combo,    OUT_XU)   // ぅ
  COMBO(q_comm_combo, OUT_XE)   // ぇ
  COMBO(q_dot_combo,  OUT_XO)   // ぉ
  COMBO(q_slsh_combo, OUT_XWA)  // ゎ
  // }}}
};
// }}}

// }}}
