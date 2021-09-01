//
// Created by Caleb Huck on 8/29/21.
//

#include "Token.h"

Token::Token(QIcon *icon) {
    icon_ = icon;
}

void Token::SetTile(BoardTile *tile) {
    tile_ = tile;
}