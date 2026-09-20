// Copyright (c) 2026 Pontus Nordström
// Copyright (c) 2026 Arvid Westman
// SPDX-License-Identifier: BSD-3-Clause

/*
  This is called an include guard, we need it
  to avoid a bunch of redefinition errors when
  we need to include multiple header files.
*/
#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "piece.h"

// Represents a square.
typedef uint8_t Square;

// Represents the board.
typedef Piece Board[128];

void print_board(Board b); 
void construct_starting_position(Board b); 
void construct_temp_board(Board b);

#endif // End of include guard, keep this at the bottom!
