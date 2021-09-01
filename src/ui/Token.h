//
// Created by Caleb Huck on 8/29/21.
//

#ifndef CHECKERSGUI_TOKEN_H
#define CHECKERSGUI_TOKEN_H

#include <QIcon>
#include "BoardTile.h"
class BoardTile;

class Token {

public:
    Token(int id);
    ~Token() = default;

    void SetTile(BoardTile *tile);
    void SetIcons(QIcon *reg, QIcon *king);

private:
    int id_;
    bool kinged_ = false;
    QIcon *reg_;
    QIcon *king_;
    BoardTile *tile_;
};


#endif //CHECKERSGUI_TOKEN_H
