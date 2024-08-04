//
// Created by Randrew on 8/2/2024.
//

#include <iostream>
#include "board.hpp"
#include "setup.hpp"

int main() {
    chessBoard chessBoard;

    setupBoard(chessBoard);

    chessBoard.printBoard();
}
