// Layer
#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
  #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif

#if defined(BUNA_ENABLE) && defined(MTGAP_ENABLE)
  #define DYNAMIC_KEYMAP_LAYER_COUNT 9
#elif defined(BUNA_ENABLE)
  #define DYNAMIC_KEYMAP_LAYER_COUNT 8
#elif defined(SHINGETA_ENABLE)
  #define DYNAMIC_KEYMAP_LAYER_COUNT 6
#elif defined(MTGAP_ENABLE)
  #define DYNAMIC_KEYMAP_LAYER_COUNT 6
#else
  #define DYNAMIC_KEYMAP_LAYER_COUNT 5
#endif

// Tap-Hold Configuration
#define TAPPING_TERM 150
#define QUICK_TAP_TERM 0
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

// Caps Word
#ifdef CAPS_WORD_ENABLE
  #define CAPS_WORD_IDLE_TIMEOUT 0
#endif

// One Shot Keys
#ifdef BUNA_ENABLE
  #define ONESHOT_TAP_TOGGLE 0
  #define ONESHOT_TIMEOUT 0
#endif
