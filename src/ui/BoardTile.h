//
// Created by Caleb Huck on 8/29/21.
//

#ifndef CHECKERSGUI_BOARDTILE_H
#define CHECKERSGUI_BOARDTILE_H

#include <QWidget>
#include <QPushButton>
#include "Token.h"

class GameBoard;
class BoardTile : public QPushButton {
    Q_OBJECT
public:
    BoardTile(int i, int j, GameBoard *parent);
    ~BoardTile() = default;
    bool Selected();
    void SetToken(Token *token);
private:
    int row_;
    int col_;
    bool selected_;
    Token *token_ = nullptr;
signals:
    void TileClicked(int row, int col);
public slots:
    void ClickEvent();
};


#endif //CHECKERSGUI_BOARDTILE_H
