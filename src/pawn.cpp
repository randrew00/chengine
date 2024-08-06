#include "pawn.hpp"
#include <iostream>

bool piecePawn::isValidMove(int start_x, int start_y, int end_x, int end_y, const std::vector<std::vector<chessPiece*>>& board) const {
    int direction = is_white ? 1 : -1;
    if (start_x + direction == end_x && start_y == end_y && board[end_x][end_y] == nullptr) {
        return true;
    }
    std::cout << "invalid move!\n";
    return false;
}

std::vector<Move> piecePawn::generatePossibleMoves(int x, int y, const std::vector<std::vector<chessPiece*>>& board) const {
    std::vector<Move> moves;
    int direction = is_white ? 1 : -1;

    // Move forward one square
    if (x + direction >= 0 && x + direction < 8 && board[x + direction][y] == nullptr) {
        moves.emplace_back(x, y, x + direction, y);
    }

    if ((is_white && x == 1) || (!is_white && x == 6)) {
        if (x + 2 * direction >= 0 && x + 2 * direction < 8 && board[x + 2 * direction][y] == nullptr) {
            moves.emplace_back(x, y, x + 2 * direction, y);
        }
    }

    if (x + direction >= 0 && direction < 8) {
        if (y - 1 >= 0 && board[x + direction][y - 1] != nullptr && board[x + direction][y - 1]->isWhitePiece() != is_white) {
            moves.emplace_back(x, y, x + direction, y + 1);
        }
        if (y + 1 < 8 && board[x + direction][y + 1] != nullptr && board[x + direction][y - 1]->isWhitePiece() != is_white) {
            moves.emplace_back(x, y, x + direction, y + 1);
        }
    }
    return moves;
}

char piecePawn::toChar() const {
    return is_white ? 'P' : 'p';
}