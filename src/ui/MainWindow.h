//
// Created by Caleb Huck on 8/28/21.
//

#ifndef CHECKERSGUI_MAINWINDOW_H
#define CHECKERSGUI_MAINWINDOW_H


#include <QMainWindow>
#include <QtWidgets/qpushbutton.h>
#include <game/GameLoop.h>
//#include "ChoosePlayers.h"
#include "GameBoard.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QApplication *app);
    ~MainWindow() = default;

private:
    QWidget* choose_num_players_ = nullptr;
    GameBoard* game_board_ = nullptr;
    GameLoop* game_loop_ = nullptr;

    int screen_height_;
    int screen_width_;
    int usable_window_height_;
    int usable_window_width_;
    int one_or_two_selection_ = 0;
    int selected_num_players_;
    public slots:
    void SelectPlayersWindow();
    void SetNumPlayers(int num_players);
    void ResetGame();
    void NewGame();
};


#endif //CHECKERSGUI_MAINWINDOW_H
