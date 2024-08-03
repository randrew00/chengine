cmake_minimum_required(VERSION 3.24)

project(chengine)

add_executable(main ../src/main.cpp
        ../src/piece.h
        ../src/pawn.h
        ../src/board.h
        ../src/minimax.h)