#ifndef CHESS_MOVEGEN_H
#define CHESS_MOVEGEN_H

#include "position.h"
#include "move.h"
#include <stdint.h>

typedef struct {
  uint8_t size;
  uint8_t moves[8];
} Offset;

void generate_pseudo_legal_moves(Move *moves, Position *position);

#endif
