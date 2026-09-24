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
#define WHITE_RANK_START 16
#define WHITE_RANK_END 23
#define BLACK_RANK_START 96
#define BLACK_RANK_END 103
#define FIRST_RANK_START 0
#define FIRST_RANK_END 7
#define EIGHTH_RANK_START 112
#define EIGHTH_RANK_END 119


// Represents a square.
typedef uint8_t Square;

// Represents the board.
typedef Piece Board[128];

void print_board(Board b); 
void construct_starting_position(Board b); 
void construct_temp_board(Board b);

#endif // End of include guard, keep this at the bottom!
