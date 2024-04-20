// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Pawn.h                                                            ║
// ║ Description  : Definition of the pawn   chess piece                              ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef CHESS_SRC_CHESSPIECE_PAWN_PAWN_H_
#define CHESS_SRC_CHESSPIECE_PAWN_PAWN_H_

#include "../ChessPiece.h"
#include <array>

class Pawn final : public ChessPiece {
  bool lastMoveWastwoCellMove = false;
  bool enPassentIsValid{};
  std::array<Coords, 2> enPassentMoves = {{{-1, -1}, {-1, -1}}};

  public:
    Pawn(ChessPieceType type, ChessPieceColor color, Game& instance, int x, int y);
    std::vector<Coords> getValidMoves() override;

    void setLastMoveWasTwoCellMove(bool last_move_wastwo_cell_move) {
      lastMoveWastwoCellMove = last_move_wastwo_cell_move;
    }

    [[nodiscard]] bool getLastMoveWasTwoCellMove() const {
      return lastMoveWastwoCellMove;
    }

    void setEnPassentIsValid(bool en_passent_is_valid) {
      enPassentIsValid = en_passent_is_valid;
    }

  [[nodiscard]] bool getEnPassentIsValid() const {
      return enPassentIsValid;
    }

  [[nodiscard]] const std::array<Coords, 2>& getEnPassentMoves() const {
      return enPassentMoves;
    }
};


#endif //CHESS_SRC_CHESSPIECE_PAWN_PAWN_H_
