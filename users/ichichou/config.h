// Layer Count
#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif

#define DEFAULT_LAYER_COUNT 5

#define LAYER_COUNT_IF(condition, count) \
  (defined(condition) ? (count) : 0)

#define DYNAMIC_KEYMAP_LAYER_COUNT \
  ( \
    DEFAULT_LAYER_COUNT \
    + LAYER_COUNT_IF(MTGAP_ENABLE,       1) \
    + LAYER_COUNT_IF(STENO_SETUP_ENABLE, 1) \
    + LAYER_COUNT_IF(SHINGETA_ENABLE,    2) \
    + LAYER_COUNT_IF(BUNA_ENABLE,        3) \
  )

// Tap-Hold Configuration
#define TAPPING_TERM 150
#define QUICK_TAP_TERM 0
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

// Combo Configuration
#ifdef COMBO_ENABLE
  #define COMBO_TERM 50
  #define COMBO_TERM_PER_COMBO
  #define COMBO_HOLD_TERM 100
  #define COMBO_MUST_HOLD_PER_COMBO
  // #define COMBO_MUST_TAP_PER_COMBO
#endif

// Caps Word
#ifdef CAPS_WORD_ENABLE
  #define CAPS_WORD_IDLE_TIMEOUT 0
#endif

// One Shot Keys
#ifdef BUNA_ENABLE
  #define ONESHOT_TAP_TOGGLE 0
  #define ONESHOT_TIMEOUT 0
#endif
