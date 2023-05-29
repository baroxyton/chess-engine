#include "pieces.h"
namespace Pieces{
		Piece::Piece() : pieceType(-1), color(-1), pieceValue(-1) {};
		
		Pawn::Pawn(int color){
			this->color = color;
			pieceType=0;
			pieceValue = 1;
		}

		Knight::Knight(int color){
			this->color = color;
			pieceType=1;
			pieceValue = 3;
		}
		
		Bishop::Bishop(int color){
			this->color = color;
			pieceType=2;
			pieceValue = 3.25;
		}

		Rook::Rook(int color){
			this->color = color;
			pieceType=3;
			pieceValue = 5;
		}

		Queen::Queen(int color){
			this->color = color;
			pieceType=4;
			pieceValue = 9;
		}
		
		King::King(int color){
			this->color = color;
			pieceType=5;
			pieceValue = 0;
		}

		EmptySquare::EmptySquare(){
			pieceType = -1;
			color = -1;
			pieceValue = -1;
		};
}
