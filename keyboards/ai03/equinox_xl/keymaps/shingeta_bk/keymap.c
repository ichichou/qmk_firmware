// KB: Equinox XL
// KM: shingeta_bk

// -- Includes {{{

#include QMK_KEYBOARD_H

// }}}

// -- Macros {{{

// Layers
#define BASE  DF(_BASE)
#define SHING DF(_SHINGETA)

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

// -- Macros for Shingeta {{{

#define CONST_COMBO(combo_name, shift_key, key) \
  const uint16_t PROGMEM combo_name##_combo[] = {shift_key, key, COMBO_END};

#define COMBO_LIST(combo_code, combo_name, output_key) \
  [combo_code] = COMBO(combo_name##_combo, output_key)

#define SHINGETA_KEYCODE(name, sg_kana, qwerty_key, qw_var) \
  case name:                                                \
    {                                                       \
      static bool qw_var##_registered;                      \
                                                            \
      if (record->event.pressed) {                          \
        if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) {         \
          SEND_STRING(sg_kana);                             \
          return false;                                     \
        } else {                                            \
          register_code(qwerty_key);                        \
          qw_var##_registered = true;                       \
          return false;                                     \
        }                                                   \
      } else {                                              \
        if (qw_var##_registered) {                          \
          unregister_code(qwerty_key);                      \
          qw_var##_registered = false;                      \
          return false;                                     \
        }                                                   \
      }                                                     \
      return false;                                         \
    }

#define OUTPUT_KEYCODE(output_keycode, str) \
  case output_keycode:                      \
    if (record->event.pressed) {            \
      SEND_STRING(str);                     \
      return false;                         \
    }                                       \
    return false;

// }}}

// -- Layers {{{

enum layer_names {
  _BASE,
  _SHINGETA,
  _NAV,
  _SYM,
  _WIN,
  _FN,
};

// }}}

// -- Custom Keycodes {{{

enum my_keycodes {
  // 制御用キーコード {{{
  SG_ON = QK_USER + 100,
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
  SG_COMM,
  SG_DOT,
  SG_SLSH,
  SG_SCLN,
  SG_QUOT,
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
  // 拗音 (清音) {{{
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
  // }}}
  // 拗音 (濁音・半濁音) {{{
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
  OUT_VA,
  OUT_VI,
  OUT_VU,
  OUT_VE,
  OUT_VO,
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
  OUT_BRC,
  OUT_PRN,
  OUT_CBR,
  // }}}
  // }}}
};

// }}}

// -- Behavior of Any Keycode {{{

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  switch (keycode) {
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
    SHINGETA_KEYCODE(SG_A,    "no",  KC_A,    a)
    SHINGETA_KEYCODE(SG_B,    "tu",  KC_B,    b)
    SHINGETA_KEYCODE(SG_C,    "ki",  KC_C,    c)
    SHINGETA_KEYCODE(SG_D,    "ka",  KC_D,    d)
    SHINGETA_KEYCODE(SG_E,    "ha",  KC_E,    e)
    SHINGETA_KEYCODE(SG_F,    "nn",  KC_F,    f)
    SHINGETA_KEYCODE(SG_G,    "xtu", KC_G,    g)
    SHINGETA_KEYCODE(SG_H,    "ku",  KC_H,    h)
    SHINGETA_KEYCODE(SG_I,    "ko",  KC_I,    i)
    SHINGETA_KEYCODE(SG_J,    "u",   KC_J,    j)
    SHINGETA_KEYCODE(SG_K,    "i",   KC_K,    k)
    SHINGETA_KEYCODE(SG_L,    "si",  KC_L,    l)
    SHINGETA_KEYCODE(SG_M,    "ta",  KC_M,    m)
    SHINGETA_KEYCODE(SG_N,    "te",  KC_N,    n)
    SHINGETA_KEYCODE(SG_O,    "ga",  KC_O,    o)
    SHINGETA_KEYCODE(SG_P,    "hi",  KC_P,    p)
    SHINGETA_KEYCODE(SG_Q,    "'",   KC_Q,    q)
    SHINGETA_KEYCODE(SG_R,    ",",   KC_R,    r)
    SHINGETA_KEYCODE(SG_S,    "to",  KC_S,    s)
    SHINGETA_KEYCODE(SG_T,    "ti",  KC_T,    t)
    SHINGETA_KEYCODE(SG_U,    "ba",  KC_U,    u)
    SHINGETA_KEYCODE(SG_V,    "ru",  KC_V,    v)
    SHINGETA_KEYCODE(SG_W,    "ni",  KC_W,    w)
    SHINGETA_KEYCODE(SG_X,    "ma",  KC_X,    x)
    SHINGETA_KEYCODE(SG_Y,    "gu",  KC_Y,    y)
    SHINGETA_KEYCODE(SG_Z,    "su",  KC_Z,    z)
    SHINGETA_KEYCODE(SG_COMM, "de",  KC_COMM, comm)
    SHINGETA_KEYCODE(SG_DOT,  ".",   KC_DOT,  dot)
    SHINGETA_KEYCODE(SG_SLSH, "bu",  KC_SLSH, slsh)
    SHINGETA_KEYCODE(SG_SCLN, "na",  KC_SCLN, scln)
    SHINGETA_KEYCODE(SG_QUOT, "ge",  KC_QUOT, quot)
    // }}}
    // 出力用キーコード {{{
    // 清音 {{{
    OUTPUT_KEYCODE(OUT_A, "a")
    OUTPUT_KEYCODE(OUT_I, "i")
    OUTPUT_KEYCODE(OUT_U, "u")
    OUTPUT_KEYCODE(OUT_E, "e")
    OUTPUT_KEYCODE(OUT_O, "o")
    OUTPUT_KEYCODE(OUT_KA,"ka")
    OUTPUT_KEYCODE(OUT_KI,"ki")
    OUTPUT_KEYCODE(OUT_KU,"ku")
    OUTPUT_KEYCODE(OUT_KE,"ke")
    OUTPUT_KEYCODE(OUT_KO,"ko")
    OUTPUT_KEYCODE(OUT_SA,"sa")
    OUTPUT_KEYCODE(OUT_SI,"si")
    OUTPUT_KEYCODE(OUT_SU,"su")
    OUTPUT_KEYCODE(OUT_SE,"se")
    OUTPUT_KEYCODE(OUT_SO,"so")
    OUTPUT_KEYCODE(OUT_TA,"ta")
    OUTPUT_KEYCODE(OUT_TI,"ti")
    OUTPUT_KEYCODE(OUT_TU,"tu")
    OUTPUT_KEYCODE(OUT_TE,"te")
    OUTPUT_KEYCODE(OUT_TO,"to")
    OUTPUT_KEYCODE(OUT_NA,"na")
    OUTPUT_KEYCODE(OUT_NI,"ni")
    OUTPUT_KEYCODE(OUT_NU,"nu")
    OUTPUT_KEYCODE(OUT_NE,"ne")
    OUTPUT_KEYCODE(OUT_NO,"no")
    OUTPUT_KEYCODE(OUT_HA,"ha")
    OUTPUT_KEYCODE(OUT_HI,"hi")
    OUTPUT_KEYCODE(OUT_HU,"hu")
    OUTPUT_KEYCODE(OUT_HE,"he")
    OUTPUT_KEYCODE(OUT_HO,"ho")
    OUTPUT_KEYCODE(OUT_MA,"ma")
    OUTPUT_KEYCODE(OUT_MI,"mi")
    OUTPUT_KEYCODE(OUT_MU,"mu")
    OUTPUT_KEYCODE(OUT_ME,"me")
    OUTPUT_KEYCODE(OUT_MO,"mo")
    OUTPUT_KEYCODE(OUT_YA,"ya")
    OUTPUT_KEYCODE(OUT_YU,"yu")
    OUTPUT_KEYCODE(OUT_YO,"yo")
    OUTPUT_KEYCODE(OUT_RA,"ra")
    OUTPUT_KEYCODE(OUT_RI,"ri")
    OUTPUT_KEYCODE(OUT_RU,"ru")
    OUTPUT_KEYCODE(OUT_RE,"re")
    OUTPUT_KEYCODE(OUT_RO,"ro")
    OUTPUT_KEYCODE(OUT_WA,"wa")
    OUTPUT_KEYCODE(OUT_WO,"wo")
    OUTPUT_KEYCODE(OUT_NN,"nn")
    // }}}
    // 濁音・半濁音 {{{
    OUTPUT_KEYCODE(OUT_GA, "ga")
    OUTPUT_KEYCODE(OUT_GI, "gi")
    OUTPUT_KEYCODE(OUT_GU, "gu")
    OUTPUT_KEYCODE(OUT_GE, "ge")
    OUTPUT_KEYCODE(OUT_GO, "go")
    OUTPUT_KEYCODE(OUT_ZA, "za")
    OUTPUT_KEYCODE(OUT_ZI, "zi")
    OUTPUT_KEYCODE(OUT_ZU, "zu")
    OUTPUT_KEYCODE(OUT_ZE, "ze")
    OUTPUT_KEYCODE(OUT_ZO, "zo")
    OUTPUT_KEYCODE(OUT_DA, "da")
    OUTPUT_KEYCODE(OUT_DI, "di")
    OUTPUT_KEYCODE(OUT_DU, "du")
    OUTPUT_KEYCODE(OUT_DE, "de")
    OUTPUT_KEYCODE(OUT_DO, "do")
    OUTPUT_KEYCODE(OUT_BA, "ba")
    OUTPUT_KEYCODE(OUT_BI, "bi")
    OUTPUT_KEYCODE(OUT_BU, "bu")
    OUTPUT_KEYCODE(OUT_BE, "be")
    OUTPUT_KEYCODE(OUT_BO, "bo")
    OUTPUT_KEYCODE(OUT_PA, "pa")
    OUTPUT_KEYCODE(OUT_PI, "pi")
    OUTPUT_KEYCODE(OUT_PU, "pu")
    OUTPUT_KEYCODE(OUT_PE, "pe")
    OUTPUT_KEYCODE(OUT_PO, "po")
    // }}}
    // 拗音 (清音) {{{
    OUTPUT_KEYCODE(OUT_KYA, "kya")
    OUTPUT_KEYCODE(OUT_KYU, "kyu")
    OUTPUT_KEYCODE(OUT_KYO, "kyo")
    OUTPUT_KEYCODE(OUT_SYA, "sya")
    OUTPUT_KEYCODE(OUT_SYU, "syu")
    OUTPUT_KEYCODE(OUT_SYO, "syo")
    OUTPUT_KEYCODE(OUT_TYA, "tya")
    OUTPUT_KEYCODE(OUT_TYU, "tyu")
    OUTPUT_KEYCODE(OUT_TYO, "tyo")
    OUTPUT_KEYCODE(OUT_NYA, "nya")
    OUTPUT_KEYCODE(OUT_NYU, "nyu")
    OUTPUT_KEYCODE(OUT_NYO, "nyo")
    OUTPUT_KEYCODE(OUT_HYA, "hya")
    OUTPUT_KEYCODE(OUT_HYU, "hyu")
    OUTPUT_KEYCODE(OUT_HYO, "hyo")
    OUTPUT_KEYCODE(OUT_MYA, "mya")
    OUTPUT_KEYCODE(OUT_MYU, "myu")
    OUTPUT_KEYCODE(OUT_MYO, "myo")
    OUTPUT_KEYCODE(OUT_RYA, "rya")
    OUTPUT_KEYCODE(OUT_RYU, "ryu")
    OUTPUT_KEYCODE(OUT_RYO, "ryo")
    // }}}
    // 拗音 (濁音・半濁音) {{{
    OUTPUT_KEYCODE(OUT_GYA, "gya")
    OUTPUT_KEYCODE(OUT_GYU, "gyu")
    OUTPUT_KEYCODE(OUT_GYO, "gyo")
    OUTPUT_KEYCODE(OUT_ZYA, "zya")
    OUTPUT_KEYCODE(OUT_ZYU, "zyu")
    OUTPUT_KEYCODE(OUT_ZYO, "zyo")
    OUTPUT_KEYCODE(OUT_DYA, "dya")
    OUTPUT_KEYCODE(OUT_DYU, "dyu")
    OUTPUT_KEYCODE(OUT_DYO, "dyo")
    OUTPUT_KEYCODE(OUT_BYA, "bya")
    OUTPUT_KEYCODE(OUT_BYU, "byu")
    OUTPUT_KEYCODE(OUT_BYO, "byo")
    OUTPUT_KEYCODE(OUT_PYA, "pya")
    OUTPUT_KEYCODE(OUT_PYU, "pyu")
    OUTPUT_KEYCODE(OUT_PYO, "pyo")
    // }}}
    // 外来音 {{{
    OUTPUT_KEYCODE(OUT_WI,  "wi")
    OUTPUT_KEYCODE(OUT_WE,  "we")
    OUTPUT_KEYCODE(OUT_WHO, "who")
    OUTPUT_KEYCODE(OUT_FA,  "fa")
    OUTPUT_KEYCODE(OUT_FI,  "fi")
    OUTPUT_KEYCODE(OUT_FE,  "fe")
    OUTPUT_KEYCODE(OUT_FO,  "fo")
    OUTPUT_KEYCODE(OUT_SYE, "sye")
    OUTPUT_KEYCODE(OUT_ZYE, "zye")
    OUTPUT_KEYCODE(OUT_TYE, "tye")
    OUTPUT_KEYCODE(OUT_THI, "thi")
    OUTPUT_KEYCODE(OUT_DHI, "dhi")
    OUTPUT_KEYCODE(OUT_TWU, "twu")
    OUTPUT_KEYCODE(OUT_DWU, "dwu")
    OUTPUT_KEYCODE(OUT_VA,  "va")
    OUTPUT_KEYCODE(OUT_VI,  "vi")
    OUTPUT_KEYCODE(OUT_VU,  "vu")
    OUTPUT_KEYCODE(OUT_VE,  "ve")
    OUTPUT_KEYCODE(OUT_VO,  "vo")
    // }}}
    // 捨て仮名 {{{
    OUTPUT_KEYCODE(OUT_XTU, "xtu")
    OUTPUT_KEYCODE(OUT_XYA, "xya")
    OUTPUT_KEYCODE(OUT_XYU, "xyu")
    OUTPUT_KEYCODE(OUT_XYO, "xyo")
    OUTPUT_KEYCODE(OUT_XA,  "xa")
    OUTPUT_KEYCODE(OUT_XI,  "xi")
    OUTPUT_KEYCODE(OUT_XU,  "xu")
    OUTPUT_KEYCODE(OUT_XE,  "xe")
    OUTPUT_KEYCODE(OUT_XO,  "xo")
    OUTPUT_KEYCODE(OUT_XWA, "xwa")
    // }}}
    // 記号 {{{
    OUTPUT_KEYCODE(OUT_COMM, ",")
    OUTPUT_KEYCODE(OUT_DOT,  ".")
    OUTPUT_KEYCODE(OUT_LONG, "'")
    OUTPUT_KEYCODE(OUT_MDOT, "\"")
    OUTPUT_KEYCODE(OUT_SLSH, "/")
    OUTPUT_KEYCODE(OUT_EXLM, "!")
    OUTPUT_KEYCODE(OUT_QUES, "?")
    OUTPUT_KEYCODE(OUT_BRC,  "[]" SS_TAP(X_LEFT))
    OUTPUT_KEYCODE(OUT_PRN,  "()" SS_TAP(X_LEFT))
    OUTPUT_KEYCODE(OUT_CBR,  "{}" SS_TAP(X_LEFT))
    // }}}
    // }}}
    default:
      return true;
  }
}

// }}}

// -- Combos {{{

// Combo list {{{

enum combos {
  // 制御用 {{{
  BASE_DF,
  BASE_JK,
  SHINGETA_DF,
  SHINGETA_JK,
  // }}}
  // 記号類 {{{
  FG,
  HJ,
  RG,
  RF,
  UH,
  UJ,
  FB,
  FV,
  JN,
  JM,
  // }}}
  // 中指シフト (左) {{{
  D_Y,
  D_U,
  D_I,
  D_O,
  D_P,
  D_H,
  D_J,
  D_K,
  D_L,
  D_SCLN,
  D_QUOT,
  D_N,
  D_M,
  D_COMM,
  D_DOT,
  D_SLSH,
  // }}}
  // 中指シフト (右) {{{
  K_Q,
  K_W,
  K_E,
  K_R,
  K_T,
  K_A,
  K_S,
  K_F,
  K_G,
  K_Z,
  K_X,
  K_C,
  K_V,
  K_B,
  // }}}
  // 薬指シフト (左) {{{
  S_Y,
  S_U,
  S_I,
  S_O,
  S_P,
  S_H,
  S_J,
  S_L,
  S_SCLN,
  S_N,
  S_M,
  S_COMM,
  S_DOT,
  S_SLSH,
  // }}}
  // 薬指シフト (右) {{{
  L_Q,
  L_W,
  L_E,
  L_R,
  L_T,
  L_A,
  L_F,
  L_G,
  L_Z,
  L_X,
  L_C,
  L_V,
  L_B,
  // }}}
  // 中指上段シフト {{{
  I_Q,
  I_W,
  I_E,
  I_R,
  I_T,
  I_A,
  I_F,
  I_G,
  I_Z,
  I_X,
  I_C,
  I_V,
  I_B,
  // }}}
  // 薬指上段シフト {{{
  O_Q,
  O_W,
  O_E,
  O_R,
  O_T,
  O_A,
  O_F,
  O_G,
  O_Z,
  O_X,
  O_C,
  O_V,
  O_B,
  // }}}
  // 小指上段シフト (右) {{{
  P_Q,
  P_W,
  P_E,
  P_R,
  P_T,
  P_A,
  P_F,
  P_G,
  P_Z,
  P_C,
  P_V,
  P_B,
  // }}}
  // 小指上段シフト (左) {{{
  Q_Y,
  Q_U,
  Q_H,
  Q_J,
  Q_SCLN,
  Q_QUOT,
  Q_N,
  Q_M,
  Q_COMM,
  Q_DOT,
  Q_SLSH,
  // }}}
};

// }}}

// Sequences of keys {{{

// 制御用 {{{
const uint16_t PROGMEM base_df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM base_jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM shingeta_df_combo[] = {SG_D, SG_F, COMBO_END};
const uint16_t PROGMEM shingeta_jk_combo[] = {SG_J, SG_K, COMBO_END};
// }}}
// 記号類 {{{
const uint16_t PROGMEM fg_combo[] = {SG_F, SG_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {SG_H, SG_J, COMBO_END};
const uint16_t PROGMEM rg_combo[] = {SG_R, SG_G, COMBO_END};
const uint16_t PROGMEM rf_combo[] = {SG_R, SG_F, COMBO_END};
const uint16_t PROGMEM uh_combo[] = {SG_U, SG_H, COMBO_END};
const uint16_t PROGMEM uj_combo[] = {SG_U, SG_J, COMBO_END};
const uint16_t PROGMEM fb_combo[] = {SG_F, SG_B, COMBO_END};
const uint16_t PROGMEM fv_combo[] = {SG_F, SG_V, COMBO_END};
const uint16_t PROGMEM jn_combo[] = {SG_J, SG_N, COMBO_END};
const uint16_t PROGMEM jm_combo[] = {SG_J, SG_M, COMBO_END};
// }}}
// 中指シフト (左) {{{
CONST_COMBO(d_y,    SG_D, SG_Y)
CONST_COMBO(d_u,    SG_D, SG_U)
CONST_COMBO(d_i,    SG_D, SG_I)
CONST_COMBO(d_o,    SG_D, SG_O)
CONST_COMBO(d_p,    SG_D, SG_P)
CONST_COMBO(d_h,    SG_D, SG_H)
CONST_COMBO(d_j,    SG_D, SG_J)
CONST_COMBO(d_k,    SG_D, SG_K)
CONST_COMBO(d_l,    SG_D, SG_L)
CONST_COMBO(d_scln, SG_D, SG_SCLN)
CONST_COMBO(d_quot, SG_D, SG_QUOT)
CONST_COMBO(d_n,    SG_D, SG_N)
CONST_COMBO(d_m,    SG_D, SG_M)
CONST_COMBO(d_comm, SG_D, SG_COMM)
CONST_COMBO(d_dot,  SG_D, SG_DOT)
CONST_COMBO(d_slsh, SG_D, SG_SLSH)
// }}}
// 中指シフト (右) {{{
CONST_COMBO(k_q, SG_K, SG_Q)
CONST_COMBO(k_w, SG_K, SG_W)
CONST_COMBO(k_e, SG_K, SG_E)
CONST_COMBO(k_r, SG_K, SG_R)
CONST_COMBO(k_t, SG_K, SG_T)
CONST_COMBO(k_a, SG_K, SG_A)
CONST_COMBO(k_s, SG_K, SG_S)
CONST_COMBO(k_f, SG_K, SG_F)
CONST_COMBO(k_g, SG_K, SG_G)
CONST_COMBO(k_z, SG_K, SG_Z)
CONST_COMBO(k_x, SG_K, SG_X)
CONST_COMBO(k_c, SG_K, SG_C)
CONST_COMBO(k_v, SG_K, SG_V)
CONST_COMBO(k_b, SG_K, SG_B)
// }}}
// 薬指シフト (左) {{{
CONST_COMBO(s_y,    SG_S, SG_Y)
CONST_COMBO(s_u,    SG_S, SG_U)
CONST_COMBO(s_i,    SG_S, SG_I)
CONST_COMBO(s_o,    SG_S, SG_O)
CONST_COMBO(s_p,    SG_S, SG_P)
CONST_COMBO(s_h,    SG_S, SG_H)
CONST_COMBO(s_j,    SG_S, SG_J)
CONST_COMBO(s_l,    SG_S, SG_L)
CONST_COMBO(s_scln, SG_S, SG_SCLN)
CONST_COMBO(s_n,    SG_S, SG_N)
CONST_COMBO(s_m,    SG_S, SG_M)
CONST_COMBO(s_comm, SG_S, SG_COMM)
CONST_COMBO(s_dot,  SG_S, SG_DOT)
CONST_COMBO(s_slsh, SG_S, SG_SLSH)
// }}}
// 薬指シフト (右) {{{
CONST_COMBO(l_q, SG_L, SG_Q)
CONST_COMBO(l_w, SG_L, SG_W)
CONST_COMBO(l_e, SG_L, SG_E)
CONST_COMBO(l_r, SG_L, SG_R)
CONST_COMBO(l_t, SG_L, SG_T)
CONST_COMBO(l_a, SG_L, SG_A)
CONST_COMBO(l_f, SG_L, SG_F)
CONST_COMBO(l_g, SG_L, SG_G)
CONST_COMBO(l_z, SG_L, SG_Z)
CONST_COMBO(l_x, SG_L, SG_X)
CONST_COMBO(l_c, SG_L, SG_C)
CONST_COMBO(l_v, SG_L, SG_V)
CONST_COMBO(l_b, SG_L, SG_B)
// }}}
// 中指上段シフト {{{
CONST_COMBO(i_q, SG_I, SG_Q)
CONST_COMBO(i_w, SG_I, SG_W)
CONST_COMBO(i_e, SG_I, SG_E)
CONST_COMBO(i_r, SG_I, SG_R)
CONST_COMBO(i_t, SG_I, SG_T)
CONST_COMBO(i_a, SG_I, SG_A)
CONST_COMBO(i_f, SG_I, SG_F)
CONST_COMBO(i_g, SG_I, SG_G)
CONST_COMBO(i_z, SG_I, SG_Z)
CONST_COMBO(i_x, SG_I, SG_X)
CONST_COMBO(i_c, SG_I, SG_C)
CONST_COMBO(i_v, SG_I, SG_V)
CONST_COMBO(i_b, SG_I, SG_B)
// }}}
// 薬指上段シフト {{{
CONST_COMBO(o_q, SG_O, SG_Q)
CONST_COMBO(o_w, SG_O, SG_W)
CONST_COMBO(o_e, SG_O, SG_E)
CONST_COMBO(o_r, SG_O, SG_R)
CONST_COMBO(o_t, SG_O, SG_T)
CONST_COMBO(o_a, SG_O, SG_A)
CONST_COMBO(o_f, SG_O, SG_F)
CONST_COMBO(o_g, SG_O, SG_G)
CONST_COMBO(o_z, SG_O, SG_Z)
CONST_COMBO(o_x, SG_O, SG_X)
CONST_COMBO(o_c, SG_O, SG_C)
CONST_COMBO(o_v, SG_O, SG_V)
CONST_COMBO(o_b, SG_O, SG_B)
// }}}
// 小指上段シフト (右) {{{
CONST_COMBO(p_q, SG_P, SG_Q)
CONST_COMBO(p_w, SG_P, SG_W)
CONST_COMBO(p_e, SG_P, SG_E)
CONST_COMBO(p_r, SG_P, SG_R)
CONST_COMBO(p_t, SG_P, SG_T)
CONST_COMBO(p_a, SG_P, SG_A)
CONST_COMBO(p_f, SG_P, SG_F)
CONST_COMBO(p_g, SG_P, SG_G)
CONST_COMBO(p_z, SG_P, SG_Z)
CONST_COMBO(p_c, SG_P, SG_C)
CONST_COMBO(p_v, SG_P, SG_V)
CONST_COMBO(p_b, SG_P, SG_B)
// }}}
// 小指上段シフト (左) {{{
CONST_COMBO(q_y,    SG_Q, SG_Y)
CONST_COMBO(q_u,    SG_Q, SG_U)
CONST_COMBO(q_h,    SG_Q, SG_H)
CONST_COMBO(q_j,    SG_Q, SG_J)
CONST_COMBO(q_scln, SG_Q, SG_SCLN)
CONST_COMBO(q_quot, SG_Q, SG_QUOT)
CONST_COMBO(q_n,    SG_Q, SG_N)
CONST_COMBO(q_m,    SG_Q, SG_M)
CONST_COMBO(q_comm, SG_Q, SG_COMM)
CONST_COMBO(q_dot,  SG_Q, SG_DOT)
CONST_COMBO(q_slsh, SG_Q, SG_SLSH)
// }}}

// }}}

// Combos and its resulting action {{{

combo_t key_combos[] = {
  // 制御用 {{{
  [BASE_DF] = COMBO(base_df_combo, SG_OFF),
  [BASE_JK] = COMBO(base_jk_combo, SG_ON),
  [SHINGETA_DF] = COMBO(shingeta_df_combo, SG_OFF),
  [SHINGETA_JK] = COMBO(shingeta_jk_combo, SG_ON),
  // }}}
  // 記号類 {{{
  [FG] = COMBO(fg_combo, OUT_BRC),
  [HJ] = COMBO(hj_combo, OUT_PRN),
  [RG] = COMBO(rg_combo, OUT_MDOT),
  [RF] = COMBO(rf_combo, OUT_MDOT),
  [UH] = COMBO(uh_combo, OUT_SLSH),
  [UJ] = COMBO(uj_combo, OUT_SLSH),
  [FB] = COMBO(fb_combo, OUT_EXLM),
  [FV] = COMBO(fv_combo, OUT_EXLM),
  [JN] = COMBO(jn_combo, OUT_QUES),
  [JM] = COMBO(jm_combo, OUT_QUES),
  // }}}
  // 中指シフト (左) {{{
  COMBO_LIST(D_Y,    d_y,    OUT_WI),
  COMBO_LIST(D_U,    d_u,    OUT_PA),
  COMBO_LIST(D_I,    d_i,    OUT_YO),
  COMBO_LIST(D_O,    d_o,    OUT_MI),
  COMBO_LIST(D_P,    d_p,    OUT_WE),
  COMBO_LIST(D_H,    d_h,    OUT_HE),
  COMBO_LIST(D_J,    d_j,    OUT_A),
  COMBO_LIST(D_K,    d_k,    OUT_RE),
  COMBO_LIST(D_L,    d_l,    OUT_O),
  COMBO_LIST(D_SCLN, d_scln, OUT_E),
  COMBO_LIST(D_QUOT, d_quot, OUT_WHO),
  COMBO_LIST(D_N,    d_n,    OUT_SE),
  COMBO_LIST(D_M,    d_m,    OUT_NE),
  COMBO_LIST(D_COMM, d_comm, OUT_BE),
  COMBO_LIST(D_DOT,  d_dot,  OUT_PU),
  COMBO_LIST(D_SLSH, d_slsh, OUT_VU),
  // }}}
  // 中指シフト (右) {{{
  COMBO_LIST(K_Q, k_q, OUT_FA),
  COMBO_LIST(K_W, k_w, OUT_GO),
  COMBO_LIST(K_E, k_e, OUT_HU),
  COMBO_LIST(K_R, k_r, OUT_FI),
  COMBO_LIST(K_T, k_t, OUT_FE),
  COMBO_LIST(K_A, k_a, OUT_HO),
  COMBO_LIST(K_S, k_s, OUT_ZI),
  COMBO_LIST(K_F, k_f, OUT_MO),
  COMBO_LIST(K_G, k_g, OUT_YU),
  COMBO_LIST(K_Z, k_z, OUT_DU),
  COMBO_LIST(K_X, k_x, OUT_ZO),
  COMBO_LIST(K_C, k_c, OUT_BO),
  COMBO_LIST(K_V, k_v, OUT_MU),
  COMBO_LIST(K_B, k_b, OUT_FO),
  // }}}
  // 薬指シフト (左) {{{
  COMBO_LIST(S_Y,    s_y,    OUT_SYE),
  COMBO_LIST(S_U,    s_u,    OUT_PE),
  COMBO_LIST(S_I,    s_i,    OUT_DO),
  COMBO_LIST(S_O,    s_o,    OUT_YA),
  COMBO_LIST(S_P,    s_p,    OUT_ZYE),
  COMBO_LIST(S_H,    s_h,    OUT_BI),
  COMBO_LIST(S_J,    s_j,    OUT_RA),
  COMBO_LIST(S_L,    s_l,    OUT_SA),
  COMBO_LIST(S_SCLN, s_scln, OUT_SO),
  COMBO_LIST(S_N,    s_n,    OUT_WA),
  COMBO_LIST(S_M,    s_m,    OUT_DA),
  COMBO_LIST(S_COMM, s_comm, OUT_PI),
  COMBO_LIST(S_DOT,  s_dot,  OUT_PO),
  COMBO_LIST(S_SLSH, s_slsh, OUT_TYE),
  // }}}
  // 薬指シフト (右) {{{
  COMBO_LIST(L_Q, l_q, OUT_DI),
  COMBO_LIST(L_W, l_w, OUT_ME),
  COMBO_LIST(L_E, l_e, OUT_KE),
  COMBO_LIST(L_R, l_r, OUT_THI),
  COMBO_LIST(L_T, l_t, OUT_DHI),
  COMBO_LIST(L_A, l_a, OUT_WO),
  COMBO_LIST(L_F, l_f, OUT_RI),
  COMBO_LIST(L_G, l_g, OUT_ZU),
  COMBO_LIST(L_Z, l_z, OUT_ZE),
  COMBO_LIST(L_X, l_x, OUT_ZA),
  COMBO_LIST(L_C, l_c, OUT_GI),
  COMBO_LIST(L_V, l_v, OUT_RO),
  COMBO_LIST(L_B, l_b, OUT_NU),
  // }}}
  // 中指上段シフト {{{
  COMBO_LIST(I_Q, i_q, OUT_HYU),
  COMBO_LIST(I_W, i_w, OUT_SYU),
  COMBO_LIST(I_E, i_e, OUT_SYO),
  COMBO_LIST(I_R, i_r, OUT_KYU),
  COMBO_LIST(I_T, i_t, OUT_TYU),
  COMBO_LIST(I_A, i_a, OUT_HYO),
  COMBO_LIST(I_F, i_f, OUT_KYO),
  COMBO_LIST(I_G, i_g, OUT_TYO),
  COMBO_LIST(I_Z, i_z, OUT_HYA),
  COMBO_LIST(I_X, i_x, OUT_TWU),
  COMBO_LIST(I_C, i_c, OUT_SYA),
  COMBO_LIST(I_V, i_v, OUT_KYA),
  COMBO_LIST(I_B, i_b, OUT_TYA),
  // }}}
  // 薬指上段シフト {{{
  COMBO_LIST(O_Q, o_q, OUT_RYU),
  COMBO_LIST(O_W, o_w, OUT_ZYU),
  COMBO_LIST(O_E, o_e, OUT_ZYO),
  COMBO_LIST(O_R, o_r, OUT_GYU),
  COMBO_LIST(O_T, o_t, OUT_NYU),
  COMBO_LIST(O_A, o_a, OUT_RYO),
  COMBO_LIST(O_F, o_f, OUT_GYO),
  COMBO_LIST(O_G, o_g, OUT_NYO),
  COMBO_LIST(O_Z, o_z, OUT_RYA),
  COMBO_LIST(O_X, o_x, OUT_DWU),
  COMBO_LIST(O_C, o_c, OUT_ZYA),
  COMBO_LIST(O_V, o_v, OUT_GYA),
  COMBO_LIST(O_B, o_b, OUT_NYA),
  // }}}
  // 小指上段シフト (右) {{{
  COMBO_LIST(P_Q, p_q, OUT_PYU),
  COMBO_LIST(P_W, p_w, OUT_MYU),
  COMBO_LIST(P_E, p_e, OUT_MYO),
  COMBO_LIST(P_R, p_r, OUT_BYU),
  COMBO_LIST(P_T, p_t, OUT_DYU),
  COMBO_LIST(P_A, p_a, OUT_PYO),
  COMBO_LIST(P_F, p_f, OUT_BYO),
  COMBO_LIST(P_G, p_g, OUT_DYO),
  COMBO_LIST(P_Z, p_z, OUT_PYA),
  COMBO_LIST(P_C, p_c, OUT_MYA),
  COMBO_LIST(P_V, p_v, OUT_BYA),
  COMBO_LIST(P_B, p_b, OUT_DYA),
  // }}}
  // 小指上段シフト (左) {{{
  COMBO_LIST(Q_Y,    q_y,    OUT_XYA),
  COMBO_LIST(Q_U,    q_u,    OUT_XA),
  COMBO_LIST(Q_H,    q_h,    OUT_XYU),
  COMBO_LIST(Q_J,    q_j,    OUT_XI),
  COMBO_LIST(Q_SCLN, q_scln, OUT_GE),
  COMBO_LIST(Q_QUOT, q_quot, OUT_XWA),
  COMBO_LIST(Q_N,    q_n,    OUT_XYO),
  COMBO_LIST(Q_M,    q_m,    OUT_XU),
  COMBO_LIST(Q_COMM, q_comm, OUT_XE),
  COMBO_LIST(Q_DOT,  q_dot,  OUT_XO),
  COMBO_LIST(Q_SLSH, q_slsh, OUT_WHO),
  // }}}
};

// }}}

// }}}

// -- Combo Configuration {{{

// COMBO_TERM_PER_COMBO (Default: 50)
// コンボ受付時間を '50' にすると、Karabiner での同時押し判定に支障が出る。
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
    case BASE_DF:     return 20;
    case BASE_JK:     return 20;
    case SHINGETA_DF: return 20;
    case SHINGETA_JK: return 20;
  }
  return COMBO_TERM;
}

// // COMBO_MUST_TAP_PER_COMBO
// bool get_combo_must_tap(uint16_t index, combo_t *combo) {
//   switch (index) {
//     case BASE_DF:     return true;
//     case BASE_JK:     return true;
//     case SHINGETA_DF: return true;
//     case SHINGETA_JK: return true;
//   }
//   return false;
// }

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

// Hold On Other Key Press Mode
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Layer Keys
    case NAV_ESC: return true;
    case SYM_TAB: return true;
    case SYM_ENT: return true;
    case FN_GRV:  return true;

    // Mod Keys
    case RHYPR_TAB:  return true;
    case RHYPR_BSPC: return true;
    case LSFT_SPC:   return true;
    case RSFT_BSLS:  return true;
    case LCTL_ESC:   return true;
    case RCTL_ENT:   return true;
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

// }}}

// -- Keymaps {{{

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    RHYPR_TAB,           KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_Y, KC_U, KC_I,    KC_O,   KC_P,      KC_BSPC, KC_QUOT,
    LCTL_ESC,            KC_A, KC_S, KC_D, KC_F, KC_G, KC_RBRC, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,            RCTL_ENT,
    KC_LSFT,   MO(_NAV), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_GRV,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,            FN_BSLS,
    MO(_FN),   XXXXXXX,  LGUI_LNG2,        LSFT_SPC,   RCTL_TAB,      SYM_ENT,               RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

  [_SHINGETA] = LAYOUT(
    RHYPR_TAB,           SG_Q, SG_W, SG_E, SG_R, SG_T, KC_LBRC, SG_Y, SG_U, SG_I,    SG_O,   SG_P,      KC_BSPC, SG_QUOT,
    LCTL_ESC,            SG_A, SG_S, SG_D, SG_F, SG_G, KC_RBRC, SG_H, SG_J, SG_K,    SG_L,   SG_SCLN,            RCTL_ENT,
    KC_LSFT,   MO(_NAV), SG_Z, SG_X, SG_C, SG_V, SG_B, KC_GRV,  SG_N, SG_M, SG_COMM, SG_DOT, SG_SLSH,            FN_BSLS,
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
    XXXXXXX,          LCA(KC_U),    LCA(KC_I), XXXXXXX,   MEH(KC_C),    C(KC_1), XXXXXXX, C(KC_4), MEH(KC_C),   A(KC_UP),   XXXXXXX, XXXXXXX, LCA(KC_BSPC), XXXXXXX,
    XXXXXXX,          LCA(KC_LEFT), LCA(KC_D), LCA(KC_G), LCA(KC_RGHT), C(KC_2), XXXXXXX, C(KC_5), LCA(KC_C),   A(KC_DOWN), XXXXXXX, XXXXXXX,               MEH(KC_ENT),
    XXXXXXX, XXXXXXX, LCA(KC_Z),    LCA(KC_X), LCA(KC_V), LCA(KC_B),    C(KC_3), XXXXXXX, C(KC_6), LCA(KC_ENT), LCG(KC_F),  XXXXXXX, XXXXXXX,               XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,               XXXXXXX,          XXXXXXX,                          XXXXXXX, XXXXXXX,      XXXXXXX
  ),

  [_FN] = LAYOUT(
    LCG(KC_Q),          KC_F1, KC_F2,  KC_F3,  KC_F4,  BASE,    XXXXXXX, LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT,
    XXXXXXX,            KC_F5, KC_F6,  KC_F7,  KC_F8,  SHING,   XXXXXXX, LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,          KC_MPLY,
    XXXXXXX,   XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
    _______,   XXXXXXX, XXXXXXX,               XXXXXXX,         QK_BOOT,            XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
  ),

};

// }}}
