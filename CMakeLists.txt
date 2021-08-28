cmake_minimum_required(VERSION 3.20)
project(CheckersGUI)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(CheckersGUI src/main.cpp src/UI/GameWindow.cpp src/UI/GameWindow.h src/debug/debug.cpp src/debug/debug.h)
target_link_libraries(CheckersGUI
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

set_property(TARGET CheckersGUI PROPERTY AUTOMOC ON)

