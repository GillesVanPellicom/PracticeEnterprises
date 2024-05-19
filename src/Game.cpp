// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Game.cpp                                                          ║
// ║ Description  : Implementation of the chess game logic                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/12                                                        ║
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
    showVisualizeMoves(selected.x, selected.y);
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

  if (promotionBox() == QUEEN) {
    std::cout << "great success" << std::endl;
  }
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
  // If game has ended don't handle clicks
  if (checkmate != NO_COLOR) {
    return;
  }

  std::cout << "click: (" << x << ", " << y << ") => ";
  // Remove all markings from previous iteration
  removeAllMarkingsType(POSSIBLE);

  const ChessPiecePtr& piece = board[x][y];

  // If selected cell is the same as the new cell
  if (isSelected && selected.x == x && selected.y == y) {
    std::cout << "deselect" << std::endl;
    // Unmark
    setSelected(x, y, false);

    refreshGui();
    return;
  }

  // If a cell was previously selected and that cell contains a chess piece
  if (isSelected && board[selected.x][selected.y] != nullptr) {
    // potential move

    // Check potential move against list of actually valid moves for that piece

    // if an iterator is returned
    if (const auto& validMoves = board[selected.x][selected.y]->getValidMoves();
      std::ranges::find_if(validMoves,
                           [x, y](const auto& move) {
                             return move.x == x && move.y == y;
                           }) != validMoves.end()) {
      // confirmed move
      std::cout << "move";

      // If selected piece is not empty and of type PAWN and en passent is possible
      if (const auto& p = dynamic_cast<Pawn*>(board[selected.x][selected.y].get());
        p != nullptr && p->getType() == PAWN && p->getEnPassentIsValid()) {
        // If the move to be made can be found in the list of possible en passent moves
        if (const auto& enPassentMoves = p->getEnPassentMoves();
          std::ranges::find_if(enPassentMoves.begin(),
                               enPassentMoves.end(),
                               [x, y](const auto& move) {
                                 return move.x == x && move.y == y;
                               }) != enPassentMoves.end()) {
          // Current move is en passent
          std::cout << ", en passent";

          // Movement goes down for white, up for black.
          const int dy = p->getColor() == WHITE ? -1 : 1;

          // Special case, take piece under or above location to be moved to
          movePiece(selected.x, selected.y, x, y + dy);

          // Modify selected coordinates to reflect move
          selected = {x, y + dy};

          // Let final location movement and potential double capture be handled by main code
        }
      }

      // If selected piece is not empty and of type KING and castling is possible
      if (const auto& k = dynamic_cast<King*>(board[selected.x][selected.y].get());
        k != nullptr && k->getType() == KING && (k->isValidCastleKS || k->isValidCastleQS)) {
        // If castle kingside coordinates equal current
        if (auto [_x, _y] = k->castleKS; _x == x && _y == y) {
          // Verified KS castle.
          std::cout << ", castle KS";
          movePiece(7, y, 5, y);

          // If castle queenside coordinates equal current
        } else if (auto [_x, _y] = k->castleQS; _x == x && _y == y) {
          // Verified QS castle.
          std::cout << ", castle QS";
          movePiece(0, y, 3, y);
        }
      }

      movePiece(selected.x, selected.y, x, y);
      setSelected(x, y, false);

      // Check check
      check();

      if (whiteInCheck) {
        // Possible white checkmate
        checkMate(WHITE);
      }

      if (blackInCheck) {
        // Possible white checkmate
        checkMate(BLACK);
      }

      check();

      if (checkmate != NO_COLOR) {
        // Confirmed checkmate
        if (checkmate == WHITE) {
          std::cout << ", checkmate (white)";
        } else {
          std::cout << ", checkmate (black)";
        }
        std::cout << std::endl;

        refreshGui();
        customMsgBox("Checkmate!", "Checkmate", "Someone won!");
        return;
      }

      if (whiteInCheck) {
        std::cout << ", check (white)";
      }
      if (blackInCheck) {
        std::cout << ", check (black)";
      }

      // Switch turns
      currentTurn = (currentTurn == WHITE) ? BLACK : WHITE;

      refreshGui();
      std::cout << std::endl;

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
      showVisualizeMoves(x, y);
    }

    refreshGui();
    return;
  }

  std::cout << "invalid" << std::endl;
}


// ╔════════════════════════════════════════╗
// ║         Game helper functions          ║
// ╚════════════════════════════════════════╝

ChessPieceColor Game::invertColor(const ChessPieceColor color) {
  return color == WHITE ? BLACK : WHITE;
}

void Game::check() {
  whiteInCheck = isAttackable(whiteKingPos.x, whiteKingPos.y, BLACK);
  blackInCheck = isAttackable(blackKingPos.x, blackKingPos.y, WHITE);
}

void Game::checkMate(const ChessPieceColor color) {
  for (const auto& col : board) {
    for (const auto& p : col) {
      // Skip pieces of wrong color
      if (p == nullptr || p->getColor() != color) continue;

      for (const auto [x2, y2] : p->getValidMoves()) {
        simulateMove(p->getX(), p->getY(), x2, y2);
        check();
        if ((color == WHITE && !whiteInCheck) || (color == BLACK && !blackInCheck)) {
          // Escape possible
          // Stop simulation
          stopSimulation();
          // Return check state to before simulation
          check();
          refreshGui();
          std::cout << "Escape possible" << std::endl;

          return;
        }
        stopSimulation();
      }
    }
  }


  std::cout << "No escape possible" << std::endl;
  // No escape possible, color is in checkmate
  checkmate = color;
}


bool Game::isAttackable(const int x, const int y, const ChessPieceColor attackerColor) {
  // For the entire board
  for (const auto& col : board) {
    for (const auto& p : col) {
      // If current cell empty or piece color not attackerCollor, continue.
      if (p == nullptr || p->getColor() != attackerColor) continue;
      // Generate it's valid moves and see if one of these moves is a check, if so return true
      if (const auto moves = p->getValidMoves();
        std::ranges::any_of(moves,
                            [&](const auto& move) {
                              return move.x == x && move.y == y;
                            })) {
        return true;
      }
    }
  }
  // If no check was found, return false
  return false;
}


Coords& Game::findKing(const ChessPieceColor color) {
  if (color == WHITE) {
    return whiteKingPos;
  }
  return blackKingPos;
}


void Game::showVisualizeMoves(const int x, const int y) {
  // For all moves
  for (const auto [_x, _y] : board[x][y]->getValidMoves()) {
    // Mark cell
    markCellAs(_x, _y, POSSIBLE);
  }
}


void Game::initializeGame() {
  // Reset variables from previous iteration
  currentTurn = WHITE;

  isSelected = false;
  selected = {-1, -1};

  whiteKingPos = {4, 0};
  blackKingPos = {4, 7};

  blackInCheck = false;
  whiteInCheck = false;

  // Initialize board as nullptrs
  // Skipping this step leads to undefined cross-platform behavior
  for (auto& i : board) {
    for (int j = 0; j < std::size(board[0]); ++j) {
      i[j] = nullptr;
    }
  }

  // // Black pieces top row
  // generatePiece(0, 7, ROOK, BLACK);
  // generatePiece(1, 7, KNIGHT, BLACK);
  // generatePiece(2, 7, BISHOP, BLACK);
  // generatePiece(3, 7, QUEEN, BLACK);
  // generatePiece(4, 7, KING, BLACK);
  // generatePiece(5, 7, BISHOP, BLACK);
  // generatePiece(6, 7, KNIGHT, BLACK);
  // generatePiece(7, 7, ROOK, BLACK);
  //
  // // Black pawn row
  // for (int i = 0; i < 8; ++i) {
  //   generatePiece(i, 6, PAWN, BLACK);
  // }
  //
  // // White pawn row
  // for (int i = 0; i < 8; ++i) {
  //   generatePiece(i, 1, PAWN, WHITE);
  // }
  //
  // generatePiece(2, 1, ROOK, BLACK);
  //
  //
  // // White pieces bottom row
  // generatePiece(0, 0, ROOK, WHITE);
  // generatePiece(1, 0, KNIGHT, WHITE);
  // generatePiece(2, 0, BISHOP, WHITE);
  // generatePiece(3, 0, QUEEN, WHITE);
  // generatePiece(4, 0, KING, WHITE);
  // generatePiece(5, 0, BISHOP, WHITE);
  // generatePiece(6, 0, KNIGHT, WHITE);
  // generatePiece(7, 0, ROOK, WHITE);


  generatePiece(4, 7, KING, BLACK);

  generatePiece(5, 5, QUEEN, WHITE);
  generatePiece(5, 2, BISHOP, WHITE);

  generatePiece(4, 0, KING, WHITE);


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
      board[x][y] = std::make_shared<King>(type, color, *this, x, y);
      break;
    }

    case QUEEN: {
      board[x][y] = std::make_shared<Queen>(type, color, *this, x, y);
      break;
    }

    case ROOK: {
      board[x][y] = std::make_shared<Rook>(type, color, *this, x, y);
      break;
    }

    case BISHOP: {
      board[x][y] = std::make_shared<Bishop>(type, color, *this, x, y);
      break;
    }

    case KNIGHT: {
      board[x][y] = std::make_shared<Knight>(type, color, *this, x, y);
      break;
    }

    case PAWN: {
      board[x][y] = std::make_shared<Pawn>(type, color, *this, x, y);
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
  ChessPiecePtr& current = board[x1][y1];

  // If piece has not moved
  if (!current->getHasMoved()) {
    // set hasMoved to true
    current->setHasMoved(true);
  }

  // If move captures piece
  if (board[x2][y2] != nullptr) {
    std::cout << ", capture";
    // If piece captured is a king
    if (const ChessPiecePtr& p = board[x2][y2]; p->getType() == KING) {
      // Set win variable to appropriate side
      checkmate = invertColor(p->getColor());
    }
    board[x2][y2].reset();
  }

  // If promotion is applicable

  // No special move applicable

  // Move piece
  board[x2][y2] = std::move(current);
  board[x1][y1].reset();

  // Make piece aware of its own position
  board[x2][y2]->setX(x2);
  board[x2][y2]->setY(y2);

  if ((y2 == 7 || y2 == 0) && board[x2][y2]->getType() == PAWN) {
    std::cout << ", promotion";
    // Get attributes before removal
    const ChessPieceColor color = board[x2][y2]->getColor();

    // Remove current pawn
    board[x2][y2] = nullptr;

    // Generate new piece as chosen by promotionBox()
    generatePiece(x2, y2, promotionBox(), color);
    // Point current to new ChessPiece
  }

  // Remember king position
  if (board[x2][y2]->getType() == KING) {
    if (board[x2][y2]->getColor() == WHITE) {
      whiteKingPos = {x2, y2};
    } else {
      blackKingPos = {x2, y2};
    }
  }

  // Make GUI reflect changes
  setChessItem(x1, y1, EMPTY, NO_COLOR);
  setChessItem(x2, y2, EMPTY, NO_COLOR);

  setChessItem(x2, y2, board[x2][y2]->getType(), board[x2][y2]->getColor());
}


void Game::setSelected(const int x, const int y, const bool _isSelected) {
  if (_isSelected) {
    markCellAs(x, y, SELECTED);
    this->isSelected = true;
    selected = {x, y};
  } else {
    removeAllMarkingsType(SELECTED);
    this->isSelected = false;
    selected = {-1, -1};
  }
}

bool Game::canBeAttacked(const int x, const int y, const ChessPieceColor attackerColor) const {
  // For entire board
  for (const auto& row : board) {
    for (const auto& piece : row) {
      // Check if the piece is not null and matches the specified color
      if (piece != nullptr && piece->getColor() == attackerColor) {
        // For all attacks for this piece, check if the given position is vulnerable

        // King's getValidMoves() makes a call to this function trough other functions.
        // getValidAttacks() makes a call to getValidMoves();
        // To avoid an infinite function loop,
        // when the type is KING, we need to get all moves excluding castling
        // This doesn't affect anything since you can't capture with castling anyways.
        for (const auto& attacks = (piece->getType() == KING)
                                     ? dynamic_cast<King*>(piece.get())->getValidMovesExclCastling()
                                     : piece->getValidMoves();
             const auto [_x, _y] : attacks) {
          if (_x == x && _y == y) {
            // The position can be attacked
            return true;
          }
        }
      }
    }
  }
  // The position cannot be attacked
  return false;
}

void Game::takeBoardSnapshot() {
}

void Game::simulateMove(const int x1, const int y1, const int x2, const int y2) {
  // If a previous simulation is active, stop.
  if (simulationActive) {
    stopSimulation();
  }
  movePieceSimulated(x1, y1, x2, y2);
}

void Game::stopSimulation() {
  if (!simulationActive) return;

  // Revert move based on saved data
  movePieceSimulated(simCoords2.x, simCoords2.y, simCoords1.x, simCoords1.y);
  // Return captured piece from limbo if applicable
  if (simulationLimbo != nullptr) {
    board[simulationLimboCoords.x][simulationLimboCoords.y] = std::move(simulationLimbo);
  }
  // Mark simulation as inactive
  simulationActive = false;
}

void Game::movePieceSimulated(const int x1, const int y1, const int x2, const int y2) {
  simulationActive = true;

  // Save state for revert
  simCoords1 = {x1, y1};
  simCoords2 = {x2, y2};

  // If move is capture
  if (board[x2][y2] != nullptr) {
    // Save piece to limbo
    simulationLimbo = std::move(board[x2][y2]);
    simulationLimboCoords = {x2, y2};
  }

  board[x2][y2] = std::move(board[x1][y1]);
  board[x1][y1] = nullptr;

  // Make piece aware of its own position
  board[x2][y2]->setX(x2);
  board[x2][y2]->setY(y2);
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

ChessPieceType Game::promotionBox() {
  return ChessWindow::promotionBox();
}
