#include "setup.hpp"
#include "pawn.hpp"

void setupBoard(chessBoard &board) {
    for (int i = 0; i < 8; i++) {
        board.setPieceAt(1, i, new piecePawn(true));
        board.setPieceAt(6, i, new piecePawn(false));
    }
}

