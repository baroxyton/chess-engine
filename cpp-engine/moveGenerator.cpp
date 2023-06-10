#include "moveGenerator.h"
#include "pieces.h"
#include <vector>
namespace MoveGenerator
{
    // list[rank, file, (promotion)]
    std::vector<std::vector<std::vector<int>>> pseudolegalMoveGenerator(std::vector<std::vector<Pieces::Piece *>> &board, std::vector<int> legalCastles, std::vector<int> enpassantSquare, int turn)
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
                if (pieceColor != turn)
                {
                    continue;
                }
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
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j, i + direction, promotion}});

                        // Double move from starting position
                        if (doubleMove && board[i + 2 * direction][j]->pieceType == PIECE_NONE)
                        {
                            result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j, i + 2 * direction, promotion}});
                        }
                    }

                    // Capture diagonally
                    if (j != 0 && board[i + direction][j - 1]->color != COLOR_NONE && board[i + direction][j - 1]->color != pieceColor)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{i, j}, std::vector<int>{j - 1, i + direction, promotion}});
                    }

                    if (j != 7 && board[i + direction][j + 1]->color != COLOR_NONE && board[i + direction][j + 1]->color != pieceColor)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{i, j}, std::vector<int>{j + 1, i + direction, promotion}});
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
                                std::vector<int>{j, i},
                                std::vector<int>{y, x, 0}});
                        }
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
                                std::vector<int>{j, i},
                                std::vector<int>{y, x, 0}});

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
                                std::vector<int>{j, i},
                                std::vector<int>{y, x, 0}});

                            if (board[x][y]->color != COLOR_NONE)
                            {
                                break; // Stop if the target square contains an opponent's piece
                            }

                            x += dx;
                            y += dy;
                        }
                    }
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
                                std::vector<int>{j, i},
                                std::vector<int>{y, x, 0}});

                            if (board[x][y]->color != COLOR_NONE)
                            {
                                break; // Stop if the target square contains an opponent's piece
                            }

                            x += dx;
                            y += dy;
                        }
                    }
                }
                // King
                if (piece->pieceType == PIECE_KING)
                {
                    std::vector<std::pair<int, int>> kingMoves = {
                        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

                    for (const auto &move : kingMoves)
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
                                std::vector<int>{j, i},
                                std::vector<int>{y, x, 0}});
                        }
                    }
                    // White kingside castle
                    if (pieceColor == COLOR_WHITE && legalCastles[0] == 1 && board[i][j + 1]->pieceType == PIECE_NONE && board[i][j + 2]->pieceType == PIECE_NONE)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j + 2, i}});
                    }
                    // White queenside castle
                    if (pieceColor == COLOR_WHITE && legalCastles[1] == 1 && board[i][j - 1]->pieceType == PIECE_NONE && board[i][j - 2]->pieceType == PIECE_NONE && board[i][j - 3]->pieceType == PIECE_NONE)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j - 2, i}});
                    }
                    // Black kingside castle
                    if (pieceColor == COLOR_BLACK && legalCastles[2] == 1 && board[i][j + 1]->pieceType == PIECE_NONE && board[i][j + 2]->pieceType == PIECE_NONE)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j + 2, i}});
                    }
                    // Black queenside castle
                    if (pieceColor == COLOR_BLACK && legalCastles[3] == 1 && board[i][j - 1]->pieceType == PIECE_NONE && board[i][j - 2]->pieceType == PIECE_NONE && board[i][j - 3]->pieceType == PIECE_NONE)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j - 2, i}});
                    }
                }
            }
        }
        return result;
    }
    // Filter illegal moves that allow the capture of the king
    std::vector<std::vector<std::vector<int>>> legalMoveGenerator(std::vector<std::vector<Pieces::Piece *>> board, std::vector<int> legalCastles, std::vector<int> enpassantSquare, int turn)
    {
        std::vector<std::vector<std::vector<int>>> result;
        auto pseudolegalMoves = pseudolegalMoveGenerator(board, legalCastles, enpassantSquare, turn);
        int otherTurn = (turn == COLOR_WHITE) ? COLOR_BLACK : COLOR_WHITE;
        std::vector<int> kingPosition;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                auto piece = board[i][j];
                if (piece->color == turn && piece->pieceType == PIECE_KING)
                {
                    kingPosition = std::vector<int>{j, i};
                    break;
                }
            }
        }
        for (auto move : pseudolegalMoves)
        {
            bool isLegal = true;
            // If the king moves, we need to check if we walk into an attacked piece
            if (board[move[0][1]][move[0][0]]->pieceType == PIECE_KING)
            {
                auto movesOpponent = pseudolegalMoveGenerator(board, legalCastles, enpassantSquare, otherTurn);
                for (auto opponentMove : movesOpponent)
                {
                    if (opponentMove[1][0] == move[1][0] && opponentMove[1][1] == move[1][1])
                    {
                        isLegal = false;
                        break;
                    }
                }
                // Check if we can castle
                // Kingside castle
                if (move[0][0] == 4 /* e file*/ && move[1][0] == 6 /** g file */)
                {
                    for (auto opponentMove : movesOpponent)
                    {
                        if ((opponentMove[1][0] == move[0][0] && opponentMove[1][1] == move[0][1]) || (opponentMove[1][0] == move[0][0] + 1 && opponentMove[1][1] == move[0][1]) || (opponentMove[1][0] == move[0][0] + 2 && opponentMove[1][1] == move[0][1]))
                        {
                            isLegal = false;
                            break;
                        }
                    }
                }
                // Queenside castle
                if (move[0][0] == 4 /* e file */ && move[1][0] == 2 /* c file */)
                {
                    for (auto opponentMove : movesOpponent)
                    {
                        if ((opponentMove[1][0] == move[0][0] && opponentMove[1][1] == move[0][1]) || (opponentMove[1][0] == move[0][0] - 1 && opponentMove[1][1] == move[0][1]) || (opponentMove[1][0] == move[0][0] - 2 && opponentMove[1][1] == move[0][1]) || (opponentMove[1][0] == move[0][0] - 3 && opponentMove[1][1] == move[0][1]))
                        {
                            isLegal = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                auto boardCopy = board;
                boardCopy[move[1][1]][move[1][0]] = boardCopy[move[0][1]][move[0][0]];
                boardCopy[move[0][1]][move[0][0]] = new Pieces::EmptySquare{};
                auto movesOpponent = pseudolegalMoveGenerator(boardCopy, legalCastles, enpassantSquare, otherTurn);
                for (auto opponentMove : movesOpponent)
                {
                    if (opponentMove[1][0] == kingPosition[0] && opponentMove[1][1] == kingPosition[1])
                    {
                        isLegal = false;
                        break;
                    }
                }
            }

            if (isLegal)
            {
                result.push_back(move);
            }
        }
        return result;
    };

}