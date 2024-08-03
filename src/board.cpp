#include <iostream>
#include <vector>
#include "board.hpp"

// HELPER FUNCTIONS FOR DETERMINING ELIGIBILITY OF PIECE MOVE

bool chessBoard::isOccupied(const int x, const int y) const {
    return board[x][y] != nullptr;
}

bool chessBoard::isValidMove(const int start_x, const int start_y, const int end_x, const int end_y) const {
    chessPiece* piece = board[start_x][start_y];
    if (piece && piece->isValidMove(start_x, start_y, end_x, end_y, board)) {
        return true;
    }
    return false;
}

chessPiece* chessBoard::getPieceAt(const int x, const int y) const {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return nullptr;
    }
    return board[x][y];
}

// FUNCTIONS FOR NAVIGATING/UNDERSTANDING BOARD

void chessBoard::setPieceAt(const int x, const int y, chessPiece* piece) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        board[x][y] = piece;
        if (piece) {
            piece->setPosition(x, y);
        }
    }
}

void chessBoard::movePiece(const int start_x, const int start_y, const int end_x, const int end_y) {
    chessPiece* piece = getPieceAt(start_x, start_y);
    if (piece) {
        setPieceAt(end_x, end_y, piece);
        setPieceAt(start_x, start_y, nullptr);
    }
}

std::vector<Move> chessBoard::getAllPossibleMoves(bool is_white) const {
    std::vector<Move> possibleMoves;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessPiece* piece = getPieceAt(i, j);
            if (piece && piece->isWhitePiece() == is_white) {
                std::vector<Move> pieceMoves = generatePossibleMovesForPiece(piece, i, j);
                for (const Move& move : pieceMoves) {
                    if (isMoveLegal(move, is_white)) {
                        possibleMoves.push_back(move);
                    }
                }
            }
        }
    }
    return possibleMoves;
}

// BASIC UTILITY; UI/UX, User

void chessBoard::printBoard() const {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (isOccupied(i, j)) {
                std::cout << board[i][j]->toChar() << " ";
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << '\n';
    }
}

std::vector<Move> chessBoard::generatePossibleMovesForPiece(chessPiece* piece, int x, int y) const {
    std::vector<Move> possibleMoves;
    if (piece) {
        possibleMoves = piece->generatePossibleMoves(x, y, board);
    }
    return possibleMoves;
}

chessPiece* chessBoard::findKing(bool is_white) const {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessPiece* piece = getPieceAt(i, j);
            if (piece && piece->toChar() == (is_white ? 'K' : 'k')) {
                return piece;
            }
        }
    }
    return nullptr;
}

bool chessBoard::isKingInCheck(int x, int y, bool is_white) const {
    bool opponent_color = !is_white;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessPiece* piece = getPieceAt(i, j);
            if (piece && piece->isWhitePiece() == opponent_color) {
                std::vector<Move> opponent_moves = generatePossibleMovesForPiece(piece, i, j);
                for (const Move& move : opponent_moves) {
                    if (move.end_x == x && move.end_y == y) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool chessBoard::isMoveLegal(const Move& move, bool is_white) const {
    chessBoard temp_board = *this;
    temp_board.movePiece(move.start_x, move.start_y, move.end_x, move.end_y);

    chessPiece* king = findKing(is_white);
    if (king && isKingInCheck(king->get_x(), king->get_y(), is_white)) {
        return false;
    }
    return true;
}
