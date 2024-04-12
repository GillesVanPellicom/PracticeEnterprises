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

class Pawn : public ChessPiece {
 public:
  Pawn(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y);

  std::vector<Coords> getValidMoves() override;

};


#endif //CHESS_SRC_CHESSPIECE_PAWN_PAWN_H_
