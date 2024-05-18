// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : King.cpp                                                          ║
// ║ Description  : Implementation of the king chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "King.h"

#include "../../Game.h"
King::King(const ChessPieceType type,
           const ChessPieceColor color,
           Game& instance,
           const int x,
           const int y) : ChessPiece(type, color, instance, x, y) {
}

std::vector<Coords> King::getValidMovesExclCastling() const {
  std::vector<Coords> moves;
  constexpr int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
      dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int i = 0; i < 8; ++i) {
    if (const int newX = x + dx[i], newY = y + dy[i];
      isValidMove(newX, newY)) {
      moves.emplace_back(newX, newY);
    }
  }
  return moves;
}


std::vector<Coords> King::getValidMoves() {
  // Regular moves
  // This is split to avoid infinite loops since castling checks require recursive board analysys.
  auto moves = getValidMovesExclCastling();

  // Castling

  // Reset variables from previous iterations
  isValidCastleKS = false;
  isValidCastleQS = false;

  // Row 0 for white, 7 for black
  const int row = color == WHITE ? 0 : 7;

  // If king has moved or king is in check
  if (hasMoved ||
    (getInstance().blackInCheck && color == BLACK) || (getInstance().whiteInCheck && color == WHITE)) {
    // Castling not possible
    return moves;
  }
  // King hasn't moved and isn't in check

  // for left and right rook cells
  for (const int col : {0, 7}) {
    // If current cell is empty or current piece isn't a rook or current piece has moved
    if (const auto& curr = board[col][row];
      curr == nullptr || curr->getType() != ROOK || curr->getHasMoved()) {
      // Next iteration
      continue;
    }

    // Check if line of sight is clear and line of sight doesn't pass trough check
    // move left for left rook and right for right rook
    const int dx = col == 0 ? -1 : 1;

    // Starting from king position, move left or right
    bool lineChecksPassed = true;
    for (int i = 4 + dx; i > 0 && i < 7; i += dx) {
      // Check line of sight
      if (board[i][row] != nullptr) {
        // Line of sight not clear
        lineChecksPassed = false;
        break;
      }

      // Check pass trough check
      if (const ChessPieceColor attackingColor = color == WHITE ? BLACK : WHITE;
        getInstance().canBeAttacked(i, row, attackingColor)) {
        // Pass trough check
        lineChecksPassed = false;
        break;
      }
    }

    if (!lineChecksPassed) {
      continue;
    }

    // Castling possible
    // Move is always one before rook
    const int newCol = col == 0 ? 2 : 6;
    moves.emplace_back(newCol, row);

    // Set castling variable for move function

    if (col == 0) {
      // Left side or queenside
      isValidCastleQS = true;
      castleQS = {newCol, row};
    } else {
      // Right side or kingside
      isValidCastleKS = true;
      castleKS = {newCol, row};
    }
  }

  return moves;
}
