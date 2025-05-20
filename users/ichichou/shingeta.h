// shingeta.h

#pragma once
#include QMK_KEYBOARD_H
#include "ichichou.h"

// -- Macros

#define RCTL_SG_QUOT RCTL_T(SG_QUOT)
#define JSYM_SG_R    LT(_JSYM, SG_R)

// -- Prototypes

bool process_shingeta_key(uint8_t qwerty_key,
                          const char *kana,
                          bool *registered,
                          keyrecord_t *record,
                          uint8_t mod_state);

bool process_output_key(const char *kana,
                        keyrecord_t *record,
                        uint8_t mod_state);

bool process_record_shingeta(uint16_t keycode,
                             keyrecord_t *record,
                             uint8_t mod_state);

// -- Wrappers

#define __________________SHINGETA_L1______________ SG_Q, SG_W, SG_E, JSYM_SG_R, SG_T
#define __________________SHINGETA_L2______________ SG_A, SG_S, SG_D, SG_F,      SG_G
#define __________________SHINGETA_L3______________ SG_Z, SG_X, SG_C, SG_V,      SG_B

#define __________________SHINGETA_R1______________ SG_Y, SG_U, SG_I,    SG_O,   SG_P
#define __________________SHINGETA_R2______________ SG_H, SG_J, SG_K,    SG_L,   SG_SCLN
#define __________________SHINGETA_R3______________ SG_N, SG_M, SG_COMM, SG_DOT, SG_SLSH

#define __________________JSYM_R1__________________ JSYM_Y, JSYM_U, JSYM_I,    JSYM_O,   JSYM_P
#define __________________JSYM_R2__________________ JSYM_H, JSYM_J, JSYM_K,    JSYM_L,   JSYM_SCLN
#define __________________JSYM_R3__________________ JSYM_N, JSYM_M, JSYM_COMM, JSYM_DOT, JSYM_SLSH
