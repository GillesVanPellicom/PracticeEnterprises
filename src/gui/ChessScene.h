// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessScene.h                                                      ║
// ║ Description  : Definitions of the QGraphicsScene                                 ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef PRACTICEENTERPRISES_GUI_CHESSSCENE_H_
#define PRACTICEENTERPRISES_GUI_CHESSSCENE_H_

// Qt
#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

// std
#include <iostream>
#include <regex>
#include <utility>
#include <unordered_map>

// local
#include "../utils/Type.h"

// third party
#include "../lib/mini/ini.h"

class ChessScene : public QGraphicsScene {
 Q_OBJECT

 public:
  explicit ChessScene(QObject* parent = nullptr);
  void setClickCallback(std::function<void(int, int)> callback);

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 private:
  // Color palette
  // White
  QColor whiteSquareColor;
  QColor whiteSquareSelectedColor;
  QColor blackSquareDangerFriendlyColor;
  QColor blackSquareDangerEnemyColor;
  QColor whiteSquarePossibleColor;
  //Black
  QColor blackSquareColor;
  QColor blackSquareSelectedColor;
  QColor whiteSquareDangerFriendlyColor;
  QColor whiteSquareDangerEnemyColor;
  QColor blackSquarePossibleColor;

  // Currently focussed cell
  int focusX, focusY = -1;

  // All markings as enum, associated with a coordinate pair (x, y)
  // Implicitly define hash function because std is being screwy.
  std::unordered_map<ChessType::Coords, ChessType::BoardMarkingType, ChessType::Coords::Hash> markings;

  bool isInactiveMarkingUsed = false;
  std::pair<ChessType::Coords, ChessType::BoardMarkingType> inactiveMarking;



  // Dimensions
  int cellWidth;
  int boardMargin;

  // Callback for click event
  std::function<void(int, int)> clickCallback;

  /**
   * Initializes the markings datastructure to begin state.
   *
   * Only to be called once in constructor.
   */
  void initializeMarkingsMap();

  /**
   * Reads out colorscheme.ini and populates variables.
   */
  void readColorConfig();

  /**
   * Converts a hex color code as a string to QColor object.
   * @param hex input string
   * @return QColor object
   */
  static QColor hexstrToQColor(std::string& hex);

  /**
   * Draws a specific tile.
   * Calculates color of tile based on location.
   * @param x
   * @param y
   */
  void drawTile(int x, int y);

/**
   *  Draws the entire bord
   *  Utilizes drawTile()
   */
  void drawBoard();

  /**
   * Marks a specified cell as selected
   *
   * Only one cell can be selected at one time.
   * Old cells will automatically be unselected.
   * Selecting an already marked cell will unmark that cell.
   * @param x x-coordinate of the cell
   * @param y y-coordinate of the cell
   */
  void setCellMarkedSelected(int x, int y);

 public:
  /**
   * Refreshes the graphics of the entire board.
   *
   * This includes tile color, markings, images.
   */
  void refreshBoard();



  /**
   * Removes all markings of a specified type
   * @param type Type to be specified
   */
  void removeAllMarkingsType(ChessType::BoardMarkingType type);

  /**
   * Marks a specified cell as a specified type
   *
   * When type is SELECTED:
   * Only one cell can be selected at one time.
   * Old selected cells will be automatically deselected.
   * Selecting an already selected cell will deselect that cell.
   * If the cell to be deselected already had a marking before selection,
   * that marking will be restored.
   *
   * When type is anything else:
   * Override the current type for that cell.
   * Overriding a cell marked as SELECTED is not allowed,
   * but this behavior is not enforced.
   * However, doing so will cause visual bugs.
   * @param x x-coordinate of the cell
   * @param y y-coordinate of the cell
   */
  void setCellMarkedType(int x, int y, ChessType::BoardMarkingType type);

};

#endif //PRACTICEENTERPRISES_GUI_CHESSSCENE_H_


