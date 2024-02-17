// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessMenu.h                                                      ║
// ║ Description  : Lorem ipsum dolor sit amet                                        ║
// ║                Lorem ipsum dolor sit amet                                        ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/17                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef CHESS_SRC_GUI_CHESSMENU_H_
#define CHESS_SRC_GUI_CHESSMENU_H_


#include <QGraphicsScene>
#include <QtCore>


class ChessMenu : public QGraphicsScene {
  Q_OBJECT

 public:
  explicit ChessMenu(QObject* parent = nullptr);
};


#endif //CHESS_SRC_GUI_CHESSMENU_H_
