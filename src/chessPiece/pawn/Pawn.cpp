// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Pawn.cpp                                                          ║
// ║ Description  : Implementation of the pawn chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Pawn.h"
Pawn::Pawn(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y) :
ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Pawn::getValidMoves() {
  std::vector<Coords> moves;

  int _x = this->getX();
  int _y = this->getY();

  // Pseudo-valid
  int deltaY;

  deltaY = (this->getColor() == ChessPieceColor::WHITE) ? 1 : -1;
  moves.emplace_back(_x, _y+deltaY);

  if (isFirstMove) {
    deltaY = (this->getColor() == ChessPieceColor::WHITE) ? 2 : -2;
    moves.emplace_back(_x, _y+deltaY);

    isFirstMove = false;
  }

  return moves;
}
