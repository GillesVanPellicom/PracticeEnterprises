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
  // Ask user input
  if (yesNoMsgBox(
      "New game",
      "Do you want to start a new game?",
      "All changes will be lost.") == QMessageBox::Ok) {
    // User clicked Ok
    // Reset GUI
    clearGUI();

    // Set all game variables back to default
    initializeGame();
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
  // Turn on markings
  doVisualizeMoves = true;

  // In case piece was already selected
  if (isSelected) {
    // Immediately show markings
    showVisualizeMoves(board[selected.x][selected.y]);
    refreshGui();
  }
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
  setChessItem(4, 4, EMPTY, NO_COLOR);
  setChessItem(0, 0, PAWN, BLACK);

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

void Game::onClick(const int x, const int y) {
  std::cout << "Clicked at coordinates: (" << x << ", " << y << ")" << std::endl;
  // Remove all markings from previous iteration
  removeAllMarkingsType(POSSIBLE);

  ChessPiece* piece = board[x][y];

  // If selected cell is the same as the new cell
  if (isSelected && selected.x == x && selected.y == y) {
    std::cout << "deselect" << std::endl;
    // Unmark
    setSelected(x, y, false);

    refreshGui();
    return;
  }

  // If a cell was previously selected and that cell contains a chess piece and the new cell is empty
  if (isSelected && board[selected.x][selected.y] != nullptr) {
    bool moveIsValid = false;
    for (const auto& move : board[selected.x][selected.y]->getValidMoves(board)) {
      if (move.x == x && move.y == y) {
        moveIsValid = true;
        break;
      }
    }

    if (moveIsValid) {
      std::cout << "move" << std::endl;

      if (board[selected.x][selected.y]->getType() == PAWN) {
        auto* p = dynamic_cast<Pawn*>(board[selected.x][selected.y]);
        if (p->getIsFirstMove()) {
          p->setIsFirstMove(false);
        }
        // FIXME: en passant
      }

      movePiece(selected.x, selected.y, x, y);

      setSelected(x, y, false);

      // Switch turns
      currentTurn = (currentTurn == WHITE) ? BLACK : WHITE;

      refreshGui();
      return;
    }
  }


  // If the clicked cell contains a piece and that piece is the same color as the current turn
  if (piece != nullptr && piece->getColor() == currentTurn) {
    std::cout << "select" << std::endl;

    // If a cell is already selected
    if (isSelected) {
      // Deselect old cell
      setSelected(-1, -1, false);
    }

    // Select cell
    setSelected(x, y, true);

    // Something has to be visualised
    if (doVisualizeMoves) {
      showVisualizeMoves(piece);
    }

    refreshGui();
    return;
  }

  std::cout << "invalid" << std::endl;
}


// ╔════════════════════════════════════════╗
// ║         Game helper functions          ║
// ╚════════════════════════════════════════╝

void Game::showVisualizeMoves(ChessPiece* piece) {
  for (const auto& move : piece->getValidMoves(board)) {
    markCellAs(move.x, move.y, POSSIBLE);
  }
}


void Game::initializeGame() {
  isSelected = false;
  currentTurn = WHITE;

  // Initialize board as nullptr
  // Skipping this step leads to undefined cross-platform behavior
  for (int i = 0; i < std::size(board); ++i) {
    for (int j = 0; j < std::size(board[0]); ++j) {
      board[i][j] = nullptr;
    }
  }

  // Black pieces top row
  generatePiece(0, 7, ROOK, BLACK);
  generatePiece(1, 7, KNIGHT, BLACK);
  generatePiece(2, 7, BISHOP, BLACK);
  generatePiece(3, 7, QUEEN, BLACK);
  generatePiece(4, 7, KING, BLACK);
  generatePiece(5, 7, BISHOP, BLACK);
  generatePiece(6, 7, KNIGHT, BLACK);
  generatePiece(7, 7, ROOK, BLACK);

  // Black pawn row
  for (int i = 0; i < 8; ++i) {
    generatePiece(i, 6, PAWN, BLACK);
  }

  // White pawn row
  for (int i = 0; i < 8; ++i) {
    generatePiece(i, 1, PAWN, WHITE);
  }

  // White pieces bottom row
  generatePiece(0, 0, ROOK, WHITE);
  generatePiece(1, 0, KNIGHT, WHITE);
  generatePiece(2, 0, BISHOP, WHITE);
  generatePiece(3, 0, QUEEN, WHITE);
  generatePiece(4, 0, KING, WHITE);
  generatePiece(5, 0, BISHOP, WHITE);
  generatePiece(6, 0, KNIGHT, WHITE);
  generatePiece(7, 0, ROOK, WHITE);


  refreshGui();
}


bool Game::generatePiece(const int x, const int y, const ChessPieceType type, const ChessPieceColor color) {
  // Position occupied, fail.
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


void Game::movePiece(const int x1, const int y1, const int x2, const int y2) {
  ChessPiece* current = board[x1][y1];

  // If move takes piece
  if (board[x2][y2] != nullptr) {
    delete board[x2][y2];
  }

  // Move piece
  board[x2][y2] = current;
  board[x1][y1] = nullptr;

  // Make piece aware of its own position
  current->setX(x2);
  current->setY(y2);

  // Make GUI reflect changes
  setChessItem(x1, y1, EMPTY, NO_COLOR);
  setChessItem(x2, y2, EMPTY, NO_COLOR);

  setChessItem(x2, y2, current->getType(), current->getColor());
}


void Game::setSelected(const int x, const int y, const bool _isSelected) {
  if (_isSelected) {
    markCellAs(x, y, SELECTED);
    this->isSelected = true;
    selected.x = x;
    selected.y = y;
  } else {
    removeAllMarkingsType(SELECTED);
    this->isSelected = false;
    selected.x = -1;
    selected.y = -1;
  }
}


// ╔════════════════════════════════════════╗
// ║          Inherited Functions           ║
// ╚════════════════════════════════════════╝

void Game::markCellAs(const int x, const int y, const BoardMarkingType type) {
  ChessWindow::markCellAs(x, y, type);
}

void Game::removeAllMarkingsType(const BoardMarkingType type) {
  ChessWindow::removeAllMarkingsType(type);
}

void Game::refreshGui() {
  ChessWindow::refreshGui();
}

void Game::setChessItem(const int x, const int y, const ChessPieceType type, const ChessPieceColor color) {
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
