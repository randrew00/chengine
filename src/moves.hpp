#ifndef MOVES_H
#define MOVES_H

// Structure for generating possible moves

struct Move {
    int start_x, start_y, end_x, end_y;
    Move(int s_x, int s_y, int e_x, int e_y)
        : start_x(s_x), start_y(s_y), end_x(e_x), end_y(e_y) {}
};

#endif
