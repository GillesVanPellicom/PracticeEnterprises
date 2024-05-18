// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Bishop.cpp                                                        ║
// ║ Description  : Implementation of the bishop chess piece                          ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Bishop.h"
Bishop::Bishop(const ChessPieceType type,
               const ChessPieceColor color,
               Game& instance,
               const int x,
               const int y) : ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Bishop::getValidMoves() {
  std::vector<Coords> moves;

  // Check diagonal moves (top-right, top-left, bottom-right, bottom-left)
  for (const int dx : {-1, 1}) {
    for (const int dy : {-1, 1}) {
      for (int i = 1; i < 8; ++i) {
        int newX = x + i * dx,
            newY = y + i * dy;

        if (!isValidMove(newX, newY)) break;
        moves.emplace_back(newX, newY);
        if (board[newX][newY] != nullptr) break;
      }
    }
  }

  return moves;
}
