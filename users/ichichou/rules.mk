SRC += ichichou.c
EXTRAFLAGS += -flto

VIA_ENABLE = no
CAPS_WORD_ENABLE = yes
SEND_STRING_ENABLE = yes

ifeq ($(strip $(GAME_ENABLE)), yes)
  SRC += game.c
  OPT_DEFS += -DGAME_ENABLE
  NKRO_ENABLE = yes
endif

ifeq ($(strip $(MTGAP_ENABLE)), yes)
  SRC += mtgap.c
  OPT_DEFS += -DMTGAP_ENABLE
endif

ifeq ($(strip $(STENO_SETUP_ENABLE)), yes)
  SRC += steno.c
  OPT_DEFS += -DSTENO_SETUP_ENABLE
  NKRO_ENABLE = yes
  STENO_ENABLE = yes
  STENO_PROTOCOL = geminipr
endif

ifeq ($(strip $(BUNA_ENABLE)), yes)
  SRC += buna.c
  OPT_DEFS += -DBUNA_ENABLE
endif

ifeq ($(strip $(SHINGETA_ENABLE)), yes)
  SRC += shingeta.c
  OPT_DEFS += -DSHINGETA_ENABLE
endif

ifeq ($(strip $(INVERTED_NUM_ENABLE)), yes)
  SRC += inverted_num.c
  OPT_DEFS += -DINVERTED_NUM_ENABLE
endif

ifeq ($(strip $(TRI_WIN_LAYER_ENABLE)), yes)
  OPT_DEFS += -DTRI_WIN_LAYER_ENABLE
endif
