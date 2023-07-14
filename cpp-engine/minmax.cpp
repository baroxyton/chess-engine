#include "minmax.h"
#include "staticeval.h"
#include "moveGenerator.h"
#include "utils.h"
#include <iostream>
namespace Analysis
{
    int minMax(std::vector<std::vector<char>> &board, std::vector<int> legalCastles, std::vector<int> enpassantSquares, int depth, int toPlay)
    {
        std::vector<int> bestMoves;
        if (depth == 0)
        {
            return Analysis::staticEvaluate(board);
        }
        auto legalMoves = MoveGenerator::pseudolegalMoveGenerator(board, legalCastles, enpassantSquares, toPlay, false, false);
        
        if (toPlay == COLOR_WHITE)
        {
            
            int maxEval = INT_MIN;
            for(auto move : legalMoves){
                if(board[move[1][1]][move[1][0]] == BLACK_KING){
                    return 10000;
                }
                std::vector<std::vector<char>> boardClone = board;
                boardClone = Utils::boardMove(boardClone, move[0], move[1]);
                auto eval = minMax(boardClone, legalCastles, enpassantSquares, depth-1, COLOR_BLACK);
                if(depth == 4){
                    std::cout << eval << " " << Utils::squareToStr(move[0]) << " " << Utils::squareToStr(move[1]) << std::endl;
                }
                maxEval = std::max(eval, maxEval);
            }
            return maxEval;
        }
        else{
            int minEval = INT_MAX;
            for(auto move : legalMoves){
                if(board[move[1][1]][move[1][0]] == WHITE_KING){
                    return -10000;
                }
                std::vector<std::vector<char>> boardClone = board;
                boardClone = Utils::boardMove(boardClone, move[0], move[1]);
                auto eval = minMax(boardClone, legalCastles, enpassantSquares, depth-1, COLOR_WHITE);
                if(depth == 4){
                   std::cout << eval << " " << Utils::squareToStr(move[0]) << " " << Utils::squareToStr(move[1]) << std::endl;
                }
                minEval = std::min(eval, minEval);
            }
            return minEval;
        }
    }

}