#pragma once
#define COLOR_NONE -1
#define COLOR_WHITE 0
#define COLOR_BLACK 1

#define PIECE_NONE -1
#define PIECE_PAWN 0
#define PIECE_KNIGHT 1
#define PIECE_BISHOP 2
#define PIECE_ROOK 3
#define PIECE_QUEEN 4
#define PIECE_KING 5

#define WHITE_KING 'K'
#define WHITE_QUEEN 'Q'
#define WHITE_ROOK 'R'
#define WHITE_BISHOP 'B'
#define WHITE_KNIGHT 'N'
#define WHITE_PAWN 'P'

#define BLACK_KING 'k'
#define BLACK_QUEEN 'q'
#define BLACK_ROOK 'r'
#define BLACK_BISHOP 'b'
#define BLACK_KNIGHT 'n'
#define BLACK_PAWN 'p'

#define EMPTY_SQUARE ' '

#include <string>
namespace Pieces
{
	char generatePiece(int type, int color);
	int getColor(char piece);
	int getType(char piece);
	int getValue(char piece);
}
