#pragma once
#include "pieces.h"
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

namespace Utils
{
	struct parsedBoard
	{
		std::vector<std::vector<Pieces::Piece*>> boardContent;
		std::vector<int> legalCastles;
		std::vector<int> enpassantSquare;
		int toPlay;
		int numRepetitions;
	};
	Pieces::Piece *letterToPiece(std::string letter);
	parsedBoard parseFEN(std::string fen);
	std::vector<int> fileAndRank(std::string square);
};
