#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "chess/piece.h"
#include "chess/position.h"
#include "chess/move.h"
#include "chess/movegen.h"

// Piece offsets
int8_t ROOK_MOVESET[4] = {-1, 1, 16, -16};
int8_t BISHOP_MOVESET[4] = {15, 17, -15, -17};
int8_t QUEEN_MOVESET[8] = {-1, 1, 16, -16, 15, 17, -15, -17};
int8_t PAWN_MOVESET[3] = {16, 15, 17};
int8_t KNIGHT_MOVESET[8] = {18, 33, 31, 14, -18, -33, -31, -14};
int8_t KING_MOVESET[8] = {-1, 1, 16, -16, 15, 17, -15, -17};

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
static int is_empty(const Piece p) {
  return (!(p & 3));
}

// Discards the color from a piece.
static Piece strip_color(const Piece p) {
  return (p & 0xFC);
}

static void generate_sliding_moves(Move **moves, const Position *position, const Offset offset, const Square fs) {
  for (size_t i = 0; i < offset.size; i++) {
    int8_t dir = offset.moves[i];
    Color cur_color = position->side_to_move;
    Square cur_sq = fs + dir;

    while (on_board(cur_sq)) {
      Piece piece = position->board[cur_sq];

      if (is_friend(piece, cur_color)) {
        break;
      }

      (*moves)->from_square = fs;
      (*moves)->to_square   = cur_sq;
      (*moves)++;

      if (is_enemy(piece, cur_color)) {
        break;
      }

      cur_sq += dir;
    }
  }
}

static void generate_king_moves(Move **moves, const Position *position, const Offset offset, const Square fs){
  for (size_t i = 0; i < offset.size; i++){
    int8_t dir = offset.moves[i];
    Color cur_color = position->side_to_move;
    Square cur_sq = fs + dir;
    Piece piece = position->board[cur_sq];
      //firend on square
      if (is_friend(piece, cur_color)) {
        continue;
      }
      if (!on_board(cur_sq)){
        continue;
      }
      
      (*moves)->from_square = fs;
      (*moves)->to_square   = cur_sq;
      (*moves)++;
      
  }
}

static void generate_knight_moves(Move **moves, const Position *position, const Offset offset, const Square fs){
  for (size_t i = 0; i < offset.size; i++){
    int8_t dir = offset.moves[i];
    Color cur_color = position->side_to_move;
    Square cur_sq = fs + dir;
    Piece piece = position->board[cur_sq];
      //firend on square
      if (is_friend(piece, cur_color)) {
        continue;
      }
      if (!on_board(cur_sq)){
        continue;
      }
      
      (*moves)->from_square = fs;
      (*moves)->to_square   = cur_sq;
      (*moves)++;
      
  }
}

static int on_pawn_rank(Square sq, Color c){
  switch (c){
    case COLOR_WHITE:
      return (sq >= WHITE_RANK_START && sq <= WHITE_RANK_END);
    case COLOR_BLACK:
       return (sq >= BLACK_RANK_START && sq <= BLACK_RANK_END);
    default:
      return -1; // Something went wrong
  }
}

static int can_promote(Square sq){
  return ((sq >= FIRST_RANK_START && sq <= FIRST_RANK_END) 
  || (sq >= EIGHTH_RANK_START && sq <= EIGHTH_RANK_END));
}


static void generate_pawn_moves(Move **moves, const Position *position, const Square fs){
  
  Color cur_color = position->side_to_move;
  
  int8_t straight = 16;
  int8_t left = 15;
  int8_t right = 17;
  if (cur_color & COLOR_BLACK){
      straight = -16;
      left = -15;
      right = -17;
    }
  //MOVE FORWARD
  Square cur_sq = fs + straight;
   
  Piece piece = position->board[cur_sq];

  if (is_empty(piece)){
    (*moves)->from_square = fs;
    (*moves)->to_square   = cur_sq;
    if (can_promote(cur_sq)){
      // ADD PROMOTE FLAG TO MOVES
    } 
    (*moves)++;
    //Check double push
    if (on_pawn_rank(fs, cur_color)){
      cur_sq += straight;
      piece = position->board[cur_sq];
      if (is_empty(piece)){
        (*moves)->from_square = fs;
        (*moves)->to_square   = cur_sq;
        (*moves)++;
      }
    }
  }

  //MOVE DIAGONALY LEFT AND CAPTURE
  cur_sq = fs + left;
  if (on_board(cur_sq)){
    piece = position->board[cur_sq];

    if (is_enemy(piece, cur_color) ){
      (*moves)->from_square = fs;
      (*moves)->to_square   = cur_sq;
      if (can_promote(cur_sq)){
      // ADD PROMOTE FLAG TO MOVES
      } 
      (*moves)++;
    } 
  }

  //MOVE DIAGONALY RIGHT AND CAPTURE
  cur_sq = fs + right;
  if (on_board(cur_sq)){
    piece = position->board[cur_sq];

    if (is_enemy(piece, cur_color) ){
      (*moves)->from_square = fs;
      (*moves)->to_square   = cur_sq;
      if (can_promote(cur_sq)){
      // ADD PROMOTE FLAG TO MOVES
      } 
      (*moves)++;
    } 
  }
}

static void generate_castle_moves(Move **moves, const Position *position){
  
  if (position->side_to_move & COLOR_WHITE){
    if (position->can_castle & CASTLE_WHITE_QUEEN){
      if(is_empty(position->board[3]) && is_empty(position->board[2]) && is_empty(position->board[1])){
      (*moves)->from_square = 4;
      (*moves)->to_square   = 2;
      (*moves)++;
      }
    }
    if (position->can_castle & CASTLE_WHITE_KING){
      if(is_empty(position->board[5]) && is_empty(position->board[6])){
      (*moves)->from_square = 4;
      (*moves)->to_square   = 6;
      (*moves)++;
      }
    }
  }

  if (position->side_to_move & COLOR_BLACK){
    if (position->can_castle & CASTLE_BLACK_QUEEN){
      if(is_empty(position->board[115]) && is_empty(position->board[114]) && is_empty(position->board[113])){
      (*moves)->from_square = 116;
      (*moves)->to_square   = 114;
      (*moves)++;
      }
    }
    if (position->can_castle & CASTLE_BLACK_KING){
      if(is_empty(position->board[117]) && is_empty(position->board[118])){
      (*moves)->from_square = 116;
      (*moves)->to_square   = 118;
      (*moves)++;
      }
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
    case PIECE_BISHOP:
      o.size = 4;
      for (int i = 0; i < o.size; i++) {
        o.moves[i] = BISHOP_MOVESET[i]; 
      }
      return o;
    case PIECE_QUEEN:
      o.size = 8;
      for (int i = 0; i < o.size; i++) {
        o.moves[i] = QUEEN_MOVESET[i]; 
      }
      return o;
    case PIECE_KNIGHT:
      o.size = 8;
      for (int i = 0; i < o.size; i++) {
        o.moves[i] = KNIGHT_MOVESET[i]; 
      }
      return o;
    case PIECE_KING:
      o.size = 8;
      for (int i = 0; i < o.size; i++) {
        o.moves[i] = KING_MOVESET[i]; 
      }
      return o;
    case PIECE_PAWN:
      o.size = 4;
      for (int i = 0; i < o.size; i++) {
        o.moves[i] = PAWN_MOVESET[i]; 
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
          generate_sliding_moves(&moves, position, generate_offset(cur_piece), sq);
        }
        if (cur_piece == (PIECE_QUEEN | cur_color)) {
          generate_sliding_moves(&moves, position, generate_offset(cur_piece), sq);
        }
        if (cur_piece == (PIECE_BISHOP | cur_color)) {
          generate_sliding_moves(&moves, position, generate_offset(cur_piece), sq);
        }
        if (cur_piece == (PIECE_KNIGHT | cur_color)) {
          generate_knight_moves(&moves, position, generate_offset(cur_piece), sq);
        }
        if (cur_piece == (PIECE_KING | cur_color)) {
          generate_king_moves(&moves, position, generate_offset(cur_piece), sq);
          generate_castle_moves(&moves, position);
        }
        if (cur_piece == (PIECE_PAWN | cur_color)) {
          generate_pawn_moves(&moves, position, sq); // might be more optimal with colored pawn functions
        }
    }
}
