//
// Created by Caleb Huck on 8/28/21.
//

#include <QMainWindow>
#include "GameBoard.h"
#include "MainWindow.h"
#include <QDebug>
#include <QWidget>
//#include "BoardTile.h"

GameBoard::GameBoard(int height, int width, MainWindow *parent) {
    this->setParent(parent);
    this->resize(height, width);
//    board = new QWidget[64];
    int tile_size = height / 8;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i * 8 + j] = new BoardTile(i, j, this);
            if ((i + 1) % 2 == 0)
                if ((j + 1) % 2 == 0)
                    board[i  * 8 + j]->setStyleSheet("background-color: #3f6e3a");
                else
                    board[i  * 8 + j]->setStyleSheet("background-color: white");
            else
                if ((j + 1) % 2 == 0)
                    board[i  * 8 + j]->setStyleSheet("background-color: white");
                else
                    board[i  * 8 + j]->setStyleSheet("background-color: #3f6e3a");

            board[i * 8 + j]->resize(tile_size, tile_size);
            board[i * 8 + j]->move(i * tile_size, j * tile_size);
        }

    }
}

void GameBoard::TileClicked(int row, int col) {
    qDebug() << row << col;
}