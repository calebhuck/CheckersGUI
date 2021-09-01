//
// Created by Caleb Huck on 8/28/21.
//

#include <QMainWindow>
#include "GameBoard.h"
#include "MainWindow.h"
#include <QDebug>
#include <QWidget>
//#include "Board_Tile.h"
#include "Token.h"

GameBoard::GameBoard(int height, int width, MainWindow *parent) {
    this->setParent(parent);
    this->resize(height, width);

    int tile_size = height / 8;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board_[i][j] = new BoardTile(i, j, this);
            if ((i + 1) % 2 == 0)
                if ((j + 1) % 2 == 0)
                    board_[i][j]->setStyleSheet("background-color: #3f6e3a");
                else
                    board_[i][j]->setStyleSheet("background-color: white");
            else
                if ((j + 1) % 2 == 0)
                    board_[i][j]->setStyleSheet("background-color: white");
                else
                    board_[i][j]->setStyleSheet("background-color: #3f6e3a");

                board_[i][j]->resize(tile_size, tile_size);
                board_[i][j]->move(j * tile_size, i * tile_size);
        }

    }
    for (int i = 0; i < 24; i++) {
        tokens_.push_back(new Token(i));
    }
    ResetGame();
}

void GameBoard::ResetGame() {
    auto it = tokens_.begin();
    auto *p1_icon = new QIcon("../img/p1.svg");
    auto *p1_icon_king = new QIcon("../img/p1_king.svg");
    auto *p2_icon = new QIcon("../img/p2.svg");
    auto *p2_icon_king = new QIcon("../img/p2_king.svg");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i <= 2 || i >= 5) {
                if (j % 2 == 0 && i % 2 == 0) {
                    const QIcon temp("../img/coin.svg");
                    board_[i][j]->setIcon(temp);
                }
                else if (j % 2 != 0 && i % 2 != 0) {
                    const QIcon temp("../img/coin.svg");
                    board_[i][j]->setIcon(temp);
                }

            }
        }
    }
}

void GameBoard::TileClicked(int row, int col) {
    qDebug() << row << col;
}