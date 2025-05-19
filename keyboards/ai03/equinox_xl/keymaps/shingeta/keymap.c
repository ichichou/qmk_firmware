// KB: Equinox XL
// KM: shingeta

// コンボが利かない。
// 単打の場合は正しく入力される。

// -km shingeta_bk は正常に動作する。要比較。
// まずは Combo list を移植してみるのがいい。
// -> 移植した。動作を検証。

#include QMK_KEYBOARD_H
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define __________________FN_EQUINOX_R1____________ LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_EQUINOX_R2____________ LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV
#define __________________FN_EQUINOX_R3____________ LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE

// Combo list {{{

enum combos {
  // 制御用 {{{
  BASE_DF,
  BASE_JK,
  SHINGETA_DF,
  SHINGETA_JK,
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
  // K_D,
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
  // S_K,
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
  // L_S,
  // L_D,
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
  Q_N,
  Q_M,
  Q_COMM,
  Q_DOT,
  Q_SLSH,
  // }}}
};

// }}}

// Sequences of keys {{{

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

// Combos and its resulting action {{{

combo_t key_combos[] = {
  // 制御キー {{{
  [BASE_DF] = COMBO(base_df_combo, SG_OFF),
  [BASE_JK] = COMBO(base_jk_combo, SG_ON),
  [SHINGETA_DF] = COMBO(shingeta_df_combo, SG_OFF),
  [SHINGETA_JK] = COMBO(shingeta_jk_combo, SG_ON),
  // }}}
  // 中指シフト (左) {{{
  [D_Y]    = COMBO(d_y_combo,    OUT_WI),   // うぃ
  [D_U]    = COMBO(d_u_combo,    OUT_PA),   // ぱ
  [D_I]    = COMBO(d_i_combo,    OUT_YO),   // よ
  [D_O]    = COMBO(d_o_combo,    OUT_MI),   // み
  [D_P]    = COMBO(d_p_combo,    OUT_WE),   // うぇ
  [D_H]    = COMBO(d_h_combo,    OUT_HE),   // へ
  [D_J]    = COMBO(d_j_combo,    OUT_A),    // あ
  [D_K]    = COMBO(d_k_combo,    OUT_RE),   // れ
  [D_L]    = COMBO(d_l_combo,    OUT_O),    // お
  [D_SCLN] = COMBO(d_scln_combo, OUT_E),    // え
  [D_QUOT] = COMBO(d_quot_combo, OUT_WHO),  // うぉ
  [D_N]    = COMBO(d_n_combo,    OUT_SE),   // せ
  [D_M]    = COMBO(d_m_combo,    OUT_NE),   // ね
  [D_COMM] = COMBO(d_comm_combo, OUT_BE),   // べ
  [D_DOT]  = COMBO(d_dot_combo,  OUT_PU),   // ぷ
  [D_SLSH] = COMBO(d_slsh_combo, OUT_VU),   // ヴ
  // }}}
  // 中指シフト (右) {{{
  [K_Q] = COMBO(k_q_combo, OUT_FA),  // ふぁ
  [K_W] = COMBO(k_w_combo, OUT_GO),  // ご
  [K_E] = COMBO(k_e_combo, OUT_HU),  // ふ
  [K_R] = COMBO(k_r_combo, OUT_FI),  // ふぃ
  [K_T] = COMBO(k_t_combo, OUT_FE),  // ふぇ
  [K_A] = COMBO(k_a_combo, OUT_HO),  // ほ
  [K_S] = COMBO(k_s_combo, OUT_ZI),  // じ
  // [K_D] = COMBO(k_d_combo, OUT_RE),  // れ
  [K_F] = COMBO(k_f_combo, OUT_MO),  // も
  [K_G] = COMBO(k_g_combo, OUT_YU),  // ゆ
  [K_Z] = COMBO(k_z_combo, OUT_DU),  // づ
  [K_X] = COMBO(k_x_combo, OUT_ZO),  // ぞ
  [K_C] = COMBO(k_c_combo, OUT_BO),  // ぼ
  [K_V] = COMBO(k_v_combo, OUT_MU),  // む
  [K_B] = COMBO(k_b_combo, OUT_FO),  // ふぉ
  // }}}
  // 薬指シフト (左) {{{
  [S_Y]    = COMBO(s_y_combo,    OUT_SYE),  // しぇ
  [S_U]    = COMBO(s_u_combo,    OUT_PE),   // ぺ
  [S_I]    = COMBO(s_i_combo,    OUT_DO),   // ど
  [S_O]    = COMBO(s_o_combo,    OUT_YA),   // や
  [S_P]    = COMBO(s_p_combo,    OUT_ZYE),  // じぇ
  [S_H]    = COMBO(s_h_combo,    OUT_BI),   // び
  [S_J]    = COMBO(s_j_combo,    OUT_RA),   // ら
  // [S_K]    = COMBO(s_k_combo,    OUT_ZI),   // じ
  [S_L]    = COMBO(s_l_combo,    OUT_SA),   // さ
  [S_SCLN] = COMBO(s_scln_combo, OUT_SO),   // そ
  [S_N]    = COMBO(s_n_combo,    OUT_WA),   // わ
  [S_M]    = COMBO(s_m_combo,    OUT_DA),   // だ
  [S_COMM] = COMBO(s_comm_combo, OUT_PI),   // ぴ
  [S_DOT]  = COMBO(s_dot_combo,  OUT_PO),   // ぽ
  [S_SLSH] = COMBO(s_slsh_combo, OUT_TYE),  // ちぇ
  // }}}
  // 薬指シフト (右) {{{
  [L_Q] = COMBO(l_q_combo, OUT_DI),   // ぢ
  [L_W] = COMBO(l_w_combo, OUT_ME),   // め
  [L_E] = COMBO(l_e_combo, OUT_KE),   // け
  [L_R] = COMBO(l_r_combo, OUT_THI),  // てぃ
  [L_T] = COMBO(l_t_combo, OUT_DHI),  // でぃ
  [L_A] = COMBO(l_a_combo, OUT_WO),   // を
  // [L_S] = COMBO(l_s_combo, OUT_SA),   // さ
  // [L_D] = COMBO(l_d_combo, OUT_O),    // お
  [L_F] = COMBO(l_f_combo, OUT_RI),   // り
  [L_G] = COMBO(l_g_combo, OUT_ZU),   // ず
  [L_Z] = COMBO(l_z_combo, OUT_ZE),   // ぜ
  [L_X] = COMBO(l_x_combo, OUT_ZA),   // ざ
  [L_C] = COMBO(l_c_combo, OUT_GI),   // ぎ
  [L_V] = COMBO(l_v_combo, OUT_RO),   // ろ
  [L_B] = COMBO(l_b_combo, OUT_NU),   // ぬ
  // }}}
  // 中指上段シフト {{{
  [I_Q] = COMBO(i_q_combo, OUT_HYU),  // ひゅ
  [I_W] = COMBO(i_w_combo, OUT_SYU),  // しゅ
  [I_E] = COMBO(i_e_combo, OUT_SYO),  // しょ
  [I_R] = COMBO(i_r_combo, OUT_KYU),  // きゅ
  [I_T] = COMBO(i_t_combo, OUT_TYU),  // ちゅ
  [I_A] = COMBO(i_a_combo, OUT_HYO),  // ひょ
  [I_F] = COMBO(i_f_combo, OUT_KYO),  // きょ
  [I_G] = COMBO(i_g_combo, OUT_TYO),  // ちょ
  [I_Z] = COMBO(i_z_combo, OUT_HYA),  // ひゃ
  [I_X] = COMBO(i_x_combo, OUT_TWU),  // とぅ
  [I_C] = COMBO(i_c_combo, OUT_SYA),  // しゃ
  [I_V] = COMBO(i_v_combo, OUT_KYA),  // きゃ
  [I_B] = COMBO(i_b_combo, OUT_TYA),  // ちゃ
  // }}}
  // 薬指上段シフト {{{
  [O_Q] = COMBO(o_q_combo, OUT_RYU),  // りゅ
  [O_W] = COMBO(o_w_combo, OUT_ZYU),  // じゅ
  [O_E] = COMBO(o_e_combo, OUT_ZYO),  // じょ
  [O_R] = COMBO(o_r_combo, OUT_GYU),  // ぎゅ
  [O_T] = COMBO(o_t_combo, OUT_NYU),  // にゅ
  [O_A] = COMBO(o_a_combo, OUT_RYO),  // りょ
  [O_F] = COMBO(o_f_combo, OUT_GYO),  // ぎょ
  [O_G] = COMBO(o_g_combo, OUT_NYO),  // にょ
  [O_Z] = COMBO(o_z_combo, OUT_RYA),  // りゃ
  [O_X] = COMBO(o_x_combo, OUT_DWU),  // どぅ
  [O_C] = COMBO(o_c_combo, OUT_ZYA),  // じゃ
  [O_V] = COMBO(o_v_combo, OUT_GYA),  // ぎゃ
  [O_B] = COMBO(o_b_combo, OUT_NYA),  // にゃ
  // }}}
  // 小指上段シフト (右) {{{
  [P_Q] = COMBO(p_q_combo, OUT_PYU),  // ぴゅ
  [P_W] = COMBO(p_w_combo, OUT_MYU),  // みゅ
  [P_E] = COMBO(p_e_combo, OUT_MYO),  // みょ
  [P_R] = COMBO(p_r_combo, OUT_BYU),  // びゅ
  [P_T] = COMBO(p_t_combo, OUT_DYU),  // ぢゅ
  [P_A] = COMBO(p_a_combo, OUT_PYO),  // ぴょ
  [P_F] = COMBO(p_f_combo, OUT_BYO),  // びょ
  [P_G] = COMBO(p_g_combo, OUT_DYO),  // ぢょ
  [P_Z] = COMBO(p_z_combo, OUT_PYA),  // ぴゃ
  [P_C] = COMBO(p_c_combo, OUT_MYA),  // みゃ
  [P_V] = COMBO(p_v_combo, OUT_BYA),  // びゃ
  [P_B] = COMBO(p_b_combo, OUT_DYA),  // ぢゃ
  // }}}
  // 小指上段シフト (左) {{{
  [Q_Y]    = COMBO(q_y_combo,    OUT_XYA),  // ゃ
  [Q_U]    = COMBO(q_u_combo,    OUT_XA),   // ぁ
  [Q_H]    = COMBO(q_h_combo,    OUT_XYU),  // ゅ
  [Q_J]    = COMBO(q_j_combo,    OUT_XI),   // ぃ
  [Q_N]    = COMBO(q_n_combo,    OUT_XYO),  // ょ
  [Q_M]    = COMBO(q_m_combo,    OUT_XU),   // ぅ
  [Q_COMM] = COMBO(q_comm_combo, OUT_XE),   // ぇ
  [Q_DOT]  = COMBO(q_dot_combo,  OUT_XO),   // ぉ
  [Q_SLSH] = COMBO(q_slsh_combo, OUT_XWA),  // ゎ
  // }}}
};

// }}}

// Combo Configurations {{{

// コンパイルエラーになる。
// Combo list で定義した名前で case XXXX: とすれば改善するかも。
// -> 修正した。要検証。
// -> コンパイルは通った。

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
  switch (combo_index) {
    case BASE_DF:     return 20;
    case BASE_JK:     return 20;
    case SHINGETA_DF: return 20;
    case SHINGETA_JK: return 20;
  }
  return COMBO_TERM;
}

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
