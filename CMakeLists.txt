cmake_minimum_required(VERSION 3.24)

project(chengine)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp
        src/piece_factory.cpp
        src/piece_factory.hpp
        src/piece.hpp
        src/pawn.hpp
        src/board.hpp
        src/minimax.hpp
        src/moves.hpp
        src/pawn.cpp
        src/board.cpp
)