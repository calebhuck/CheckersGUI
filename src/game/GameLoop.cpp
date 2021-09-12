//
// Created by Caleb Huck on 9/11/21.
//

#include <iostream>
#include <ui/GameBoard.h>
#include "GameLoop.h"
class GameBoard;
GameLoop::GameLoop(QObject* parent, int num_players, GameBoard *game_board) {}

void GameLoop::run() {
    while (!abort_) {
        std::cout << "testing game loop...\n";
//        sleep(2);
    }
}

void GameLoop::abort() {
    abort_ = true;
}