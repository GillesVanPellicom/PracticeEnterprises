cmake_minimum_required(VERSION 3.28)
project(chess)

set(CMAKE_CXX_STANDARD 26)

# ASAN
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# Flags
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Werror")

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
        src/chessPiece/ChessPiece.cpp
        src/chessPiece/ChessPiece.h
        src/chessPiece/bishop/Bishop.cpp
        src/chessPiece/bishop/Bishop.h
        src/chessPiece/king/King.cpp
        src/chessPiece/king/King.h
        src/chessPiece/knight/Knight.cpp
        src/chessPiece/knight/Knight.h
        src/chessPiece/pawn/Pawn.cpp
        src/chessPiece/pawn/Pawn.h
        src/chessPiece/queen/Queen.cpp
        src/chessPiece/queen/Queen.h
        src/chessPiece/rook/Rook.cpp
        src/chessPiece/rook/Rook.h
)
add_executable(chess ${SOURCE_FILES})

# More Qt stuff
target_link_libraries(chess
        Qt::Core
        Qt6::Widgets
)

