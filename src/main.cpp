//
// Created by Randrew on 8/2/2024.
//

#include <iostream>
#include "board.h"
#include "pawn.h"

int main() {
    chessBoard board;
    for (int i = 0; i < 8; i++) {
        board.setPieceAt(1, i, new piecePawn(true));
        board.setPieceAt(6, i, new piecePawn(false));
    }

    board.printBoard();

    board.movePiece(1,0,3,0);

    std::cout << "\nBoard after moving pawn:\n";
    board.printBoard();
}
