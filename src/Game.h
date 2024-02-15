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

// std
#include <iostream>

// local
#include "gui/ChessWindow.h"

/**
 * @brief Head game logic class\n
 * @throws std::out_of_range If invalid board coördinates are provided
 */
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
  void onVisualizeThreatenedFriendly() override;
  // Mouse click handler
  void onClick(int x, int y) override;
  // Cell marking functions
  void markCellAs(int x, int y, BoardMarkingType type) override;
  void removeAllMarkingsType(BoardMarkingType type) override;

  void refreshGui() override;

  void setChessItem(int x, int y, ChessPieceType type, ChessPieceColor color) override;

  void clearGUI() override;


 public:
  Game();
 private:

  // Booleans for menuBar checkboxes
  bool doVisualizeMoves = false;
  bool doVisualizeThreatenedEnemy = false;
  bool doVisualizeThreatenedFriendly = false;

};

#endif //PRACTICEENTERPRISES_GAME_H_
