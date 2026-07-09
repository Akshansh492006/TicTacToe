#include "Board.h"

Board::Board() {
    clear();
}

void Board::clear() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            grid[row][col] = ' ';
        }
    }
    winner = ' ';
    winType = 0;
    winIndex = -1;
}

bool Board::makeMove(int row, int col, char symbol) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    if (grid[row][col] != ' ') {
        return false;
    }
    grid[row][col] = symbol;
    return true;
}

bool Board::checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') {
            winner = grid[i][0];
            winType = 1;
            winIndex = i;
            return true;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') {
            winner = grid[0][i];
            winType = 2;
            winIndex = i;
            return true;
        }
    }

    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') {
        winner = grid[0][0];
        winType = 3;
        winIndex = 0;
        return true;
    }

    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') {
        winner = grid[0][2];
        winType = 4;
        winIndex = 0;
        return true;
    }

    return false;
}

bool Board::checkDraw() const {
    if (winner != ' ') {
        return false;
    }
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (grid[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}

char Board::getCell(int row, int col) const {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return ' ';
    }
    return grid[row][col];
}

void Board::setCell(int row, int col, char value) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        grid[row][col] = value;
    }
}

char Board::getWinner() const {
    return winner;
}

int Board::getWinType() const {
    return winType;
}

int Board::getWinIndex() const {
    return winIndex;
}
