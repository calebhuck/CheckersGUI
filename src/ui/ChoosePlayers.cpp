//
// Created by Caleb Huck on 8/28/21.
//

#include "ChoosePlayers.h"
#include "MainWindow.h"
#include <QApplication>
#include <QStyle>

ChoosePlayers::ChoosePlayers(int usable_window_height, int usable_window_width, MainWindow *parent) {
    this->setParent(parent);
    this->resize(usable_window_height, usable_window_width);
    int window_bar_offset = QApplication::style()->pixelMetric(QStyle::PM_TitleBarHeight);
    one_player_btn = new QPushButton("One Player", this);
    two_player_btn = new QPushButton("Two Player", this);
    one_player_btn->setStyleSheet("background-color:#254030; border-radius:20px; border:1px solid black; font-family:verdana; font-size:30px");
    two_player_btn->setStyleSheet("background-color:#254030; border-radius:20px; border:1px solid black; font-family:verdana; font-size:30px");
    int button_height = usable_window_width / 7;
    int button_width = usable_window_height / 3;

//    QWidget *test = new QWidget(this);
//    test->setStyleSheet("background-color:#90ab91; border-radius:40px; border: 2px solid grey");
//    int middle_square_dim = 500;
//    test->resize(middle_square_dim, middle_square_dim);
//    test->move(usable_window_width / 2 - middle_square_dim / 2 , usable_window_height / 2 - middle_square_dim / 2);
//    test->lower();

    qDebug() << usable_window_height;
    qDebug() << usable_window_width;
    one_player_btn->resize(button_width, button_height);
    two_player_btn->resize(button_width, button_height);
    one_player_btn->move(usable_window_width / 2 - one_player_btn->width() / 2, usable_window_height / 2 - one_player_btn->height() - 10);// - one_player_btn->height() / 2);

    two_player_btn->move(usable_window_width / 2 - two_player_btn->width() / 2, usable_window_height / 2 + 10);

    QObject::connect(one_player_btn, &QPushButton::clicked, this, &ChoosePlayers::SetOnePlayer);
    QObject::connect(two_player_btn, &QPushButton::clicked, this, &ChoosePlayers::SetTwoPlayer);
    QObject::connect(this, &ChoosePlayers::SetNumPlayers, parent, &MainWindow::SetNumPlayers);
}

void ChoosePlayers::SetOnePlayer() {
    qDebug() << "set one player";
    emit SetNumPlayers(1);
}

void ChoosePlayers::SetTwoPlayer() {
    qDebug() << "set two oplayer";
    emit SetNumPlayers(2);
}