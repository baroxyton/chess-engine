#include "staticeval.h"
#include "utils.h"
#include "pieces.h"
#include "moveGenerator.h"
#include <math.h>
#include <iostream>

// Returns value in centipawns
// Evaluate for white
int Analysis::staticEvaluate(std::vector<std::vector<char>> parsedBoard)
{
    auto pseudolegalMoves = MoveGenerator::pseudolegalMoveGenerator(parsedBoard, std::vector<int>{0, 0, 0, 0}, std::vector<int>{}, COLOR_WHITE, false, true);
    int evaluation = 0;
    for (int i = 0; i < parsedBoard.size(); i++)
    {
        auto row = parsedBoard[i];
        for (int j = 0; j < row.size(); j++)
        {
            auto piece = row[j];

            auto pieceType = Pieces::getType(piece);
            auto pieceColor = Pieces::getColor(piece);
            auto pieceValue = Pieces::getValue(piece);

            if(pieceType == PIECE_NONE){
                continue;
            }

            // Scalar depending on color
            int positiveEval = (pieceColor == COLOR_WHITE)?1:-1;

            evaluation += pieceValue * positiveEval * 100;
            if(pieceType == PIECE_BISHOP||pieceType == PIECE_QUEEN){
                int numMoves = 0;
                
                for(auto move : pseudolegalMoves){
                    if(move[0][1] == i && move[0][0] == j){
                        numMoves++;
                    }
                }
                // Average bishop should see around ~6 squares, so more squares are counted good, less bad
                // locked in bishop: 1 pawn value
                evaluation += ceil((double)(numMoves - 6) * (double)33.333333) * positiveEval;

            }
            if(pieceType == PIECE_ROOK){
                if(i == (pieceColor==COLOR_WHITE)?7:2){
                    evaluation += 1.5 * 100 * positiveEval;
                }
            }
        }
    }
    /*
    if(evaluation == -1){
        std::cout << "ERROR";
        for(auto line : parsedBoard){
            for(auto piece : line){
                if(piece == EMPTY_SQUARE){
                    std::cout << "1";
                }
                else{
                    std::cout << std::vector<std::string>{"pawn", "bishop", "knight", "rook", "queen", "king"}[Pieces::getType(piece)] << " ";
                }
                std::cout << "/";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    */
    return evaluation;
};