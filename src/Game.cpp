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
  initializeGame();

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
  std::cout << "Clicked at coordinates: (" << x << ", " << y << ")" << std::endl;
  markCellAs(x, y, BoardMarkingType::SELECTED);

  // If selected cell is the same as the new cell
  if (isSelected && selected.x == x && selected.y == y) {
    std::cout << "Unmarked" << std::endl;
    // Unmark
    setSelected(x, y, false);
    refreshGui();
    return;
  }

  // If a cell was previously selected and that cell contains a chess piece and the new cell is empty
  if (isSelected && board[selected.x][selected.y] != nullptr && board[x][y] == nullptr) {
    std::cout << "move" << std::endl;
    // A possible move could be made.
    // FIXME: Check move validity
    // Temp: just move piece
    movePiece(selected.x, selected.y, x, y);
    setSelected(x, y, false);
    // Unmark when move is complete
    markCellAs(x, y, BoardMarkingType::SELECTED);
    refreshGui();
    return;
  }

  // If the clicked cell contains a piece and that piece is the same color as the current turn
  if (board[x][y] != nullptr && board[x][y]->getColor() == currentTurn) {
    // Select cell
    std::cout << "select" << std::endl;

    // Switch turns
    currentTurn = (board[x][y]->getColor() == ChessPieceColor::WHITE) ? ChessPieceColor::BLACK : ChessPieceColor::WHITE;

    setSelected(x, y, true);
    refreshGui();
    return;
  }

  std::cout << "Invalid" << std::endl;
}


void Game::initializeGame() {

  isSelected = false;
  currentTurn == ChessPieceColor::WHITE;

  // Initialize board as nullptr
  // Skipping this step leads to undefined cross-platform behavior
  for (int i = 0; i < std::size(board); ++i) {
    for (int j = 0; j < std::size(board[0]); ++j) {
      board[i][j] = nullptr;
    }
  }

  // Black pieces top row
  generatePiece(0, 7, ChessPieceType::ROOK, ChessPieceColor::BLACK);
  generatePiece(1, 7, ChessPieceType::KNIGHT, ChessPieceColor::BLACK);
  generatePiece(2, 7, ChessPieceType::BISHOP, ChessPieceColor::BLACK);
  generatePiece(3, 7, ChessPieceType::QUEEN, ChessPieceColor::BLACK);
  generatePiece(4, 7, ChessPieceType::KING, ChessPieceColor::BLACK);
  generatePiece(5, 7, ChessPieceType::BISHOP, ChessPieceColor::BLACK);
  generatePiece(6, 7, ChessPieceType::KNIGHT, ChessPieceColor::BLACK);
  generatePiece(7, 7, ChessPieceType::ROOK, ChessPieceColor::BLACK);

  // Black pawn row
  generatePiece(0, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  generatePiece(1, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  generatePiece(2, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  generatePiece(3, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  generatePiece(4, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  generatePiece(5, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  generatePiece(6, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);
  generatePiece(7, 6, ChessPieceType::PAWN, ChessPieceColor::BLACK);

  // White pawn row
  generatePiece(0, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  generatePiece(1, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  generatePiece(2, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  generatePiece(3, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  generatePiece(4, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  generatePiece(5, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  generatePiece(6, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);
  generatePiece(7, 1, ChessPieceType::PAWN, ChessPieceColor::WHITE);

  // White pieces bottom row
  generatePiece(0, 0, ChessPieceType::ROOK, ChessPieceColor::WHITE);
  generatePiece(1, 0, ChessPieceType::KNIGHT, ChessPieceColor::WHITE);
  generatePiece(2, 0, ChessPieceType::BISHOP, ChessPieceColor::WHITE);
  generatePiece(3, 0, ChessPieceType::QUEEN, ChessPieceColor::WHITE);
  generatePiece(4, 0, ChessPieceType::KING, ChessPieceColor::WHITE);
  generatePiece(5, 0, ChessPieceType::BISHOP, ChessPieceColor::WHITE);
  generatePiece(6, 0, ChessPieceType::KNIGHT, ChessPieceColor::WHITE);
  generatePiece(7, 0, ChessPieceType::ROOK, ChessPieceColor::WHITE);

  markCellAs(0, 0, BoardMarkingType::THREATENED_FRIENDLY);

  refreshGui();
}


bool Game::generatePiece(int x, int y, ChessPieceType type, ChessPieceColor color) {
  // If position occupied, fail.
  if (board[x][y] != nullptr) {
    return false;
  }

  // Instantiate appropriate object for type
  switch (type) {

    case KING: {
      board[x][y] = new King(type, color, this, x, y);
      break;
    }

    case QUEEN: {
      board[x][y] = new Queen(type, color, this, x, y);
      break;
    }

    case ROOK: {
      board[x][y] = new Rook(type, color, this, x, y);
      break;
    }

    case BISHOP: {
      board[x][y] = new Bishop(type, color, this, x, y);
      break;
    }

    case KNIGHT: {
      board[x][y] = new Knight(type, color, this, x, y);
      break;
    }

    case PAWN: {
      board[x][y] = new Pawn(type, color, this, x, y);
      break;
    }
    case EMPTY: {
      // If empty, fail.
      return false;
    }
  }

  setChessItem(x, y, type, color);

  return true;
}


bool Game::movePiece(int x1, int y1, int x2, int y2) {

  if (board[x2][y2] != nullptr) {
    return false;
  }

  ChessPiece* current = board[x1][y1];

  // Move piece
  board[x2][y2] = current;
  board[x1][y1] = nullptr;

  // Make piece aware of it's own position
  current->setX(x2);
  current->setY(y2);

  // Make GUI reflect changes
  setChessItem(x1, y1, ChessPieceType::EMPTY, ChessPieceColor::NO_COLOR);
  setChessItem(x2, y2, current->getType(), current->getColor());

  return true;
}


void Game::setSelected(int x, int y, bool isSelected) {
  if (isSelected) {
    this->isSelected = true;
    selected.x = x;
    selected.y = y;
  } else {

    this->isSelected = false;
    selected.x = -1;
    selected.y = -1;
  }
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


