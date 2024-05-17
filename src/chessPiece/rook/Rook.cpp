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
           const int y) : ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Rook::getValidMoves() {
  std::vector<Coords> moves;

  // Horizontal moves (right, left)
  for (const int dx : {-1, 1}) {
    for (int _x = this->x + dx; _x >= 0 && _x < 8; _x += dx) {
      if (!isValidMove(_x, this->y)) break;
      moves.emplace_back(_x, this->y);
      if (this->board[_x][this->y] != nullptr) break;
    }
  }

  // Vertical moves (up, down)
  for (const int dy : {-1, 1}) {
    for (int _y = this->y + dy; _y >= 0 && _y < 8; _y += dy) {
      if (!isValidMove(this->x, _y)) break;
      moves.emplace_back(this->x, _y);
      if (this->board[this->x][_y] != nullptr) break;
    }
  }

  return moves;
}
