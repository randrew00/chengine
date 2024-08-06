#ifndef INCLUDED_PIECE_FACTORY_HPP
#define INCLUDED_PIECE_FACTORY_HPP

#include "piece.hpp"
#include "pawn.hpp"

class pieceFactory {
public:
    static chessPiece* createPiece(char type, bool is_white);
};

#endif
