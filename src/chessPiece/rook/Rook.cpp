// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Rook.cpp                                                          ║
// ║ Description  : Implementation of the rook chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Rook.h"
Rook::Rook(const ChessPieceType type,
           const ChessPieceColor color,
           Game* instance,
           const int x,
           const int y) : ChessPiece(type, color, instance, x, y) {
}

std::vector<Coords> Rook::getValidMoves(ChessPiece* board[8][8]) {
  std::vector<Coords> moves;
  int _x = this->getX();
  int _y = this->getY();

  // Check horizontal moves to the right
  for (int x = _x + 1; isValidMove(x, _y, board); ++x) {
    moves.emplace_back(x, _y);
    if (board[x][_y] != nullptr) break;
  }

  // Check horizontal moves to the left
  for (int x = _x - 1; isValidMove(x, _y, board); --x) {
    moves.emplace_back(x, _y);
    if (board[x][_y] != nullptr) break;
  }

  // Check vertical moves upwards
  for (int y = _y + 1; isValidMove(_x, y, board); ++y) {
    moves.emplace_back(_x, y);
    if (board[_x][y] != nullptr) break;
  }

  // Check vertical moves downwards
  for (int y = _y - 1; isValidMove(_x, y, board); --y) {
    moves.emplace_back(_x, y);
    if (board[_x][y] != nullptr) break;
  }

  return moves;
}
