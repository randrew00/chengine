#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include "piece.hpp"

class chessBoard {
public:
    chessBoard();
    ~chessBoard();
    
    // HELPER FUNCTIONS FOR DETERMINING ELIGIBILITY OF PIECE MOVE

    bool isOccupied(int x, int y) const;

    bool isValidMove(int start_x, int start_y, int end_x, int end_y) const;

    chessPiece* getPieceAt(int x, int y) const;

    // FUNCTIONS FOR NAVIGATING/UNDERSTANDING BOARD

    void setPieceAt(int x, int y, chessPiece* piece);

    void movePiece(int start_x, int start_y, int end_x, int end_y);

    std::vector<Move> getAllPossibleMoves(bool is_white) const;

    // BASIC UTILITY; UI/UX, User

    void printBoard() const;

    // Getter for board

    chessPiece* const (*getBoard() const)[8];

private:
    chessPiece* board[8][8];

    std::vector<Move> generatePossibleMovesForPiece(chessPiece* piece, int x, int y) const;

    chessPiece* findKing(bool is_white) const;

    bool isKingInCheck(int x, int y, bool is_white) const;

    bool isMoveLegal(const Move& move, bool is_white) const;
};

#endif