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

#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <regex>

#include "../lib/mini/ini.h"

class Click {
 public:
  qreal x, y;
};

class ChessScene : public QGraphicsScene {
 Q_OBJECT
 public:
  explicit ChessScene(QObject* parent = nullptr);

 protected:

 private:
  QColor whiteSquareColor;
  QColor whiteSquareSelectedColor;
  QColor whiteSquareDangerColor;
  QColor whiteSquarePossibleColor;

  QColor blackSquareColor;
  QColor blackSquareSelectedColor;
  QColor blackSquareDangerColor;
  QColor blackSquarePossibleColor;

  qint8 focusRow, focusCol;

  quint8 rowFromPoint(int y) const { return y / cellWidth; }
  quint8 colFromPoint(int x) const { return x / cellWidth; }

  int cellWidth;
  int boardMargin;


  /**
   * Reads out colorscheme.ini and populates variables.
   */
  void readColorConfig();

  /**
   * Converts a hex color code as a string to QColor object.
   * @param hex input string
   * @return QColor object
   */
  QColor hexstrToQColor(std::string& hex);

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
};

#endif //PRACTICEENTERPRISES_GUI_CHESSSCENE_H_


