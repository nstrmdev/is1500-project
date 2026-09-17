#include <chess/piece.h>
#include <chess/board.h>
#include <stdio.h>

int main(void) {
  Board b;

  construct_starting_position(&b);
  print_board(&b);
}
