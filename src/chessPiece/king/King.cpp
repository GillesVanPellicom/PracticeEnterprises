// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : King.cpp                                                          ║
// ║ Description  : Implementation of the king chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "King.h"
King::King(const ChessPieceType type,
           const ChessPieceColor color,
           Game& instance,
           const int x,
           const int y) : ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> King::getValidMoves() {
  std::vector<Coords> moves;

  constexpr int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
                dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int i = 0; i < 8; ++i) {
    if (const int newX = x + dx[i], newY = y + dy[i];
      isValidMove(newX, newY)) {
      moves.emplace_back(newX, newY);
    }
  }

  return moves;
}
