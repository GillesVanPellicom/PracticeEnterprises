// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Type.h                                                            ║
// ║ Description  : Definitions of collected types used in codebase                   ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/13                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include <iostream>

#ifndef CHESS_SRC_UTILS_TYPE_H_
#define CHESS_SRC_UTILS_TYPE_H_

namespace ChessType {
enum ChessPieceType {
  KING,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT,
  PAWN
};

enum ChessPieceColor {
  BLACK,
  WHITE
};

enum BoardMarkingType {
  NONE,
  SELECTED,
  THREATENED_ENEMY,
  THREATENED_FRIENDLY,
  POSSIBLE
};

class Coords {
 public:
  Coords(int x, int y);
  // Overload comparison function to enable comparisons
  bool operator==(const Coords& other) const {
    return (x == other.x) && (y == other.y);
  }

  // Hash function for Coords objects
  struct Hash {
    std::size_t operator()(const Coords& coords) const {
      // Combine hash values of x and y to create a unique hash value
      return std::hash<int>()(coords.x) ^ (std::hash<int>()(coords.y) << 1);
    }
  };
  int x = 0;
  int y = 0;
};
}

#endif //CHESS_SRC_UTILS_TYPE_H_