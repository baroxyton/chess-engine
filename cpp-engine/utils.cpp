#include "pieces.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <algorithm>
namespace Utils
{
	Pieces::Piece *letterToPiece(std::string letter)
	{
		int color = COLOR_WHITE;
		std::string lowerLetter = letter;
		boost::algorithm::to_lower(lowerLetter);
		if (lowerLetter == letter)
		{
			color = COLOR_BLACK;
		}
		if (lowerLetter == "p")
		{
			return new Pieces::Pawn{color};
		}
		else if (lowerLetter == "n")
		{
			return new Pieces::Knight{color};
		}
		else if (lowerLetter == "b")
		{
			return new Pieces::Bishop{color};
		}
		else if (lowerLetter == "r")
		{
			return new Pieces::Rook{color};
		}
		else if (lowerLetter == "q")
		{

			return new Pieces::Queen{color};
		}
		else if (lowerLetter == "k")
		{

			return new Pieces::King{color};
		}
		else
		{
			return new Pieces::EmptySquare{};
		}
	}

	std::vector<int> fileAndRank(std::string square)
	{
		int file = square[0] - 'a';
		int rank = atoi(std::string{square[1]}.c_str());

		return std::vector<int>{file, rank};
	}

	parsedBoard parseFEN(std::string fen)
	{
		parsedBoard result;

		// Split the FEN into its properties
		std::vector<std::string> splitFen;
		boost::split(splitFen, fen, boost::is_any_of(" "));

		std::vector<std::vector<Pieces::Piece *>> boardPosition;
		int whoseTurn;
		std::vector<int> availableCastles = std::vector<int>{0, 0, 0, 0};

		// FEN board position to matrix
		std::vector<std::string> ranks;
		boost::split(ranks, splitFen[0], boost::is_any_of("/"));
		for (int i = 0; i < ranks.size(); i++)
		{
			std::vector<Pieces::Piece *> rank;
			for (auto letter : ranks[i])
			{
				if (atoi((std::string{letter}).c_str()))
				{
					for (int j = 0; j < atoi((std::string{letter}).c_str()); j++)
					{
						rank.push_back((Pieces::Piece *)new Pieces::EmptySquare());
					}
				}
				else
				{
					rank.push_back((Pieces::Piece *)Utils::letterToPiece(std::string{letter}));
				}
			}
			boardPosition.push_back(rank);
		}
		std::reverse(boardPosition.begin(), boardPosition.end());

		if (splitFen.size() < 3)
		{
			splitFen[2] = "";
		}
		for (auto letter : splitFen[2])
		{
			if (letter == 'K')
			{
				availableCastles[0] = 1;
			}
			if (letter == 'Q')
			{
				availableCastles[1] = 1;
			}
			if (letter == 'k')
			{
				availableCastles[2] = 1;
			}
			if (letter == 'q')
			{
				availableCastles[3] = 1;
			}
		}
		if (splitFen.size() < 2)
		{
			splitFen[1] = "w";
		}
		if (splitFen[1] == "w")
		{
			whoseTurn = 0;
		}
		else
		{
			whoseTurn = 1;
		}
		if (splitFen.size() < 4)
		{
			splitFen[3] = "-";
		}
		std::string enpassantSquare = splitFen[3];
		if (splitFen[3].size() != 2)
		{
			enpassantSquare = "-";
		}

		result.boardContent = boardPosition;
		if (splitFen[3].size() == 2)
		{
			result.enpassantSquare = fileAndRank(enpassantSquare);
		}
		else
		{
			result.enpassantSquare = std::vector<int>{};
		}
		result.legalCastles = availableCastles;
		result.toPlay = whoseTurn;
		result.numRepetitions = 0;
		return result;
	}

	std::string squareToStr(std::vector<int> square){
		std::string result;
		std::string file = (std::vector<std::string>{"a", "b", "c", "d", "e", "f", "g", "h"})[square[0]];
		int rank = square[1]+1;

		return file + std::to_string(rank);
	}
}
