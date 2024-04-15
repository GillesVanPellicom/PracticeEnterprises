// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Queen.h                                                           ║
// ║ Description  : Definition of the queen chess piece                               ║
// ║                Lorem ipsum dolor sit amet                                        ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef CHESS_SRC_CHESSPIECE_QUEEN_QUEEN_H_
#define CHESS_SRC_CHESSPIECE_QUEEN_QUEEN_H_

#include "../ChessPiece.h"

class Queen final : public ChessPiece {
 public:
  Queen(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y);

  std::vector<Coords> getValidMoves(ChessPiece* board[8][8]) override;

};


#endif //CHESS_SRC_CHESSPIECE_QUEEN_QUEEN_H_
