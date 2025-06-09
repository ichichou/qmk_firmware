// KB: The Uni v4 (RP2040)
// KM: ichichou

// To compile:
// >_ qmk compile -c -kb stenokeyboards/the_uni/rp_2040

// Copyright {{{

/*
Copyright 2021 Peter C. Park <peter@stenokeyboards.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// }}}

#include QMK_KEYBOARD_H

#define OS_LOCK (QK_LCTL | QK_LGUI | KC_Q)

#define FN_1 1
#define FN_2 2
#define FN_12 3
static uint8_t fn_n = 0;

// Layers & Keycodes {{{

enum layer_names {
  _GEMINI,
  _PLOVER,
  _FN,
};

enum my_keycodes {
  GEMINI = QK_USER,
  PLOVER,
  FN,
  FN1,
  FN2,
};

// }}}

// process_record_user {{{

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GEMINI:
      if (record->event.pressed) {
        layer_move(0);
        layer_on(_GEMINI);
      }
      return false;

    case PLOVER:
      if (record->event.pressed) {
        layer_move(0);
        layer_on(_PLOVER);
      }
      return false;

    case FN:
      if (record->event.pressed) {
        fn_n = 0;
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;

    case FN1:
      if (record->event.pressed) {
        fn_n = fn_n | FN_1;
        if (fn_n == FN_12) {
          layer_on(_FN);
        }
      } else {
        fn_n = fn_n & ~FN_1;
        if (fn_n != FN_12) {
          layer_off(_FN);
        }
      }
      return false;

    case FN2:
      if (record->event.pressed) {
        fn_n = fn_n | FN_2;
        if (fn_n == FN_12) {
          layer_on(_FN);
        }
      } else {
        fn_n = fn_n & ~FN_2;
        if (fn_n != FN_12) {
          layer_off(_FN);
        }
      }
      return false;

    default:
      return true;
  }
}

// }}}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_GEMINI] = LAYOUT(
    STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,    STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,    STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                      FN1,     STN_A,   STN_O,      STN_E,   STN_U,   FN2
  ),

  [_PLOVER] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                      FN1,     KC_C,    KC_V,       KC_N,    KC_M,    FN2
  ),

  [_FN] = LAYOUT(
    OS_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, GEMINI,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, PLOVER,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, XXXXXXX, EE_CLR,     QK_BOOT, XXXXXXX, _______
  ),

};
