SRC += ichichou.c
EXTRAFLAGS += -flto

VIA_ENABLE = no
CAPS_WORD_ENABLE = yes
SEND_STRING_ENABLE = yes

ifeq ($(strip $(MTGAP_ENABLE)), yes)
  SRC += mtgap.c
  OPT_DEFS += -DMTGAP_ENABLE
endif

ifeq ($(strip $(BUNA_ENABLE)), yes)
  SRC += buna.c
  OPT_DEFS += -DBUNA_ENABLE
endif

ifeq ($(strip $(INVERTED_NUM_ENABLE)), yes)
  SRC += inverted_num.c
  OPT_DEFS += -DINVERTED_NUM_ENABLE
endif
