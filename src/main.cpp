//
// Created by Randrew on 8/2/2024.
//

#include <iostream>
#include "board.hpp"
#include "pawn.hpp"

int main() {
    chessBoard board;

    piecePawn* whitePawn1 = new piecePawn(true);
    piecePawn* blackPawn1 = new piecePawn(false);

    board.setPieceAt(1, 4, whitePawn1);
    board.setPieceAt(6, 4, blackPawn1);

    board.printBoard();
}
