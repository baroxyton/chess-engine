#include "pieces.h"
#include <string>
#include <boost/algorithm/string.hpp>
namespace Utils{
	Pieces::Piece letterToPiece(std::string letter){
		int color = 1;
		std::string lowerLetter = letter;
	       	boost::algorithm::to_lower(lowerLetter); 
		if(lowerLetter == letter){
			color = 0;
		}
		if(lowerLetter == "p"){
			return Pieces::Pawn(color);
		}
		else if(lowerLetter == "n"){
			return Pieces::Knight(color);
		}
		else if(lowerLetter == "b"){
			return Pieces::Bishop(color);
		}
		else if(lowerLetter == "r"){
			return Pieces::Rook(color);
		}
		else if(lowerLetter == "q"){
			return Pieces::Queen(color);
		}
		else if(lowerLetter == "k"){
			return Pieces::King(color);
		}
		else{
			return Pieces::EmptySquare();
		}
		
	}
}
