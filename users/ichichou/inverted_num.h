// inverted_num.h

// Inverted number key の実装はうまくいっていない。
// 動作として単打 -> 記号、シフト -> 数字、となってほしい。
// ただ、シフトキーを押しながら INV_1 等のキーを押しても、
// 1打目では数字にならず、連続で2回押してやっと数字になる。
// 1回目は必ず記号が入力される。
// 実用に耐えないのでいったん塩漬けにする。

#pragma once
#include QMK_KEYBOARD_H
#include "ichichou.h"

// -- Prototypes

bool process_inverted_num_key(uint8_t num_key,
                              uint16_t symbol_key,
                              keyrecord_t *record,
                              uint8_t mod_state);

bool process_record_inverted_num(uint16_t keycode,
                                 keyrecord_t *record,
                                 uint8_t mod_state);
