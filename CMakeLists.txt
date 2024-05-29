cmake_minimum_required(VERSION 3.28)
project(chess)

# C++ Standard
set(CMAKE_CXX_STANDARD 26)

# ASAN
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# Compiler Flags
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Werror -Ofast")

# Qt6 Integration
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Source Files
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

# Executable Creation
add_executable(chess ${SOURCE_FILES})

# Link with Qt Libraries
target_link_libraries(chess
        Qt::Core
        Qt6::Widgets
)
