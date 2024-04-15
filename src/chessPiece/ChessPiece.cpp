// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessPiece.cpp                                                    ║
// ║ Description  : Implementation of the abstract chess piece class                  ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "ChessPiece.h"

ChessPiece::ChessPiece(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y)
    : type(type), color(color), instance(instance), x(x), y(y) {}

std::vector<Coords> ChessPiece::getValidMoves(ChessPiece* board[8][8]) {
  return {};
}
int ChessPiece::getY() const {
  return y;
}
void ChessPiece::setY(int y) {
  ChessPiece::y = y;
}
int ChessPiece::getX() const {
  return x;
}
void ChessPiece::setX(int x) {
  ChessPiece::x = x;
}
ChessPieceType ChessPiece::getType() const {
  return type;
}
ChessPieceColor ChessPiece::getColor() const {
  return color;
}
Game* ChessPiece::getInstance() const {
  return instance;
}
ChessPiece::~ChessPiece() = default;

