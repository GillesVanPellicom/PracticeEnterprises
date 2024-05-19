// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessWindow.cpp                                                   ║
// ║ Description  : Definition of the ChessWindow class.                              ║
// ║                Handles the Qt scene, view and menubar.                           ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "ChessWindow.h"


ChessWindow::ChessWindow(QWidget* parent) : QMainWindow(parent) {
  //  scene = new ChessScene(this);
  scene = new ChessScene(this);
  view = new QGraphicsView(scene);
  setCentralWidget(view);

  // Setup menubar
  createActions();
  createMenus();

  // Initialize click callback
  scene->setClickCallback([this](const int x, const int y) {
    onClick(x, y);
  });


  show();
}

void ChessWindow::changeDemoActionText(const std::string& s) const {
  demoEnableDisable->setText(QString::fromStdString(s));
}

void ChessWindow::setDemoScenariosVisibility(const bool isVisible) const {
  demoScenarioMoves->setVisible(isVisible);
  demoScenarioEnPassent->setVisible(isVisible);
  demoScenarioPromotion->setVisible(isVisible);
  demoScenarioCastling->setVisible(isVisible);
  demoScenarioCheckmate->setVisible(isVisible);
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

  // Demo
  demoMenu = menuBar()->addMenu(tr("&Demo"));
  demoMenu->addAction(demoEnableDisable);
  demoMenu->addAction(demoScenarioMoves);
  demoMenu->addAction(demoScenarioEnPassent);
  demoMenu->addAction(demoScenarioPromotion);
  demoMenu->addAction(demoScenarioCastling);
  demoMenu->addAction(demoScenarioCheckmate);
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

  // Visualize threatened enemy positions
  visualizeThreatenedEnemyAction = new QAction(tr("Vulnerable &enemies"), this);
  visualizeThreatenedEnemyAction->setStatusTip(tr("Mark all vulnerable enemies"));
  visualizeThreatenedEnemyAction->setCheckable(true);
  connect(visualizeThreatenedEnemyAction, &QAction::triggered, this, &ChessWindow::onVisualizeThreatenedEnemy);

  // Visualize threatened friendly positions
  visualizeThreatenedPlayerAction = new QAction(tr("Vulnerable &friendlies"), this);
  visualizeThreatenedPlayerAction->setStatusTip(tr("Mark all vulnerable friendlies"));
  visualizeThreatenedPlayerAction->setCheckable(true);
  connect(visualizeThreatenedPlayerAction, &QAction::triggered, this, &ChessWindow::onVisualizeThreatenedFriendly);

  visualizeThreatenedPlayerAction = new QAction(tr("Vulnerable &friendlies"), this);
  visualizeThreatenedPlayerAction->setStatusTip(tr("Mark all vulnerable friendlies"));
  visualizeThreatenedPlayerAction->setCheckable(true);
  connect(visualizeThreatenedPlayerAction, &QAction::triggered, this, &ChessWindow::onVisualizeThreatenedFriendly);


  // *Demo*
  // Demo start/next
  demoEnableDisable = new QAction(tr("Start Demo"), this);
  demoEnableDisable->setStatusTip(tr("Demo start/stop"));
  connect(demoEnableDisable, &QAction::triggered, this, &ChessWindow::onDemoEnableDisable);

  // Demo scenario moves
  demoScenarioMoves = new QAction(tr("Scenario: moves"), this);
  demoScenarioMoves->setStatusTip(tr("Select scenario moves"));
  demoScenarioMoves->setVisible(false);
  connect(demoScenarioMoves, &QAction::triggered, this, &ChessWindow::onDemoScenarioMoves);

  // Demo scenario en passent
  demoScenarioEnPassent = new QAction(tr("Scenario: en passent"), this);
  demoScenarioEnPassent->setStatusTip(tr("Select scenario en passent"));
  demoScenarioEnPassent->setVisible(false);
  connect(demoScenarioEnPassent, &QAction::triggered, this, &ChessWindow::onDemoScenarioEnPassent);

  // Demo scenario promotion
  demoScenarioPromotion = new QAction(tr("Scenario: promotion"), this);
  demoScenarioPromotion->setStatusTip(tr("Select scenario promotion"));
  demoScenarioPromotion->setVisible(false);
  connect(demoScenarioPromotion, &QAction::triggered, this, &ChessWindow::onDemoScenarioPromotion);

  // Demo scenario castling
  demoScenarioCastling = new QAction(tr("Scenario: castling"), this);
  demoScenarioCastling->setStatusTip(tr("Select scenario castling"));
  demoScenarioCastling->setVisible(false);
  connect(demoScenarioCastling, &QAction::triggered, this, &ChessWindow::onDemoScenarioCastling);

  // Demo scenario checkmate
  demoScenarioCheckmate = new QAction(tr("Scenario: checkmate"), this);
  demoScenarioCheckmate->setStatusTip(tr("Select scenario checkmate"));
  demoScenarioCheckmate->setVisible(false);
  connect(demoScenarioCheckmate, &QAction::triggered, this, &ChessWindow::onDemoScenarioCheckmate);
}
