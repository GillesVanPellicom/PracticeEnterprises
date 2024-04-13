// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Knight.cpp                                                        ║
// ║ Description  : Implementation of the knight chess piece                          ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Knight.h"
Knight::Knight(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y) : ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Knight::getValidMoves() {
  std::vector<Coords> moves;
  // Pseudo-valid

  int _x = this->getX();
  int _y = this->getY();

  int deltaX[] = {1, 1, 2, 2, -1, -1, -2, -2};
  int deltaY[] = {2, -2, 1, -1, 2, -2, 1, -1};

  for (int i = 0; i < 8; ++i) {
    int newX = _x + deltaX[i];
    int newY = _y + deltaY[i];
    if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
      moves.emplace_back(newX, newY);
    }
  }

  return moves;
}
