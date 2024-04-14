// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Knight.cpp                                                        ║
// ║ Description  : Implementation of the knight chess piece                          ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Knight.h"
Knight::Knight(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y) : ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Knight::getValidMoves(ChessPiece* board[8][8]) {
  std::vector<Coords> moves;

  int _x = this->getX();
  int _y = this->getY();
  ChessPieceColor color = this->getColor();

  // Define helper function to check if a square is valid to move to
  auto isValidMove = [&](int x, int y) {
    // If the move is within bounds and
    // (the cell in question is empty or
    // the color of the not empty cell is not the same as the color of the current piece)
    return x >= 0 && x < 8 && y >= 0 && y < 8 &&
        (board[x][y] == nullptr || board[x][y]->getColor() != color);
  };

  int deltaX[] = {1, 1, 2, 2, -1, -1, -2, -2};
  int deltaY[] = {2, -2, 1, -1, 2, -2, 1, -1};

  for (int i = 0; i < 8; ++i) {
    int newX = _x + deltaX[i];
    int newY = _y + deltaY[i];
    if (isValidMove(newX, newY)) {
      moves.emplace_back(newX, newY);
    }
  }

  return moves;
}
