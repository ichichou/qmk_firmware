// steno.c

#include "steno.h"

bool process_record_steno(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_move(_BASE);
        set_single_default_layer(_BASE);
        #if NKRO_DEFAULT_ON != true
          keymap_config.nkro = false;
        #endif
      }
      return false;

    case GEMINI:
      if (record->event.pressed) {
        layer_move(_BASE);
        layer_on(_GEMINI);
        #if NKRO_DEFAULT_ON != true
          keymap_config.nkro = true;
        #endif
      }
      return false;

    // case PLOVER:
    //   if (record->event.pressed) {
    //     layer_move(_BASE);
    //     layer_on(_PLOVER);
    //     #if NKRO_DEFAULT_ON != true
    //       keymap_config.nkro = true;
    //     #endif
    //   }
    //   return false;

    case EXT_GEMINI:
      if (record->event.pressed) {
        layer_off(_GEMINI);
        #if NKRO_DEFAULT_ON != true
          keymap_config.nkro = false;
        #endif
      }
      return false;

    // case EXT_PLOVER:
    //   if (record->event.pressed) {
    //     layer_off(_PLOVER);
    //     #if NKRO_DEFAULT_ON != true
    //       keymap_config.nkro = false;
    //     #endif
    //   }
    //   return false;

    default:
      return true;
  }
}
