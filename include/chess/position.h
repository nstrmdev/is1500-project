#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H

#include "board.h"

typedef struct {
  Board board;
  Color side_to_move;
  uint8_t can_castle; 
} Position;

#endif
