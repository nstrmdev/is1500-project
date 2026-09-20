#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "chess/piece.h"
#include "chess/position.h"
#include "chess/move.h"
#include "chess/movegen.h"

// Piece offsets
uint8_t ROOK_MOVESET[] = {-1, 1, 16, -16};

// Is piece on board?
// Returns true if on board, false if not.
static int on_board(const Square sq) {
  return !(sq & 0x88);
}

// Is a specific piece of our color?
static int is_friend(const Piece p, const Color c) {
  return (p & c);
}

// Flips the color.
static int is_enemy(const Piece p, const Color c) {
  return (p & (c ^ 3));
}

// Discards the color from a piece.
static Piece strip_color(const Piece p) {
  return (p & 0xFC);
}

static void generate_sliding_moves(Move *moves, const Position *position, const Offset offset, const Square fs) {
  for (size_t i = 0; i < offset.size; i++) {
    int8_t dir = offset.moves[i];
    Color cur_color = position->side_to_move;
    Square cur_sq = fs + dir;

    while (on_board(cur_sq)) {
      Piece piece = position->board[cur_sq];

      if (is_friend(piece, cur_color)) {
        break;
      }

      moves->from_square = fs;
      moves->to_square   = cur_sq;
      moves++;

      if (is_enemy(piece, cur_color)) {
        break;
      }

      cur_sq += dir;
    }
  }
}

static Offset generate_offset(Piece p) {
  Offset o;

  switch(strip_color(p)) {
    case PIECE_ROOK:
      o.size = 4;
      for (int i = 0; i < o.size; i++) {
        o.moves[i] = ROOK_MOVESET[i];
      }
      return o;

    default:
      // Something must have gone wrong
      o.size = -1;
      return o;
  }
}

void generate_pseudo_legal_moves(Move *moves, Position *position) {
    for (int sq = 0; sq < 128; sq++) {
        Color cur_color = position->side_to_move;
        Piece cur_piece = position->board[sq];
        if (cur_piece == (PIECE_ROOK | cur_color)) {
          generate_sliding_moves(moves, position, generate_offset(cur_piece), sq);
        }
    }
}
