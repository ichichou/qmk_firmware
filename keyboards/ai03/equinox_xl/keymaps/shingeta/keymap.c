// KB: Equinox XL
// KM: shingeta

#include QMK_KEYBOARD_H
#include "ichichou.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define __________________FN_EQUINOX_R1____________ LSG(KC_2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________FN_EQUINOX_R2____________ LSG(KC_3), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV
#define __________________FN_EQUINOX_R3____________ LSG(KC_4), XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE

// -- Combo List {{{

enum combos {
  // レイヤー {{{
  BASE_SD,
  BASE_KL,
  BASE_WE,
  BASE_IO,
  SG_SD,
  SG_KL,
  SG_WE,
  SG_IO,
  // }}}
  // 制御キー {{{
  BASE_DF,
  BASE_JK,
  BASE_VM,
  BASE_VN,
  SG_DF,
  SG_JK,
  SG_VM,
  SG_VN,
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
  D_7,
  D_8,
  D_9,
  D_0,
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
  K_1,
  K_2,
  K_3,
  K_4,
  K_5,
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
  S_7,
  S_8,
  S_9,
  S_0,
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
  L_1,
  L_2,
  L_3,
  L_4,
  L_5,
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
  I_1,
  I_2,
  I_3,
  I_4,
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
  O_1,
  O_2,
  O_3,
  O_4,
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
  // 記号 {{{
  R_G,
  R_F,
  U_H,
  F_B,
  F_V,
  J_N,
  F_G,
  H_J,
  // }}}
};

// }}}

// -- Sequences of Keys {{{

// レイヤー {{{
const uint16_t PROGMEM base_sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM base_kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM base_we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM base_io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM sg_sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM sg_kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM sg_we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sg_io_combo[] = {KC_I, KC_O, COMBO_END};
// }}}
// 制御キー {{{
const uint16_t PROGMEM base_df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM base_jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM base_vm_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM base_vn_combo[] = {KC_V, KC_N, COMBO_END};
const uint16_t PROGMEM sg_df_combo[] = {SG_D, SG_F, COMBO_END};
const uint16_t PROGMEM sg_jk_combo[] = {SG_J, SG_K, COMBO_END};
const uint16_t PROGMEM sg_vm_combo[] = {SG_V, SG_M, COMBO_END};
const uint16_t PROGMEM sg_vn_combo[] = {SG_V, SG_N, COMBO_END};
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
const uint16_t PROGMEM d_7_combo[]    = {SG_D, KC_7,    COMBO_END};
const uint16_t PROGMEM d_8_combo[]    = {SG_D, KC_8,    COMBO_END};
const uint16_t PROGMEM d_9_combo[]    = {SG_D, KC_9,    COMBO_END};
const uint16_t PROGMEM d_0_combo[]    = {SG_D, KC_0,    COMBO_END};
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
const uint16_t PROGMEM k_1_combo[] = {SG_K, KC_1, COMBO_END};
const uint16_t PROGMEM k_2_combo[] = {SG_K, KC_2, COMBO_END};
const uint16_t PROGMEM k_3_combo[] = {SG_K, KC_3, COMBO_END};
const uint16_t PROGMEM k_4_combo[] = {SG_K, KC_4, COMBO_END};
const uint16_t PROGMEM k_5_combo[] = {SG_K, KC_5, COMBO_END};
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
const uint16_t PROGMEM s_7_combo[]    = {SG_S, KC_7,    COMBO_END};
const uint16_t PROGMEM s_8_combo[]    = {SG_S, KC_8,    COMBO_END};
const uint16_t PROGMEM s_9_combo[]    = {SG_S, KC_9,    COMBO_END};
const uint16_t PROGMEM s_0_combo[]    = {SG_S, KC_0,    COMBO_END};
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
const uint16_t PROGMEM l_1_combo[] = {SG_L, KC_1, COMBO_END};
const uint16_t PROGMEM l_2_combo[] = {SG_L, KC_2, COMBO_END};
const uint16_t PROGMEM l_3_combo[] = {SG_L, KC_3, COMBO_END};
const uint16_t PROGMEM l_4_combo[] = {SG_L, KC_4, COMBO_END};
const uint16_t PROGMEM l_5_combo[] = {SG_L, KC_5, COMBO_END};
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
const uint16_t PROGMEM i_1_combo[] = {SG_I, KC_1, COMBO_END};
const uint16_t PROGMEM i_2_combo[] = {SG_I, KC_2, COMBO_END};
const uint16_t PROGMEM i_3_combo[] = {SG_I, KC_3, COMBO_END};
const uint16_t PROGMEM i_4_combo[] = {SG_I, KC_4, COMBO_END};
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
const uint16_t PROGMEM o_1_combo[] = {SG_O, KC_1, COMBO_END};
const uint16_t PROGMEM o_2_combo[] = {SG_O, KC_2, COMBO_END};
const uint16_t PROGMEM o_3_combo[] = {SG_O, KC_3, COMBO_END};
const uint16_t PROGMEM o_4_combo[] = {SG_O, KC_4, COMBO_END};
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
// 記号 {{{
const uint16_t PROGMEM r_g_combo[] = {SG_R, SG_G, COMBO_END};
const uint16_t PROGMEM r_f_combo[] = {SG_R, SG_F, COMBO_END};
const uint16_t PROGMEM u_h_combo[] = {SG_U, SG_H, COMBO_END};
const uint16_t PROGMEM f_b_combo[] = {SG_F, SG_B, COMBO_END};
const uint16_t PROGMEM f_v_combo[] = {SG_F, SG_V, COMBO_END};
const uint16_t PROGMEM j_n_combo[] = {SG_J, SG_N, COMBO_END};
const uint16_t PROGMEM f_g_combo[] = {SG_F, SG_G, COMBO_END};
const uint16_t PROGMEM h_j_combo[] = {SG_H, SG_J, COMBO_END};
// }}}

// }}}

// -- Resulting Action {{{

combo_t key_combos[] = {
  // レイヤー {{{
  [BASE_SD] = COMBO(base_sd_combo, MO(_NAV)),
  [BASE_KL] = COMBO(base_kl_combo, MO(_NAV)),
  [BASE_WE] = COMBO(base_we_combo, MO(_WIN)),
  [BASE_IO] = COMBO(base_io_combo, MO(_WIN)),
  [SG_SD] = COMBO(base_sd_combo, MO(_NAV)),
  [SG_KL] = COMBO(base_kl_combo, MO(_NAV)),
  [SG_WE] = COMBO(base_we_combo, MO(_WIN)),
  [SG_IO] = COMBO(base_io_combo, MO(_WIN)),
  // }}}
  // 制御キー {{{
  [BASE_DF] = COMBO(base_df_combo, SG_OFF),
  [BASE_JK] = COMBO(base_jk_combo, SG_ON),
  [BASE_VM] = COMBO(base_vm_combo, KC_ENT),
  [BASE_VN] = COMBO(base_vn_combo, KC_ENT),
  [SG_DF] = COMBO(sg_df_combo, SG_OFF),
  [SG_JK] = COMBO(sg_jk_combo, SG_ON),
  [SG_VM] = COMBO(sg_vm_combo, KC_ENT),
  [SG_VN] = COMBO(sg_vn_combo, KC_ENT),
  // }}}
  // 中指シフト (左) {{{
  [D_Y]    = COMBO(d_y_combo,    OUT_WI),    // うぃ
  [D_U]    = COMBO(d_u_combo,    OUT_PA),    // ぱ
  [D_I]    = COMBO(d_i_combo,    OUT_YO),    // よ
  [D_O]    = COMBO(d_o_combo,    OUT_MI),    // み
  [D_P]    = COMBO(d_p_combo,    OUT_WE),    // うぇ
  [D_H]    = COMBO(d_h_combo,    OUT_HE),    // へ
  [D_J]    = COMBO(d_j_combo,    OUT_A),     // あ
  [D_K]    = COMBO(d_k_combo,    OUT_RE),    // れ
  [D_L]    = COMBO(d_l_combo,    OUT_O),     // お
  [D_SCLN] = COMBO(d_scln_combo, OUT_E),     // え
  [D_QUOT] = COMBO(d_quot_combo, OUT_WHO),   // うぉ
  [D_N]    = COMBO(d_n_combo,    OUT_SE),    // せ
  [D_M]    = COMBO(d_m_combo,    OUT_NE),    // ね
  [D_COMM] = COMBO(d_comm_combo, OUT_BE),    // べ
  [D_DOT]  = COMBO(d_dot_combo,  OUT_PU),    // ぷ
  [D_SLSH] = COMBO(d_slsh_combo, OUT_VU),    // ヴ
  [D_7]    = COMBO(d_7_combo,    OUT_COMM),  // 、
  [D_8]    = COMBO(d_8_combo,    OUT_SCLN),  // ；
  [D_9]    = COMBO(d_9_combo,    OUT_LBRC),  // 「
  [D_0]    = COMBO(d_0_combo,    OUT_RBRC),  // 」
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
  [K_1] = COMBO(k_1_combo, OUT_XA),  // ぁ
  [K_2] = COMBO(k_2_combo, OUT_XI),  // ぃ
  [K_3] = COMBO(k_3_combo, OUT_XU),  // ぅ
  [K_4] = COMBO(k_4_combo, OUT_XE),  // ぇ
  [K_5] = COMBO(k_5_combo, OUT_XO),  // ぉ
  // }}}
  // 薬指シフト (左) {{{
  [S_Y]    = COMBO(s_y_combo,    OUT_SYE),   // しぇ
  [S_U]    = COMBO(s_u_combo,    OUT_PE),    // ぺ
  [S_I]    = COMBO(s_i_combo,    OUT_DO),    // ど
  [S_O]    = COMBO(s_o_combo,    OUT_YA),    // や
  [S_P]    = COMBO(s_p_combo,    OUT_ZYE),   // じぇ
  [S_H]    = COMBO(s_h_combo,    OUT_BI),    // び
  [S_J]    = COMBO(s_j_combo,    OUT_RA),    // ら
  // [S_K]    = COMBO(s_k_combo,    OUT_ZI),    // じ
  [S_L]    = COMBO(s_l_combo,    OUT_SA),    // さ
  [S_SCLN] = COMBO(s_scln_combo, OUT_SO),    // そ
  [S_N]    = COMBO(s_n_combo,    OUT_WA),    // わ
  [S_M]    = COMBO(s_m_combo,    OUT_DA),    // だ
  [S_COMM] = COMBO(s_comm_combo, OUT_PI),    // ぴ
  [S_DOT]  = COMBO(s_dot_combo,  OUT_PO),    // ぽ
  [S_SLSH] = COMBO(s_slsh_combo, OUT_TYE),   // ちぇ
  [S_7]    = COMBO(s_7_combo,    OUT_DOT),   // 。
  [S_8]    = COMBO(s_8_combo,    OUT_COLN),  // ：
  [S_9]    = COMBO(s_9_combo,    OUT_LPRN),  // （
  [S_0]    = COMBO(s_0_combo,    OUT_RPRN),  // ）
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
  [L_1] = COMBO(l_1_combo, OUT_XYA),  // ゃ
  [L_2] = COMBO(l_2_combo, OUT_MYA),  // みゃ
  [L_3] = COMBO(l_3_combo, OUT_MYU),  // みゅ
  [L_4] = COMBO(l_4_combo, OUT_MYO),  // みょ
  [L_5] = COMBO(l_5_combo, OUT_XWA),  // ゎ
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
  [I_1] = COMBO(i_1_combo, OUT_XYU),  // ゅ
  [I_2] = COMBO(i_2_combo, OUT_BYA),  // びゃ
  [I_3] = COMBO(i_3_combo, OUT_BYU),  // びゅ
  [I_4] = COMBO(i_4_combo, OUT_BYO),  // びょ
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
  [O_1] = COMBO(o_1_combo, OUT_XYO),  // ょ
  [O_2] = COMBO(o_2_combo, OUT_PYA),  // ぴゃ
  [O_3] = COMBO(o_3_combo, OUT_PYU),  // ぴゅ
  [O_4] = COMBO(o_4_combo, OUT_PYO),  // ぴょ
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
  // 記号 {{{
  [R_G] = COMBO(r_g_combo, OUT_MDOT),  // ・
  [R_F] = COMBO(r_f_combo, OUT_MDOT),  // ・
  [U_H] = COMBO(u_h_combo, OUT_SLSH),  // ／
  [F_B] = COMBO(f_b_combo, OUT_EXLM),  // ！
  [F_V] = COMBO(f_v_combo, OUT_EXLM),  // ！
  [J_N] = COMBO(j_n_combo, OUT_QUES),  // ？
  [F_G] = COMBO(f_g_combo, OUT_BRCS),  // 「」
  [H_J] = COMBO(h_j_combo, OUT_PRNS),  // （）
  // }}}
};

// }}}

// -- Combo Configurations {{{

// COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
  switch (combo_index) {
    // レイヤー
    case BASE_SD: return 20;
    case BASE_KL: return 20;
    case BASE_WE: return 20;
    case BASE_IO: return 20;
    case SG_SD:   return 20;
    case SG_KL:   return 20;
    case SG_WE:   return 20;
    case SG_IO:   return 20;

    // 制御キー
    case BASE_DF: return 20;
    case BASE_JK: return 20;
    case SG_DF:   return 20;
    case SG_JK:   return 20;
  }
  return COMBO_TERM;
}

// COMBO_MUST_HOLD_PER_COMBO
bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  switch (index) {
    // レイヤー
    case BASE_SD: return true;
    case BASE_KL: return true;
    case BASE_WE: return true;
    case BASE_IO: return true;
    case SG_SD:   return true;
    case SG_KL:   return true;
    case SG_WE:   return true;
    case SG_IO:   return true;
  }
  return false;
}

// // COMBO_MUST_TAP_PER_COMBO
// bool get_combo_must_tap(uint16_t index, combo_t *combo) {
//   switch (index) {
//   }
//   return false;
// }

// }}}

// -- Key Overrides {{{

// Key Overrides はユーザースペースに書くとコンパイルエラーになる。
// keymap.c に書くとコンパイルが通る。

// Key Overrides は Karabiner との相性が悪いため、併用できない。
// 例えば QMK 側で LCmd-H -> Left とオーバーライドしたなら、Karabiner が干渉して LCmd-H -> LCmd-Left と出力されてしまう。
// これは Karabiner の Complex Modifications に何もルールを登録していなかったとしても同じである。
// 唯一の手段として、Key Overrides を使用したいキーボードを Karabiner の管理対象から外せば、Karabiner の干渉を免れることができる。
// （当然 Karabiner と Key Overrides の併用はできなくなる）

#ifdef KEY_OVERRIDE_ENABLE

const key_override_t lgui_h_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_H, KC_LEFT);
const key_override_t lgui_j_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_J, KC_DOWN);
const key_override_t lgui_k_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_K, KC_UP);
const key_override_t lgui_l_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_L, KC_RGHT);

const key_override_t lgui_n_override    = ko_make_basic(MOD_BIT(KC_LGUI), KC_N,    KC_BSPC);
const key_override_t lgui_m_override    = ko_make_basic(MOD_BIT(KC_LGUI), KC_M,    KC_DEL);
const key_override_t lgui_comm_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_COMM, C(KC_A));
const key_override_t lgui_dot_override  = ko_make_basic(MOD_BIT(KC_LGUI), KC_DOT,  C(KC_E));

const key_override_t lctl_j_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_J, KC_LNG1);
const key_override_t lctl_l_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_L, KC_LNG2);
const key_override_t lctl_n_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_N, G(KC_DOWN));
const key_override_t lctl_p_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_P, G(KC_UP));
const key_override_t lctl_h_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_H, KC_BSPC);

const key_override_t *key_overrides[] = {
  &lgui_h_override,
  &lgui_j_override,
  &lgui_k_override,
  &lgui_l_override,

  &lgui_n_override,
  &lgui_m_override,
  &lgui_comm_override,
  &lgui_dot_override,

  &lctl_j_override,
  &lctl_l_override,
  &lctl_n_override,
  &lctl_p_override,
  &lctl_h_override,
};

#endif

// }}}

// -- Keymap {{{

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

// }}}
