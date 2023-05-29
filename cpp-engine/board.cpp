#include "board.h"
#include <string>
#include <cstring>
#include "pieces.h"
#include "utils.h"
#include <iostream>
#include <boost/algorithm/string.hpp>

Board::Board(std::string fen){
	// Split the FEN into its properties
	std::vector<std::string> splitFen;
	boost::split(splitFen, fen, boost::is_any_of(" ")); 
	for(auto str : splitFen){
		std::cout << str << std::endl;
	}

	std::vector<std::vector<Pieces::Piece>> boardPosition;
	int whoseTurn;
	std::vector<int> availableCastles;

	// FEN board position to matrix
	std::vector<std::string> ranks;
	boost::split(ranks, splitFen[0], boost::is_any_of("/"));
	for(int i = 0; i < ranks.size(); i++){
		std::vector<Pieces::Piece*> rank;
		for(auto letter : ranks[i]){
			if(atoi((std::string{letter}).c_str())){
				for(int j = 0; j < atoi((std::string{letter}).c_str()); j++){
					rank.push_back(new Pieces::EmptySquare());
					std::cout << "empty" << std::endl;
				}
			}
			else{
				rank.push_back((Pieces::Piece*) Utils::letterToPiece(std::string{letter}));
				std::cout << rank[rank.size()-1]->pieceType << std::endl;
			}
		}	
	}
};

Board::Board() : Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") {}
int main(){
	Board();
}
