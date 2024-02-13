// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Game.cpp                                                          ║
// ║ Description  : Implementation of the chess game logic                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Game.h"

void Game::onFileQuit() {
  std::cout << "Test file/quit" << std::endl;
  exit(0);
}


void Game::onFileNew() {
  std::cout << "Test file/new" << std::endl;
}


void Game::onFileSave() {
  std::cout << "Test file/save" << std::endl;

}


void Game::onFileLoad() {
  std::cout << "Test file/load" << std::endl;

}


void Game::onGameUndo() {
  std::cout << "Test game/undo" << std::endl;

}


void Game::onGameRedo() {
  std::cout << "Test game/redo" << std::endl;

}


void Game::onVisualizeMoves() {
  if (!doVisualizeMoves) {
    // TODO: Place code to retrieve and display possible moves here

    // EXAMPLE
    markCellAs(5, 3, ChessType::POSSIBLE);
    markCellAs(5, 2, ChessType::POSSIBLE);


    doVisualizeMoves = true;
    return;
  }
  removeAllMarkingsType(ChessType::POSSIBLE);
  doVisualizeMoves = false;
}


void Game::onVisualizeThreatenedEnemy() {
  if (!doVisualizeThreatenedEnemy) {
    // TODO: Place code to retrieve and display threatened enemy pieces here

    // EXAMPLE
    markCellAs(2, 3, ChessType::THREATENED_ENEMY);
    markCellAs(2, 2, ChessType::THREATENED_ENEMY);


    doVisualizeThreatenedEnemy = true;
    return;
  }
  removeAllMarkingsType(ChessType::THREATENED_ENEMY);

  doVisualizeThreatenedEnemy = false;

}


void Game::onVisualizeThreatenedFriendly() {
  if (!doVisualizeThreatenedFriendly) {
    // TODO: Place code to retrieve and display threatened friendly pieces here

    // EXAMPLE
    markCellAs(3, 3, ChessType::THREATENED_FRIENDLY);
    markCellAs(3, 2, ChessType::THREATENED_FRIENDLY);


    doVisualizeThreatenedFriendly = true;
    return;
  }
  removeAllMarkingsType(ChessType::THREATENED_FRIENDLY);
  doVisualizeThreatenedFriendly = false;

}


void Game::onClick(int x, int y) {
  std::cout << "Clicked at coordinates: (" << x << ", " << y << ")" << std::endl;
}

// Inherited functions
void Game::markCellAs(int x, int y, ChessType::BoardMarkingType type) {
  ChessWindow::markCellAs(x, y, type);
}
void Game::removeAllMarkingsType(ChessType::BoardMarkingType type) {
  ChessWindow::removeAllMarkingsType(type);
}


