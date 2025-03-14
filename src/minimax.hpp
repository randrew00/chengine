#ifndef INCLUDED_MINIMAX_HPP
#define INCLUDED_MINIMAX_HPP

#include "board.hpp"
#include <algorithm>

class minimax {
public:
    static int evaluateBoard(chessBoard& board) {
        int score = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chessPiece* piece = board.getPieceAt(i , j);
                if (piece != nullptr) {
                    int pieceValue = getPieceValue(piece);
                    score += piece->is_white_piece() ? pieceValue : -pieceValue;
                }
            }
        }
        return score;
    }

    static int minimax(chessBoard& board, int depth, bool is_maximizing) {
        if (depth == 0) {
            return evaluateBoard(board);
        }
    }

private:
    static int getPieceValue(chessPiece* piece) {
        const char pieceChar = piece->toChar();
        switch(pieceChar) {
            case 'P': return 1;
            case 'p': return 1;
            case 'N': return 3;
            case 'n': return 3;
            case 'B': return 3;
            case 'b': return 3;
            case 'R': return 5;
            case 'r': return 5;
            case 'Q': return 9;
            case 'q': return 9;
            case 'K': return 0;
            case 'k': return 0;
            default: return 0;
        }
    }
};

#endif