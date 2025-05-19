// buna.h

#pragma once
#include QMK_KEYBOARD_H
#include "ichichou.h"

// -- Macros

#define BUNA  DF(_BUNA1)
#define BUNA2 OSL(_BUNA2)
#define BUNA3 OSL(_BUNA3)

// -- Prototypes

bool process_buna_key(uint8_t qwerty_key,
                      const char *kana,
                      bool *registered,
                      keyrecord_t *record,
                      uint8_t mod_state);

bool process_record_buna(uint16_t keycode,
                         keyrecord_t *record,
                         uint8_t mod_state);

// -- Wrappers

#define __________________BUNA1_L1_________________ BN1_Q, BN1_W, BN1_E,    BN1_R,   BN1_T
#define __________________BUNA1_L2_________________ BN1_A, BN1_S, BUNA2,    BN1_F,   BN1_G
#define __________________BUNA1_L3_________________ BN1_Z, BN1_X, BN1_C,    BN1_V,   BN1_B

#define __________________BUNA1_R1_________________ BN1_Y, BN1_U, BN1_I,    BN1_O,   BN1_P
#define __________________BUNA1_R2_________________ BN1_H, BN1_J, BUNA3,    BN1_L,   BN1_SCLN
#define __________________BUNA1_R3_________________ BN1_N, BN1_M, BN1_COMM, BN1_DOT, BN1_SLSH

#define __________________BUNA2_L1_________________ BN2_Q, BN2_W, BN2_E,    BN2_R,   BN2_T
#define __________________BUNA2_L2_________________ BN2_A, BN2_S, BN2_D,    BN2_F,   BN2_G
#define __________________BUNA2_L3_________________ BN2_Z, BN2_X, BN2_C,    BN2_V,   BN2_B

#define __________________BUNA2_R1_________________ BN2_Y, BN2_U, BN2_I,    BN2_O,   BN2_P
#define __________________BUNA2_R2_________________ BN2_H, BN2_J, BN2_K,    BN2_L,   BN2_SCLN
#define __________________BUNA2_R3_________________ BN2_N, BN2_M, BN2_COMM, BN2_DOT, BN2_SLSH

#define __________________BUNA3_L1_________________ BN3_Q, BN3_W, BN3_E,    BN3_R,   BN3_T
#define __________________BUNA3_L2_________________ BN3_A, BN3_S, BN3_D,    BN3_F,   BN3_G
#define __________________BUNA3_L3_________________ BN3_Z, BN3_X, BN3_C,    BN3_V,   BN3_B

#define __________________BUNA3_R1_________________ BN3_Y, BN3_U, BN3_I,    BN3_O,   BN3_P
#define __________________BUNA3_R2_________________ BN3_H, BN3_J, BN3_K,    BN3_L,   BN3_SCLN
#define __________________BUNA3_R3_________________ BN3_N, BN3_M, BN3_COMM, BN3_DOT, BN3_SLSH
