// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Queen.cpp                                                         ║
// ║ Description  : Implementation of the queen chess piece                           ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Queen.h"
Queen::Queen(const ChessPieceType type,
             const ChessPieceColor color,
             Game* instance,
             const int x,
             const int y) : ChessPiece(type, color, instance, x, y) {
}

std::vector<Coords> Queen::getValidMoves(ChessPiece* board[8][8]) {
  std::vector<Coords> moves;

  const int _x = this->getX();
  const int _y = this->getY();
  const ChessPieceColor color = this->getColor();

  // Define helper function to check if a square is valid to move to
  auto isValidMove = [&](const int x, const int y) {
    // If the move is within bounds and
    // (the cell in question is empty or
    // the color of the not empty cell is not the same as the color of the current piece)
    return x >= 0 && x < 8 && y >= 0 && y < 8 &&
        (board[x][y] == nullptr || board[x][y]->getColor() != color);
  };

  // Check diagonal moves (top-right, top-left, bottom-right, bottom-left)
  // Top-right
  for (int i = 1; i < 8; ++i) {
    if (!isValidMove(_x + i, _y + i)) break;
    moves.emplace_back(_x + i, _y + i);
    if (board[_x + i][_y + i] != nullptr) break;
  }

  // Top-left
  for (int i = 1; i < 8; ++i) {
    if (!isValidMove(_x + i, _y - i)) break;
    moves.emplace_back(_x + i, _y - i);
    if (board[_x + i][_y - i] != nullptr) break;
  }

  // Bottom-right
  for (int i = 1; i < 8; ++i) {
    if (!isValidMove(_x - i, _y + i)) break;
    moves.emplace_back(_x - i, _y + i);
    if (board[_x - i][_y + i] != nullptr) break;
  }

  // Bottom-left
  for (int i = 1; i < 8; ++i) {
    if (!isValidMove(_x - i, _y - i)) break;
    moves.emplace_back(_x - i, _y - i);
    if (board[_x - i][_y - i] != nullptr) break;
  }

  // Check horizontal moves (left, right)
  // Right
  for (int x = _x + 1; x < 8; ++x) {
    if (!isValidMove(x, _y)) break;
    moves.emplace_back(x, _y);
    if (board[x][_y] != nullptr) break;
  }

  // Left
  for (int x = _x - 1; x >= 0; --x) {
    if (!isValidMove(x, _y)) break;
    moves.emplace_back(x, _y);
    if (board[x][_y] != nullptr) break;
  }

  // Check vertical moves (up, down)
  // Up
  for (int y = _y + 1; y < 8; ++y) {
    if (!isValidMove(_x, y)) break;
    moves.emplace_back(_x, y);
    if (board[_x][y] != nullptr) break;
  }

  // Down
  for (int y = _y - 1; y >= 0; --y) {
    if (!isValidMove(_x, y)) break;
    moves.emplace_back(_x, y);
    if (board[_x][y] != nullptr) break;
  }

  return moves;
}
