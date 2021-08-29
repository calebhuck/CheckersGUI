//
// Created by Caleb Huck on 8/28/21.
//

#ifndef CHECKERSGUI_MAINWINDOW_H
#define CHECKERSGUI_MAINWINDOW_H


#include <QMainWindow>
#include <QtWidgets/qpushbutton.h>
//#include "ChoosePlayers.h"
#include "GameBoard.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow() = default;

private:
    QWidget *choose_num_players;
    GameBoard *game_board;

    int screen_height;
    int screen_width;
    int usable_window_height;
    int usable_window_width;
    int one_or_two_selection = 0;
    int selected_num_players;
public slots:
    void SetNumPlayers(int num_players);
    void ResetGame();
    void NewGame();
};


#endif //CHECKERSGUI_MAINWINDOW_H
