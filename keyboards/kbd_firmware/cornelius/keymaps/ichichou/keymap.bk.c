// QMK Code Backup

// -- Define Macros {{{
//
// 一部の機能を利用するには rules.mk にコードの記述が必要
// 例：
//
// CAPS_WORD_ENABLE = yes
// SEND_STRING_ENABLE = yes

// Modifier Keycodes
#define RHYPR_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)
#define LCG(kc)     (QK_LCTL | QK_LGUI | (kc))

// Tap-Hold Keys
#define NAV_ESC   LT(_NAV, KC_ESC)
#define SYM_TAB   LT(_SYM, KC_TAB)
#define HYPR_TAB  RHYPR_T(KC_TAB)
#define HYPR_BSPC RHYPR_T(KC_BSPC)
#define CTL_ESC   CTL_T(KC_ESC)
#define CTL_ENT   CTL_T(KC_ENT)
#define CTL_QUOT  CTL_T(KC_QUOT)
#define CTL_Q     CTL_T(KC_Q)
#define SFT_SPC   SFT_T(KC_SPC)
#define SFT_CW    SFT_T(CW_TOGG)
#define SFT_BSLS  SFT_T(KC_BSLS)
#define GUI_LNG2  GUI_T(KC_LNG2)
#define RGUI_LNG1 RGUI_T(KC_LNG1)

// Home Row Mods
#define CTL_LBRC  CTL_T(KC_LBRC)
#define SFT_RBRC  SFT_T(KC_RBRC)
#define ALT_LSG_A ALT_T(LSG(KC_A))

// }}}

// -- Layers {{{
//
// 定義したレイヤーを利用しなくても、コメントアウトする必要はない

enum layer_names {
  _BASE,
  _MTGAP,
  _NAV,
  _SYM,
  _WIN,
  _FN,
};

// Tri Layers
//
// 有効化には rules.mk に以下のコードを記述する：
// TRI_LAYER_ENABLE = yes
//
// なお、Tri Layers の遷移先として指定したレイヤーは、コンボから遷移できなくなるよう
// そのためコンボと Tri layers を併用したければ、_WIN と同じキーマップの _TRI レイヤーを作る必要がある

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _SYM, _WIN);
}

// }}}

// -- Custom Keycodes {{{
//
// 定義したキーコードを利用しなくても、コメントアウトする必要はない

enum my_keycodes {
  SAMPLE_1 = SAFE_RANGE,
  SAMPLE_2,
};

// }}}

// -- Behavior of Any Keycode {{{

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Caps Word / Shift
    case SFT_CW:
      if (record->tap.count && record->event.pressed) {
        caps_word_toggle();
        return false;
      }
      return true;

    // Shift-Command-A / Option
    case ALT_T(LSG(KC_A)):
      if (record->tap.count && record->event.pressed) {
        tap_code16(LSG(KC_A));
        return false;
      }
      return true;

    // Otherwise
    default:
      return true;

  }
  return true;
}

// -- }}}

// -- Combos {{{
//
// 有効化には rules.mk に以下のコードを記述する：
// COMBO_ENABLE = yes
// 有効化しない場合は keymap.c のコードをコメントアウトする必要あり
//
// 設定のため、必要に応じて config.h に以下のコードを記述する：
// #define COMBO_TERM 20              // この時間以内に押された一連のキーがコンボと解釈される
// #define COMBO_HOLD_TERM 100        // ホールド必須ならこの時間以上ホールドする。タップ必須ならこの時間未満にタップする
// #define COMBO_MUST_TAP_PER_COMBO   // 個々のコンボでタップ必須かどうかを設定可能にする
// #define COMBO_MUST_HOLD_PER_COMBO  // 個々のコンボでホールド必須かどうかを設定可能にする

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

// COMBO_MUST_HOLD_PER_COMBO
bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  switch (index) {
    case SD:
      return true;
    case KL:
      return true;
    case WE:
      return true;
    case IO:
      return true;
  }
  return false;
}

// }}}

// -- Key Overrides {{{
//
// 有効化には rules.mk に以下のコードを記述する：
// KEY_OVERRIDE_ENABLE = yes
//
// 有効化しない場合は keymap.c のコードをコメントアウトする必要あり

const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_ALT, KC_ESC, KC_GRV);
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_TILD);
const key_override_t *key_overrides[] = {
  &grave_esc_override,
  &tilde_esc_override,
};

// }}}

// -- PERMISSIVE_HOLD_PER_KEY {{{
//
// 有効化には config.h に以下のコードを記述する：
// #define PERMISSIVE_HOLD
//
// 有効化しない場合は keymap.c のコードをコメントアウトする必要あり

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      return false;
  }
}

// }}}

// -- HOLD_ON_OTHER_KEY_PRESS_PER_KEY {{{
//
// 有効化には config.h に以下のコードを記述する：
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
//
// 有効化しない場合は keymap.c のコードをコメントアウトする必要あり

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Hold On Other Key Press Mode
    case NAV_ESC:
      return true;
    case SYM_TAB:
      return true;
    case HYPR_TAB:
      return true;
    case HYPR_BSPC:
      return true;
    case CTL_ESC:
      return true;
    case CTL_ENT:
      return true;
    case SFT_SPC:
      return true;
    case SFT_CW:
      return true;
    case GUI_LNG2:
      return true;
    case RGUI_LNG1:
      return true;

    // Default Mode
    case CTL_QUOT:
      return false;
    case SFT_BSLS:
      return false;
    case CTL_LBRC:
      return false;
    case SFT_RBRC:
      return false;
    case ALT_LSG_A:
      return false;

    // Otherwise
    default:
      return false;

  }
}

// }}}
