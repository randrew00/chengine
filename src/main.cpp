//
// Created by Randrew on 8/2/2024.
//

#include <iostream>
#include "board.hpp"
#include "setup.hpp"

int main() {
    chessBoard chessBoard;

    setupBoard(chessBoard);


    /*
    chessBoard.printBoard();

    if (chessBoard.isValidMove(1, 0, 2, 0)) {
        chessBoard.movePiece(1, 0, 2, 0);
    }
    else {
        std::cout << "Invalid move for white pawn.\n";
    }

    std::cout << "Board after moving white pawn from (1,0) to (2,0): \n";

    chessBoard.printBoard();

    if (chessBoard.isValidMove(6, 1, 5, 1)) {
        chessBoard.movePiece(6,1,5,1);
    }
    else {
        std::cout << "Invalid move for black pawn.\n";
    }

    std::cout << "Bard after moving black pawn from (6,1), to (5,1): \n";
    */
    chessBoard.printBoard();

}
