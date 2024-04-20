// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Rook.h                                                            ║
// ║ Description  : Definition of the rook chess piece                                ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef CHESS_SRC_CHESSPIECE_ROOK_ROOK_H_
#define CHESS_SRC_CHESSPIECE_ROOK_ROOK_H_

#include "../ChessPiece.h"


class Rook final : public ChessPiece {
  public:
    Rook(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y);

    std::vector<Coords> getValidMoves() override;
};


#endif //CHESS_SRC_CHESSPIECE_ROOK_ROOK_H_
