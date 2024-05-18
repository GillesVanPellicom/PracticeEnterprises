// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Pawn.cpp                                                          ║
// ║ Description  : Implementation of the pawn chess piece                            ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
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
  std::vector<Coords> moves;

  // Reset variables from previous iteration
  if (enPassentIsValid) {
    enPassentIsValid = false;
    enPassentMoves[0] = {-1, -1};
    enPassentMoves[1] = {-1, -1};
  }

  const ChessPieceColor color = getColor();

  // Movement goes up for white, down for black.
  const int dy = color == WHITE ? 1 : -1;


  // Straight ahead
  if (board[x][y + dy] == nullptr) {
    moves.emplace_back(x, y + dy);

    // Opening 2-cell
    // Only if pawn hasn't moved yet, the first cell is possible and the second cell is possible
    if (!hasMoved && board[x][y + dy * 2] == nullptr) {
      moves.emplace_back(x, y + dy * 2);
    }
  }



  int i = 0;
  // Left & right
  for (const int dx : {-1, 1}) {
    int newX = x + dx;

    if (newX < 0 || newX >= 8) {
      // Out of bounds
      continue;
    }
    // Capture

    // If cell isn't empty and piece is enemy
    if (ChessPiecePtr& p = board[newX][y + dy]; p != nullptr && p->getColor() != color) {
      moves.emplace_back(newX, y + dy);
    }

    // En passant

    // FIXME: doesn't check if the pawn to be captured has just moved 2 cells
    // If cell isn't empty and piece is enemy and piece is pawn and (piece is on row 3 or 4)
    if (ChessPiecePtr& p = board[newX][y]; p != nullptr && p->getColor() != color
      && p->getType() == PAWN && (p->getY() == 3 || p->getY() == 4)) {
      // Conditions met
      // If cell isn't empty and piece is friendly
      if (const ChessPiecePtr& p2 = board[newX][y + dy]; p2 != nullptr && p2->getColor() == color) {
        // Friendly piece in way, don't add move
        continue;
      }

      // Valid en passent move
      enPassentIsValid = true;
      Coords move = {newX, y + dy};
      enPassentMoves[i++] = move;
      moves.emplace_back(move);
    }
  }

  return moves;
}
