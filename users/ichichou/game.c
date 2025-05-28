// game.c

#include "game.h"

bool process_record_game(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GAME:
      if (record->event.pressed) {
        layer_move(_BASE);
        layer_on(_GAME);
        keymap_config.nkro = true;
      }
      return false;

    case EXT_GAME:
      if (record->event.pressed) {
        layer_move(_BASE);
        keymap_config.nkro = false;
      }
      return false;

    default:
      return true;
  }
}
