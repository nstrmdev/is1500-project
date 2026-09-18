#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H

#include "board.h"

typedef struct {
  Board *board;
  uint8_t side_to_move;
} Position;

#endif
