//
// Created by Caleb Huck on 8/23/21.
//

#ifndef CHECKERSGUI_GAMEWINDOW_H
#define CHECKERSGUI_GAMEWINDOW_H


#include <QMainWindow>
#include <QPushButton>

class GameWindow : public QMainWindow{
    Q_OBJECT
public:
    GameWindow();
    ~GameWindow() = default;
private:
    QPushButton *button;
};


#endif //CHECKERSGUI_GAMEWINDOW_H
