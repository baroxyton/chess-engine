#include "staticeval.h"
#include "utils.h"
#include "pieces.h"
#include "moveGenerator.h"

// Returns value in centipawns
// Evaluate for white
int Analysis::staticEvaluate(std::vector<std::vector<char>> parsedBoard)
{
    auto pseudolegalMoves = MoveGenerator::pseudolegalMoveGenerator(parsedBoard, std::vector<int>{}, std::vector<int>{}, false, true);
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

            if(pieceType == EMPTY_SQUARE){
                continue;
            }

            // Scalar depending on color
            int positiveEval = (pieceColor == COLOR_WHITE)?1:-1;

            evaluation += pieceValue * positiveEval * 100;

            if(pieceType == PIECE_BISHOP){
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
    return evaluation;
};