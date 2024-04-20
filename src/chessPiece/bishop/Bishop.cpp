// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Bishop.cpp                                                        ║
// ║ Description  : Implementation of the bishop chess piece                          ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Bishop.h"
Bishop::Bishop(const ChessPieceType type,
               const ChessPieceColor color,
               Game& instance,
               const int x,
               const int y) : ChessPiece(type, color, instance, x, y) {
}

std::vector<Coords> Bishop::getValidMoves() {
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

  return moves;
}
