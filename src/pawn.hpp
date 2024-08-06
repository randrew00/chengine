#ifndef INCLUDED_PAWN_HPP
#define INCLUDED_PAWN_HPP

#include <vector>

#include "piece.hpp"

class piecePawn : public chessPiece {
public:
    piecePawn(bool is_white) : chessPiece(is_white) {}

    bool isValidMove(int start_x, int start_y, int end_x, int end_y, chessPiece* const board[8][8]) const override;

    std::vector<Move> generatePossibleMoves(int x, int y, chessPiece* const board[8][8]) const override;

    char toChar() const override;
};

#endif

