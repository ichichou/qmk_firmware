// Layer Count
#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif

#define DEFAULT_LAYER_COUNT 5

#ifdef MTGAP_ENABLE
  #define LAYER_COUNT_MTGAP 1
#else
  #define LAYER_COUNT_MTGAP 0
#endif

#ifdef STENO_SETUP_ENABLE
  #define LAYER_COUNT_STENO_SETUP 1
#else
  #define LAYER_COUNT_STENO_SETUP 0
#endif

#ifdef SHINGETA_ENABLE
  #define LAYER_COUNT_SHINGETA 2
#else
  #define LAYER_COUNT_SHINGETA 0
#endif

#ifdef BUNA_ENABLE
  #define LAYER_COUNT_BUNA 3
#else
  #define LAYER_COUNT_BUNA 0
#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT \
  ( \
    DEFAULT_LAYER_COUNT \
    + LAYER_COUNT_MTGAP \
    + LAYER_COUNT_STENO_SETUP \
    + LAYER_COUNT_SHINGETA \
    + LAYER_COUNT_BUNA \
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
