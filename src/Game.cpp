// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Game.cpp                                                          ║
// ║ Description  : Implementation of the chess game logic                            ║
// ║ Author(s)    : "Bert Schenkelaars" <r990071@student.thomasmore.be>               ║
// ║              : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/12                                                        ║
// ║ Version      : 1.5                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Game.h"

// ╔════════════════════════════════════════╗
// ║             Constructors               ║
// ╚════════════════════════════════════════╝

Game::Game() {
  // FIXME: DEMONSTRATION OF GUI
  guiDemonstration1();

}


// ╔════════════════════════════════════════╗
// ║             Event handlers             ║
// ╚════════════════════════════════════════╝

// MenuBar

void Game::onFileQuit() {
  // TODO: Handle all option branches
  QMessageBox::StandardButton returnValue = saveQuitMsgBox();

  if (returnValue == QMessageBox::Save) {
    // User clicked Save
    std::cout << "Save clicked" << std::endl;

  } else if (returnValue == QMessageBox::Discard) {
    // User clicked Discard
    std::cout << "Discard clicked" << std::endl;
    exit(0);

  } else if (returnValue == QMessageBox::Cancel) {
    // User clicked Cancel
    std::cout << "Cancel clicked" << std::endl;

  } else {
    // User closed the message box without clicking any button
    std::cout << "Message box closed without selection" << std::endl;
  }
}


void Game::onFileNew() {
  // TODO: handle new game request

  QMessageBox::StandardButton returnValue = yesNoMsgBox(
      "New game",
      "Do you want to start a new game?",
      "All changes will be lost.");

  if (returnValue == QMessageBox::Ok) {
    // User clicked Ok
    // Set all game variables back to default
    doVisualizeMoves = false;
    doVisualizeThreatenedEnemy = false;
    doVisualizeThreatenedFriendly = false;
    clearGUI();

  } else if (returnValue == QMessageBox::Cancel) {
    // User clicked Cancel
    std::cout << "Cancel clicked" << std::endl;

  } else {
    // User closed the message box without clicking any button
    std::cout << "Message box closed without selection" << std::endl;
  }
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

  // FIXME: DEMONSTRATION OF GUI
  guiDemonstration2();
}

// EXAMPLES. These can be removed when understood.

void Game::guiDemonstration1() {
  // This function could be used for filling the board whilst file I/O isn't yet implemented.
  // Black pieces top row
  setChessItem(0, 7, ChessPieceType::ROOK, ChessPieceColor::BLACK);
  setChessItem(1, 7, ChessPieceType::KNIGHT, ChessPieceColor::BLACK);
  setChessItem(2, 7, ChessPieceType::BISHOP, ChessPieceColor::BLACK);
  setChessItem(3, 7, ChessPieceType::QUEEN, ChessPieceColor::BLACK);
  setChessItem(4, 7, ChessPieceType::KING, ChessPieceColor::BLACK);
  setChessItem(5, 7, ChessPieceType::BISHOP, ChessPieceColor::BLACK);
  setChessItem(6, 7, ChessPieceType::KNIGHT, ChessPieceColor::BLACK);
  setChessItem(7, 7, ChessPieceType::ROOK, ChessPieceColor::BLACK);

  // Black pawn row
  setChessItem(0, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  setChessItem(1, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  setChessItem(2, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  setChessItem(3, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  setChessItem(4, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  setChessItem(5, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  setChessItem(6, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  setChessItem(7, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);

  // White pawn row
  setChessItem(0, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  setChessItem(1, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  setChessItem(2, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  setChessItem(3, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  setChessItem(4, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  setChessItem(5, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  setChessItem(6, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  setChessItem(7, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);

  // White pieces bottom row
  setChessItem(0, 0, ChessPieceType::ROOK, ChessPieceColor::WHITE);
  setChessItem(1, 0, ChessPieceType::KNIGHT, ChessPieceColor::WHITE);
  setChessItem(2, 0, ChessPieceType::BISHOP, ChessPieceColor::WHITE);
  setChessItem(3, 0, ChessPieceType::QUEEN, ChessPieceColor::WHITE);
  setChessItem(4, 0, ChessPieceType::KING, ChessPieceColor::WHITE);
  setChessItem(5, 0, ChessPieceType::BISHOP, ChessPieceColor::WHITE);
  setChessItem(6, 0, ChessPieceType::KNIGHT, ChessPieceColor::WHITE);
  setChessItem(7, 0, ChessPieceType::ROOK, ChessPieceColor::WHITE);

  refreshGui();
}
void Game::guiDemonstration2() {
  // Clear initial board setup demonstration
  clearGUI();

  // Place piece images on board
  setChessItem(1, 1, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  setChessItem(0, 3, ChessPieceType::QUEEN, ChessPieceColor::BLACK);
  setChessItem(0, 4, ChessPieceType::KING, ChessPieceColor::WHITE);
  setChessItem(2, 4, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  setChessItem(3, 3, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  setChessItem(2, 7, ChessPieceType::BISHOP, ChessPieceColor::WHITE);
  setChessItem(5, 3, ChessPieceType::KING, ChessPieceColor::WHITE);
  setChessItem(7, 2, ChessPieceType::ROOK, ChessPieceColor::BLACK);

  // Mark threatened friendly pieces
  markCellAs(3, 3, THREATENED_FRIENDLY);
  markCellAs(0, 4, THREATENED_FRIENDLY);

  // Mark threatened enemy pieces based on what piece is selected
  markCellAs(7, 2, THREATENED_ENEMY);


  // Mark the currently selected piece
  markCellAs(2, 7, SELECTED);

  // Mark all possible moves for the selected piece
  markCellAs(1, 6, POSSIBLE);
  markCellAs(0, 5, POSSIBLE);
  markCellAs(3, 6, POSSIBLE);
  markCellAs(4, 5, POSSIBLE);
  markCellAs(5, 4, POSSIBLE);
  markCellAs(6, 3, POSSIBLE);

  refreshGui();

  customMsgBox("Demonstration",
               "It's black's turn",
               "The bishop is selected. Possible moves are shown. Possible takes are highlighted and possible threats to one's own pieces are also shown.");
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
QMessageBox::StandardButton Game::saveQuitMsgBox() {
  return ChessWindow::saveQuitMsgBox();
}
void Game::customMsgBox(const std::string& title, const std::string& header, const std::string& subtext) {
  ChessWindow::customMsgBox(title, header, subtext);
}
QMessageBox::StandardButton Game::yesNoMsgBox(const std::string& title,
                                              const std::string& header,
                                              const std::string& subtext) {
  return ChessWindow::yesNoMsgBox(title, header, subtext);
}