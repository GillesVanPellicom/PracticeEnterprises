// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessPiece.h                                                      ║
// ║ Description  : Definition of the abstract chess piece class                      ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef CHESS_SRC_CHESSPIECE_CHESSPIECE_H_
#define CHESS_SRC_CHESSPIECE_CHESSPIECE_H_


#include <vector>
#include "../utils/Type.h"

class Game;

class ChessPiece {
  protected:
    // ╔════════════════════════════════════════╗
    // ║               Variables                ║
    // ╚════════════════════════════════════════╝
    ChessPieceType type;
    ChessPieceColor color;
    Game& instance;
    int x;
    int y;

  public:
    // Board mirror
    // KEEP PUBLIC
    std::array<std::array<std::shared_ptr<ChessPiece>, 8>, 8>& board;


    // ╔════════════════════════════════════════╗
    // ║       Constructors / Destructors       ║
    // ╚════════════════════════════════════════╝

    ChessPiece(ChessPieceType type, ChessPieceColor color, Game& instance, int x, int y);


    // ╔════════════════════════════════════════╗
    // ║           Getters / Setters            ║
    // ╚════════════════════════════════════════╝
    virtual ~ChessPiece();

    [[nodiscard]] Game& getInstance() const;
    virtual std::vector<Coords> getValidMoves() = 0;

    [[nodiscard]] int getX() const;
    void setX(int x);

    [[nodiscard]] int getY() const;
    void setY(int y);

    [[nodiscard]] ChessPieceType getType() const;
    [[nodiscard]] ChessPieceColor getColor() const;

    bool isValidMove(int x, int y);
};


#endif //CHESS_SRC_CHESSPIECE_CHESSPIECE_H_
