//
// Created by Caleb Huck on 8/29/21.
//

#include "Token.h"

Token::Token(int id, QIcon* reg, QIcon *king) : id_(id), reg_(reg), king_(king){

}

void Token::SetTile(BoardTile *tile) {
    tile_ = tile;
    if (kinged_) {
        tile_->setIcon(*king_);
        tile_->setIconSize(QSize(static_cast<int>(tile_->height() * .8), static_cast<int>(tile_->height() * .8)));
    }
    else {
        tile_->setIcon(*reg_);
        tile_->setIconSize(QSize(static_cast<int>(tile_->height() * .8), static_cast<int>(tile_->height() * .8)));
    }
}