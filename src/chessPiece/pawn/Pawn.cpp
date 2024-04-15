// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Pawn.cpp                                                          ║
// ║ Description  : Implementation of the pawn chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 2.1                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Pawn.h"
Pawn::Pawn(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y) :
    ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Pawn::getValidMoves(ChessPiece* board[8][8]) {
  std::vector<Coords> moves;

  int _x = this->getX();
  int _y = this->getY();
  ChessPieceColor color = this->getColor();

  int deltaY = (color == ChessPieceColor::WHITE) ? 1 : -1;

  ChessPiece* p;

  // Straight ahead
  moves.emplace_back(_x, _y + deltaY);

  // Opening extra cell
  if (isFirstMove) {
    moves.emplace_back(_x, _y + deltaY*2);
  }

  // Left & right
  for (int dx : {-1, 1}) {
    // Capture
    p = board[_x + dx][_y + deltaY];
    if (p != nullptr && p->getColor() != color) {
      moves.emplace_back(_x + dx, _y + deltaY);
    }

    // En passant
    p = board[_x + dx][_y];
    // FIXME: doesn't check if the pawn to be captured has just moved 2 cells
    if (p != nullptr && p->getColor() != color && p->getType() == ChessPieceType::PAWN) {
      // Conditions met
      ChessPiece* p2 = board[_x + dx][_y+deltaY];
      if (p2 != nullptr && p2->getColor() == color) {
        // Friendly piece in way, don't add move
        continue;
      } else if (p2 != nullptr && p2->getColor() != color) {
        // Enemy piece in way, double capture
        // FIXME: implement double capture
      }
      // Valid move
      // FIXME: relay this as a capture
      moves.emplace_back(_x + dx, _y + deltaY);
    }
  }

  return moves;
}
void Pawn::setIsFirstMove(bool is_first_move) {
  isFirstMove = is_first_move;
}
