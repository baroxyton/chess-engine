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

	auto valid_moves = MoveGenerator::pseudolegalMoveGenerator(boardContent, legalCastles, enpassantSquare, toPlay);
	for(auto move : valid_moves){
		std::cout << Utils::squareToStr(move[0]) << " TO " << Utils::squareToStr(move[1]) << std::endl;
	}

};
Board::Board() : Board("rnb1kbnr/pp2pppp/8/2pq4/6P1/8/PPPPPP1P/R1BQKBNR b KQkq - 0 4") {}
int main()
{
	Board();
}
