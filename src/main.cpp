#include "board.hpp"

int main() {
    chessBoard board;
    board.print(); 

    chessPiece* piece = board.getPieceAt(1,6);

    if (piece) {
        std::vector<Move> possibleMoves = piece->generatePossibleMoves(1, 6, board.getBoard());
    
        for (const Move& move : possibleMoves) {
            std::cout << "(" << move.start_x << ", " << move.start_y << ") -> ("
            << move.end_x << ", " << move.end_y << ")\n";
        }
    }
  
}
