// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : King.cpp                                                          ║
// ║ Description  : Implementation of the king chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "King.h"
King::King(const ChessPieceType type,
           const ChessPieceColor color,
           Game& instance,
           const int x,
           const int y) : ChessPiece(type, color, instance, x, y) {
}

std::vector<Coords> King::getValidMoves() {
  auto& board = this->getInstance()->board;

  std::vector<Coords> moves;

  const int _x = this->getX();
  const int _y = this->getY();

  constexpr int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  constexpr int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int i = 0; i < 8; ++i) {
    const int newX = _x + dx[i];
    const int newY = _y + dy[i];
    if (isValidMove(newX, newY)) {

      moves.emplace_back(newX, newY);
    }
  }

  return moves;
}
