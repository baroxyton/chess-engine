#pragma once
#include "utils.h"
#include "pieces.h"
#include <vector>
namespace MoveGenerator
{
    std::vector<std::vector<std::vector<int>>> pseudolegalMoveGenerator(std::vector<std::vector<char>> &board, std::vector<int> legalCastles, std::vector<int> enpassantSquare, int turn, bool rangePiecesOnly, bool bothSides);
    std::vector<std::vector<std::vector<int>>> legalMoveGenerator(const std::vector<std::vector<char>>& board, const std::vector<int>& legalCastles, const std::vector<int>& enpassantSquare, int turn);
}