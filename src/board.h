#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "piece.h"

class chessBoard {
public:
    chessBoard() {
        // init nullptrs for positions
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = nullptr;
            }
        }
    }

    ~chessBoard() {
        for (auto & i : board) {
            for (auto & j : i) {
                delete j;
            }
        }
    }

    // HELPER FUNCTIONS FOR DETERMINING ELIGIBILITY OF PIECE MOVE

    bool isOccupied(const int x, const int y) const;

    bool isValidMove(const int start_x, const int start_y, const int end_x, const int end_y) const;

    chessPiece* getPieceAt(const int x, const int y) const;

    // FUNCTIONS FOR NAVIGATING/UNDERSTANDING BOARD

    void setPieceAt(const int x, const int y, chessPiece* piece);

    void movePiece(const int start_x, const int start_y, const int end_x, const int end_y);

    std::vector<Move> getAllPossibleMoves(bool is_white) const;

    // BASIC UTILITY; UI/UX, User

    void printBoard() const;

private:
    chessPiece* board[8][8];

    std::vector<Move> generatePossibleMovesForPiece(chessPiece* piece, int x, int y) const;

    chessPiece* findKing(bool is_white) const;

    bool isKingInCheck(int x, int y, bool is_white) const;

    bool isMoveLegal(const Move& move, bool is_white) const;
};

#endif