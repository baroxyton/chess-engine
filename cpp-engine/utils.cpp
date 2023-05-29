#include "pieces.h"
#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
namespace Utils{
	Pieces::Piece* letterToPiece(std::string letter){
		int color = 1;
		std::string lowerLetter = letter;
	       	boost::algorithm::to_lower(lowerLetter); 
		if(lowerLetter == letter){
			color = 0;
		}
		if(lowerLetter == "p"){
			return  new Pieces::Pawn{color};
		}
		else if(lowerLetter == "n"){
			return new Pieces::Knight{color};
		}
		else if(lowerLetter == "b"){
			return new Pieces::Bishop{color};
		}
		else if(lowerLetter == "r"){
			return new Pieces::Rook{color};
		}
		else if(lowerLetter == "q"){

			return new Pieces::Queen{color};
		}
		else if(lowerLetter == "k"){

			return new Pieces::King{color};
		}
		else{
			return new Pieces::EmptySquare{};
		}
		
	}
}
