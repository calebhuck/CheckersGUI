//
// Created by Caleb Huck on 9/11/21.
//

#include <iostream>
#include "GameLoop.h"

GameLoop::GameLoop(QObject* parent) : QThread(parent){}

void GameLoop::run() {
    while (!abort_) {
        std::cout << "testing game loop...\n";
//        sleep(2);
    }
}

void GameLoop::abort() {
    abort_ = true;
}