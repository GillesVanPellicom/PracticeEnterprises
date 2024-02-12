// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessScene.h                                                      ║
// ║ Description  : eeefzeihfeukzfuizefhezihfzofueheeee.                              ║
// ║                efzzefzefezffffffffffffffffffffffffffff                           ║
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

class ChessScene : public QGraphicsScene {
 Q_OBJECT
 public:
  explicit ChessScene(QObject* parent = nullptr);
 private:
  QColor whiteSquareColor;
  QColor whiteSquareSelectedColor;
  QColor whiteSquareDangerColor;
  QColor whiteSquarePossibleColor;

  QColor blackSquareColor;
  QColor blackSquareSelectedColor;
  QColor blackSquareDangerColor;
  QColor blackSquarePossibleColor;

  int cellWidth;
  int boardMargin;

  void drawTile(int x, int y);
  void drawBoard();
};

#endif //PRACTICEENTERPRISES_GUI_CHESSSCENE_H_
