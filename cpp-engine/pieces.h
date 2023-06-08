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

#include <string>
namespace Pieces{
	class Piece{
		public:
		Piece();
		int color;
		int pieceType;
		int pieceValue;
	};
	class Pawn : public Piece{
		public:
			Pawn(int color);
	};
	class Bishop : public Piece{
		public:
			Bishop(int color);
	}; 
	class Knight : public Piece{
		public:
			Knight(int color);
	}; 
	class Rook : public Piece{
		public:
			Rook(int color);
	};
	class Queen : public Piece{
		public:
			Queen(int color);
	};
	class King : public Piece{
		public:
			King(int color);
	};
	class EmptySquare : public Piece{
		public:
		EmptySquare();
	};
}
