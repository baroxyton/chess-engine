#pragma once
#include "utils.h"
#include "pieces.h"
#include <vector>
namespace MoveGenerator
{
    std::vector<std::vector<std::vector<int>>> pseudolegalMoveGenerator(std::vector<std::vector<char>> &board, std::vector<int> legalCastles, std::vector<int> enpassantSquare, int turn);
    std::vector<std::vector<std::vector<int>>> legalMoveGenerator(std::vector<std::vector<char>> board, std::vector<int> legalCastles, std::vector<int> enpassantSquare, int turn);
}