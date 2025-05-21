// mtgap.c

#include "mtgap.h"

// -- Functions {{{

bool process_mtgap_key(uint8_t qwerty_key,
                       uint8_t mtgap_key,
                       bool *qwerty_registered,
                       bool *mtgap_registered,
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

// process_record_mtgap {{{

static bool mtgap_registered[31];
static bool qwerty_registered[31];

bool process_record_mtgap(uint16_t keycode,
                          keyrecord_t *record,
                          uint8_t mod_state) {
  switch (keycode) {
    case MT_A:    return process_mtgap_key(KC_A,    KC_I,    &qwerty_registered[0],  &mtgap_registered[0],  record, mod_state);
    case MT_B:    return process_mtgap_key(KC_B,    KC_X,    &qwerty_registered[1],  &mtgap_registered[1],  record, mod_state);
    case MT_C:    return process_mtgap_key(KC_C,    KC_QUOT, &qwerty_registered[2],  &mtgap_registered[2],  record, mod_state);
    case MT_D:    return process_mtgap_key(KC_D,    KC_E,    &qwerty_registered[3],  &mtgap_registered[3],  record, mod_state);
    case MT_E:    return process_mtgap_key(KC_E,    KC_O,    &qwerty_registered[4],  &mtgap_registered[4],  record, mod_state);
    case MT_F:    return process_mtgap_key(KC_F,    KC_A,    &qwerty_registered[5],  &mtgap_registered[5],  record, mod_state);
    case MT_G:    return process_mtgap_key(KC_G,    KC_COMM, &qwerty_registered[6],  &mtgap_registered[6],  record, mod_state);
    case MT_H:    return process_mtgap_key(KC_H,    KC_M,    &qwerty_registered[7],  &mtgap_registered[7],  record, mod_state);
    case MT_I:    return process_mtgap_key(KC_I,    KC_L,    &qwerty_registered[8],  &mtgap_registered[8],  record, mod_state);
    case MT_J:    return process_mtgap_key(KC_J,    KC_H,    &qwerty_registered[9],  &mtgap_registered[9],  record, mod_state);
    case MT_K:    return process_mtgap_key(KC_K,    KC_T,    &qwerty_registered[10], &mtgap_registered[10], record, mod_state);
    case MT_L:    return process_mtgap_key(KC_L,    KC_S,    &qwerty_registered[11], &mtgap_registered[11], record, mod_state);
    case MT_M:    return process_mtgap_key(KC_M,    KC_F,    &qwerty_registered[12], &mtgap_registered[12], record, mod_state);
    case MT_N:    return process_mtgap_key(KC_N,    KC_B,    &qwerty_registered[13], &mtgap_registered[13], record, mod_state);
    case MT_O:    return process_mtgap_key(KC_O,    KC_C,    &qwerty_registered[14], &mtgap_registered[14], record, mod_state);
    case MT_P:    return process_mtgap_key(KC_P,    KC_W,    &qwerty_registered[15], &mtgap_registered[15], record, mod_state);
    case MT_Q:    return process_mtgap_key(KC_Q,    KC_Y,    &qwerty_registered[16], &mtgap_registered[16], record, mod_state);
    case MT_R:    return process_mtgap_key(KC_R,    KC_U,    &qwerty_registered[17], &mtgap_registered[17], record, mod_state);
    case MT_S:    return process_mtgap_key(KC_S,    KC_N,    &qwerty_registered[18], &mtgap_registered[18], record, mod_state);
    case MT_T:    return process_mtgap_key(KC_T,    KC_SCLN, &qwerty_registered[19], &mtgap_registered[19], record, mod_state);
    case MT_U:    return process_mtgap_key(KC_U,    KC_D,    &qwerty_registered[20], &mtgap_registered[20], record, mod_state);
    case MT_V:    return process_mtgap_key(KC_V,    KC_DOT,  &qwerty_registered[21], &mtgap_registered[21], record, mod_state);
    case MT_W:    return process_mtgap_key(KC_W,    KC_P,    &qwerty_registered[22], &mtgap_registered[22], record, mod_state);
    case MT_X:    return process_mtgap_key(KC_X,    KC_SLSH, &qwerty_registered[23], &mtgap_registered[23], record, mod_state);
    case MT_Y:    return process_mtgap_key(KC_Y,    KC_K,    &qwerty_registered[24], &mtgap_registered[24], record, mod_state);
    case MT_Z:    return process_mtgap_key(KC_Z,    KC_Z,    &qwerty_registered[25], &mtgap_registered[25], record, mod_state);
    case MT_SCLN: return process_mtgap_key(KC_SCLN, KC_R,    &qwerty_registered[26], &mtgap_registered[26], record, mod_state);
    case MT_QUOT: return process_mtgap_key(KC_QUOT, KC_Q,    &qwerty_registered[27], &mtgap_registered[27], record, mod_state);
    case MT_COMM: return process_mtgap_key(KC_COMM, KC_G,    &qwerty_registered[28], &mtgap_registered[28], record, mod_state);
    case MT_DOT:  return process_mtgap_key(KC_DOT,  KC_V,    &qwerty_registered[29], &mtgap_registered[29], record, mod_state);
    case MT_SLSH: return process_mtgap_key(KC_SLSH, KC_J,    &qwerty_registered[30], &mtgap_registered[30], record, mod_state);

    default:
      return true;
  }
}

// }}}
