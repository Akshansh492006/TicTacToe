#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    char grid[3][3];
    char winner;
    int winType;
    int winIndex;

public:
    Board();
    void clear();
    bool makeMove(int row, int col, char symbol);
    bool checkWin();
    bool checkDraw() const;
    char getCell(int row, int col) const;
    void setCell(int row, int col, char value);
    char getWinner() const;
    int getWinType() const;
    int getWinIndex() const;
};

#endif
