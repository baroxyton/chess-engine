#pragma once
#include "pieces.h"
#include <vector>
namespace Analysis{
    int minMax(std::vector<std::vector<char>> &board, std::vector<int> legalCastles, std::vector<int> enpassantSquares, int depth, int toPlay);
}