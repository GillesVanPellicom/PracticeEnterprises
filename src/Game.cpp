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
  std::cout << "Test visualize/moves" << std::endl;

}

void Game::onVisualizeThreatenedEnemy() {
  std::cout << "Test visualize/threatenedEnemy" << std::endl;

}

void Game::onVisualizeThreatenedPlayer() {
  std::cout << "Test visualize/threatenedPlayer" << std::endl;

}

void Game::onClick(int x, int y) {
  std::cout << "Clicked at coordinates: (" << x << ", " << y << ")" << std::endl;
}
