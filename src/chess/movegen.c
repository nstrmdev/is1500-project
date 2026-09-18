#include <stdint.h>
#include "chess/piece.h"
#include "chess/board.h"
#include "chess/position.h"
uint8_t[4] ROOK_OFFSETS = {-1, 1, 16, -16};
uint8_t[4] BISHOP_OFFSETS = {15, 17, -15, -17};
// uint8_t[4] QUEEN_OFFSET = {-1, 1, 16, -16, 15, 17, -15, -17};

void sliding_moves(Move *moves, Position *position, uint8_t[] offset, int i)
{
    for (int i = 0; i < sizeof(offset) / sizeof(uint8_t); i++)
    {
        uint8_t direction = offset[i];
        uint8_t current_square = i;

        while ((current_square & 0x88) == 0)
        {
            curent_square += direction;
            if ((board[current_square] & *position->side_to_move))
            {
                break;
            }
            if ((board[current_square] & (*position->side_to_move) ^ 3))
            {
                
                *moves->from = i;
                *moves->to = current_square;
                moves++;
                break;
            }

            
            *moves->from = i;
            *moves->to = current_square;
            moves++;
        }
    }
}

void possible_moves(Move *moves, Position *position)
{

    for (int i = 0; i < 128; i++)
    {

        switch (*position->board[i])
        {
        case (PIECE_ROOK | *position->side_to_move):
            sliding_moves(moves, position, ROOK_OFFSETS, i);
        case (PIECE_KNIGHT | *position->side_to_move):

        case (PIECE_BISHOP | *position->side_to_move):
        case (PIECE_QUEEN | *position->side_to_move):
        case (PIECE_KING | *position->side_to_move):
        case (PIECE_PAWN | *position->side_to_move):
        case (EMPTY_SQUARE):
            continue;
            default EMPTY_SQUARE:
        }
    }
}
