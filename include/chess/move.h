#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include "board.h"

typedef struct {
  Square from_square;
  Square to_square;
} Move;

#endif
