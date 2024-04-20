// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Queen.cpp                                                         ║
// ║ Description  : Implementation of the queen chess piece                           ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Queen.h"
Queen::Queen(const ChessPieceType type,
             const ChessPieceColor color,
             Game& instance,
             const int x,
             const int y) : ChessPiece(type, color, instance, x, y) {
}

std::vector<Coords> Queen::getValidMoves() {
  std::vector<Coords> moves;

  const int _x = this->getX();
  const int _y = this->getY();

  // Check diagonal moves (top-right, top-left, bottom-right, bottom-left)
  for (const int dx : {-1, 1}) {
    for (const int dy : {-1, 1}) {
      for (int i = 1; i < 8; ++i) {
        int new_x = _x + i * dx;
        int new_y = _y + i * dy;
        if (!isValidMove(new_x, new_y)) break;
        moves.emplace_back(new_x, new_y);
        if (this->board[new_x][new_y] != nullptr) break;
      }
    }
  }

  // Horizontal moves (right, left)
  for (const int dx : {-1, 1}) {
    for (int x = _x + dx; x >= 0 && x < 8; x += dx) {
      if (!isValidMove(x, _y)) break;
      moves.emplace_back(x, _y);
      if (this->board[x][_y] != nullptr) break;
    }
  }

  // Vertical moves (up, down)
  for (const int dy : {-1, 1}) {
    for (int y = _y + dy; y >= 0 && y < 8; y += dy) {
      if (!isValidMove(_x, y)) break;
      moves.emplace_back(_x, y);
      if (this->board[_x][y] != nullptr) break;
    }
  }

  return moves;
}
