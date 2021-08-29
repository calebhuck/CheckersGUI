//
// Created by Caleb Huck on 8/28/21.
//

#ifndef CHECKERSGUI_CHOOSEPLAYERS_H
#define CHECKERSGUI_CHOOSEPLAYERS_H
#include <QWidget>
#include <QPushButton>
#include "MainWindow.h"

class ChoosePlayers : public QWidget {
    Q_OBJECT
public:
    ChoosePlayers(int usable_window_height, int usable_window_width, MainWindow *parent);
    ~ChoosePlayers() = default;
private:
    QPushButton *one_player_btn;
    QPushButton *two_player_btn;
signals:
    void SetNumPlayers(int num_players);
public slots:
    void SetOnePlayer();
    void SetTwoPlayer();
};


#endif //CHECKERSGUI_CHOOSEPLAYERS_H
