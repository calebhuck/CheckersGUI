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
#include "game/GameLoop.h"

MainWindow::MainWindow(QApplication *app) {
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
    screen_height_ = screen->geometry().height();
    screen_width_ = screen->geometry().width();
    usable_window_height_ = screen->geometry().height() / 2;
    usable_window_width_ = screen->geometry().height() / 2;

    this->setFixedSize(usable_window_height_, usable_window_width_);
    this->setStyleSheet("background-color:#cdcdcd");

    game_loop_ = new GameLoop(this);
    QObject::connect(app, &QApplication::aboutToQuit, game_loop_, [this](){
        game_loop_->abort();
        game_loop_->quit();
        game_loop_->wait(6000);
    });
    SelectPlayersWindow();
    this->show();
}

void MainWindow::SelectPlayersWindow() {
    if (game_board_ != nullptr) {
        delete game_board_;
        game_board_ = nullptr;
    }
    choose_num_players_ = new ChoosePlayers(usable_window_height_, usable_window_width_, this);
    this->setCentralWidget(choose_num_players_);
}

void MainWindow::SetNumPlayers(int num_players) {
    selected_num_players_ = num_players;
    delete choose_num_players_;
    game_board_ = new GameBoard(usable_window_height_, usable_window_width_, this);
    this->setCentralWidget(game_board_);
    if (game_loop_ != nullptr) {
        delete game_loop_;
    }
    game_loop_ = new GameLoop(this);
    game_loop_->start();

}

void MainWindow::ResetGame() {
    qDebug() << "reset game";
}

void MainWindow::NewGame() {
    qDebug() << "new game";
}