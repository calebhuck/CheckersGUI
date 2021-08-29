//
// Created by Caleb Huck on 8/28/21.
//

#ifndef CHECKERSGUI_GAMEBOARD_H
#define CHECKERSGUI_GAMEBOARD_H

#include <QWidget>
#include <QGraphicsScene>
#include "BoardTile.h"
class MainWindow;

class GameBoard : public QWidget {
    Q_OBJECT
public:
    GameBoard(int height, int width, MainWindow *parent);
    ~GameBoard() = default;
private:
    BoardTile *board[64];
public slots:
    void TileClicked(int row, int col);
};


#endif //CHECKERSGUI_GAMEBOARD_H
