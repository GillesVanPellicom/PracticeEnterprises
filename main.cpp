// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : main.cpp                                                          ║
// ║ Description  : Game entrypoint, main file.                                       ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include <QApplication>
#include "Game.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  Game g;

  return QApplication::exec();
}
