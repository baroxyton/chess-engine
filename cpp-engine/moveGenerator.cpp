#include "moveGenerator.h"
#include "pieces.h"
#include <vector>
namespace MoveGenerator
{
    // list[rank, file, (promotion)]
    std::vector<std::vector<std::vector<int>>> pseudolegalMoveGenerator(std::vector<std::vector<char>>& board, std::vector<int> legalCastles, std::vector<int> enpassantSquare, int turn, bool rangePiecesOnly=false)
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
                if (Pieces::getType(piece) == PIECE_NONE||(rangePiecesOnly && (Pieces::getType(piece) < PIECE_BISHOP || Pieces::getType(piece) == PIECE_KING)))
                {
                    continue;
                }
                auto pieceColor = Pieces::getColor(piece);
                if (pieceColor != turn)
                {
                    continue;
                }
                // Pawn
                if (Pieces::getType(piece) == PIECE_PAWN)
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
                    if (Pieces::getType(board[i + direction][j]) == PIECE_NONE)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j, i + direction, promotion}});

                        // Double move from starting position
                        if (doubleMove && Pieces::getType(board[i + 2 * direction][j]) == PIECE_NONE)
                        {
                            result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j, i + 2 * direction, promotion}});
                        }
                    }

                    // Capture diagonally
                    if (j != 0 && Pieces::getColor(board[i + direction][j - 1]) != COLOR_NONE && Pieces::getColor(board[i + direction][j - 1]) != pieceColor)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{i, j}, std::vector<int>{j - 1, i + direction, promotion}});
                    }

                    if (j != 7 && Pieces::getColor(board[i + direction][j + 1]) != COLOR_NONE && Pieces::getColor(board[i + direction][j + 1]) != pieceColor)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{i, j}, std::vector<int>{j + 1, i + direction, promotion}});
                    }
                }

                // Knight
                if (Pieces::getType(piece) == PIECE_KNIGHT)
                {
                    std::vector<std::pair<int, int>> knightMoves = {
                        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

                    for (const auto &move : knightMoves)
                    {
                        int x = i + move.first;
                        int y = j + move.second;

                        if (x >= 0 && x < 8 && y >= 0 && y < 8)
                        {
                            if (Pieces::getColor(board[x][y]) == pieceColor)
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
                if (Pieces::getType(piece) == PIECE_BISHOP)
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
                            if (Pieces::getColor(board[x][y]) == pieceColor)
                            {
                                break; // Stop if the target square contains a friendly piece
                            }

                            result.push_back(std::vector<std::vector<int>>{
                                std::vector<int>{j, i},
                                std::vector<int>{y, x, 0}});

                            if (Pieces::getColor(board[x][y]) != COLOR_NONE)
                            {
                                break; // Stop if the target square contains an opponent's piece
                            }

                            x += dx;
                            y += dy;
                        }
                    }
                }
                // Rook
                if (Pieces::getType(piece) == PIECE_ROOK)
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
                            if (Pieces::getColor(board[x][y]) == pieceColor)
                            {
                                break; // Stop if the target square contains a friendly piece
                            }

                            result.push_back(std::vector<std::vector<int>>{
                                std::vector<int>{j, i},
                                std::vector<int>{y, x, 0}});

                            if (Pieces::getColor(board[x][y]) != COLOR_NONE)
                            {
                                break; // Stop if the target square contains an opponent's piece
                            }

                            x += dx;
                            y += dy;
                        }
                    }
                }
                // Queen
                if (Pieces::getType(piece) == PIECE_QUEEN)
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
                            if (Pieces::getColor(board[x][y]) == pieceColor)
                            {
                                break; // Stop if the target square contains a friendly piece
                            }

                            result.push_back(std::vector<std::vector<int>>{
                                std::vector<int>{j, i},
                                std::vector<int>{y, x, 0}});

                            if (Pieces::getColor(board[x][y]) != COLOR_NONE)
                            {
                                break; // Stop if the target square contains an opponent's piece
                            }

                            x += dx;
                            y += dy;
                        }
                    }
                }
                // King
                if (Pieces::getType(piece) == PIECE_KING)
                {
                    std::vector<std::pair<int, int>> kingMoves = {
                        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

                    for (const auto &move : kingMoves)
                    {
                        int x = i + move.first;
                        int y = j + move.second;

                        if (x >= 0 && x < 8 && y >= 0 && y < 8)
                        {
                            if (Pieces::getColor(board[x][y]) == pieceColor)
                            {
                                continue; // Skip if the target square contains a friendly piece
                            }

                            result.push_back(std::vector<std::vector<int>>{
                                std::vector<int>{j, i},
                                std::vector<int>{y, x, 0}});
                        }
                    }
                    // White kingside castle
                    if (pieceColor == COLOR_WHITE && legalCastles[0] == 1 && Pieces::getType(board[i][j + 1]) == PIECE_NONE && Pieces::getType(board[i][j + 2]) == PIECE_NONE)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j + 2, i}});
                    }
                    // White queenside castle
                    if (pieceColor == COLOR_WHITE && legalCastles[1] == 1 && Pieces::getType(board[i][j - 1]) == PIECE_NONE && Pieces::getType(board[i][j - 2]) == PIECE_NONE && Pieces::getType(board[i][j - 3]) == PIECE_NONE)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j - 2, i}});
                    }
                    // Black kingside castle
                    if (pieceColor == COLOR_BLACK && legalCastles[2] == 1 && Pieces::getType(board[i][j + 1]) == PIECE_NONE && Pieces::getType(board[i][j + 2]) == PIECE_NONE)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j + 2, i}});
                    }
                    // Black queenside castle
                    if (pieceColor == COLOR_BLACK && legalCastles[3] == 1 && Pieces::getType(board[i][j - 1]) == PIECE_NONE && Pieces::getType(board[i][j - 2]) == PIECE_NONE && Pieces::getType(board[i][j - 3]) == PIECE_NONE)
                    {
                        result.push_back(std::vector<std::vector<int>>{std::vector<int>{j, i}, std::vector<int>{j - 2, i}});
                    }
                }
            }
        }
        return result;
    }
    // Filter illegal moves that allow the capture of the king
    std::vector<std::vector<std::vector<int>>> legalMoveGenerator(const std::vector<std::vector<char>>& board, const std::vector<int>& legalCastles, const std::vector<int>& enpassantSquare, int turn)
{   std::vector<std::vector<char>> boardCopy = board;
    std::vector<std::vector<std::vector<int>>> result;
    const auto& pseudolegalMoves = pseudolegalMoveGenerator(boardCopy, legalCastles, enpassantSquare, turn);
    const int otherTurn = (turn == COLOR_WHITE) ? COLOR_BLACK : COLOR_WHITE;
    std::vector<int> kingPosition;
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            const auto piece = board[i][j];
            if (Pieces::getColor(piece) == turn && Pieces::getType(piece) == PIECE_KING)
            {
                kingPosition = {j, i};
                break;
            }
        }
    }
    
    for (const auto& move : pseudolegalMoves)
    {
        bool isLegal = true;
        
        // If the king moves, check if it walks into an attacked piece
        if (Pieces::getType(board[move[0][1]][move[0][0]]) == PIECE_KING)
        {
            const auto movesOpponent = pseudolegalMoveGenerator(boardCopy, legalCastles, enpassantSquare, otherTurn);
            
            for (const auto& opponentMove : movesOpponent)
            {
                if (opponentMove[1][0] == move[1][0] && opponentMove[1][1] == move[1][1])
                {
                    isLegal = false;
                    break;
                }
            }
            
            // Check if we can castle
            if (move[0][0] == 4 /* e file */)
            {
                const int castlingRank = (turn == COLOR_WHITE) ? 0 : 7;
                
                if (move[1][0] == 6 /* g file */)
                {
                    for (const auto& opponentMove : movesOpponent)
                    {
                        if (opponentMove[1][0] == 4 && opponentMove[1][1] == castlingRank ||
                            opponentMove[1][0] == 5 && opponentMove[1][1] == castlingRank ||
                            opponentMove[1][0] == 6 && opponentMove[1][1] == castlingRank)
                        {
                            isLegal = false;
                            break;
                        }
                    }
                }
                else if (move[1][0] == 2 /* c file */)
                {
                    for (const auto& opponentMove : movesOpponent)
                    {
                        if (opponentMove[1][0] == 4 && opponentMove[1][1] == castlingRank ||
                            opponentMove[1][0] == 3 && opponentMove[1][1] == castlingRank ||
                            opponentMove[1][0] == 2 && opponentMove[1][1] == castlingRank)
                        {
                            isLegal = false;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            std::vector<std::vector<char>> boardCopy = board;
            std::swap(boardCopy[move[0][1]][move[0][0]], boardCopy[move[1][1]][move[1][0]]);
            const auto movesOpponent = pseudolegalMoveGenerator(boardCopy, legalCastles, enpassantSquare, true);
            
            for (const auto& opponentMove : movesOpponent)
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
}


}