cmake_minimum_required(VERSION 3.27)
project(chess)

set(CMAKE_CXX_STANDARD 23)

# Qt stuff
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Source file
set(SOURCE_FILES main.cpp
        gui/ChessWindow.cpp
        gui/ChessWindow.h
        gui/ChessScene.cpp
        gui/ChessScene.h
        Game.cpp
        Game.h
)
add_executable(chess ${SOURCE_FILES}
        lib/mini/ini.h)

# More Qt stuff
target_link_libraries(chess
        Qt::Core
        Qt6::Widgets
)

