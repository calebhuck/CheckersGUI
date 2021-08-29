//
// Created by Caleb Huck on 8/28/21.
//

#ifndef CHECKERSGUI_GAMEBOARD_H
#define CHECKERSGUI_GAMEBOARD_H

#include <QWidget>
#include <QGraphicsScene>
class MainWindow;

class GameBoard : public QWidget {
    Q_OBJECT
public:
    GameBoard(int height, int width, MainWindow *parent);
    ~GameBoard() = default;

private:
    QWidget *board;
};


#endif //CHECKERSGUI_GAMEBOARD_H
