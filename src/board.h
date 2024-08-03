#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "piece.h"
#include "pawn.h"

class chessBoard {
public:
    chessBoard() {
        // init nullptrs for positions
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = nullptr;
            }
        }

        // set up pawns
        for (int i = 0; i < 8; i++) {
            board[1][i] = new piecePawn(true);
            board[6][i] = new piecePawn(false);
        }
    }

    ~chessBoard() {
        for (auto & i : board) {
            for (auto & j : i) {
                delete j;
            }
        }
    }

    void movePiece(const int start_x, const int start_y, const int end_x, const int end_y) {
        if (isValidMove(start_x, start_y, end_x, end_y)) {
            delete board[end_x][end_y];
            board[end_x][end_y] = board[start_x][start_y];
            board[start_x][start_y] = nullptr;
        }
    }

    void printBoard() const {
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

    // HELPER FUNCTIONS FOR DETERMINING ELIGIBILITY OF PIECE MOVE


    bool isOccupied(const int x, const int y) const {
        return board[x][y] != nullptr;
    }

    bool isValidMove(const int start_x, const int start_y, const int end_x, const int end_y) {
        chessPiece* piece = board[start_x][start_y];
        if (piece && piece->isValidMove(start_x, start_y, end_x, end_y, board)) {
            return true;
        }
        return false;
    }

    chessPiece* getPieceAt(const int x, const int y) const {
        if (x < 0 || x >= 8 || y < 0 || y >= 8) {
            return nullptr;
        }
        return board[x][y];
    }

private:
    chessPiece* board[8][8];
};

#endif