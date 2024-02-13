// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Game.h                                                            ║
// ║ Description  : Definitions of the chess game logic                               ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef PRACTICEENTERPRISES_GAME_H_
#define PRACTICEENTERPRISES_GAME_H_

#include "gui/ChessWindow.h"
#include <iostream>

class Game : public ChessWindow {
 Q_OBJECT
 private:
  // GUI event handlers
  // Menu bar handlers
  void onFileQuit() override;
  void onFileNew() override;
  void onFileSave() override;
  void onFileLoad() override;
  void onGameUndo() override;
  void onGameRedo() override;
  void onVisualizeMoves() override;
  void onVisualizeThreatenedEnemy() override;
  void onVisualizeThreatenedPlayer() override;
  // Mouse click handler
  void onClick(int x, int y) override;

};

#endif //PRACTICEENTERPRISES_GAME_H_