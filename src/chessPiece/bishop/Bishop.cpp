// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Bishop.cpp                                                        ║
// ║ Description  : Implementation of the bishop chess piece                          ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Bishop.h"
Bishop::Bishop(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y) : ChessPiece(type,
                                                                                                      color,
                                                                                                      instance,
                                                                                                      x,
                                                                                                      y) {}

std::vector<Coords> Bishop::getValidMoves() {
  std::vector<Coords> moves;

  int _x = this->getX();
  int _y = this->getY();

  // Pseudo-valid
  for (int i = 1; i < 8; ++i) {
    // Right & up (x+, y+)
    if (_x + i < 8 && _y + i < 8)
      moves.emplace_back(_x + i, _y + i);

    // Right & down (x+, y-)
    if (_x + i < 8 && _y - i >= 0)
      moves.emplace_back(_x + i, _y - i);

    // Left & up (x-, y+)
    if (_x - i >= 0 && _y + i < 8)
      moves.emplace_back(_x - i, _y + i);

    // Left & down (x-, y-)
    if (_x - i >= 0 && _y - i >= 0)
      moves.emplace_back(_x - i, _y - i);
  }

  return moves;
}