// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessWindow.h                                                     ║
// ║ Description  : Definition of the ChessWindow class.                              ║
// ║                Handles the Qt scene, view and menubar.                           ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <iostream>

#ifndef PRACTICEENTERPRISES_GUI_CHESSWINDOW_H_
#define PRACTICEENTERPRISES_GUI_CHESSWINDOW_H_

class ChessWindow : public QMainWindow {
 Q_OBJECT

 public:
  explicit ChessWindow(QWidget* parent = nullptr);

 // Menu bar event handlers
 private slots:
  void onFileQuit();
  void onFileNew();
  void onFileSave();
  void onFileLoad();
  void onGameUndo();
  void onGameRedo();
  void onVisualizeMoves();
  void onVisualizeThreatenedEnemy();
  void onVisualizeThreatenedPlayer();

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
