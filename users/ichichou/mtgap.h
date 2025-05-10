// mtgap.h

#pragma once
#include QMK_KEYBOARD_H
#include "keycodes_start.h"

#define MTGAP     MO(_MTGAP)
#define RCTL_MT_Q RCTL_T(MT_Q)

// Custom Keycodes {{{

enum mtgap_keycodes {
  MT_A = MT_START,
  MT_B,
  MT_C,
  MT_D,
  MT_E,
  MT_F,
  MT_G,
  MT_H,
  MT_I,
  MT_J,
  MT_K,
  MT_L,
  MT_M,
  MT_N,
  MT_O,
  MT_P,
  MT_Q,
  MT_R,
  MT_S,
  MT_T,
  MT_U,
  MT_V,
  MT_W,
  MT_X,
  MT_Y,
  MT_Z,
  MT_SCLN,
  MT_QUOT,
  MT_COMM,
  MT_DOT,
  MT_SLSH,
};

// }}}

bool process_mtgap_key(uint8_t mtgap_key,
                       uint8_t qwerty_key,
                       bool *mtgap_registered,
                       bool *qwerty_registered,
                       keyrecord_t *record,
                       uint8_t mod_state);

bool process_record_mtgap(uint16_t keycode,
                          keyrecord_t *record,
                          uint8_t mod_state);
