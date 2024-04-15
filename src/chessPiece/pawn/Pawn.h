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

class Pawn final : public ChessPiece {

  bool isFirstMove = true;
 public:
  Pawn(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y);

  std::vector<Coords> getValidMoves(ChessPiece* board[8][8]) override;
  void setIsFirstMove(bool is_first_move);
  bool getIsFirstMove() const;
};


#endif //CHESS_SRC_CHESSPIECE_PAWN_PAWN_H_
