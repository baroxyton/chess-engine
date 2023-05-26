#pragma once
#include <string>
namespace Pieces{
	class Piece{
		public:
			int file;
			int color;
			int pieceValue;
			int pieceType;
	};
	class Pawn : Piece{
		public:
			Pawn(int rank, int file, int color);
			const static int pieceType = 0;
			const static int pieceValue = 1;
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
			const static int pieceValue = 3.1;
	}; 
	class Knight : Piece{
		public:
			Knight(int rank, int file, int color);
			const static int pieceType = 1;
			int file;
			int rank;
			int color;
			const static int pieceValue = 3;
	}; 
	class Rook : Piece{
		public:
			Rook(int rank, int file, int color);
			const static int pieceType = 3;
			int file;
			int rank;
			int color;
			const static int pieceValue = 5;
	};
	class Queen : Piece{
		public:
			Queen(int rank, int file, int color);
			const static int pieceType = 4;
			int file;
			int rank;
			int color;
			const static int pieceValue = 9;
	};
	class King : Piece{
		public:
			King(int rank, int file, int color);
			const static int pieceType = 5;
			int file;
			int rank;
			int color;
			const static int pieceValue = 0;
	};
	class EmpySquare{
		EmptySquare(int rank, int file);
		int rank;
		int file;
		const static int pieceType = -1;
		const static int color = -1;
		const static int pieceValue = 0;
	};
}
