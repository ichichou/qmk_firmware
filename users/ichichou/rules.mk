SRC += ichichou.c

VIA_ENABLE = yes
CAPS_WORD_ENABLE = yes
SEND_STRING_ENABLE = yes
# COMBO_ENABLE = yes
# KEY_OVERRIDE_ENABLE = yes
EXTRAFLAGS += -flto

ifeq ($(strip $(ENABLE_MTGAP)), yes)
  SRC += mtgap.c
  OPT_DEFS += -DENABLE_MTGAP
endif
