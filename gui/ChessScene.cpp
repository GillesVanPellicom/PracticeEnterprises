// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessScene.cpp                                                    ║
// ║ Description  : eeefzeihfeukzfuizefhezihfzofueheeee.                              ║
// ║                efzzefzefezffffffffffffffffffffffffffff                           ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "ChessScene.h"

ChessScene::ChessScene(QObject* parent) : QGraphicsScene(parent) {
  // Measurements in px
  cellWidth = 45;
  boardMargin = 0;

  // Hard-coded defaults in case of config I/O error
  whiteSquareColor = Qt::white;
  blackSquareColor = Qt::black;
}
