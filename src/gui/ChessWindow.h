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

// Qt
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

// std
#include <iostream>

// local
#include "ChessScene.h"

/**
 * @brief Abstract window containing chess GUI\n
 * @throws std::out_of_range If invalid board coördinates are provided
 */
class ChessWindow : public QMainWindow {
 Q_OBJECT


 public:
  explicit ChessWindow(QWidget* parent = nullptr);

 protected slots:
  // Abstract menu bar event handlers
  virtual void onFileQuit() = 0;
  virtual void onFileNew() = 0;
  virtual void onFileSave() = 0;
  virtual void onFileLoad() = 0;
  virtual void onGameUndo() = 0;
  virtual void onGameRedo() = 0;
  virtual void onVisualizeMoves() = 0;
  virtual void onVisualizeThreatenedEnemy() = 0;
  virtual void onVisualizeThreatenedFriendly() = 0;
 protected:
  // Abstract click event handler
  virtual void onClick(int x, int y) = 0;
  // Cell marking functions
  virtual void markCellAs(int x, int y, BoardMarkingType type) { scene->setCellMarkedType(x, y, type); }
  virtual void removeAllMarkingsType(BoardMarkingType type) { scene->removeAllMarkingsType(type); }
  // Global GUI functions
  virtual void refreshGui() { scene->refreshBoard(); }

  virtual void setChessItem(int x, int y, ChessPieceType type, ChessPieceColor color) {
    scene->setCellPieceType(x, y, type, color);
  }

  virtual QMessageBox::StandardButton saveQuitMsgBox() { return ChessScene::saveQuitMsgBox(); }

  virtual void customMsgBox(const std::string& title,
                            const std::string& header,
                            const std::string& subtext) { ChessScene::customMsgBox(title, header, subtext); }

  virtual QMessageBox::StandardButton yesNoMsgBox(const std::string& title,
                                                  const std::string& header,
                                                  const std::string& subtext) {
    return ChessScene::yesNoMsgBox(title, header, subtext);
  }


  virtual void clearGUI() {
    scene->clearGUI();
    visualizeMovesAction->setChecked(false);
    visualizeThreatenedEnemyAction->setChecked(false);
    visualizeThreatenedPlayerAction->setChecked(false);
  };


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
  QMenu* fileMenu{};
  QMenu* gameMenu{};
  QMenu* visualizeMenu{};

  // Define menu actions
  QAction* fileQuitAction{};
  QAction* fileNewAction{};
  QAction* fileSaveAction{};
  QAction* fileLoadAction{};
  QAction* gameUndoAction{};
  QAction* gameRedoAction{};
  QAction* visualizeMovesAction{};
  QAction* visualizeThreatenedPlayerAction{};
  QAction* visualizeThreatenedEnemyAction{};

  // Define the scene and the view
  QGraphicsView* view;
  ChessScene* scene;
};

#endif //PRACTICEENTERPRISES_GUI_CHESSWINDOW_H_
