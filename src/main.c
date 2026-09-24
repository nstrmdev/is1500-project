// Copyright (c) 2026 Pontus Nordström
// Copyright (c) 2026 Arvid Westman
// SPDX-License-Identifier: BSD-3-Clause

#include <chess/piece.h>
#include <chess/board.h>
#include <chess/move.h>
#include <chess/position.h>
#include <chess/movegen.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Position p;
  p.side_to_move = COLOR_BLACK;
  p.can_castle = 15;

  Move *moves = malloc(256 * sizeof(Move));

  construct_temp_board(p.board);
  print_board(p.board);

  generate_pseudo_legal_moves(moves, &p);

  for (int i = 0; i < 256; i++) {
    printf("From: %d", moves[i].from_square);
    printf("To: %d", moves[i].to_square);
    printf("\n");
  }
}
