// Copyright (c) 2026 Pontus Nordström
// Copyright (c) 2026 Arvid Westman
// SPDX-License-Identifier: BSD-3-Clause

/*
  This is called an include guard, we need it
  to avoid a bunch of redefinition errors when
  we need to include multiple header files.
*/
#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <stdint.h>

// Represents a piece.
typedef uint8_t Piece;
typedef uint8_t Color;

/*
  Piece type and color are disjoint piece
  flags.

  Inspiration from:
  https://chessprogramming.org/Pieces
*/
enum {
  COLOR_NONE   = 0x0,
  COLOR_WHITE  = 0x1,
  COLOR_BLACK  = 0x2, 
};

enum {
  PIECE_EMPTY  = 0x0,
  PIECE_PAWN   = 0x4,
  PIECE_ROOK   = 0x8,
  PIECE_KNIGHT = 0x10,
  PIECE_BISHOP = 0x20,
  PIECE_QUEEN  = 0x40,
  PIECE_KING   = 0x80,
};

enum {
  EMPTY_SQUARE = COLOR_NONE  | PIECE_EMPTY,
  
  WHITE_PAWN   = COLOR_WHITE | PIECE_PAWN,
  WHITE_ROOK   = COLOR_WHITE | PIECE_ROOK,
  WHITE_KNIGHT = COLOR_WHITE | PIECE_KNIGHT,
  WHITE_BISHOP = COLOR_WHITE | PIECE_BISHOP,
  WHITE_QUEEN  = COLOR_WHITE | PIECE_QUEEN,
  WHITE_KING   = COLOR_WHITE | PIECE_KING,

  BLACK_PAWN   = COLOR_BLACK | PIECE_PAWN,
  BLACK_ROOK   = COLOR_BLACK | PIECE_ROOK,
  BLACK_KNIGHT = COLOR_BLACK | PIECE_KNIGHT,
  BLACK_BISHOP = COLOR_BLACK | PIECE_BISHOP,
  BLACK_QUEEN  = COLOR_BLACK | PIECE_QUEEN,
  BLACK_KING   = COLOR_BLACK | PIECE_KING,


};

enum {
  CASTLE_WHITE_QUEEN = 1,
  CASTLE_WHITE_KING = 2,
  CASTLE_BLACK_QUEEN = 4,
  CASTLE_BLACK_KING = 8,
};

#endif // End of include guard, keep this at the bottom!
