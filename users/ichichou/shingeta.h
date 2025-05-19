// shingeta.h

#pragma once
#include QMK_KEYBOARD_H

// -- Macros

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
