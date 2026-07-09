#include "AI.h"

static bool checkWinSymbol(const Board& board, char symbol) {
    for (int i = 0; i < 3; ++i) {
        if (board.getCell(i, 0) == symbol && board.getCell(i, 1) == symbol && board.getCell(i, 2) == symbol) return true;
        if (board.getCell(0, i) == symbol && board.getCell(1, i) == symbol && board.getCell(2, i) == symbol) return true;
    }
    if (board.getCell(0, 0) == symbol && board.getCell(1, 1) == symbol && board.getCell(2, 2) == symbol) return true;
    if (board.getCell(0, 2) == symbol && board.getCell(1, 1) == symbol && board.getCell(2, 0) == symbol) return true;
    return false;
}

static bool checkDrawState(const Board& board) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (board.getCell(r, c) == ' ') return false;
        }
    }
    return true;
}

int AI::minimax(Board& board, int depth, bool isMax, char aiSymbol, char opponentSymbol) {
    if (checkWinSymbol(board, aiSymbol)) return 10 - depth;
    if (checkWinSymbol(board, opponentSymbol)) return depth - 10;
    if (checkDrawState(board)) return 0;

    if (isMax) {
        int bestScore = -1000;
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (board.getCell(r, c) == ' ') {
                    board.setCell(r, c, aiSymbol);
                    int score = minimax(board, depth + 1, false, aiSymbol, opponentSymbol);
                    board.setCell(r, c, ' ');
                    if (score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (board.getCell(r, c) == ' ') {
                    board.setCell(r, c, opponentSymbol);
                    int score = minimax(board, depth + 1, true, aiSymbol, opponentSymbol);
                    board.setCell(r, c, ' ');
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

void AI::getBestMove(Board& board, char aiSymbol, char opponentSymbol, int& bestRow, int& bestCol) {
    int bestScore = -1000;
    bestRow = -1;
    bestCol = -1;

    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (board.getCell(r, c) == ' ') {
                board.setCell(r, c, aiSymbol);
                int score = minimax(board, 0, false, aiSymbol, opponentSymbol);
                board.setCell(r, c, ' ');
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = r;
                    bestCol = c;
                }
            }
        }
    }
}
