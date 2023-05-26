#pragma once
#include <string>
namespace Pieces{
	class Piece{
		public:
		int pieceType;
			int file;
			int color;
	};
	class Pawn : Piece{
		public:
			Pawn(int rank, int file, int color);
			const static int pieceType = 0;
			int file;
			int rank;
			int color;
	};
	class Bishop : Piece{
		public:
			Bishop(int rank, int file, int color);
			const static int pieceType = 2;
			int file;
			int rank;
			int color;
	}; 
	class Knight : Piece{
		public:
			Knight(int rank, int file, int color);
			const static int pieceType = 1;
			int file;
			int rank;
			int color;
	}; 
	class Rook : Piece{
		public:
			Rook(int rank, int file, int color);
			const static int pieceType = 3;
			int file;
			int rank;
			int color;
	};
	class Queen : Piece{
		public:
			Queen(int rank, int file, int color);
			const static int pieceType = 4;
			int file;
			int rank;
			int color;
	};
	class King : Piece{
		public:
			King(int rank, int file, int color);
			const static int pieceType = 5;
			int file;
			int rank;
			int color;
	};
}
