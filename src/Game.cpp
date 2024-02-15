// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Game.cpp                                                          ║
// ║ Description  : Implementation of the chess game logic                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Game.h"

// ╔════════════════════════════════════════╗
// ║             Constructors               ║
// ╚════════════════════════════════════════╝

Game::Game() {}


// ╔════════════════════════════════════════╗
// ║             Event handlers             ║
// ╚════════════════════════════════════════╝

// MenuBar

void Game::onFileQuit() {
  // TODO: ask user before quit using modal window
  exit(0);
}


void Game::onFileNew() {
  // TODO: handle new game request
  // Set all game variables back to default
  doVisualizeMoves = false;
  doVisualizeThreatenedEnemy = false;
  doVisualizeThreatenedFriendly = false;
  clearGUI();
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
    removeAllMarkingsType(POSSIBLE);
    refreshGui();
    doVisualizeMoves = false;
    return;
  }
  doVisualizeMoves = true;

  // TODO: Place code to retrieve and display possible moves here

  // EXAMPLE
  // =========================
  markCellAs(6, 3, POSSIBLE);
  markCellAs(6, 2, POSSIBLE);
  setChessItem(4, 4, ChessPieceType::QUEEN, ChessPieceColor::BLACK);
  refreshGui();
  // =========================


}


void Game::onVisualizeThreatenedEnemy() {
  if (doVisualizeThreatenedEnemy) {
    // Turn off markings
    removeAllMarkingsType(THREATENED_ENEMY);
    refreshGui();
    doVisualizeThreatenedEnemy = false;
    return;
  }
  doVisualizeThreatenedEnemy = true;

  // TODO: Place code to retrieve and display threatened enemy pieces here

  // EXAMPLE
  // =========================
  markCellAs(1, 3, THREATENED_ENEMY);
  markCellAs(1, 2, THREATENED_ENEMY);
  setChessItem(4, 4, ChessPieceType::EMPTY, ChessPieceColor::NO_COLOR);
  setChessItem(0, 0, ChessPieceType::PAWN, ChessPieceColor::BLACK);

  refreshGui();
  // =========================

}


void Game::onVisualizeThreatenedFriendly() {
  if (doVisualizeThreatenedFriendly) {
    // Turn off markings
    removeAllMarkingsType(THREATENED_FRIENDLY);
    refreshGui();
    doVisualizeThreatenedFriendly = false;
    return;
  }
  doVisualizeThreatenedFriendly = true;

  // TODO: Place code to retrieve and display threatened friendly pieces here

  // EXAMPLE
  // =========================
  markCellAs(3, 3, THREATENED_FRIENDLY);
  markCellAs(3, 2, THREATENED_FRIENDLY);
  markCellAs(3, 7, THREATENED_FRIENDLY);
  markCellAs(3, 6, THREATENED_FRIENDLY);
  refreshGui();
  // =========================

}

// MouseClickEvent Handler

void Game::onClick(int x, int y) {
  // TODO: handle mouse clicks
  std::cout << "Clicked at coordinates: (" << x << ", " << y << ")" << std::endl;
}


// ╔════════════════════════════════════════╗
// ║          Inherited Functions           ║
// ╚════════════════════════════════════════╝

void Game::markCellAs(int x, int y, BoardMarkingType type) {
  ChessWindow::markCellAs(x, y, type);
}
void Game::removeAllMarkingsType(BoardMarkingType type) {
  ChessWindow::removeAllMarkingsType(type);
}
void Game::refreshGui() {
  ChessWindow::refreshGui();
}
void Game::setChessItem(int x, int y, ChessPieceType type, ChessPieceColor color) {
  ChessWindow::setChessItem(x, y, type, color);
}
void Game::clearGUI() {
  ChessWindow::clearGUI();
}


