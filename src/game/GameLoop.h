//
// Created by Caleb Huck on 9/11/21.
//

#ifndef CHECKERSGUI_GAMELOOP_H
#define CHECKERSGUI_GAMELOOP_H

#include <QThread>
#include "GameLoop.h"
class GameBoard;
class GameLoop : public QThread {
Q_OBJECT
public:
    GameLoop(QObject* parent, int num_players, GameBoard *game_board);
    ~GameLoop() = default;
    void abort();
    bool abort_ = false;
private:
    void run() override;
};


#endif //CHECKERSGUI_GAMELOOP_H
