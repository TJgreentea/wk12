#include <iostream>
#include "Game.h"

int main() {
    Game game;
    game.initGame(5, 3, 100, 100);

    game.gameLoop(10, 5.0);

    return 0;
}
