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
    case MT_A ... MT_SLSH:
      return process_record_mtgap(keycode, record, mod_state);

    case RCTL_T(MT_Q):
      if (record->tap.count && record->event.pressed) {
        if ((mod_state & ~(MOD_MASK_SHIFT)) == 0) {
          tap_code(KC_Q);
          return false;
        } else {
          tap_code(KC_QUOT);
          return false;
        }
      }
      return true;
#endif

#ifdef BUNA_ENABLE
    case BN1_A ... BN3_SLSH:
      return process_record_buna(keycode, record, mod_state);
#endif

    default:
      return true;
  }
}

// }}}

// -- Tap-Hold Configuration {{{

// Hold On Other Key Press Mode
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Layer-Tap
    case NAV_ESC: return true;
    case NAV_TAB: return true;
    case SYM_TAB: return true;
    case SYM_ENT: return true;
    case FN_BSLS: return true;
    case FN_GRV:  return true;

    // Mod-Tap
    case RHYPR_TAB:  return true;
    case RHYPR_BSPC: return true;
    case LSFT_SPC:   return true;
    case LSFT_CW:    return true;
    case RSFT_SLSH:  return true;
    case RSFT_BSLS:  return true;
    case LCTL_ESC:   return true;
    case RCTL_ENT:   return true;
    case RCTL_QUOT:  return true;
    case RCTL_TAB:   return true;
    case RALT_GRV:   return true;
    case LGUI_LNG2:  return true;
    case RGUI_LNG1:  return true;

    // Home Row Mods
    case LCTL_LBRC: return true;
    case LSFT_RBRC: return true;
    case LGUI_GRV:  return true;

# ifdef MTGAP_ENABLE
    case RCTL_MT_Q: return true;
#endif

    default:
      return false;
  }
}

// Permissive Hold Mode
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      return false;
  }
}

// }}}
