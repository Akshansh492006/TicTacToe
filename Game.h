#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Board.h"

class Game {
private:
    Board board;
    char currentPlayer;
    bool isAiMode;
    char aiSymbol;
    char humanSymbol;
    bool gameOver;

    sf::RenderWindow window;
    sf::Font font;
    sf::Text statusText;
    sf::Text restartText;
    sf::Text modeText;

    sf::RectangleShape restartButton;
    sf::RectangleShape modeButton;

    void handleEvents();
    void update();
    void render();
    void reset();
    void handleMouseClick(int x, int y);

public:
    Game();
    void run();
};

#endif
