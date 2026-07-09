#include "Game.h"
#include "AI.h"
#include <iostream>

Game::Game() : statusText(font), restartText(font), modeText(font) {
    std::cout << "Enter Player X Name: ";
    std::getline(std::cin, playerXName);
    if (playerXName.empty()) {
        playerXName = "Player X";
    }

    std::cout << "Enter Player O Name: ";
    std::getline(std::cin, enteredPlayerOName);
    if (enteredPlayerOName.empty()) {
        enteredPlayerOName = "Player O";
    }

    isAiMode = true;
    aiSymbol = 'O';
    humanSymbol = 'X';
    currentPlayer = 'X';
    gameOver = false;
    playerOName = "Computer";

    window.create(sf::VideoMode(sf::Vector2u(600, 700)), "Tic-Tac-Toe", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf")) {
        (void)font.openFromFile("arial.ttf");
    }

    statusText.setCharacterSize(24);
    statusText.setFillColor(sf::Color::White);

    restartButton.setSize(sf::Vector2f(120.f, 40.f));
    restartButton.setFillColor(sf::Color(60, 65, 80));
    restartButton.setOutlineThickness(2.f);
    restartButton.setOutlineColor(sf::Color(100, 110, 130));
    restartButton.setPosition(sf::Vector2f(460.f, 20.f));

    restartText.setString("Restart");
    restartText.setCharacterSize(18);
    restartText.setFillColor(sf::Color::White);
    restartText.setPosition(sf::Vector2f(490.f, 28.f));

    modeButton.setSize(sf::Vector2f(160.f, 40.f));
    modeButton.setFillColor(sf::Color(60, 65, 80));
    modeButton.setOutlineThickness(2.f);
    modeButton.setOutlineColor(sf::Color(100, 110, 130));
    modeButton.setPosition(sf::Vector2f(20.f, 20.f));

    modeText.setString("Mode: Vs AI");
    modeText.setCharacterSize(18);
    modeText.setFillColor(sf::Color::White);
    modeText.setPosition(sf::Vector2f(45.f, 28.f));
}

void Game::reset() {
    board.clear();
    currentPlayer = 'X';
    gameOver = false;
}

void Game::handleMouseClick(int x, int y) {
    if (x >= 20 && x <= 180 && y >= 20 && y <= 60) {
        isAiMode = !isAiMode;
        modeText.setString(isAiMode ? "Mode: Vs AI" : "Mode: 1 vs 1");
        playerOName = isAiMode ? "Computer" : enteredPlayerOName;
        reset();
        return;
    }

    if (x >= 460 && x <= 580 && y >= 20 && y <= 60) {
        reset();
        return;
    }

    if (gameOver) {
        return;
    }

    if (isAiMode && currentPlayer == aiSymbol) {
        return;
    }

    if (y >= 100 && y <= 700) {
        int row = (y - 100) / 200;
        int col = x / 200;

        if (board.makeMove(row, col, currentPlayer)) {
            if (board.checkWin()) {
                gameOver = true;
            } else if (board.checkDraw()) {
                gameOver = true;
            } else {
                if (currentPlayer == 'X') {
                    currentPlayer = 'O';
                } else {
                    currentPlayer = 'X';
                }
            }
        }
    }
}

void Game::handleEvents() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        } else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mousePressed->button == sf::Mouse::Button::Left) {
                handleMouseClick(mousePressed->position.x, mousePressed->position.y);
            }
        }
    }
}

void Game::update() {
    if (isAiMode && currentPlayer == aiSymbol && !gameOver) {
        int bestRow = -1;
        int bestCol = -1;
        AI::getBestMove(board, aiSymbol, humanSymbol, bestRow, bestCol);
        if (bestRow != -1 && bestCol != -1) {
            board.makeMove(bestRow, bestCol, aiSymbol);
            if (board.checkWin()) {
                gameOver = true;
            } else if (board.checkDraw()) {
                gameOver = true;
            } else {
                currentPlayer = humanSymbol;
            }
        }
    }
}

void Game::render() {
    window.clear(sf::Color(25, 30, 45));

    window.draw(modeButton);
    window.draw(modeText);
    window.draw(restartButton);
    window.draw(restartText);

    if (gameOver) {
        if (board.getWinner() == 'X') {
            statusText.setString(playerXName + " Wins!");
        } else if (board.getWinner() == 'O') {
            statusText.setString(playerOName + " Wins!");
        } else {
            statusText.setString("Game Draw!");
        }
    } else {
        if (currentPlayer == 'X') {
            statusText.setString(playerXName + "'s Turn");
        } else {
            statusText.setString(playerOName + "'s Turn");
        }
    }

    sf::FloatRect textRect = statusText.getLocalBounds();
    statusText.setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x / 2.f, textRect.position.y + textRect.size.y / 2.f));
    statusText.setPosition(sf::Vector2f(300.f, 40.f));
    window.draw(statusText);

    sf::RectangleShape line1(sf::Vector2f(8.f, 600.f));
    line1.setFillColor(sf::Color(80, 90, 100));
    line1.setPosition(sf::Vector2f(196.f, 100.f));
    window.draw(line1);

    sf::RectangleShape line2(sf::Vector2f(8.f, 600.f));
    line2.setFillColor(sf::Color(80, 90, 100));
    line2.setPosition(sf::Vector2f(396.f, 100.f));
    window.draw(line2);

    sf::RectangleShape line3(sf::Vector2f(600.f, 8.f));
    line3.setFillColor(sf::Color(80, 90, 100));
    line3.setPosition(sf::Vector2f(0.f, 296.f));
    window.draw(line3);

    sf::RectangleShape line4(sf::Vector2f(600.f, 8.f));
    line4.setFillColor(sf::Color(80, 90, 100));
    line4.setPosition(sf::Vector2f(0.f, 496.f));
    window.draw(line4);

    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            char val = board.getCell(r, c);
            float cx = c * 200.f + 100.f;
            float cy = 100.f + r * 200.f + 100.f;

            if (val == 'X') {
                sf::RectangleShape xLine1(sf::Vector2f(140.f, 12.f));
                xLine1.setOrigin(sf::Vector2f(70.f, 6.f));
                xLine1.setPosition(sf::Vector2f(cx, cy));
                xLine1.setRotation(sf::degrees(45.f));
                xLine1.setFillColor(sf::Color(80, 200, 255));
                window.draw(xLine1);

                sf::RectangleShape xLine2(sf::Vector2f(140.f, 12.f));
                xLine2.setOrigin(sf::Vector2f(70.f, 6.f));
                xLine2.setPosition(sf::Vector2f(cx, cy));
                xLine2.setRotation(sf::degrees(-45.f));
                xLine2.setFillColor(sf::Color(80, 200, 255));
                window.draw(xLine2);
            } else if (val == 'O') {
                sf::CircleShape circle(50.f);
                circle.setOrigin(sf::Vector2f(50.f, 50.f));
                circle.setPosition(sf::Vector2f(cx, cy));
                circle.setFillColor(sf::Color::Transparent);
                circle.setOutlineThickness(10.f);
                circle.setOutlineColor(sf::Color(255, 80, 120));
                window.draw(circle);
            }
        }
    }

    if (gameOver && board.getWinner() != ' ') {
        int winType = board.getWinType();
        int winIndex = board.getWinIndex();

        if (winType == 1) {
            float y = 100.f + winIndex * 200.f + 100.f;
            sf::RectangleShape winLine(sf::Vector2f(600.f, 12.f));
            winLine.setPosition(sf::Vector2f(0.f, y - 6.f));
            winLine.setFillColor(sf::Color(255, 215, 0));
            window.draw(winLine);
        } else if (winType == 2) {
            float x = winIndex * 200.f + 100.f;
            sf::RectangleShape winLine(sf::Vector2f(12.f, 600.f));
            winLine.setPosition(sf::Vector2f(x - 6.f, 100.f));
            winLine.setFillColor(sf::Color(255, 215, 0));
            window.draw(winLine);
        } else if (winType == 3) {
            sf::RectangleShape winLine(sf::Vector2f(848.5f, 12.f));
            winLine.setPosition(sf::Vector2f(0.f, 100.f));
            winLine.setRotation(sf::degrees(45.f));
            winLine.setFillColor(sf::Color(255, 215, 0));
            window.draw(winLine);
        } else if (winType == 4) {
            sf::RectangleShape winLine(sf::Vector2f(848.5f, 12.f));
            winLine.setPosition(sf::Vector2f(600.f, 100.f));
            winLine.setRotation(sf::degrees(135.f));
            winLine.setFillColor(sf::Color(255, 215, 0));
            window.draw(winLine);
        }
    }

    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}
