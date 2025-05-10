// mtgap.c

#include "mtgap.h"

// Functions {{{

bool process_mtgap_key(uint8_t mtgap_key,
                       uint8_t qwerty_key,
                       bool *mtgap_registered,
                       bool *qwerty_registered,
                       keyrecord_t *record,
                       uint8_t mod_state) {
  if (record->event.pressed) {
    if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) {
      register_code(mtgap_key);
      *mtgap_registered = true;
      return false;
    } else {
      register_code(qwerty_key);
      *qwerty_registered = true;
      return false;
    }
  } else {
    if (*mtgap_registered) {
      unregister_code(mtgap_key);
      *mtgap_registered = false;
      return false;
    } else if (*qwerty_registered) {
      unregister_code(qwerty_key);
      *qwerty_registered = false;
      return false;
    }
  }
  return false;
}

// }}}

// process_record_* {{{

static bool mtgap_registered[31];
static bool qwerty_registered[31];

bool process_record_mtgap(uint16_t keycode,
                          keyrecord_t *record,
                          uint8_t mod_state) {
  switch (keycode) {
    case MT_A:    return process_mtgap_key(KC_A,    KC_F,    &mtgap_registered[0],  &qwerty_registered[0],  record, mod_state);
    case MT_B:    return process_mtgap_key(KC_B,    KC_N,    &mtgap_registered[1],  &qwerty_registered[1],  record, mod_state);
    case MT_C:    return process_mtgap_key(KC_C,    KC_O,    &mtgap_registered[2],  &qwerty_registered[2],  record, mod_state);
    case MT_D:    return process_mtgap_key(KC_D,    KC_U,    &mtgap_registered[3],  &qwerty_registered[3],  record, mod_state);
    case MT_E:    return process_mtgap_key(KC_E,    KC_D,    &mtgap_registered[4],  &qwerty_registered[4],  record, mod_state);
    case MT_F:    return process_mtgap_key(KC_F,    KC_M,    &mtgap_registered[5],  &qwerty_registered[5],  record, mod_state);
    case MT_G:    return process_mtgap_key(KC_G,    KC_COMM, &mtgap_registered[6],  &qwerty_registered[6],  record, mod_state);
    case MT_H:    return process_mtgap_key(KC_H,    KC_J,    &mtgap_registered[7],  &qwerty_registered[7],  record, mod_state);
    case MT_I:    return process_mtgap_key(KC_I,    KC_A,    &mtgap_registered[8],  &qwerty_registered[8],  record, mod_state);
    case MT_J:    return process_mtgap_key(KC_J,    KC_SLSH, &mtgap_registered[9],  &qwerty_registered[9],  record, mod_state);
    case MT_K:    return process_mtgap_key(KC_K,    KC_Y,    &mtgap_registered[10], &qwerty_registered[10], record, mod_state);
    case MT_L:    return process_mtgap_key(KC_L,    KC_I,    &mtgap_registered[11], &qwerty_registered[11], record, mod_state);
    case MT_M:    return process_mtgap_key(KC_M,    KC_H,    &mtgap_registered[12], &qwerty_registered[12], record, mod_state);
    case MT_N:    return process_mtgap_key(KC_N,    KC_S,    &mtgap_registered[13], &qwerty_registered[13], record, mod_state);
    case MT_O:    return process_mtgap_key(KC_O,    KC_E,    &mtgap_registered[14], &qwerty_registered[14], record, mod_state);
    case MT_P:    return process_mtgap_key(KC_P,    KC_W,    &mtgap_registered[15], &qwerty_registered[15], record, mod_state);
    case MT_Q:    return process_mtgap_key(KC_Q,    KC_QUOT, &mtgap_registered[16], &qwerty_registered[16], record, mod_state);
    case MT_R:    return process_mtgap_key(KC_R,    KC_SCLN, &mtgap_registered[17], &qwerty_registered[17], record, mod_state);
    case MT_S:    return process_mtgap_key(KC_S,    KC_L,    &mtgap_registered[18], &qwerty_registered[18], record, mod_state);
    case MT_T:    return process_mtgap_key(KC_T,    KC_K,    &mtgap_registered[19], &qwerty_registered[19], record, mod_state);
    case MT_U:    return process_mtgap_key(KC_U,    KC_R,    &mtgap_registered[20], &qwerty_registered[20], record, mod_state);
    case MT_V:    return process_mtgap_key(KC_V,    KC_DOT,  &mtgap_registered[21], &qwerty_registered[21], record, mod_state);
    case MT_W:    return process_mtgap_key(KC_W,    KC_P,    &mtgap_registered[22], &qwerty_registered[22], record, mod_state);
    case MT_X:    return process_mtgap_key(KC_X,    KC_B,    &mtgap_registered[23], &qwerty_registered[23], record, mod_state);
    case MT_Y:    return process_mtgap_key(KC_Y,    KC_Q,    &mtgap_registered[24], &qwerty_registered[24], record, mod_state);
    case MT_Z:    return process_mtgap_key(KC_Z,    KC_Z,    &mtgap_registered[25], &qwerty_registered[25], record, mod_state);
    case MT_SCLN: return process_mtgap_key(KC_SCLN, KC_T,    &mtgap_registered[26], &qwerty_registered[26], record, mod_state);
    case MT_QUOT: return process_mtgap_key(KC_QUOT, KC_C,    &mtgap_registered[27], &qwerty_registered[27], record, mod_state);
    case MT_COMM: return process_mtgap_key(KC_COMM, KC_G,    &mtgap_registered[28], &qwerty_registered[28], record, mod_state);
    case MT_DOT:  return process_mtgap_key(KC_DOT,  KC_V,    &mtgap_registered[29], &qwerty_registered[29], record, mod_state);
    case MT_SLSH: return process_mtgap_key(KC_SLSH, KC_X,    &mtgap_registered[30], &qwerty_registered[30], record, mod_state);

    default:
      return true;
  }
}

// }}}
