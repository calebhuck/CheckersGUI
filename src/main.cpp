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
#include "ui/MainWindow.h"
#define QT_MESSAGELOGCONTEXT

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    qInstallMessageHandler(DebugMessageHandler);
    MainWindow window(&app);
//    qFatal("Jonathan, you are not the favorite...");

//    while (true) {
//        std::cout << window.size().width() << " " << window.size().height() << std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds (1000));
//    }

//    window.show();


    return QApplication::exec();
}
