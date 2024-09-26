
# Chess Engine

This is a simple, extensible chess engine implemented in C++. It provides basic functionalities for setting up a chessboard, moving pieces, and generating possible moves for each piece. The engine is built using object-oriented principles, where different chess pieces inherit from a base `chessPiece` class, and a factory (`pieceFactory`) is used to initialize pieces on the board.

The engine supports both human players and an AI opponent that leverages the **Minimax algorithm** with **Alpha-Beta Pruning** for decision-making.

## Features

### 1. **Board Setup**

-   The chessboard is represented by an 8x8 grid (`std::vector<std::vector<chessPiece*>>`) initialized with `nullptr` values.
-   Each piece can be placed at a specific position using the `setPieceAt` method, and pieces can be moved using the `movePiece` function.
-   The board can be printed in a text-based format using the `print` method.

### 2. **Piece Movement**

-   Each chess piece (e.g., pawn, rook, bishop) inherits from the base `chessPiece` class.
-   The board provides `movePiece` functionality, allowing for valid piece movements to be performed.
-   Movements are validated by each piece's `isValidMove` method, ensuring moves are consistent with the rules of chess.

### 3. **Generating Possible Moves**

-   Each piece has its own implementation of `generatePossibleMoves`, which calculates all legal moves based on its current position and the state of the board.
-   The board's `getAllPossibleMoves` function aggregates possible moves for all pieces of a specified color (black or white).

### 4. **AI with Minimax and Alpha-Beta Pruning**

-   The engine includes an AI opponent powered by the **Minimax algorithm**, which evaluates the game tree to determine optimal moves.
-   **Alpha-Beta Pruning** is used to improve the efficiency of the Minimax algorithm by cutting off branches in the game tree that cannot affect the final decision, reducing the computation time and improving performance.

### 5. **Piece Factory**

-   The `pieceFactory` is responsible for dynamically creating chess pieces based on their type and color.
-   This abstraction simplifies the setup of the board by providing a clear method to initialize the standard chess pieces.

### 6. **King's Safety**

-   The chessboard provides a mechanism for ensuring the king is not in check. The `isKingInCheck` function verifies if any move would leave the king in a vulnerable position.
-   The `findKing` method efficiently tracks the location of the kings to support this feature.

### 7. **Utility Functions**

-   `isOccupied`: Checks if a position on the board is occupied.
-   `getPieceAt`: Returns the chess piece at a given position.
-   `setPieceAt`: Sets a chess piece at a given position on the board.
-   `movePiece`: Moves a piece from one position to another.
-   `print`: Prints the current state of the board, showing pieces and empty spaces.

## Code Structure


├── board.hpp       # Definition of the chessBoard class \
├── board.cpp       # Implementation of the chessBoard class \
├── piece.hpp       # Definition of the base chessPiece class \
├── piece.cpp       # Implementation of various chess pieces \
├── piece_factory.hpp  # Definition of pieceFactory for creating pieces \
├── pawn.hpp        # Definition of the pawn piece (inherits chessPiece) \
├── pawn.cpp        # Implementation of pawn-specific logic \
├── minimax.hpp     # Definition of Minimax and Alpha-Beta pruning algorithms \
├── moves.hpp       # Definition of the Move class, representing chess moves \
└── CMakeLists.txt  # CMake configuration for building the project` \

## Getting Started

1.  **Clone the repository:**
    
    `git clone https://github.com/randrew00/chengine.git` \
    `cd chengine`

     **OR** 

    `git clone git@github.com:randrew00/chengine.git` \
    `cd chengine`
    
3.  **Build using CMake:** 
    In root of project: \
        `mkdir build` \
    In build dir \
        `cmake ..` \
        `make` 
    
    

## Future Enhancements

-   **Additional Pieces:** Extend the implementation to include pieces like rooks, knights, bishops, queens, and the king.
-   **Check and Checkmate:** Implement functions to detect check and checkmate conditions.
-   **AI Improvements:** Enhance the AI by implementing more advanced techniques like Monte Carlo Tree Search.
