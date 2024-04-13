// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Bishop.cpp                                                        ║
// ║ Description  : Implementation of the bishop chess piece                          ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Bishop.h"
Bishop::Bishop(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y) : ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Bishop::getValidMoves() {
  std::vector<Coords> moves;
  // Pseudo-valid

  int currentX = this->getX();
  int currentY = this->getY();

  for (int i = -7; i <= 7; ++i) {
    if (currentX + i >= 0 && currentX + i < 8 && currentY + i >= 0 && currentY + i < 8 && i != 0) {
      moves.emplace_back(currentX + i, currentY + i);
      moves.emplace_back(currentX - i, currentY + i);
    }
  }

  return moves;
}