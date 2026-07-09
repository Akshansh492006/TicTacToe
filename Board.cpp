#include "Board.h"
#include <iostream>

Board::Board() {
    clear();
}

void Board::clear() {
    char currentNum = '1';
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            grid[row][col] = currentNum++;
        }
    }
}

void Board::display() const {
    std::cout << "\n";
    for (int row = 0; row < 3; ++row) {
        std::cout << " " << grid[row][0] << " | " << grid[row][1] << " | " << grid[row][2] << " \n";
        if (row < 2) {
            std::cout << "---+---+---\n";
        }
    }
    std::cout << "\n";
}

