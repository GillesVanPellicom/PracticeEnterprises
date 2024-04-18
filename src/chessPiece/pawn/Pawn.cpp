// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Pawn.cpp                                                          ║
// ║ Description  : Implementation of the pawn chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 2.1                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Pawn.h"
Pawn::Pawn(const ChessPieceType type,
           const ChessPieceColor color,
           Game* instance,
           const int x,
           const int y) : ChessPiece(type, color, instance, x, y) {
}

std::vector<Coords> Pawn::getValidMoves(ChessPiece* board[8][8]) {
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
  moves.emplace_back(_x, _y + dy);

  // Opening 2-cell
  if ((_y == 1 && color == WHITE) || (_y == 6 && color == BLACK)) {
    moves.emplace_back(_x, _y + dy * 2);
  }

  int i = 0;
  // Left & right
  for (const int dx : {-1, 1}) {
    if (_x + dx < 0 || _x + dx >= 8) {
      // Out of bounds
      continue;
    }
    // Capture
    p = board[_x + dx][_y + dy];
    if (p != nullptr && p->getColor() != color) {
      moves.emplace_back(_x + dx, _y + dy);
    }

    // En passant
    p = board[_x + dx][_y];
    // FIXME: doesn't check if the pawn to be captured has just moved 2 cells
    if (p != nullptr && p->getColor() != color && p->getType() == PAWN) {
      // Conditions met
      ChessPiece* p2 = board[_x + dx][_y + dy];
      if (p2 != nullptr && p2->getColor() == color) {
        // Friendly piece in way, don't add move
        continue;
      }
      // if (p2 != nullptr && p2->getColor() != color) {
      //   // Enemy piece in way, double capture
      //   // FIXME: implement double capture
      // }
      // Valid move
      // FIXME: relay this as a capture
      enPassentIsValid = true;
      enPassentMoves[i++] = {_x + dx, _y + dy};

      moves.emplace_back(_x + dx, _y + dy);
    }
  }

  return moves;
}
