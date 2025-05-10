SRC += ichichou.c
EXTRAFLAGS += -flto

VIA_ENABLE = no
CAPS_WORD_ENABLE = yes
SEND_STRING_ENABLE = yes
# COMBO_ENABLE = yes
# KEY_OVERRIDE_ENABLE = yes

ifeq ($(strip $(ENABLE_MTGAP)), yes)
  SRC += mtgap.c
  OPT_DEFS += -DENABLE_MTGAP
endif

ifeq ($(strip $(ENABLE_BUNA)), yes)
  SRC += buna.c
  OPT_DEFS += -DENABLE_BUNA
endif
