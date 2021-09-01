//
// Created by Caleb Huck on 8/29/21.
//

#ifndef CHECKERSGUI_TOKEN_H
#define CHECKERSGUI_TOKEN_H

#include <QIcon>
class BoardTile;

class Token {

public:
    Token(QIcon *icon);
    ~Token() = default;

    void SetTile(BoardTile *tile);

private:
    QIcon *icon_;
    BoardTile *tile_;
};


#endif //CHECKERSGUI_TOKEN_H
