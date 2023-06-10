#include "pieces.h"
namespace Pieces
{
	char generatePiece(int type, int color)
	{
		bool isWhite = (color == COLOR_WHITE);
		switch (type)
		{
		case PIECE_PAWN:
			return isWhite ? WHITE_PAWN : BLACK_PAWN;
			break;
		case PIECE_KNIGHT:
			return isWhite ? WHITE_KNIGHT : BLACK_KNIGHT;
			break;
		case PIECE_BISHOP:
			return isWhite ? WHITE_BISHOP : BLACK_BISHOP;
			break;
		case PIECE_ROOK:
			return isWhite ? WHITE_ROOK : BLACK_ROOK;
			break;
		case PIECE_QUEEN:
			return isWhite ? WHITE_QUEEN : BLACK_QUEEN;
			break;
		case PIECE_KING:
			return isWhite ? WHITE_KING : BLACK_KING;
			break;
		default:
			return EMPTY_SQUARE;
		}
	};
	int getColor(char piece)
	{
		switch (piece)
		{
		case WHITE_PAWN:
		case WHITE_KNIGHT:
		case WHITE_BISHOP:
		case WHITE_ROOK:
		case WHITE_QUEEN:
		case WHITE_KING:
			return COLOR_WHITE;
			break;
		case BLACK_PAWN:
		case BLACK_KNIGHT:
		case BLACK_BISHOP:
		case BLACK_ROOK:
		case BLACK_QUEEN:
		case BLACK_KING:
			return COLOR_BLACK;
			break;
		default:
			return COLOR_NONE;
		}
	}
	int getType(char piece)
	{
		switch (piece)
		{
		case WHITE_PAWN:
		case BLACK_PAWN:
			return PIECE_PAWN;
			break;
		case WHITE_KNIGHT:
		case BLACK_KNIGHT:
			return PIECE_KNIGHT;
			break;
		case WHITE_BISHOP:
		case BLACK_BISHOP:
			return PIECE_BISHOP;
			break;
		case WHITE_ROOK:
		case BLACK_ROOK:
			return PIECE_ROOK;
			break;
		case WHITE_QUEEN:
		case BLACK_QUEEN:
			return PIECE_QUEEN;
			break;
		case WHITE_KING:
		case BLACK_KING:
			return PIECE_KING;
			break;
		default:
			return PIECE_NONE;
		}
	}
	int getValue(char piece)
	{
		int pieceType = getType(piece);
		switch (piece)
		{
		case PIECE_PAWN:
			return 1;
		case PIECE_KNIGHT:
			return 3;
		case PIECE_BISHOP:
			return 3.25;
		case PIECE_ROOK:
			return 5;
		case PIECE_QUEEN:
			return 9.5;
		default:
			return -1;
		}
	}
}
