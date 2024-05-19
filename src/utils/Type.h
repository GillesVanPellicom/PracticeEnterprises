// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Type.h                                                            ║
// ║ Description  : Definitions of collected types used in codebase                   ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/13                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include <iostream>

#ifndef CHESS_SRC_UTILS_TYPE_H_
#define CHESS_SRC_UTILS_TYPE_H_

/**
 * @brief Collection of datatypes used in the project
 */

enum ChessPieceType {
  KING,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT,
  PAWN,
  EMPTY
};

enum ChessPieceColor {
  BLACK,
  WHITE,
  NO_COLOR
};

enum BoardMarkingType {
  NONE,
  SELECTED,
  THREATENED_ENEMY,
  THREATENED_FRIENDLY,
  POSSIBLE
};

enum DemoScenarioType {
  NO_DEMO,
  CHOOSE_SCENARIO,
  MOVES,
  EN_PASSENT,
  PROMOTION,
  CASTLING,
  CHECKMATE
};

/**
 * @brief Coordinate datatype\n
 * @note Contains a custom hash function for use in hashed datatypes.
 * @note Overloads the comparison operator to facilitate comparisons.
 * @throws std::out_of_range If invalid board coördinates are provided
 */
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


#endif //CHESS_SRC_UTILS_TYPE_H_
