// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Knight.cpp                                                        ║
// ║ Description  : Implementation of the knight chess piece                          ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/04/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "Knight.h"
Knight::Knight(ChessPieceType type, ChessPieceColor color, Game* instance, int x, int y) : ChessPiece(type, color, instance, x, y) {}

std::vector<Coords> Knight::getValidMoves() {
  return std::vector<Coords>();
}
