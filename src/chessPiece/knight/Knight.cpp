// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Knight.cpp                                                        ║
// ║ Description  : Implementation of the knight chess piece                          ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Knight.h"
Knight::Knight(const ChessPieceType type,
               const ChessPieceColor color,
               Game& instance,
               const int x,
               const int y) : ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Knight::getValidMoves() {
  std::vector<Coords> moves;

  constexpr int dx[] = {1, 1, 2, 2, -1, -1, -2, -2},
                dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

  for (int i = 0; i < 8; ++i) {
    if (const int newX = this->x + dx[i], newY = this->y + dy[i];
      isValidMove(newX, newY)) {
      moves.emplace_back(newX, newY);
    }
  }

  return moves;
}
