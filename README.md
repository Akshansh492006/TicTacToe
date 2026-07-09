# C++ SFML Tic-Tac-Toe (with Minimax AI)

A professional graphical Tic-Tac-Toe game built in C++ using the Simple and Fast Multimedia Library (SFML 3.x). The project features an unbeatable AI powered by the Minimax algorithm and support for local 1 vs 1 matches.

## Features
* **Interactive GUI:** Responsive graphical grid where players can tap/click to place symbols.
* **Minimax AI Engine:** An unbeatable computer opponent that evaluates all possible routes to ensure optimal play.
* **1 vs 1 Manual Mode:** Support for local multi-player matches on the same machine.
* **Custom Names:** Prompts players for custom names in the console on startup, which dynamically align and display on the GUI status bar.
* **Win Line Highlighting:** Displays a gold line connecting the winning three-in-a-row combination.
* **Reset & Mode Controls:** Hoverable toggles to instantly clear the board or swap between AI and 1 vs 1 modes.

## Architecture
The project follows the **Model-View-Controller (MVC)** software design pattern to decouple code:
* **Model (`Board`):** Contains the 3x3 matrix logic, turn checkers, and win/draw evaluation algorithms.
* **Controller (`Game` input handling):** Translates mouse coordinates to matrix cells.
* **View (`Game` rendering):** Handles rendering the grid, cyan X shapes, pink O circles, gold win lines, and text using SFML.
* **AI (`AI`):** Contains the minimax logic to calculate the best possible moves.

## Compilation (MSYS2 / MinGW / UCRT64)
Ensure you have the SFML 3 library installed in your compiler path. Compile using:
```bash
g++ main.cpp Board.cpp AI.cpp Game.cpp -o tictactoe.exe -lsfml-graphics -lsfml-window -lsfml-system
```

## Runtime Dependencies
The following library files are required in the executable folder to run:
* `libsfml-graphics-3.dll`
* `libsfml-window-3.dll`
* `libsfml-system-3.dll`
* `libfreetype-6.dll`
* `libpng16-16.dll`
* `zlib1.dll`
* `libbz2-1.dll`
* `libbrotlicommon.dll`
* `libbrotlidec.dll`
* `libharfbuzz-0.dll`
* `libglib-2.0-0.dll`
* `libgraphite2.dll`
* `libiconv-2.dll`
* `libintl-8.dll`
* `libgcc_s_seh-1.dll`
* `libstdc++-6.dll`
* `libwinpthread-1.dll`
