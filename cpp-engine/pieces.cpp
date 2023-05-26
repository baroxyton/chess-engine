#include "pieces.h"
namespace Pieces{
		Pawn::Pawn(int color) :  color(color){};

		Knight::Knight(int color) : color(color){};
		
		Bishop::Bishop(int color) :  color(color){};

		Rook::Rook(int color) : color(color){};

		Queen::Queen(int color) : color(color){};
		
		King::King(int color) : color(color){};

		EmptySquare::EmptySquare(){};
}
