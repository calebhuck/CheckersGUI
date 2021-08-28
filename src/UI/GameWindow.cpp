//
// Created by Caleb Huck on 8/23/21.
//

#include "GameWindow.h"
#include <iostream>
#include <QPushButton>
#include <QMainWindow>

GameWindow::GameWindow()
{
    button = new QPushButton("test", this);
    QObject::connect(button, &QPushButton::clicked, this, &QMainWindow::close);
    button->resize(200, 100);
    button->setObjectName("Test button");
    button->move(50, 60);
    std::cout << "constructor" << std::endl;
}