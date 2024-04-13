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

  int _x = this->getX();
  int _y = this->getY();

  // Pseudo-valid
  for (int i = 0; i < 8; ++i) {
    if (i != _x) {
      moves.emplace_back(i, _y);
    }
    if (i != _y) {
      moves.emplace_back(_x, i);
    }
  }
  return moves;
}
