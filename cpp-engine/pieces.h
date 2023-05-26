#pragma once
#include <string>
namespace Pieces{
	class Piece{
		public:
			int color;
			int pieceValue;
			int pieceType;
	};
	class Pawn : Piece{
		public:
			Pawn(int color);
			const static int pieceType = 0;
			const static int pieceValue = 1;
			int color;
	};
	class Bishop : Piece{
		public:
			Bishop(int color);
			const static int pieceType = 2;
			int color;
			const static int pieceValue = 3.1;
	}; 
	class Knight : Piece{
		public:
			Knight(int color);
			const static int pieceType = 1;
			int color;
			const static int pieceValue = 3;
	}; 
	class Rook : Piece{
		public:
			Rook(int color);
			const static int pieceType = 3;
			int color;
			const static int pieceValue = 5;
	};
	class Queen : Piece{
		public:
			Queen(int color);
			const static int pieceType = 4;
			int color;
			const static int pieceValue = 9;
	};
	class King : Piece{
		public:
			King(int color);
			const static int pieceType = 5;
			int color;
			const static int pieceValue = 0;
	};
	class EmptySquare{
		EmptySquare();
		const static int pieceType = -1;
		const static int color = -1;
		const static int pieceValue = 0;
	};
}
