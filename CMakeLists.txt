cmake_minimum_required(VERSION 3.27)
project(chess)

set(CMAKE_CXX_STANDARD 23)

# Qt6
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Source file
set(SOURCE_FILES src/main.cpp
        src/gui/ChessWindow.cpp
        src/gui/ChessWindow.h
        src/gui/ChessScene.cpp
        src/gui/ChessScene.h
        src/Game.cpp
        src/Game.h
        src/lib/mini/ini.h
        src/utils/Type.cpp
        src/utils/Type.h
        src/gui/ChessMenu.cpp
        src/gui/ChessMenu.h
)
add_executable(chess ${SOURCE_FILES})

# More Qt stuff
target_link_libraries(chess
        Qt::Core
        Qt6::Widgets
)

