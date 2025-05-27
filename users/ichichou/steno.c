// steno.c

#include "steno.h"

bool process_record_steno(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_move(_BASE);
        keymap_config.nkro = false;
      }
      return false;

    case PLOVER:
      if (record->event.pressed) {
        layer_move(_BASE);
        layer_on(_PLOVER);
        keymap_config.nkro = true;
      }
      return false;

    case GEMINI:
      if (record->event.pressed) {
        layer_move(_BASE);
        layer_on(_GEMINI);
        keymap_config.nkro = true;
      }
      return false;

    case MEJIRO:
      if (record->event.pressed) {
        layer_move(_BASE);
        layer_on(_MEJIRO);
        keymap_config.nkro = true;
      }
      return false;

    default:
      return true;
  }
}
