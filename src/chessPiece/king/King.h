// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : King.h                                                            ║
// ║ Description  : Definition of the king chess piece                                ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef CHESS_SRC_CHESSPIECE_KING_KING_H_
#define CHESS_SRC_CHESSPIECE_KING_KING_H_

#include "../ChessPiece.h"

class King final : public ChessPiece {
  public:
    Coords castleKS = {-1, -1};
    Coords castleQS = {-1, -1};

    bool isValidCastleKS = false;
    bool isValidCastleQS = false;

    King(ChessPieceType type, ChessPieceColor color, Game& instance, int x, int y);

    std::vector<Coords> getValidMoves() override;
    std::vector<Coords> getValidMovesExclCastling() const;
};


#endif //CHESS_SRC_CHESSPIECE_KING_KING_H_
