// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessPiece.h                                                      ║
// ║ Description  : Definition of the abstract chess piece class                      ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef CHESS_SRC_CHESSPIECE_CHESSPIECE_H_
#define CHESS_SRC_CHESSPIECE_CHESSPIECE_H_


#include <vector>
#include "../utils/Type.h"

class Game;

class ChessPiece {
  ChessPieceType type;
  ChessPieceColor color;
  Game* instance;
  int x;
  int y;


 public:
  Game* getInstance() const;
  virtual std::vector<Coords> getValidMoves(ChessPiece* board[8][8]) = 0;
  int getY() const;
  void setY(int y);
  int getX() const;
  void setX(int x);
  ChessPieceType getType() const;
  ChessPieceColor getColor() const;
  ChessPiece(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y);
  virtual ~ChessPiece();

};


#endif //CHESS_SRC_CHESSPIECE_CHESSPIECE_H_
