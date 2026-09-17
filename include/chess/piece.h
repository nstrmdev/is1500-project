// Copyright (c) 2026 Pontus Nordström
// Copyright (c) 2026 Arvid Westman
// SPDX-License-Identifier: BSD-3-Clause

#include <stdint.h>

/*
  Piece type and color are disjoint piece
  flags.

  Inspiration from:
  https://chessprogramming.org/Pieces
*/
typedef enum {
  EMPTY  = 0x0,
  PAWN   = 0x4,
  ROOK   = 0x8,
  KNIGHT = 0x10,
  BISHOP = 0x20,
  QUEEN  = 0x40,
  KING   = 0x80,
} PieceType;

typedef enum {
  NONE  = 0x0,
  WHITE = 0x1,
  BLACK = 0x2, 
} PieceColor;

// Represents a piece.
typedef uint8_t Piece;
