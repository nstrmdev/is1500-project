// Copyright (c) 2026 Pontus Nordström
// Copyright (c) 2026 Arvid Westman
// SPDX-License-Identifier: BSD-3-Clause

#include <chess/piece.h>
#include <chess/board.h>

int main(void) {
  Board b;

  construct_starting_position(&b);
  print_board(&b);
}
