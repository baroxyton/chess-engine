#pragma once
#include "pieces.h"
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

namespace Utils
{
	struct parsedBoard
	{
		std::vector<std::vector<char>> boardContent;
		std::vector<int> legalCastles;
		std::vector<int> enpassantSquare;
		int toPlay;
		int numRepetitions;
	};
	char letterToPiece(std::string letter);
	parsedBoard parseFEN(std::string fen);
	std::vector<int> fileAndRank(std::string square);
	std::string squareToStr(std::vector<int> square);
};
