#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include "moves.hpp"

class chessPiece {
public:
    chessPiece(const bool is_white) : is_white(is_white) {}
    virtual ~chessPiece() = default;

    bool isWhitePiece() const {return is_white;}
    virtual bool isValidMove(int start_x, int start_y, int end_x, int end_y, chessPiece* const board[8][8]) const = 0;
    virtual char toChar() const = 0;
    virtual std::vector<Move> generatePossibleMoves(int x, int y, chessPiece* const board[8][8]) const = 0;

    int get_x() const {return x;}
    int get_y() const {return y;}

    void setPosition(int new_x, int new_y) {
        x = new_x;
        y = new_y;
    }

protected:
    bool is_white;
    int x, y; // Tracking position
};

#endif
