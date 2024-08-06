#include "piece_factory.hpp"
#include <iostream>
chessPiece* pieceFactory::createPiece(char type, bool is_white) {
    switch (type) {
        case 'P':
            return new piecePawn(is_white);
        case 'p':
            return new piecePawn(is_white);
        default:
            return nullptr;
    }
}