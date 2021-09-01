//
// Created by Caleb Huck on 8/29/21.
//

#include "Token.h"

Token::Token(int id) {
    id_ = id;
}

void Token::SetTile(BoardTile *tile) {
    tile_ = tile;
    if (kinged_) {
        tile_->setIcon(*king_);
    }
}

void Token::SetIcons(QIcon *reg, QIcon *king) {
    reg_ = reg;
    king_ = king;
}