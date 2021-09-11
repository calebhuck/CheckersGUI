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
    BoardTile *board_[8][8];
    std::vector<Token*> p1_tokens_;
    std::vector<Token*> p2_tokens_;
    QIcon* p1_icon_;
    QIcon* p1_icon_king_;
    QIcon* p2_icon_;
    QIcon* p2_icon_king_;
public slots:
    void TileClicked(int row, int col);
    void ResetGame();
};


#endif //CHECKERSGUI_GAMEBOARD_H
