// Key Overrides を有効化するには、対象となるキーマップで：
// - rules.mk に KEY_OVERRIDE_ENABLE = yes と記述。
// - keymap.c に #include "key_overrides_keymap.c" と記述。

// Key Overrides は Karabiner-Elements との相性が悪く、併用できない。
// 例えば QMK 側で LCmd-H -> Left とオーバーライドしたなら、Karabiner が干渉して LCmd-H -> LCmd-Left と出力されてしまう。
// これは Karabiner の Complex Modifications に何もルールを登録していなかったとしても同じである。
// 唯一の手段として、Key Overrides を使用したいキーボードを Karabiner の管理対象から外せば、Karabiner の干渉を免れることができる。
// （当然 Karabiner と Key Overrides の併用はできなくなる）

const key_override_t lgui_h_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_H, KC_LEFT);
const key_override_t lgui_j_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_J, KC_DOWN);
const key_override_t lgui_k_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_K, KC_UP);
const key_override_t lgui_l_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_L, KC_RGHT);

const key_override_t lgui_n_override    = ko_make_basic(MOD_BIT(KC_LGUI), KC_N,    KC_BSPC);
const key_override_t lgui_m_override    = ko_make_basic(MOD_BIT(KC_LGUI), KC_M,    KC_DEL);
const key_override_t lgui_comm_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_COMM, C(KC_A));
const key_override_t lgui_dot_override  = ko_make_basic(MOD_BIT(KC_LGUI), KC_DOT,  C(KC_E));

const key_override_t lctl_j_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_J, KC_LNG1);
const key_override_t lctl_l_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_L, KC_LNG2);
const key_override_t lctl_n_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_N, G(KC_DOWN));
const key_override_t lctl_p_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_P, G(KC_UP));
const key_override_t lctl_h_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_H, KC_BSPC);

const key_override_t *key_overrides[] = {
  &lgui_h_override,
  &lgui_j_override,
  &lgui_k_override,
  &lgui_l_override,

  &lgui_n_override,
  &lgui_m_override,
  &lgui_comm_override,
  &lgui_dot_override,

  &lctl_j_override,
  &lctl_l_override,
  &lctl_n_override,
  &lctl_p_override,
  &lctl_h_override,
};
