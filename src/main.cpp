#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QLabel>
#include <QMenuBar>
#include <iostream>
#include <QScreen>
#include <chrono>
#include <thread>
#include <QDebug>
#include <QDate>
#include "ui/GameWindow.h"
#include "debug/debug.h"
#define QT_MESSAGELOGCONTEXT

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    qInstallMessageHandler(DebugMessageHandler);

    GameWindow window;
    window.resize(500, 800);
    window.setWindowTitle("Simple example");
    window.setToolTip("QWidget");

//    while (true) {
//        std::cout << window.size().width() << " " << window.size().height() << std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds (1000));
//    }


    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    std::cout << height << " " << width << std::endl;

    window.show();


    return QApplication::exec();
}
