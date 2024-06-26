// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessScene.h                                                      ║
// ║ Description  : Definitions of the QGraphicsScene                                 ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef PRACTICEENTERPRISES_GUI_CHESSSCENE_H_
#define PRACTICEENTERPRISES_GUI_CHESSSCENE_H_

#define BOARDSIZE 8

// Qt
#include <QGraphicsColorizeEffect>
#include <QMessageBox>
#include <QPushButton>
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
class ChessScene final : public QGraphicsScene {
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

    // All markings as 2d-array of enumerations
    BoardMarkingType markings[BOARDSIZE][BOARDSIZE]{};

    bool isInactiveMarkingUsed = false;
    std::pair<Coords, BoardMarkingType> inactiveMarking = {{-1, -1}, NONE};

    bool isSelected = false;
    Coords selected = {0, 0};

    // All image locations as 2d-array of pairs of enumerations
    std::pair<ChessPieceType, ChessPieceColor> images[BOARDSIZE][BOARDSIZE];

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
    static QColor hexstrToQColor(const std::string& hex);

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
     *
     * When type is SELECTED:
     * Removal will restore any kind of marking previously present.
     * @param type Type to be specified
     */
    void removeAllMarkingsType(BoardMarkingType type);

    /**
     * Marks a specified cell as a specified type
     *
     * When type is SELECTED:
     * Any markings present will be saved.
     * It will be restored when the SELECTED marking is removed.
     *
     * When type is anything else:
     * Override the current type for that cell.
     * Overriding a cell marked as SELECTED will cause the cell to become that type once a new cell is selected.
     * @param x x-coordinate of the cell
     * @param y y-coordinate of the cell
     * @param type Type of what the cell should be marked as

     */
    void setCellMarkedType(int x, int y, BoardMarkingType type);


    /**
     * Removes SELECTED marking
     * Removal will restore any kind of marking previously present.
     */
    void removeCellMarkedSelected();

    /**
     * Sets the image for a certain cell
     * @param x x-coordinate of the cell
     * @param y y-coordinate of the cell
     * @param type type of the chess piece
     * @param color color of the chess piece
     */
    void setCellPieceType(int x, int y, ChessPieceType type, ChessPieceColor color = NO_COLOR);

    /**
     * Clears the entire GUI to begin-state
     */
    void clearGUI();


    /**
     * Displays a message box with as options to save, discard, or cancel
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
    static QMessageBox::StandardButton saveQuitMsgBox();

    /**
     * Displays a message box with passed arguments
     * @param title Title of the modal.
     * @param header Header text of the modal.
     * @param subtext Subtext, text under the header of the modal.
     */
    static void customMsgBox(const std::string& title, const std::string& header, const std::string& subtext);

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
    static QMessageBox::StandardButton yesNoMsgBox(const std::string& title,
                                                   const std::string& header,
                                                   const std::string& subtext);


    static ChessPieceType promotionBox();
};

#endif //PRACTICEENTERPRISES_GUI_CHESSSCENE_H_
