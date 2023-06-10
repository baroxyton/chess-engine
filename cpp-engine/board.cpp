#include "board.h"
#include <string>
#include <cstring>
#include "pieces.h"
#include "utils.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "moveGenerator.h"

Board::Board(std::string fen)
{
	Utils::parsedBoard parsedBoard = Utils::parseFEN(fen);

	boardContent = parsedBoard.boardContent;
	legalCastles = parsedBoard.legalCastles;
	enpassantSquare = parsedBoard.enpassantSquare;
	numRepetitions = parsedBoard.numRepetitions;
	toPlay = parsedBoard.toPlay;

	auto valid_moves = MoveGenerator::legalMoveGenerator(boardContent, legalCastles, enpassantSquare, toPlay);
	std::cout << "NUM LEGAL MOVES: " << valid_moves.size() << std::endl;
	for(auto move : valid_moves){
		std::cout << Utils::squareToStr(move[0]) << " TO " << Utils::squareToStr(move[1]) << std::endl;
	}

};
Board::Board() : Board("3rrr2/8/8/7B/8/8/r7/4K3 w - - 0 1") {}
int main()
{
	Board();
}
