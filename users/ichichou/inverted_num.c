// inverted_num.c

#include "inverted_num.h"

bool process_inverted_num_key(uint8_t num_key,
                              uint16_t symbol_key,
                              keyrecord_t *record,
                              uint8_t mod_state) {
  if (record->event.pressed) {
    // Not pressed modifiers
    if (mod_state == 0) {
      tap_code16(symbol_key);
      return false;
    // Pressed only shift
    } else if (((mod_state & MOD_MASK_SHIFT) != 0) && ((mod_state & ~MOD_MASK_SHIFT) == 0)) {
      uint8_t shift_mods = mod_state & MOD_MASK_SHIFT;
      del_mods(shift_mods);
      tap_code(num_key);
      add_mods(shift_mods);
      return false;
    // Pressed any modifiers
    } else {
      tap_code(num_key);
      return false;
    }
  }
  return false;
}

bool process_record_inverted_num(uint16_t keycode,
                                 keyrecord_t *record,
                                 uint8_t mod_state) {
  switch(keycode) {
    case INV_1: return process_inverted_num_key(KC_1, KC_EXLM, record, mod_state);
    case INV_2: return process_inverted_num_key(KC_2, KC_AT,   record, mod_state);
    case INV_3: return process_inverted_num_key(KC_3, KC_HASH, record, mod_state);
    case INV_4: return process_inverted_num_key(KC_4, KC_DLR,  record, mod_state);
    case INV_5: return process_inverted_num_key(KC_5, KC_PERC, record, mod_state);
    case INV_6: return process_inverted_num_key(KC_6, KC_CIRC, record, mod_state);
    case INV_7: return process_inverted_num_key(KC_7, KC_AMPR, record, mod_state);
    case INV_8: return process_inverted_num_key(KC_8, KC_ASTR, record, mod_state);
    case INV_9: return process_inverted_num_key(KC_9, KC_LPRN, record, mod_state);
    case INV_0: return process_inverted_num_key(KC_0, KC_RPRN, record, mod_state);

    default:
      return true;
  }
}
