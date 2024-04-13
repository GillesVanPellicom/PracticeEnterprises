// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : King.cpp                                                          ║
// ║ Description  : Implementation of the king chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "King.h"
King::King(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y) : ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> King::getValidMoves() {
  std::vector<Coords> moves;

  int _x = this->getX();
  int _y = this->getY();

  // Pseudo-valid
  int deltaX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int deltaY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int i = 0; i < 8; ++i) {
    int newX = _x + deltaX[i];
    int newY = _y + deltaY[i];
    if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
      moves.emplace_back(newX, newY);
    }
  }

  return moves;
}
