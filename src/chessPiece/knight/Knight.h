// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Knight.h                                                          ║
// ║ Description  : Definition of the knight chess piece                              ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef CHESS_SRC_CHESSPIECE_KNIGHT_KNIGHT_H_
#define CHESS_SRC_CHESSPIECE_KNIGHT_KNIGHT_H_

#include "../ChessPiece.h"

class Knight final : public ChessPiece {
  public:
    Knight(ChessPieceType type, ChessPieceColor color, Game& instance, int x, int y);

    std::vector<Coords> getValidMoves() override;
};


#endif //CHESS_SRC_CHESSPIECE_KNIGHT_KNIGHT_H_
