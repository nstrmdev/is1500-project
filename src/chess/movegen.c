#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "chess/piece.h"
#include "chess/position.h"
#include "chess/move.h"

int8_t ROOK_OFFSETS[4] = {-1, 1, 16, -16};
int8_t BISHOP_OFFSETS[4] = {15, 17, -15, -17};
// uint8_t[4] QUEEN_OFFSET = {-1, 1, 16, -16, 15, 17, -15, -17};

static void sliding_moves(Move *moves, Position *position, int8_t offset[], int start_square) {
  for (size_t i = 0; i < 4; i++) {
    int8_t current_square = start_square;
    int8_t direction = offset[i];
    current_square += direction;

    while ((current_square & 0x88) == 0) {
      Piece piece = (*position->board)[current_square];

      if (piece & position->side_to_move) {
        break;
      }

      moves->from_square = start_square;
      moves->to_square   = current_square;
      moves++;

      if (piece & (position->side_to_move ^ 3)) {
        break;
      }

      current_square += direction;
    }
  }
}

void possible_moves(Move *moves, Position *position) {
    for (int i = 0; i < 128; i++) {
        uint8_t current_color = position->side_to_move;
        if ((*position->board)[i] == (PIECE_ROOK | current_color)) {
          sliding_moves(moves, position, ROOK_OFFSETS, i);
        }
    }
}
