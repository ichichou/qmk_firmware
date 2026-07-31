// ichichou.c

#include "ichichou.h"

// -- process_record_user {{{

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();

  switch (keycode) {
    case SFT_T(CW_TOGG):
      if (record->tap.count && record->event.pressed) {
        caps_word_on();
        return false;
      }
      return true;

    #ifdef MTGAP_ENABLE
      case MT_A ... MT_BSLS:
        return process_record_mtgap(keycode, record, mod_state);

      case MTGAP:
        if (record->event.pressed) {
          set_single_default_layer(_MTGAP);
          keymap_config.nkro = false;
        }
        return false;
    #endif

    #ifdef STENO_SETUP_ENABLE
      case QWERTY ... EXT_GEMINI:
        return process_record_steno(keycode, record);
    #endif

    #ifdef SHINGETA_ENABLE
      case IME_SG_ON ... JSYM_SLSH:
        return process_record_shingeta(keycode, record, mod_state);

      case RCTL_T(SG_QUOT):
        if (record->tap.count && record->event.pressed) {
          if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) {
            SEND_STRING("ge");
            return false;
          } else {
            tap_code(KC_QUOT);
            return false;
          }
        }
        return true;

      case LT(_JSYM, SG_R):
        if (record->tap.count && record->event.pressed) {
          if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) {
            tap_code(KC_COMM);
            return false;
          } else {
            tap_code(KC_R);
            return false;
          }
        }
        return true;
    #endif

    #ifdef BUNA_ENABLE
      case BN1_A ... BN3_SLSH:
        return process_record_buna(keycode, record, mod_state);

      case RCTL_T(BN1_QUOT):
        if (record->tap.count && record->event.pressed) {
          if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) {
            SEND_STRING(".");
            return false;
          } else {
            tap_code(KC_QUOT);
            return false;
          }
        }
        return true;
    #endif

    #ifdef INVERTED_NUM_ENABLE
      case INV_1 ... INV_0:
        return process_record_inverted_num(keycode, record, mod_state);
    #endif

    default:
      return true;
  }
}

// }}}

// -- Tap-Hold Configuration {{{

// Quick Tap
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYM_BSPC:
      return TAPPING_TERM;
    case RGUI_BSPC:
      return TAPPING_TERM;
    default:
      return QUICK_TAP_TERM;
  }
}

// }}}

// -- Tri Layers {{{

#ifdef TRI_WIN_LAYER_ENABLE

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _SYM, _WIN);
}

#endif

// }}}
