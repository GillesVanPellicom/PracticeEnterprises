// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Pawn.cpp                                                          ║
// ║ Description  : Implementation of the pawn chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 2.1                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Pawn.h"

#include "../../Game.h"
Pawn::Pawn(const ChessPieceType type,
           const ChessPieceColor color,
           Game& instance,
           const int x,
           const int y) : ChessPiece(type, color, instance, x, y) {
}

std::vector<Coords> Pawn::getValidMoves() {
  auto& board = this->getInstance()->board;
  std::vector<Coords> moves;

  // Reset variables from previous iteration
  if (enPassentIsValid) {
    enPassentIsValid = false;
    enPassentMoves[0] = {-1, -1};
    enPassentMoves[1] = {-1, -1};
  }

  const int _x = this->getX();
  const int _y = this->getY();
  const ChessPieceColor color = this->getColor();

  // Movement goes up for white, down for black.
  const int dy = color == WHITE ? 1 : -1;

  ChessPiece* p;

  // Straight ahead
  if (board[_x][_y + dy] == nullptr) {
    moves.emplace_back(_x, _y + dy);
  }

  // Opening 2-cell
  if ((_y == 1 && color == WHITE) || (_y == 6 && color == BLACK)) {
    moves.emplace_back(_x, _y + dy * 2);
  }

  int i = 0;
  // Left & right
  for (const int dx : {-1, 1}) {
    int nexX = _x + dx;
    if (nexX < 0 || nexX >= 8) {
      // Out of bounds
      continue;
    }
    // Capture
    p = board[nexX][_y + dy];
    // If cell isn't empty and piece is enemy
    if (p != nullptr && p->getColor() != color) {
      moves.emplace_back(nexX, _y + dy);
    }

    // En passant
    p = board[nexX][_y];
    // FIXME: doesn't check if the pawn to be captured has just moved 2 cells
    // If cell isn't empty and piece is enemy and piece is pawn and (piece is on row 3 or 4)
    if (p != nullptr && p->getColor() != color && p->getType() == PAWN && (p->getY() == 3 || p->getY() == 4)) {
      // Conditions met
      // If cell isn't empty and piece is friendly
      if (const ChessPiece* p2 = board[nexX][_y + dy]; p2 != nullptr && p2->getColor() == color) {
        // Friendly piece in way, don't add move
        continue;
      }

      // Valid en passent move
      enPassentIsValid = true;
      Coords move = {nexX, _y + dy};
      enPassentMoves[i++] = move;
      moves.emplace_back(move);
    }
  }

  return moves;
}
