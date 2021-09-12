//
// Created by Caleb Huck on 8/28/21.
//

#include <QMainWindow>
#include "GameBoard.h"
#include "MainWindow.h"
#include <QDebug>
#include <QWidget>
#include "ui/BoardTile.h"
#include "game/Token.h"

GameBoard::GameBoard(int height, int width, MainWindow *parent) {
    this->setParent(parent);
    this->resize(height, width);
    p1_icon_ = new QIcon("../img/p1.png");
    p1_icon_king_ = new QIcon("../img/p1_king.png");
    p2_icon_ = new QIcon("../img/p2.png");
    p2_icon_king_ = new QIcon("../img/p2_king.png");

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
    for (int i = 0; i < 12; i++) {
        p1_tokens_.push_back(new Token(i, p1_icon_, p1_icon_king_));
        p2_tokens_.push_back(new Token(i, p2_icon_, p2_icon_king_));
    }
    ResetGame();
}

void GameBoard::ResetGame() {
    auto p1_it = p1_tokens_.begin();
    auto p2_it = p2_tokens_.begin();

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i <= 2) {
                if ((j % 2 == 0 && i % 2 == 0) || (j % 2 != 0 && i % 2 != 0)) {
                    (*std::next(p1_it, 1))->SetTile(board_[i][j]);
                }
            }
            else if (i >= 5) {
                if ((j % 2 == 0 && i % 2 == 0) || (j % 2 != 0 && i % 2 != 0)) {
                    (*std::next(p2_it, 1))->SetTile(board_[i][j]);
                }
            }
        }
    }
}

void GameBoard::TileClicked(int row, int col) {
    qDebug() << row << col;
}