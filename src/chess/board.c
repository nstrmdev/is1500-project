// Copyright (c) 2026 Pontus Nordström
// Copyright (c) 2026 Arvid Westman
// SPDX-License-Identifier: BSD-3-Clause

#include "chess/board.h"
#include "chess/piece.h"
#include <stdio.h>

static void clear_board(Board b) {
  Piece e  = EMPTY_SQUARE;

  for (int i = 0; i <= 127; i++) {
    b[i] = e;
  }
}

static char piece_to_char(const Piece piece) {
  switch (piece) {
    case EMPTY_SQUARE:
      return '.';

    case (WHITE_PAWN):
      return 'P';
    case (WHITE_ROOK):
      return 'R';
    case (WHITE_KNIGHT):
      return 'N';
    case (WHITE_BISHOP):
      return 'B';
    case (WHITE_QUEEN):
      return 'Q';
    case (WHITE_KING):
      return 'K';

    case (BLACK_PAWN):
      return 'p';
    case (BLACK_ROOK):
      return 'r';
    case (BLACK_KNIGHT):
      return 'n';
    case (BLACK_BISHOP):
      return 'b';
    case (BLACK_QUEEN):
      return 'q';
    case (BLACK_KING):
      return 'k';

    default:
      return '?';
  }
}

void print_board(Board b) {
  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file <= 7; file++) {
      int square = 16 * rank + file;
      printf("%c ", piece_to_char(b[square]));
    }
    printf("\n");
  }
}

// TEMPORARY DESTROY THIS
void construct_temp_board(Board b) {
  // Set all squares to empty
  clear_board(b);

  b[51] = WHITE_ROOK;
  b[52] = WHITE_KNIGHT;
  b[67] = WHITE_KING;
  b[20] = WHITE_PAWN;
  b[21] = WHITE_PAWN;
  b[4] = WHITE_PAWN;
  b[68] = BLACK_PAWN;
  b[99] = BLACK_PAWN;
  b[98] = BLACK_PAWN;
  b[19] = BLACK_QUEEN;
  b[36] = BLACK_PAWN;
  b[7] = BLACK_BISHOP;
  
}

void construct_starting_position(Board b) {
  // Set all squares to empty
  clear_board(b);

  // Place pawns
  for (int i = 16; i <= 23; i++) {
     b[i] = WHITE_PAWN;
  }

  for (int i = 96; i <= 103; i++) {
    b[i] = BLACK_PAWN;
  }

  // White back rank
  b[0] = WHITE_ROOK;
  b[1] = WHITE_KNIGHT;
  b[2] = WHITE_BISHOP;
  b[3] = WHITE_QUEEN;
  b[4] = WHITE_KING;
  b[5] = WHITE_BISHOP;
  b[6] = WHITE_KNIGHT;
  b[7] = WHITE_ROOK;

  // Black back rank
  b[112] = BLACK_ROOK;
  b[113] = BLACK_KNIGHT;
  b[114] = BLACK_BISHOP;
  b[115] = BLACK_QUEEN;
  b[116] = BLACK_KING;
  b[117] = BLACK_BISHOP;
  b[118] = BLACK_KNIGHT;
  b[119] = BLACK_ROOK;
}
