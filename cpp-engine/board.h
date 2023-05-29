#pragma once
#include "pieces.h"
#include <vector>

#include <string>
class Board{
	public:
		Board(std::string fen);
		Board();
		std::vector<std::vector<Pieces::Piece>> boardContent;
		bool makeMove(std::string);
		bool moveIsLegal(std::string);
};

