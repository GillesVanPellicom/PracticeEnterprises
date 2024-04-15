// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : King.cpp                                                          ║
// ║ Description  : Implementation of the king chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "King.h"
King::King(const ChessPieceType type, const ChessPieceColor color, Game* instance, const int x, const int y) :
ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> King::getValidMoves(ChessPiece* board[8][8]) {
  std::vector<Coords> moves;

  const int _x = this->getX();
  const int _y = this->getY();

  // Pseudo-valid
  constexpr int deltaX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  constexpr int deltaY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int i = 0; i < 8; ++i) {
    const int newX = _x + deltaX[i];
    const int newY = _y + deltaY[i];
    if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
      // If move cell contains a piece and that piece is the same color as the current piece
      if (board[newX][newY] != nullptr && board[newX][newY]->getColor() == this->getColor()) {
        // Friendly
        continue;
      }
      moves.emplace_back(newX, newY);
    }
  }

  return moves;
}
