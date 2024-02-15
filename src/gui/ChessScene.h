// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessScene.h                                                      ║
// ║ Description  : Definitions of the QGraphicsScene                                 ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef PRACTICEENTERPRISES_GUI_CHESSSCENE_H_
#define PRACTICEENTERPRISES_GUI_CHESSSCENE_H_

// Qt
#include <QGraphicsColorizeEffect>
#include <QMessageBox>
#include <QGuiApplication>
#include <QStyleHints>
#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

// std
#include <iostream>
#include <regex>
#include <utility>
#include <unordered_map>

// local
#include "../utils/Type.h"

// third party
#include "../lib/mini/ini.h"

/**
 * @brief Implementation of the QGraphicsScene\n
 * @throws std::out_of_range If invalid board coördinates are provided
 */
class ChessScene : public QGraphicsScene {
 Q_OBJECT

 public:
  explicit ChessScene(QObject* parent = nullptr);
  void setClickCallback(std::function<void(int, int)> callback);

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 private:
  // Color palette
  // White
  QColor whiteSquareColor;
  QColor whiteSquareSelectedColor;
  QColor blackSquareDangerFriendlyColor;
  QColor blackSquareDangerEnemyColor;
  QColor whiteSquarePossibleColor;
  //Black
  QColor blackSquareColor;
  QColor blackSquareSelectedColor;
  QColor whiteSquareDangerFriendlyColor;
  QColor whiteSquareDangerEnemyColor;
  QColor blackSquarePossibleColor;

  // Global
  bool boardBorders = false;

  // All markings as enum, associated with a coordinate pair (x, y)
  // Implicitly define hash function because std is being screwy.
  std::unordered_map<Coords, BoardMarkingType, Coords::Hash> markings;

  bool isInactiveMarkingUsed = false;
  std::pair<Coords, BoardMarkingType> inactiveMarking;

  std::unordered_map<Coords, std::pair<ChessPieceType, ChessPieceColor>, Coords::Hash> images;



  // Dimensions
  int cellWidth;
  //  int boardWidth  = cellWidth*8;
  int boardMargin;

  // Callback for click event
  std::function<void(int, int)> clickCallback;

  /**
   * Initializes the markings data structure to begin state.
   *
   * Only to be called once in constructor.
   */
  void initializeMarkingsMap();

  void initializeImagesMap();


  /**
   * Reads out basic.ini and populates variables.
   */
  void readColorConfig();

  /**
   * Converts a hex color code as a string to QColor object.
   * @param hex input string
   * @return QColor object
   */
  static QColor hexstrToQColor(std::string& hex);

  /**
   * Draws a specific tile.
   * Calculates color of tile based on location.
   * @param x
   * @param y
   */
  void drawTile(int x, int y);

/**
   *  Draws the entire bord
   *  Utilizes drawTile()
   */
  void drawBoard();

  /**
   * Marks a specified cell as selected
   *
   * Only one cell can be selected at one time.
   * Old cells will automatically be unselected.
   * Selecting an already marked cell will unmark that cell.
   * @param x x-coordinate of the cell
   * @param y y-coordinate of the cell
   */
  void setCellMarkedSelected(int x, int y);

  /**
 * Refreshes all images on the board
 *
 * After one or
 */
  void refreshImages();

  /**
   * Generates svg file link based on type and color enum
   * @param type type of the svg
   * @param color color of the svg
   * @return Relative link to the svg
   */
  static QString getImageFileName(ChessPieceType type, ChessPieceColor color);


 public:
  /**
   * Refreshes the graphics of the entire board.
   *
   * This includes tile color, markings and images.
   */
  void refreshBoard();

  /**
   * Refreshes a single piece svg on the board
   * @param x x coordinate of the svg
   * @param y y coordinate of the svg
   */
  void refreshImage(int x, int y);

  /**
   * Removes all markings of a specified type
   * @param type Type to be specified
   */
  void removeAllMarkingsType(BoardMarkingType type);

  /**
   * Marks a specified cell as a specified type
   *
   * When type is SELECTED:
   * Only one cell can be selected at one time.
   * Old selected cells will be automatically deselected.
   * Selecting an already selected cell will deselect that cell.
   * If the cell to be deselected already had a marking before selection,
   * that marking will be restored.
   *
   * When type is anything else:
   * Override the current type for that cell.
   * Overriding a cell marked as SELECTED will cause the cell to become that type once a new cell is selected.
   * @param x x-coordinate of the cell
   * @param y y-coordinate of the cell
   */
  void setCellMarkedType(int x, int y, BoardMarkingType type);

  /**
   * Sets the image for a certain
   * @param x
   * @param y
   * @param type
   * @param color
   */
  void setCellPieceType(int x, int y, ChessPieceType type, ChessPieceColor color = ChessPieceColor::NO_COLOR);

  /**
   * Clears the entire GUI to starting state.
   */
  void clearGUI();


/**
 * Displays a message box with as options to save, discard, or cancel.
 *
 * Example usage:
 * \code{.cpp}
 * QMessageBox::StandardButton returnValue = saveQuitMsgBox();
 *
 * if (returnValue == QMessageBox::Save) {
 *      // User clicked Save
 *      std::cout << "Save clicked" << std::endl;
 *
 * } else if (returnValue == QMessageBox::Discard) {
 *      // User clicked Discard
 *      std::cout << "Discard clicked" << std::endl;
 *
 * } else if (returnValue == QMessageBox::Cancel) {
 *      // User clicked Cancel
 *      std::cout << "Cancel clicked" << std::endl;
 *
 * } else {
 *      // User closed the message box without clicking any button
 *      std::cout << "Message box closed without selection" << std::endl;
 *
 * }
 * \endcode
 */
  QMessageBox::StandardButton saveQuitMsgBox();

  /**
   * Displays a message box with passed arguments
   * @param title Title of the modal.
   * @param header Header text of the modal.
   * @param subtext Subtext, text under the header of the modal.
   */
  void customMsgBox(const std::string& title, const std::string& header, const std::string& subtext);

  /**
 * Displays a message box with passed arguments and yes/no buttons.
 *
 * Example usage:
 * \code{.cpp}
 * QMessageBox::StandardButton returnValue = yesNoMsgBox();
 *
 * if (returnValue == QMessageBox::Ok) {
 *      // User clicked Ok
 *      std::cout << "Ok" << std::endl;
   *
 * } else if (returnValue == QMessageBox::Cancel) {
 *      // User clicked Cancel
 *      std::cout << "Cancel clicked" << std::endl;
   *
 * } else {
 *      // User closed the message box without clicking any button
 *      std::cout << "Message box closed without selection" << std::endl;
   *
 * }
 * \endcode
 */
  QMessageBox::StandardButton yesNoMsgBox(const std::string& title,
                                          const std::string& header,
                                          const std::string& subtext);

};

#endif //PRACTICEENTERPRISES_GUI_CHESSSCENE_H_