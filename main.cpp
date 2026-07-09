#include "Board.h"
#include <iostream>

int main() {
    std::cout << "====================================\n";
    std::cout << "   Welcome to C++ Tic-Tac-Toe!      \n";
    std::cout << "====================================\n";

    Board gameBoard;
    gameBoard.display();

    return 0;
}

