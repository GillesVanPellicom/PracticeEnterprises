// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessPiece.cpp                                                    ║
// ║ Description  : Implementation of the abstract chess piece class                  ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "ChessPiece.h"

#include "../Game.h"

ChessPiece::ChessPiece(const ChessPieceType type, const ChessPieceColor color, Game* instance, const int x, const int y)
  : type(type), color(color), instance(instance), x(x), y(y), board(instance->board) {
}

std::vector<Coords> ChessPiece::getValidMoves() {
  return {};
}
bool ChessPiece::isValidMove(const int x, const int y) {
  return x >= 0 && x < 8 && y >= 0 && y < 8 && (board[x][y] == nullptr || board[x][y]->getColor() != color);
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
void ChessPiece::setX(const int x) {
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
