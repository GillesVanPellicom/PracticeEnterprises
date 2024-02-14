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
  // TODO: ask user before quit using modal window
  exit(0);
}


void Game::onFileNew() {
  // TODO: handle new game request
  std::cout << "Test file/new" << std::endl;
}


void Game::onFileSave() {
  // TODO: handle file saving
  std::cout << "Test file/save" << std::endl;

}


void Game::onFileLoad() {
  // TODO: handle file loading
  std::cout << "Test file/load" << std::endl;

}


void Game::onGameUndo() {
  // TODO: undo functionality
  std::cout << "Test game/undo" << std::endl;

}


void Game::onGameRedo() {
  // TODO: redo functionality
  std::cout << "Test game/redo" << std::endl;

}


void Game::onVisualizeMoves() {
  if (doVisualizeMoves) {
    // Turn off markings
    removeAllMarkingsType(ChessType::POSSIBLE);
    refreshGui();
    doVisualizeMoves = false;
    return;
  }
  doVisualizeMoves = true;

  // TODO: Place code to retrieve and display possible moves here

  // EXAMPLE
  // =========================
  markCellAs(6, 3, ChessType::POSSIBLE);
  markCellAs(6, 2, ChessType::POSSIBLE);
  refreshGui();
  // =========================


}


void Game::onVisualizeThreatenedEnemy() {
  if (doVisualizeThreatenedEnemy) {
    // Turn off markings
    removeAllMarkingsType(ChessType::THREATENED_ENEMY);
    refreshGui();
    doVisualizeThreatenedEnemy = false;
    return;
  }
  doVisualizeThreatenedEnemy = true;

  // TODO: Place code to retrieve and display threatened enemy pieces here

  // EXAMPLE
  // =========================
  markCellAs(1, 3, ChessType::THREATENED_ENEMY);
  markCellAs(1, 2, ChessType::THREATENED_ENEMY);
  refreshGui();
  // =========================

}


void Game::onVisualizeThreatenedFriendly() {
  if (doVisualizeThreatenedFriendly) {
    // Turn off markings
    removeAllMarkingsType(ChessType::THREATENED_FRIENDLY);
    refreshGui();
    doVisualizeThreatenedFriendly = false;
    return;
  }
  doVisualizeThreatenedFriendly = true;

  // TODO: Place code to retrieve and display threatened friendly pieces here

  // EXAMPLE
  // =========================
  markCellAs(3, 3, ChessType::THREATENED_FRIENDLY);
  markCellAs(3, 2, ChessType::THREATENED_FRIENDLY);
  refreshGui();
  // =========================

}


void Game::onClick(int x, int y) {
  // TODO: handle mouse clicks
  std::cout << "Clicked at coordinates: (" << x << ", " << y << ")" << std::endl;
}


// Inherited functions
void Game::markCellAs(int x, int y, ChessType::BoardMarkingType type) {
  ChessWindow::markCellAs(x, y, type);
}
void Game::removeAllMarkingsType(ChessType::BoardMarkingType type) {
  ChessWindow::removeAllMarkingsType(type);
}
void Game::refreshGui() {
  ChessWindow::refreshGui();
}


