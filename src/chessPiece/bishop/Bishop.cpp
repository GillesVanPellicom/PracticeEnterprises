// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Bishop.cpp                                                        ║
// ║ Description  : Implementation of the bishop chess piece                          ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Bishop.h"
Bishop::Bishop(const ChessPieceType type, const ChessPieceColor color, Game* instance, const int x, const int y) :
ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Bishop::getValidMoves(ChessPiece* board[8][8]) {
  std::vector<Coords> moves;
  const int _x = this->getX();
  const int _y = this->getY();
  const ChessPieceColor color = this->getColor();

  // Define helper function to check if a square is valid to move to
  auto isValidMove = [&](const int x, const int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8 &&
        (board[x][y] == nullptr || board[x][y]->getColor() != color);
  };

  // Check diagonal moves (top-right, top-left, bottom-right, bottom-left)
  for (int i = 1; i < 8; ++i) {
    // Top-right
    if (!isValidMove(_x + i, _y + i)) break;
    moves.emplace_back(_x + i, _y + i);
    if (board[_x + i][_y + i] != nullptr) break;
  }
  for (int i = 1; i < 8; ++i) {
    // Top-left
    if (!isValidMove(_x + i, _y - i)) break;
    moves.emplace_back(_x + i, _y - i);
    if (board[_x + i][_y - i] != nullptr) break;
  }
  for (int i = 1; i < 8; ++i) {
    // Bottom-right
    if (!isValidMove(_x - i, _y + i)) break;
    moves.emplace_back(_x - i, _y + i);
    if (board[_x - i][_y + i] != nullptr) break;
  }
  for (int i = 1; i < 8; ++i) {
    // Bottom-left
    if (!isValidMove(_x - i, _y - i)) break;
    moves.emplace_back(_x - i, _y - i);
    if (board[_x - i][_y - i] != nullptr) break;
  }

  return moves;
}