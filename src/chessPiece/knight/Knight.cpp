// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Knight.cpp                                                        ║
// ║ Description  : Implementation of the knight chess piece                          ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Knight.h"
Knight::Knight(const ChessPieceType type,
               const ChessPieceColor color,
               Game& instance,
               const int x,
               const int y) : ChessPiece(type, color, instance, x, y) {
}

std::vector<Coords> Knight::getValidMoves() {
  std::vector<Coords> moves;

  const int _x = this->getX();
  const int _y = this->getY();

  constexpr int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
  constexpr int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

  for (int i = 0; i < 8; ++i) {
    int newX = _x + dx[i];
    int newY = _y + dy[i];
    if (isValidMove(newX, newY)) {
      moves.emplace_back(newX, newY);
    }
  }

  return moves;
}
