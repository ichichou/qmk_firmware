// inverted_num.h

// Inverted num key の実装はうまくいっていない。
// 動作として単打 -> 記号、シフト -> 数字、となってほしい。
// ただ、シフトキーを押しながら INV_1 等のキーを押しても、
// 1打目では数字にならず、連続で2回押してやっと数字になる。
// 1回目は必ず記号が入力される。
// 実用に耐えないのでいったん塩漬けにする。

#pragma once
#include QMK_KEYBOARD_H
#include "keycodes_start.h"

// -- Custom Keycodes

// 実際に利用するには keycodes_start.h で
// INV_1 のスタート地点を決める必要があるかもしれない

enum inverted_num_keycode {
  // INV_1 = QK_USER,
  INV_1,
  INV_2,
  INV_3,
  INV_4,
  INV_5,
  INV_6,
  INV_7,
  INV_8,
  INV_9,
  INV_0,
};

// -- Prototypes

bool process_inverted_num_key(uint8_t num_key,
                              uint16_t symbol_key,
                              keyrecord_t *record,
                              uint8_t mod_state);

bool process_record_inverted_num(uint16_t keycode,
                                 keyrecord_t *record,
                                 uint8_t mod_state);
