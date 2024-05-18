// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessPiece.cpp                                                    ║
// ║ Description  : Implementation of the abstract chess piece class                  ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "ChessPiece.h"

#include "../Game.h"

ChessPiece::ChessPiece(const ChessPieceType type, const ChessPieceColor color, Game& instance, const int x, const int y)
  : type(type), color(color), instance(instance), x(x), y(y), board(instance.board) {
  // Defaults
  hasMoved = false;
}

std::vector<Coords> ChessPiece::getValidMoves() {
  return {};
}

std::vector<Coords> ChessPiece::getValidAttacks() {
  std::vector<Coords> attacks;

  // For all valid moves

  for (const auto& moves = getValidMoves();
    const auto& move : moves) {
    // Which one lands on a piece
    if (board[move.x][move.y] != nullptr) {
      // Valid attack
      attacks.emplace_back(move);
    }
  }

  return attacks;
}


bool ChessPiece::isValidMove(const int x, const int y) const {
  // Move is valid if:
  //  - coordinates are in bounds
  //  − the move location is empty OR not empty but not the same color
  return x >= 0 && x < 8 && y >= 0 && y < 8 && (board[x][y] == nullptr || board[x][y]->getColor() != color);
}

int ChessPiece::getY() const {
  return y;
}

void ChessPiece::setY(const int y) {
  ChessPiece::y = y;
}

int ChessPiece::getX() const {
  return x;
}

void ChessPiece::setX(const int x) {
  ChessPiece::x = x;
}

ChessPieceType ChessPiece::getType() const {
  return type;
}

ChessPieceColor ChessPiece::getColor() const {
  return color;
}

Game& ChessPiece::getInstance() const {
  return instance;
}

void ChessPiece::setHasMoved(const bool hasMoved) {
  ChessPiece::hasMoved = hasMoved;
}

bool ChessPiece::getHasMoved() const {
  return hasMoved;
}

ChessPiece::~ChessPiece() = default;
