// Copyright (c) 2026 Pontus Nordström
// Copyright (c) 2026 Arvid Westman
// SPDX-License-Identifier: BSD-3-Clause

#include "chess/board.h"
#include "chess/piece.h"
#include <stdio.h>

static void clear_board(Board *b) {
  // Empty
  Piece e  = EMPTY  | NONE;

  for (int i = 0; i <= 127; i++) {
    (*b)[i] = e;
  }
}

static char hex_to_char(const unsigned char c) {
  switch (c) {
    case EMPTY:
      return '.';

    case (PAWN | WHITE):
      return 'P';
    case (ROOK | WHITE):
      return 'R';
    case (KNIGHT | WHITE):
      return 'N';
    case (BISHOP | WHITE):
      return 'B';
    case (QUEEN | WHITE):
      return 'Q';
    case (KING | WHITE):
      return 'K';

    case (PAWN | BLACK):
      return 'p';
    case (ROOK | BLACK):
      return 'r';
    case (KNIGHT | BLACK):
      return 'n';
    case (BISHOP | BLACK):
      return 'b';
    case (QUEEN | BLACK):
      return 'q';
    case (KING | BLACK):
      return 'k';

    default:
      return '_';
  }
}

void print_board(Board *b) {
  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file <= 7; file++) {
      int square = 16 * rank + file;
      printf("%c ", hex_to_char((*b)[square]));
    }
    printf("\n");
  }
}

void construct_starting_position(Board *b) {
  // White pieces
  Piece wp = PAWN   | WHITE;
  Piece wr = ROOK   | WHITE;
  Piece wn = KNIGHT | WHITE;
  Piece wb = BISHOP | WHITE;
  Piece wq = QUEEN  | WHITE;
  Piece wk = KING   | WHITE;

  // Black pieces
  Piece bp = PAWN   | BLACK;
  Piece br = ROOK   | BLACK;
  Piece bn = KNIGHT | BLACK;
  Piece bb = BISHOP | BLACK;
  Piece bq = QUEEN  | BLACK;
  Piece bk = KING   | BLACK;

  // Set all squares to empty
  clear_board(b);

  // Place pawns
  for (int i = 16; i <= 23; i++) {
     (*b)[i] = wp;
  }

  for (int i = 96; i <= 103; i++) {
    (*b)[i] = bp;
  }

  // White back rank
  (*b)[0] = wr;
  (*b)[1] = wn;
  (*b)[2] = wb;
  (*b)[3] = wq;
  (*b)[4] = wk;
  (*b)[5] = wb;
  (*b)[6] = wn;
  (*b)[7] = wr;

  // Black back rank
  (*b)[112] = br;
  (*b)[113] = bn;
  (*b)[114] = bb;
  (*b)[115] = bq;
  (*b)[116] = bk;
  (*b)[117] = bb;
  (*b)[118] = bn;
  (*b)[119] = br;
}
