#pragma once
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
