#include <iostream>
#include <vector>
#include "board.hpp"

// Constructor/Destructor

chessBoard::chessBoard() : board(8, std::vector<chessPiece*>(8, nullptr)) {
    setupBoard();
}

chessBoard::~chessBoard() {
    for (auto & row : board) {
        for (auto & piece : row) {
            delete piece;
        }
    }
}

// HELPER FUNCTIONS FOR DETERMINING ELIGIBILITY OF PIECE MOVE

bool chessBoard::isOccupied(const int x, const int y) const {
    return board[x][y] != nullptr;
}

chessPiece* chessBoard::getPieceAt(const int x, const int y) const {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return nullptr;
    }
    return board[x][y];
}

// FUNCTIONS FOR BOARD CONTROL

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
    if (piece && piece->isValidMove(start_x, start_y, end_x, end_y, board)) {
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
                std::vector<Move> pieceMoves = piece->generatePossibleMoves(i, j, board);
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

// BASIC UTILITY; UI/UX, Setup

void chessBoard::setupBoard() {
    for (auto & i : board) {
    for (auto & j : i) {
            j = nullptr;
        }
    }

    for (int i = 0; i < 8; i++) {
        setPieceAt(1, i, pieceFactory::createPiece('P', true));
        setPieceAt(6, i, pieceFactory::createPiece('p', false));
    }
}

void chessBoard::print() const {
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

std::vector<std::vector<chessPiece*>> chessBoard::getBoard() const {
    return board;
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

bool chessBoard::isMoveLegal(const Move& move, bool is_white) const {
    chessBoard temp_board = *this;
    temp_board.movePiece(move.start_x, move.start_y, move.end_x, move.end_y);

    chessPiece* king = findKing(is_white);
    if (king) {
        return false;
    }
    return true;
}