// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Rook.cpp                                                          ║
// ║ Description  : Implementation of the rook chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Rook.h"
Rook::Rook(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y) : ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Rook::getValidMoves() {
  std::vector<Coords> moves;
  // Pseudo-valid

  for (int i = 0; i < 8; ++i) {
    if (i != this->getX()) {
      moves.emplace_back(i, this->getY());
    }
    if (i != this->getY()) {
      moves.emplace_back(this->getX(), i);
    }
  }
  return moves;
}
