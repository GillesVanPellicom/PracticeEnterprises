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
  cellWidth = 50;
  boardMargin = 0;

  // Hard-coded defaults in case of config I/O error
  whiteSquareColor = Qt::white;
  blackSquareColor = Qt::black;
  drawBoard();
}

void ChessScene::drawTile(int x, int y) {
  auto* rect = new QGraphicsRectItem(y * cellWidth, x * cellWidth, cellWidth, cellWidth);

  if (x % 2 == y % 2) {
    rect->setBrush(QBrush(whiteSquareColor, Qt::SolidPattern));

  } else {
    rect->setBrush(QBrush(blackSquareColor, Qt::SolidPattern));

  }

  rect->setCacheMode(QGraphicsItem::NoCache);
  addItem(rect);
}

void ChessScene::drawBoard() {
  for (int x = 0; x < 8; ++x) {
    for (int y = 0; y < 8; ++y) {
      drawTile(x, y);
    }
  }
}


