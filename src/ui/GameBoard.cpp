//
// Created by Caleb Huck on 8/28/21.
//

#include <QMainWindow>
#include "GameBoard.h"
#include "MainWindow.h"
#include <QDebug>
#include <QWidget>

GameBoard::GameBoard(int height, int width, MainWindow *parent) {
    qDebug() << "contructor";
    this->setParent(parent);
    board = new QWidget[64];
}