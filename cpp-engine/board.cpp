#include "board.h"
#include <string>
#include <cstring>
#include "pieces.h"
#include "utils.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "moveGenerator.h"
#include "staticeval.h"

Board::Board(std::string fen)
{
	Utils::parsedBoard parsedBoard = Utils::parseFEN(fen);

	boardContent = parsedBoard.boardContent;
	legalCastles = parsedBoard.legalCastles;
	enpassantSquare = parsedBoard.enpassantSquare;
	numRepetitions = parsedBoard.numRepetitions;
	toPlay = parsedBoard.toPlay;
	auto valid_moves = MoveGenerator::pseudolegalMoveGenerator(boardContent, legalCastles, enpassantSquare, toPlay, false, true);
	/*
	// Current performance: ~8500 moves per second (legal move, start position)
	// ~200'000 moves per second (pseudo-legal move, start position)
	for (int i = 0; i < 100000; i++)
	{
		valid_moves = MoveGenerator::legalMoveGenerator(boardContent, legalCastles, enpassantSquare, toPlay);
	}
	*/
	std::cout << "NUM LEGAL MOVES: " << valid_moves.size() << std::endl;
	std::cout << Utils::squareToStr(enpassantSquare) << std::endl;
	for (auto move : valid_moves)
	{
		std::cout << Utils::squareToStr(move[0]) << " TO " << Utils::squareToStr(move[1]) << std::endl;
	}
		std::cout << "ANALYSIS: " << Analysis::staticEvaluate(boardContent) << std::endl;

};
Board::Board() : Board("r1bqk2r/pppp1ppp/5n2/8/2BQP3/8/PP3PPP/RNB1K2R b KQkq - 0 8") {}
int main()
{
	auto board = Board();
}
