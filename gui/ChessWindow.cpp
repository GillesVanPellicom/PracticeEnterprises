// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessWindow.cpp                                                   ║
// ║ Description  : Definition of the ChessWindow class.                              ║
// ║                Handles the Qt scene, view and menubar.                           ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ Version      : 1.1                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "ChessWindow.h"


ChessWindow::ChessWindow(QWidget *parent) : QMainWindow(parent) {
  scene = new QGraphicsScene();
  view = new QGraphicsView(scene);
  setCentralWidget(view);
  createActions();
  createMenus();
  show();
}


void ChessWindow::createMenus() {
  // Menu
  fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(fileNewAction);
  fileMenu->addAction(fileSaveAction);
  fileMenu->addAction(fileLoadAction);
  fileMenu->addAction(fileQuitAction);

  // Game
  gameMenu = menuBar()->addMenu(tr("&Game"));
  gameMenu->addAction(gameUndoAction);
  gameMenu->addAction(gameRedoAction);

  // View
  visualizeMenu = menuBar()->addMenu(tr("&View"));
  visualizeMenu->addAction(visualizeMovesAction);
  visualizeMenu->addAction(visualizeThreatenedPlayerAction);
  visualizeMenu->addAction(visualizeThreatenedEnemyAction);

}



void ChessWindow::createActions() {
  // *File*
  // New
  fileNewAction = new QAction(tr("&New"), this);
  fileNewAction->setShortcut(QKeySequence::New);
  fileNewAction->setStatusTip(tr("Start a new game"));
  connect(fileNewAction, &QAction::triggered, this, &ChessWindow::onFileNew);

  // Save as
  fileSaveAction = new QAction(tr("&Save"), this);
  fileSaveAction->setShortcut(QKeySequence::SaveAs);
  fileSaveAction->setStatusTip(tr("Save a game to disk"));
  connect(fileSaveAction, &QAction::triggered, this, &ChessWindow::onFileSave);

  // Load
  fileLoadAction = new QAction(tr("&Load"), this);
  fileLoadAction->setShortcut(QKeySequence::Open);
  fileLoadAction->setStatusTip(tr("Load a game from disk"));
  connect(fileLoadAction, &QAction::triggered, this, &ChessWindow::onFileLoad);

  // Quit
  fileQuitAction = new QAction(tr("&Quit"), this);
  fileQuitAction->setShortcut(QKeySequence::Quit);
  fileQuitAction->setStatusTip(tr("Quit the game"));
  connect(fileQuitAction, &QAction::triggered, this, &ChessWindow::onFileQuit);

  // *Game*
  // Undo
  gameUndoAction = new QAction(tr("&Undo"), this);
  gameUndoAction->setShortcut(QKeySequence::Undo);
  gameUndoAction->setStatusTip(tr("Undo last move"));
  connect(gameUndoAction, &QAction::triggered, this, &ChessWindow::onGameUndo);

  // Redo
  gameRedoAction = new QAction(tr("&Redo"), this);
  gameRedoAction->setShortcut(QKeySequence::Redo);
  gameRedoAction->setStatusTip(tr("Redo last move"));
  connect(gameRedoAction, &QAction::triggered, this, &ChessWindow::onGameRedo);

  // *Visualize*
  // Visualize possible moves
  visualizeMovesAction = new QAction(tr("Possible &moves"), this);
  visualizeMovesAction->setStatusTip(tr("Mark all possible moves"));
  visualizeMovesAction->setCheckable(true);
  connect(visualizeMovesAction, &QAction::triggered, this, &ChessWindow::onVisualizeMoves);

  visualizeThreatenedEnemyAction = new QAction(tr("Vulnerable &enemies"), this);
  visualizeThreatenedEnemyAction->setStatusTip(tr("Mark all vulnerable enemies"));
  visualizeThreatenedEnemyAction->setCheckable(true);
  connect(visualizeThreatenedEnemyAction, &QAction::triggered, this, &ChessWindow::onVisualizeThreatenedEnemy);

  visualizeThreatenedPlayerAction = new QAction(tr("Vulnerable &friendlies"), this);
  visualizeThreatenedPlayerAction->setStatusTip(tr("Mark all vulnerable friendlies"));
  visualizeThreatenedPlayerAction->setCheckable(true);
  connect(visualizeThreatenedPlayerAction, &QAction::triggered, this, &ChessWindow::onVisualizeThreatenedPlayer);

}


