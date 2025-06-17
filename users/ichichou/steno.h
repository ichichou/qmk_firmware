// steno.h

#pragma once
#include QMK_KEYBOARD_H
#include "ichichou.h"

// -- Prototypes

bool process_record_steno(uint16_t keycode, keyrecord_t *record);

// -- Wrappers

// Gemini PR:
//
// Q ROW:  STN_N3,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,    STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
// A ROW:  STN_N4,  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,    STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
// Z ROW:  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_N5,  STN_N6,     STN_N7,  STN_N8,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// SPACE:  QWERTY,  XXXXXXX, XXXXXXX, STN_N1,  STN_A,   STN_O,      STN_E,   STN_U,   STN_N2,  XXXXXXX, XXXXXXX, FN

#define __________________GEMINI_L1________________ STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1
#define __________________GEMINI_L2________________ STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2
#define __________________GEMINI_L3________________ XXXXXXX, XXXXXXX, XXXXXXX, STN_N5,  STN_N6

#define __________________GEMINI_R1________________ STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR
#define __________________GEMINI_R2________________ STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR
#define __________________GEMINI_R3________________ STN_N7,  STN_N8,  XXXXXXX, XXXXXXX, XXXXXXX

// Plover:
//
// Q ROW:  KC_3,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
// A ROW:  KC_4,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
// Z ROW:  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_5,    KC_6,       KC_7,    KC_8,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// SPACE:  QWERTY,  XXXXXXX, XXXXXXX, KC_1,    KC_C,    KC_V,       KC_N,    KC_M,    KC_2,    XXXXXXX, XXXXXXX, FN

// #define __________________PLOVER_L1________________ KC_Q,    KC_W,    KC_E,    KC_R, KC_T
// #define __________________PLOVER_L2________________ KC_A,    KC_S,    KC_D,    KC_F, KC_G
// #define __________________PLOVER_L3________________ XXXXXXX, XXXXXXX, XXXXXXX, KC_5, KC_6
//
// #define __________________PLOVER_R1________________ KC_Y, KC_U, KC_I,    KC_O,    KC_P
// #define __________________PLOVER_R2________________ KC_H, KC_J, KC_K,    KC_L,    KC_SCLN
// #define __________________PLOVER_R3________________ KC_7, KC_8, XXXXXXX, XXXXXXX, XXXXXXX
