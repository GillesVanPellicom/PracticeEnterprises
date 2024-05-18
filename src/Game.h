// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : Game.h                                                            ║
// ║ Description  : Definitions of the chess game logic                               ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/12                                                        ║                
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#ifndef PRACTICEENTERPRISES_GAME_H_
#define PRACTICEENTERPRISES_GAME_H_

// std
#include <iostream>
#include <memory>

// local
#include "gui/ChessWindow.h"
#include "chessPiece/ChessPiece.h"
#include "chessPiece/king/King.h"
#include "chessPiece/queen/Queen.h"
#include "chessPiece/rook/Rook.h"
#include "chessPiece/bishop/Bishop.h"
#include "chessPiece/knight/Knight.h"
#include "chessPiece/pawn/Pawn.h"

using ChessPiecePtr = std::shared_ptr<ChessPiece>;

/**
 * @brief Head game logic class.
 *
 * @throws std::out_of_range If invalid board coördinates are provided
 */
class Game final : public ChessWindow {
    Q_OBJECT

  private:
    // ╔════════════════════════════════════════╗
    // ║               Variables                ║
    // ╚════════════════════════════════════════╝

    // Current selected cell variables
    bool isSelected{};
    Coords selected = {-1, -1};

    Coords whiteKingPos = {-1, -1};
    Coords blackKingPos = {-1, -1};

    // Current turn
    ChessPieceColor currentTurn = WHITE;

    // Booleans for menuBar checkboxes
    bool doVisualizeMoves = false;
    bool doVisualizeThreatenedEnemy = false;
    bool doVisualizeThreatenedFriendly = false;

   std::vector<std::array<std::array<std::shared_ptr<ChessPiece>, 8>, 8>> boardHistory;
   unsigned int currentMove = 0;

  public:
    // KEEP PUBLIC

    // Board variable
    std::array<std::array<std::shared_ptr<ChessPiece>, 8>, 8> board;

    // Booleans to keep track of current checks
    bool blackInCheck = false;
    bool whiteInCheck = false;


    // ╔════════════════════════════════════════╗
    // ║       Constructors / Destructors       ║
    // ╚════════════════════════════════════════╝

    Game();


    // ╔════════════════════════════════════════╗
    // ║              Chess Logic               ║
    // ╚════════════════════════════════════════╝

    /**
     * Sets the game to a begin-state.
     * (re)sets the GUI and all game variables.
     * Does not reset GUI preferences such as visualizations.
     */
    void initializeGame();

    /**
     * Generates a ChessPiece of a specified type at a specified location on the board.
     * @param x x-coordinate of location
     * @param y y-coordinate of location
     * @param type Type of the new ChessPiece
     * @param color Color of the new ChessPiece
     * @return false when position invalid or type = EMPTY
     */
    bool generatePiece(int x, int y, ChessPieceType type, ChessPieceColor color);

    /**
     * Move piece from pos_1 to pos_2
     * FIXME: Unfinished function. Write docs
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     */
    void movePiece(int x1, int y1, int x2, int y2);

    /**
     * Sets the currently selected piece.
     * Only used to handle game variables. Doesn't alter GUI.
     * @param x x-coordinate of the select
     * @param y y-coordinate of the select
     * @param _isSelected true if something is selected. Global, not only for these coordinates.
     */
    void setSelected(int x, int y, bool _isSelected);

    /**
     * Shows all valid moves for a specific piece.
     * @param x x-coordinate
     * @param y y-coordinate
     */
    void showVisualizeMoves(int x, int y);

    /**
     * Examine if a specific cell can be attacked
     * @param x x-coordinate of the cell
     * @param y y-coordinate of the cell
     * @param attackerColor Color of the attacking side
     * @return true if that cell can be attacked, else false
     */
    bool isAttackable(int x, int y, ChessPieceColor attackerColor);
    /**
     * Examines the entire board and both sides for checks.
     * Will modify global variables blackInCheck and whiteInCheck after call.
     */
    void check();

    /**
     * Inverts a color. Eg. BLACK => WHITE and WHITE => BLACK
     * @param color Color to be inverted
     * @return
     */
    static ChessPieceColor invertColor(ChessPieceColor color);

    /**
     * Returns the position of the specified king
     * @param color Color of the king to find
     * @return Position of the king
     */
    [[nodiscard]] Coords& findKing(ChessPieceColor color);


    /**
     * Checks if a specific cell can be attacked by a specific color
     * @param x x-coordinate of the cell
     * @param y y-coordinate of the cell
     * @param attackerColor Color of the attacking side
     * @return
     */
    [[nodiscard]] bool canBeAttacked(int x, int y, ChessPieceColor attackerColor) const;

    /**
     * Saves the state of the current board to boardHistory
     * Increments moveCounter by 1;
     */
    void takeBoardSnapshot();


    // ╔════════════════════════════════════════╗
    // ║          Inherited Functions           ║
    // ╚════════════════════════════════════════╝
    // GUI event handlers
    // Menu bar handlers

    /**
     * Triggered on menubar action file/quit.
     * @note Handler function. Not to be called manually.
     */
    void onFileQuit() override;


    /**
     * Triggered on menubar action file/new.
     * @note Handler function. Not to be called manually.
     */
    void onFileNew() override;


    /**
     * Triggered on menubar action file/save.
     * @note Handler function. Not to be called manually.
     */
    void onFileSave() override;


    /**
     * Triggered on menubar action file/load.
     * @note Handler function. Not to be called manually.
     */
    void onFileLoad() override;


    /**
     * Triggered on menubar action game/undo.
     * @note Handler function. Not to be called manually.
     */
    void onGameUndo() override;


    /**
     * Triggered on menubar action game/redo.
     * @note Handler function. Not to be called manually.
     */
    void onGameRedo() override;


    /**
     * Triggered on menubar action visualize/moves.
     * @note Handler function. Not to be called manually.
     */
    void onVisualizeMoves() override;


    /**
     * Triggered on menubar action visualize/enemy.
     * @note Handler function. Not to be called manually.
     */
    void onVisualizeThreatenedEnemy() override;


    /**
     * Triggered on menubar action visualize/friendly.
     * @note Handler function. Not to be called manually.
     */
    void onVisualizeThreatenedFriendly() override;


    // Mouse click handler
    /**
     * Triggered on mouse click. Passes click board coördinates.
     * @note Handler function. Not to be called manually.
     * @param x x-coordinate of the click
     * @param y y-coordinate of the click
     */
    void onClick(int x, int y) override;

    // Cell marking functions
    /**
     * Marks a specified cell as a specified type.
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
     *
     * @param x x-coordinate of the cell
     * @param y y-coordinate of the cell
     * @param type Type of what the cell should be marked as
     */
    void markCellAs(int x, int y, BoardMarkingType type) override;


    /**
     * Removes all markings of a specified type
     *
     * When type is SELECTED:
     * Removal will restore any kind of marking previously present
     * @param type Type to be specified
     */
    void removeAllMarkingsType(BoardMarkingType type) override;


    // Global GUI functions
    /**
     * Refreshes the graphics of the entire board.
     *
     * This includes tile color, markings and images.
     */
    void refreshGui() override;


    /**
     * Clears the entire GUI to begin-state
     */
    void clearGUI() override;


    // Image manipulation functions
    /**
     * Sets the image for a specified cell.
     * @param x x-coordinate of the cell
     * @param y y-coordinate of the cell
     * @param type type of the chess piece
     * @param color color of the chess piece
     */
    void setChessItem(int x, int y, ChessPieceType type, ChessPieceColor color) override;


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
    QMessageBox::StandardButton saveQuitMsgBox() override;


    /**
     * Displays a message box with passed arguments.
     * @param title Title of the modal.
     * @param header Header text of the modal.
     * @param subtext Subtext, text under the header of the modal.
     */
    void customMsgBox(const std::string& title,
                      const std::string& header,
                      const std::string& subtext) override;


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
                                            const std::string& subtext) override;

    ChessPieceType promotionBox() override;
};

#endif //PRACTICEENTERPRISES_GAME_H_
