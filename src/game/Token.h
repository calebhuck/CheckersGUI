//
// Created by Caleb Huck on 8/29/21.
//

#ifndef CHECKERSGUI_TOKEN_H
#define CHECKERSGUI_TOKEN_H

#include <QIcon>
#include "ui/BoardTile.h"
class BoardTile;

class Token {

public:
    Token(int id, QIcon* reg, QIcon* king);
    ~Token() = default;

    void SetTile(BoardTile *tile);

private:
    int id_;
    bool kinged_ = false;
    QIcon *reg_;
    QIcon *king_;
    BoardTile *tile_;
};


#endif //CHECKERSGUI_TOKEN_H
