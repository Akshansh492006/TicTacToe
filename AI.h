#ifndef AI_H
#define AI_H

#include "Board.h"

class AI {
private:
    static int evaluateBoard(Board& board, char aiSymbol, char opponentSymbol);
    static int minimax(Board& board, int depth, bool isMax, char aiSymbol, char opponentSymbol);

public:
    static void getBestMove(Board& board, char aiSymbol, char opponentSymbol, int& bestRow, int& bestCol);
};

#endif
