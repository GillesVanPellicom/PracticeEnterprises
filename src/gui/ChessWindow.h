// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessWindow.h                                                     ║
// ║ Description  : Definition of the ChessWindow class.                              ║
// ║                Handles the Qt scene, view and menubar.                           ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ Version      : 1.1                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef PRACTICEENTERPRISES_GUI_CHESSWINDOW_H_
#define PRACTICEENTERPRISES_GUI_CHESSWINDOW_H_

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <iostream>

#include "ChessScene.h"

class ChessWindow : public QMainWindow {
 Q_OBJECT

 public:
  explicit ChessWindow(QWidget* parent = nullptr);

  // Abstract menu bar event handlers
 protected:
  virtual void onFileQuit() = 0;
  virtual void onFileNew() = 0;
  virtual void onFileSave() = 0;
  virtual void onFileLoad() = 0;
  virtual void onGameUndo() = 0;
  virtual void onGameRedo() = 0;
  virtual void onVisualizeMoves() = 0;
  virtual void onVisualizeThreatenedEnemy() = 0;
  virtual void onVisualizeThreatenedPlayer() = 0;

  virtual void clicked(int x, int y) = 0;

 private:
  // Menu bar setup
  /**
   * Creates all menus
   *
   * Creates all QMenus to be used in MenuBar()
   */
  void createMenus();
  /**
   * Creates all actions
   *
   * Creates all QAction to be used in QMenu
   */
  void createActions();

  // Define menus
  QMenu* fileMenu;
  QMenu* gameMenu;
  QMenu* visualizeMenu;

  // Define menu actions
  QAction* fileQuitAction;
  QAction* fileNewAction;
  QAction* fileSaveAction;
  QAction* fileLoadAction;
  QAction* gameUndoAction;
  QAction* gameRedoAction;
  QAction* visualizeMovesAction;
  QAction* visualizeThreatenedPlayerAction;
  QAction* visualizeThreatenedEnemyAction;

  // Define the scene and the view
  QGraphicsScene* scene;
  QGraphicsView* view;
};

#endif //PRACTICEENTERPRISES_GUI_CHESSWINDOW_H_
