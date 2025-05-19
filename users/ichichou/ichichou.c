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

      case RCTL_T(MT_QUOT):
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

    #ifdef SHINGETA_ENABLE
      case SG_A ... SG_SLSH:
        return process_record_shingeta(keycode, record, mod_state);
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
      case RCTL_MT_QUOT: return true;
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

// -- Tri Layers {{{

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _SYM, _WIN);
}

// }}}

// -- Combos {{{

// コンボは Karabiner の同時押しと干渉するため、
// 同時押し系の機能はすべて Karabiner 側で実装する。

#ifdef COMBO_ENABLE

enum combos {
  SD,
  KL,
  WE,
  IO,
};

const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
  [SD] = COMBO(sd_combo, MO(_NAV)),
  [KL] = COMBO(kl_combo, MO(_NAV)),
  [WE] = COMBO(we_combo, MO(_WIN)),
  [IO] = COMBO(io_combo, MO(_WIN)),
};

#endif

// }}}

// -- Combo Configuration {{{

#ifdef COMBO_ENABLE

// COMBO_TERM_PER_COMBO (Default: 50)
//
// Karabiner 側の閾値が 50 ms の場合、COMBO_TERM は 20 ms 程度でないと、Karabiner での同時押し判定に支障が出る。
// Karabiner 側の閾値が 70 ms なら、COMBO_TERM を 50 ms にしても実用に耐える。
// 新下駄配列の同時押しに絡まないキーでのコンボなら関係ないと思われる。
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
    case SD: return 20;
    case KL: return 20;
    case WE: return 20;
    case IO: return 20;
  }
  return COMBO_TERM;
}

// COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  switch (index) {
  }
  return false;
}

// COMBO_MUST_HOLD_PER_COMBO
bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  switch (index) {
    case SD: return true;
    case KL: return true;
    case WE: return true;
    case IO: return true;
  }
  return false;
}

#endif

// }}}

// -- Key Overrides {{{

// Key Overrides は Karabiner との相性が悪いため、併用できない。
// 例えば QMK 側で LCmd-H -> Left とオーバーライドしたなら、Karabiner が干渉して LCmd-H -> LCmd-Left と出力されてしまう。
// これは Karabiner の Complex Modifications に何もルールを登録していなかったとしても同じである。
// 唯一の手段として、Key Overrides を使用したいキーボードを Karabiner の管理対象から外せば、Karabiner の干渉を免れることができる。
// （当然 Karabiner と Key Overrides の併用はできなくなる）

#ifdef KEY_OVERRIDE_ENABLE

const key_override_t lgui_h_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_H, KC_LEFT);
const key_override_t lgui_j_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_J, KC_DOWN);
const key_override_t lgui_k_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_K, KC_UP);
const key_override_t lgui_l_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_L, KC_RGHT);
const key_override_t *key_overrides[] = {
  &lgui_h_override,
  &lgui_j_override,
  &lgui_k_override,
  &lgui_l_override,
};

#endif

// }}}
