#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class piecePawn : public chessPiece {
public:
    piecePawn(bool is_white) : chessPiece(is_white) {}

    bool isValidMove(int start_x, int start_y, int end_x, int end_y, chessPiece *board[8][8]) override {
        int direction = is_white ? 1 : -1;
        if (start_x + direction == end_x && start_y == end_y && board[end_x][end_y] == nullptr) {
            return true;
        }
        return false;
    }

    char toChar() override {
        return is_white ? 'P' : 'p';
    }
};

#endif

