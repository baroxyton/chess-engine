#pragma once
#include "utils.h"
#include "pieces.h"
#include <vector>
namespace MoveGenerator{
    std::vector<std::vector<std::vector<int>>> pseudolegalMoveGenerator(std::vector<std::vector<Pieces::Piece *>> &board);
}