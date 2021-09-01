//
// Created by Caleb Huck on 8/29/21.
//
#include <QWidget>
#include "BoardTile.h"
#include "GameBoard.h"
BoardTile::BoardTile(int i, int j, GameBoard *parent) {
    row_ = i;
    col_ = j;
    selected_ = false;
    QObject::connect(this, &QPushButton::clicked, this, &BoardTile::ClickEvent);
    QObject::connect(this, &BoardTile::TileClicked, parent, &GameBoard::TileClicked);
    this->setParent(parent);
}

void BoardTile::ClickEvent() {
//    selected = !selected;
//    if (selected) {
//        this->setStyleSheet(this->styleSheet().append(QString(";border: 2px solid yellow")));
//    }
//    else {
//        this->setStyleSheet(this->styleSheet().append(QString(";border: none")));
//    }
    emit TileClicked(row_, col_);
}

bool BoardTile::Selected() {
    return selected_;
}

void BoardTile::SetToken(Token *token) {
    token = token;
}