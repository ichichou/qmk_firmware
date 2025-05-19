// KB: Equinox XL
// KM: shingeta

// コンボが利かない。
// 単打の場合は正しく入力される。

// -km shingeta_bk は正常に動作する。要比較。
// まずは Combo list を移植してみるのがいい。

#include QMK_KEYBOARD_H
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define __________________FN_EQUINOX_R1____________ LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_EQUINOX_R2____________ LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV
#define __________________FN_EQUINOX_R3____________ LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE

// -- Combos {{{

// Sequences of keys -----------------------------

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

// Combos and its resulting action ---------------

combo_t key_combos[] = {
  // 制御キー {{{
  COMBO(base_df_combo,     SG_OFF),
  COMBO(base_jk_combo,     SG_ON),
  COMBO(shingeta_df_combo, SG_OFF),
  COMBO(shingeta_jk_combo, SG_ON),
  // }}}
  // 中指シフト (左) {{{
  COMBO(d_y_combo,    OUT_WI),   // うぃ
  COMBO(d_u_combo,    OUT_PA),   // ぱ
  COMBO(d_i_combo,    OUT_YO),   // よ
  COMBO(d_o_combo,    OUT_MI),   // み
  COMBO(d_p_combo,    OUT_WE),   // うぇ
  COMBO(d_h_combo,    OUT_HE),   // へ
  COMBO(d_j_combo,    OUT_A),    // あ
  COMBO(d_k_combo,    OUT_RE),   // れ
  COMBO(d_l_combo,    OUT_O),    // お
  COMBO(d_scln_combo, OUT_E),    // え
  COMBO(d_quot_combo, OUT_WHO),  // うぉ
  COMBO(d_n_combo,    OUT_SE),   // せ
  COMBO(d_m_combo,    OUT_NE),   // ね
  COMBO(d_comm_combo, OUT_BE),   // べ
  COMBO(d_dot_combo,  OUT_PU),   // ぷ
  COMBO(d_slsh_combo, OUT_VU),   // ヴ
  // }}}
  // 中指シフト (右) {{{
  COMBO(k_q_combo, OUT_FA),  // ふぁ
  COMBO(k_w_combo, OUT_GO),  // ご
  COMBO(k_e_combo, OUT_HU),  // ふ
  COMBO(k_r_combo, OUT_FI),  // ふぃ
  COMBO(k_t_combo, OUT_FE),  // ふぇ
  COMBO(k_a_combo, OUT_HO),  // ほ
  COMBO(k_s_combo, OUT_ZI),  // じ
  // COMBO(k_d_combo, OUT_RE),  // れ
  COMBO(k_f_combo, OUT_MO),  // も
  COMBO(k_g_combo, OUT_YU),  // ゆ
  COMBO(k_z_combo, OUT_DU),  // づ
  COMBO(k_x_combo, OUT_ZO),  // ぞ
  COMBO(k_c_combo, OUT_BO),  // ぼ
  COMBO(k_v_combo, OUT_MU),  // む
  COMBO(k_b_combo, OUT_FO),  // ふぉ
  // }}}
  // 薬指シフト (左) {{{
  COMBO(s_y_combo,    OUT_SYE),  // しぇ
  COMBO(s_u_combo,    OUT_PE),   // ぺ
  COMBO(s_i_combo,    OUT_DO),   // ど
  COMBO(s_o_combo,    OUT_YA),   // や
  COMBO(s_p_combo,    OUT_ZYE),  // じぇ
  COMBO(s_h_combo,    OUT_BI),   // び
  COMBO(s_j_combo,    OUT_RA),   // ら
  // COMBO(s_k_combo,    OUT_ZI),   // じ
  COMBO(s_l_combo,    OUT_SA),   // さ
  COMBO(s_scln_combo, OUT_SO),   // そ
  COMBO(s_n_combo,    OUT_WA),   // わ
  COMBO(s_m_combo,    OUT_DA),   // だ
  COMBO(s_comm_combo, OUT_PI),   // ぴ
  COMBO(s_dot_combo,  OUT_PO),   // ぽ
  COMBO(s_slsh_combo, OUT_TYE),  // ちぇ
  // }}}
  // 薬指シフト (右) {{{
  COMBO(l_q_combo, OUT_DI),   // ぢ
  COMBO(l_w_combo, OUT_ME),   // め
  COMBO(l_e_combo, OUT_KE),   // け
  COMBO(l_r_combo, OUT_THI),  // てぃ
  COMBO(l_t_combo, OUT_DHI),  // でぃ
  COMBO(l_a_combo, OUT_WO),   // を
  // COMBO(l_s_combo, OUT_SA),   // さ
  // COMBO(l_d_combo, OUT_O),    // お
  COMBO(l_f_combo, OUT_RI),   // り
  COMBO(l_g_combo, OUT_ZU),   // ず
  COMBO(l_z_combo, OUT_ZE),   // ぜ
  COMBO(l_x_combo, OUT_ZA),   // ざ
  COMBO(l_c_combo, OUT_GI),   // ぎ
  COMBO(l_v_combo, OUT_RO),   // ろ
  COMBO(l_b_combo, OUT_NU),   // ぬ
  // }}}
  // 中指上段シフト {{{
  COMBO(i_q_combo, OUT_HYU),  // ひゅ
  COMBO(i_w_combo, OUT_SYU),  // しゅ
  COMBO(i_e_combo, OUT_SYO),  // しょ
  COMBO(i_r_combo, OUT_KYU),  // きゅ
  COMBO(i_t_combo, OUT_TYU),  // ちゅ
  COMBO(i_a_combo, OUT_HYO),  // ひょ
  COMBO(i_f_combo, OUT_KYO),  // きょ
  COMBO(i_g_combo, OUT_TYO),  // ちょ
  COMBO(i_z_combo, OUT_HYA),  // ひゃ
  COMBO(i_x_combo, OUT_TWU),  // とぅ
  COMBO(i_c_combo, OUT_SYA),  // しゃ
  COMBO(i_v_combo, OUT_KYA),  // きゃ
  COMBO(i_b_combo, OUT_TYA),  // ちゃ
  // }}}
  // 薬指上段シフト {{{
  COMBO(o_q_combo, OUT_RYU),  // りゅ
  COMBO(o_w_combo, OUT_ZYU),  // じゅ
  COMBO(o_e_combo, OUT_ZYO),  // じょ
  COMBO(o_r_combo, OUT_GYU),  // ぎゅ
  COMBO(o_t_combo, OUT_NYU),  // にゅ
  COMBO(o_a_combo, OUT_RYO),  // りょ
  COMBO(o_f_combo, OUT_GYO),  // ぎょ
  COMBO(o_g_combo, OUT_NYO),  // にょ
  COMBO(o_z_combo, OUT_RYA),  // りゃ
  COMBO(o_x_combo, OUT_DWU),  // どぅ
  COMBO(o_c_combo, OUT_ZYA),  // じゃ
  COMBO(o_v_combo, OUT_GYA),  // ぎゃ
  COMBO(o_b_combo, OUT_NYA),  // にゃ
  // }}}
  // 小指上段シフト (右) {{{
  COMBO(p_q_combo, OUT_PYU),  // ぴゅ
  COMBO(p_w_combo, OUT_MYU),  // みゅ
  COMBO(p_e_combo, OUT_MYO),  // みょ
  COMBO(p_r_combo, OUT_BYU),  // びゅ
  COMBO(p_t_combo, OUT_DYU),  // ぢゅ
  COMBO(p_a_combo, OUT_PYO),  // ぴょ
  COMBO(p_f_combo, OUT_BYO),  // びょ
  COMBO(p_g_combo, OUT_DYO),  // ぢょ
  COMBO(p_z_combo, OUT_PYA),  // ぴゃ
  COMBO(p_c_combo, OUT_MYA),  // みゃ
  COMBO(p_v_combo, OUT_BYA),  // びゃ
  COMBO(p_b_combo, OUT_DYA),  // ぢゃ
  // }}}
  // 小指上段シフト (左) {{{
  COMBO(q_y_combo,    OUT_XYA),  // ゃ
  COMBO(q_u_combo,    OUT_XA),   // ぁ
  COMBO(q_h_combo,    OUT_XYU),  // ゅ
  COMBO(q_j_combo,    OUT_XI),   // ぃ
  COMBO(q_n_combo,    OUT_XYO),  // ょ
  COMBO(q_m_combo,    OUT_XU),   // ぅ
  COMBO(q_comm_combo, OUT_XE),   // ぇ
  COMBO(q_dot_combo,  OUT_XO),   // ぉ
  COMBO(q_slsh_combo, OUT_XWA),  // ゎ
  // }}}
};

// }}}

// -- Combo Configurations {{{

// コンパイルエラーになる。
// Combo list で定義した名前で case XXXX: とすれば改善するかも。

// uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
//   switch (combo_index) {
//     case base_df_combo:     return 20;
//     case base_jk_combo:     return 20;
//     case shingeta_df_combo: return 20;
//     case shingeta_jk_combo: return 20;
//   }
//   return COMBO_TERM;
// }

// }}}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_wrapper(
    RHYPR_TAB,     __________________BASE_L1__________________, KC_LBRC, __________________BASE_R1__________________, KC_BSPC, KC_QUOT,
    LCTL_ESC,      __________________BASE_L2__________________, KC_RBRC, __________________BASE_R2__________________,          RCTL_ENT,
    LSFT_CW,  NAV, __________________BASE_L3__________________, KC_GRV,  __________________BASE_R3__________________,          FN_BSLS,
    FN, XXXXXXX, LGUI_LNG2,                           LSFT_SPC, RCTL_TAB, SYM_ENT,                         RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

  [_SHINGETA] = LAYOUT_wrapper(
    RHYPR_TAB,     __________________SHINGETA_L1______________, KC_LBRC, __________________SHINGETA_R1______________, KC_BSPC, SG_QUOT,
    LCTL_ESC,      __________________SHINGETA_L2______________, KC_RBRC, __________________SHINGETA_R2______________,          RCTL_ENT,
    LSFT_CW,  NAV, __________________SHINGETA_L3______________, KC_GRV,  __________________SHINGETA_R3______________,          FN_BSLS,
    FN, XXXXXXX, LGUI_LNG2,                           LSFT_SPC, RCTL_TAB, SYM_ENT,                         RGUI_LNG1, XXXXXXX, RALT_GRV
  ),

  [_NAV] = LAYOUT_wrapper(
    _______,          __________________NAV_L1___________________, XXXXXXX, __________________NAV_R1___________________, G(KC_UP), G(KC_DOWN),
    _______,          __________________NAV_L2___________________, XXXXXXX, __________________NAV_R2___________________,           _______,
    _______, _______, __________________NAV_L3___________________, XXXXXXX, __________________NAV_R3___________________,           _______,
    _______, XXXXXXX, _______,                            _______, _______, _______,                            _______, XXXXXXX,  _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______,          __________________SYM_L1___________________, XXXXXXX, __________________SYM_R1___________________, _______, KC_QUOT,
    _______,          __________________SYM_L2___________________, XXXXXXX, __________________SYM_R2___________________,          _______,
    _______, _______, __________________SYM_L3___________________, XXXXXXX, __________________SYM_R3___________________,          _______,
    _______, XXXXXXX, _______,                            _______, _______, _______,                            _______, XXXXXXX, _______
  ),

  [_WIN] = LAYOUT_wrapper(
    XXXXXXX,          __________________WIN_L1___________________, XXXXXXX, __________________WIN_R1___________________, LCA(KC_BSPC), XXXXXXX,
    XXXXXXX,          __________________WIN_L2___________________, XXXXXXX, __________________WIN_R2___________________,               MEH(KC_ENT),
    XXXXXXX, _______, __________________WIN_L3___________________, XXXXXXX, __________________WIN_R3___________________,               XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, _______,                            XXXXXXX, XXXXXXX,      XXXXXXX
  ),

  [_FN] = LAYOUT_wrapper(
    LCG(KC_Q),         __________________FN_L1____________________, SG_OFF,  __________________FN_EQUINOX_R1____________, XXXXXXX, KC_MNXT,
    XXXXXXX,           __________________FN_L2____________________, SG_ON,   __________________FN_EQUINOX_R2____________,          KC_MPLY,
    XXXXXXX,  XXXXXXX, __________________FN_L3____________________, XXXXXXX, __________________FN_EQUINOX_R3____________,          _______,
    _______,  XXXXXXX, XXXXXXX,                             EE_CLR, QK_BOOT, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX
  ),

};
