// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Game.h                                                            ║
// ║ Description  : Defenitions of the chess game logic                               ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/12                                                        ║                
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef PRACTICEENTERPRISES__GAME_H_
#define PRACTICEENTERPRISES__GAME_H_

// Forward declaration
class ChessWindow;

#include "gui/ChessWindow.h"
#include <iostream>

class Game : public ChessWindow {
  Q_OBJECT
 private:
  // GUI event handlers
   void onFileQuit() override;
   void onFileNew() override;
   void onFileSave() override;
   void onFileLoad() override;
   void onGameUndo() override;
   void onGameRedo() override;
   void onVisualizeMoves() override;
   void onVisualizeThreatenedEnemy() override;
   void onVisualizeThreatenedPlayer() override;
};

#endif //PRACTICEENTERPRISES__GAME_H_
