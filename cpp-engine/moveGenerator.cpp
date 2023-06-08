#include "moveGenerator.h"
#include "pieces.h"
#include <vector>
namespace MoveGenerator
{
    // list[rank, file, (promotion)]
    std::vector<std::vector<std::vector<int>>> pseudolegalMoveGenerator(std::vector<std::vector<Pieces::Piece *>> &board)
    {
        std::vector<std::vector<std::vector<int>>> result;
        // Loop through ranks
        for (int i = 0; i < 8; i++)
        {
            // loop through files
            for (int j = 0; j < 8; j++)
            {
                auto piece = board[i][j];
                // Empty square
                if (piece->pieceType == PIECE_NONE)
                {
                    continue;
                }
                auto pieceColor = piece->color;
                // Pawn
                // Pawn
                if (piece->pieceType == PIECE_PAWN)
                {
                    int direction = 1;
                    bool isPromotion = (i == 6 && pieceColor == COLOR_WHITE) || (i == 1 && pieceColor == COLOR_BLACK);
                    bool doubleMove = (i == 6 && pieceColor == COLOR_BLACK) || (i == 1 && pieceColor == COLOR_WHITE);
                    int promotion = isPromotion ? 0 : 1;
                    if (pieceColor == COLOR_BLACK)
                    {
                        direction = -1;
                    }

                    // Single move forward
                    if (board[i + direction][j]->pieceType == PIECE_NONE)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{i, j}, std::vector<int>{i + direction, j, promotion}});

                        // Double move from starting position
                        if (doubleMove && board[i + 2 * direction][j]->pieceType == PIECE_NONE)
                        {
                            result.push_back(std::vector<std::vector<int>>{std::vector<int>{i, j}, std::vector<int>{i + 2 * direction, j, promotion}});
                        }
                    }

                    // Capture diagonally
                    if (j != 0 && board[i + direction][j - 1]->color != COLOR_NONE && board[i + direction][j - 1]->color != pieceColor)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{i, j}, std::vector<int>{i + direction, j - 1, promotion}});
                    }

                    if (j != 7 && board[i + direction][j + 1]->color != COLOR_NONE && board[i + direction][j + 1]->color != pieceColor)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{i, j}, std::vector<int>{i + direction, j + 1, promotion}});
                    }
                }

                // Knight
                if (piece->pieceType == PIECE_KNIGHT)
                {
                    std::vector<std::pair<int, int>> knightMoves = {
                        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

                    for (const auto &move : knightMoves)
                    {
                        int x = i + move.first;
                        int y = j + move.second;

                        if (x >= 0 && x < 8 && y >= 0 && y < 8)
                        {
                            if (board[x][y]->color == pieceColor)
                            {
                                continue; // Skip if the target square contains a friendly piece
                            }

                            result.push_back(std::vector<std::vector<int>>{
                                std::vector<int>{i, j},
                                std::vector<int>{x, y, 0}});
                        }
                    }
                    // Bishop
                    if (piece->pieceType == PIECE_BISHOP)
                    {
                        std::vector<std::pair<int, int>> bishopDirections = {
                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

                        for (const auto &direction : bishopDirections)
                        {
                            int dx = direction.first;
                            int dy = direction.second;
                            int x = i + dx;
                            int y = j + dy;

                            while (x >= 0 && x < 8 && y >= 0 && y < 8)
                            {
                                if (board[x][y]->color == pieceColor)
                                {
                                    break; // Stop if the target square contains a friendly piece
                                }

                                result.push_back(std::vector<std::vector<int>>{
                                    std::vector<int>{i, j},
                                    std::vector<int>{x, y, 0}});

                                if (board[x][y]->color != COLOR_NONE)
                                {
                                    break; // Stop if the target square contains an opponent's piece
                                }

                                x += dx;
                                y += dy;
                            }
                        }
                    }
                    // Rook
                    if (piece->pieceType == PIECE_ROOK)
                    {
                        std::vector<std::pair<int, int>> rookDirections = {
                            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

                        for (const auto &direction : rookDirections)
                        {
                            int dx = direction.first;
                            int dy = direction.second;
                            int x = i + dx;
                            int y = j + dy;

                            while (x >= 0 && x < 8 && y >= 0 && y < 8)
                            {
                                if (board[x][y]->color == pieceColor)
                                {
                                    break; // Stop if the target square contains a friendly piece
                                }

                                result.push_back(std::vector<std::vector<int>>{
                                    std::vector<int>{i, j},
                                    std::vector<int>{x, y, 0}});

                                if (board[x][y]->color != COLOR_NONE)
                                {
                                    break; // Stop if the target square contains an opponent's piece
                                }

                                x += dx;
                                y += dy;
                            }
                            // Queen
                            if (piece->pieceType == PIECE_QUEEN)
                            {
                                std::vector<std::pair<int, int>> queenDirections = {
                                    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

                                for (const auto &direction : queenDirections)
                                {
                                    int dx = direction.first;
                                    int dy = direction.second;
                                    int x = i + dx;
                                    int y = j + dy;

                                    while (x >= 0 && x < 8 && y >= 0 && y < 8)
                                    {
                                        if (board[x][y]->color == pieceColor)
                                        {
                                            break; // Stop if the target square contains a friendly piece
                                        }

                                        result.push_back(std::vector<std::vector<int>>{
                                            std::vector<int>{i, j},
                                            std::vector<int>{x, y, 0}});

                                        if (board[x][y]->color != COLOR_NONE)
                                        {
                                            break; // Stop if the target square contains an opponent's piece
                                        }

                                        x += dx;
                                        y += dy;
                                    }
                                }
                            }
                                                }
                    }
                }
            }
        }
        return result;
    }
}