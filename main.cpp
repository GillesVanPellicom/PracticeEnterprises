// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : main.cpp                                                          ║
// ║ Description  : Game entrypoint, main file.                                       ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "gui/ChessWindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  ChessWindow w;
  w.show();

  return QApplication::exec();
}
