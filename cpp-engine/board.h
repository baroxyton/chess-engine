#pragma once
#include "pieces.h"
#include <vector>

#include <string>
class Board{
	public:
		Board(std::string fen);
		Board();
		std::vector<std::vector<char>> boardContent;
		bool makeMove(std::string);
		bool moveIsLegal(std::string);
		std::vector<int> legalCastles;
		std::vector<int> enpassantSquare;
		int toPlay;
		int numRepetitions;
};

