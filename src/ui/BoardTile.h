//
// Created by Caleb Huck on 8/29/21.
//

#ifndef CHECKERSGUI_BOARDTILE_H
#define CHECKERSGUI_BOARDTILE_H

#include <QWidget>
#include <QPushButton>
class GameBoard;
class BoardTile : public QPushButton {
    Q_OBJECT
public:
    BoardTile(int i, int j, GameBoard *parent);
    ~BoardTile() = default;
    bool Selected();
private:
    int row;
    int col;
    bool selected;
signals:
    void TileClicked(int row, int col);
public slots:
    void ClickEvent();
};


#endif //CHECKERSGUI_BOARDTILE_H
