// steno.c

#include "steno.h"

bool process_record_steno(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_move(_BASE);
        set_single_default_layer(_BASE);
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

    case EXT_PLOVER:
      if (record->event.pressed) {
        layer_off(_PLOVER);
        keymap_config.nkro = false;
      }
      return false;

    case EXT_GEMINI:
      if (record->event.pressed) {
        layer_off(_GEMINI);
        keymap_config.nkro = false;
      }
      return false;

    default:
      return true;
  }
}
