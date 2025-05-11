SRC += ichichou.c
EXTRAFLAGS += -flto

VIA_ENABLE = no
CAPS_WORD_ENABLE = yes
SEND_STRING_ENABLE = yes
# COMBO_ENABLE = yes
# KEY_OVERRIDE_ENABLE = yes

ifeq ($(strip $(MTGAP_ENABLE)), yes)
  SRC += mtgap.c
  OPT_DEFS += -DMTGAP_ENABLE
endif

ifeq ($(strip $(BUNA_ENABLE)), yes)
  SRC += buna.c
  OPT_DEFS += -DBUNA_ENABLE
endif
