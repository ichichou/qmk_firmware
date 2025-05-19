// mtgap.h

#pragma once
#include QMK_KEYBOARD_H

// -- Macros

#define MTGAP     DF(_MTGAP)
#define RCTL_MT_QUOT RCTL_T(MT_QUOT)

// -- Prototypes

bool process_mtgap_key(uint8_t qwerty_key,
                       uint8_t mtgap_key,
                       bool *qwerty_registered,
                       bool *mtgap_registered,
                       keyrecord_t *record,
                       uint8_t mod_state);

bool process_record_mtgap(uint16_t keycode,
                          keyrecord_t *record,
                          uint8_t mod_state);

// -- Wrappers

#define __________________MTGAP_L1_________________ MT_Q, MT_W, MT_E,    MT_R,   MT_T
#define __________________MTGAP_L2_________________ MT_A, MT_S, MT_D,    MT_F,   MT_G
#define __________________MTGAP_L3_________________ MT_Z, MT_X, MT_C,    MT_V,   MT_B

#define __________________MTGAP_R1_________________ MT_Y, MT_U, MT_I,    MT_O,   MT_P
#define __________________MTGAP_R2_________________ MT_H, MT_J, MT_K,    MT_L,   MT_SCLN
#define __________________MTGAP_R3_________________ MT_N, MT_M, MT_COMM, MT_DOT, MT_SLSH
