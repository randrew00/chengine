#ifndef INCLUDED_BOARD_HPP
#define INCLUDED_BOARD_HPP

#include <iostream>
#include <vector>
#include "piece.hpp"
#include "piece_factory.hpp"

class chessBoard {
public:
    chessBoard();
    ~chessBoard();
    
    // HELPER FUNCTIONS FOR DETERMINING ELIGIBILITY OF PIECE MOVE

    bool isOccupied(int x, int y) const;

    chessPiece* getPieceAt(int x, int y) const;

    // FUNCTIONS FOR NAVIGATING/UNDERSTANDING BOARD

    void setPieceAt(int x, int y, chessPiece* piece);

    void movePiece(int start_x, int start_y, int end_x, int end_y);

    std::vector<Move> getAllPossibleMoves(bool is_white) const;

    // BASIC UTILITY; UI/UX, User

    void print() const;

    // Getter for board
    std::vector<std::vector<chessPiece*>> getBoard() const;

private:
    std::vector<std::vector<chessPiece*>> board;

    void setupBoard();

    chessPiece* findKing(bool is_white) const;

    bool isMoveLegal(const Move& move, bool is_white) const;
};

#endif