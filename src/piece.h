//
// Created by Randrew on 8/3/2024.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

class chessPiece {
protected:
    bool is_white;

public:
    chessPiece(bool is_white) : is_white(is_white) {}
    virtual ~chessPiece() = default;

    bool is_white_piece() const {return is_white;}
    virtual bool isValidMove(int start_x, int start_y, int end_x, int end_y, chessPiece* board[8][8]) = 0;



};

#endif //CHESS_PIECE_H
