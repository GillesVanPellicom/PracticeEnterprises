// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Rook.cpp                                                          ║
// ║ Description  : Implementation of the rook chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Rook.h"
Rook::Rook(const ChessPieceType type,
           const ChessPieceColor color,
           Game& instance,
           const int x,
           const int y) : ChessPiece(type, color, instance, x, y) {
}

std::vector<Coords> Rook::getValidMoves() {
  std::vector<Coords> moves;

  int _x = this->getX();
  int _y = this->getY();

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
