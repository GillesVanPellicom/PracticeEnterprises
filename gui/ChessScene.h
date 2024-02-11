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


class ChessScene : public QGraphicsScene {
 public:
  explicit ChessScene(QObject* parent);
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
};

#endif //PRACTICEENTERPRISES_GUI_CHESSSCENE_H_
