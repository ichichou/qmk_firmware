SRC += ichichou.c
EXTRAFLAGS += -flto

VIA_ENABLE = no
CAPS_WORD_ENABLE = yes
SEND_STRING_ENABLE = yes
# DYNAMIC_MACRO_ENABLE = yes

ifeq ($(strip $(MTGAP_ENABLE)), yes)
  SRC += mtgap.c
  OPT_DEFS += -DMTGAP_ENABLE
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
