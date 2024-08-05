cmake_minimum_required(VERSION 3.24)

project(chengine)

add_executable(main ../src/main.cpp
        ../src/piece.hpp
        ../src/pawn.hpp
        ../src/board.hpp
        ../src/minimax.hpp
        ../src/moves.hpp
        ../src/pawn.cpp
        ../src/board.cpp
        ../src/setup.cpp
        ../src/setup.hpp)