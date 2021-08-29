//
// Created by Caleb Huck on 8/28/21.
//

#include <QGuiApplication>
#include "MainWindow.h"
#include "ChoosePlayers.h"
#include "GameBoard.h"
#include <QScreen>
#include <QApplication>
#include <QStyle>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include "GameBoard.h"

MainWindow::MainWindow() {
    this->setWindowTitle("CheckersGUI");
    QMenuBar *menu_bar = this->menuBar();
    QMenu *menu = new QMenu("Game");
    QAction *reset_game = new QAction("Reset Game");
    QAction *new_game = new QAction("New Game");
    menu->addAction(reset_game);
    menu->addAction(new_game);
    menu_bar->addAction(menu->menuAction());
    QObject::connect(reset_game, &QAction::triggered, this, &MainWindow::ResetGame);
    QObject::connect(new_game, &QAction::triggered, this, &MainWindow::NewGame);

    QScreen *screen = QGuiApplication::primaryScreen();
    screen_height = screen->geometry().height();
    screen_width = screen->geometry().width();
    usable_window_height = screen->geometry().height() / 2;
    usable_window_width = screen->geometry().height() / 2;

    this->setFixedSize(usable_window_height, usable_window_width);
    this->setStyleSheet("background-color:#bac7b0");

    choose_num_players = new ChoosePlayers(usable_window_height, usable_window_width, this);
//    QObject::connect(choose_num_players, Ch)




//    this->se
    this->show();
}

void MainWindow::SetNumPlayers(int num_players) {
    selected_num_players = num_players;
    delete choose_num_players;
    game_board = new GameBoard(usable_window_height, usable_window_width, this);
}

void MainWindow::ResetGame() {
    qDebug() << "reset game";
}

void MainWindow::NewGame() {
    qDebug() << "new game";
}