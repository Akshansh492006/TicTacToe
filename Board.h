#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    char grid[3][3];

public:
    Board();
    void clear();
    void display() const;
};

#endif
