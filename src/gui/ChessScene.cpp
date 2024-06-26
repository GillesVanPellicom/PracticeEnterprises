// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessScene.cpp                                                    ║
// ║ Description  : Implementation of the game rendering                              ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝


#include "ChessScene.h"

ChessScene::ChessScene(QObject* parent)
  : QGraphicsScene(parent) {
  // Measurements in px
  cellWidth = 45;
  boardMargin = 0;

  // Read basic.ini and populate variables
  readColorConfig();

  // Initialize datatype for board markings.
  initializeMarkingsMap();

  // Initialize datatype for board pieces.
  initializeImagesMap();

  // This should be the last function
  drawBoard();
}

void ChessScene::drawTile(const int x, const int y) {
  auto* rect = new QGraphicsRectItem(y * cellWidth,
                                     (7 - x) * cellWidth,
                                     cellWidth,
                                     cellWidth);

  if (!boardBorders) {
    rect->setPen(Qt::NoPen);
  }

  if (x % 2 == y % 2) {
    // Qt and chess-actual coordinates are flipped.
    switch (markings[y][x]) {
      case NONE: {
        rect->setBrush(QBrush(whiteSquareColor, Qt::SolidPattern));
        break;
      }

      case SELECTED: {
        rect->setBrush(QBrush(whiteSquareSelectedColor, Qt::SolidPattern));
        break;
      }

      case POSSIBLE: {
        rect->setBrush(QBrush(whiteSquarePossibleColor, Qt::SolidPattern));

        break;
      }

      case THREATENED_FRIENDLY: {
        rect->setBrush(QBrush(whiteSquareDangerFriendlyColor, Qt::SolidPattern));

        break;
      }
      case THREATENED_ENEMY: {
        rect->setBrush(QBrush(whiteSquareDangerEnemyColor, Qt::SolidPattern));

        break;
      }
    }
  } else {
    // Qt and chess-actual coordinates are flipped.
    switch (markings[y][x]) {
      case NONE: {
        rect->setBrush(QBrush(blackSquareColor, Qt::SolidPattern));
        break;
      }

      case SELECTED: {
        rect->setBrush(QBrush(blackSquareSelectedColor, Qt::SolidPattern));
        break;
      }

      case POSSIBLE: {
        rect->setBrush(QBrush(blackSquarePossibleColor, Qt::SolidPattern));

        break;
      }

      case THREATENED_FRIENDLY: {
        rect->setBrush(QBrush(blackSquareDangerFriendlyColor, Qt::SolidPattern));

        break;
      }
      case THREATENED_ENEMY: {
        rect->setBrush(QBrush(blackSquareDangerEnemyColor, Qt::SolidPattern));

        break;
      }
    }
  }

  rect->setCacheMode(QGraphicsItem::NoCache);
  addItem(rect);
}


void ChessScene::drawBoard() {
  for (int x = 0; x < BOARDSIZE; ++x) {
    for (int y = 0; y < BOARDSIZE; ++y) {
      drawTile(x, y);
    }
  }
}


void ChessScene::readColorConfig() {
  try {
    // FIXME: hardcoded link
    const mINI::INIFile file("../config/colorschemes/chess.com.ini");
    mINI::INIStructure conf;
    file.read(conf);

    whiteSquareColor = hexstrToQColor(conf["white"]["squareColor"]);
    whiteSquareSelectedColor = hexstrToQColor(conf["white"]["squareSelectedColor"]);
    whiteSquareDangerFriendlyColor = hexstrToQColor(conf["white"]["squareDangerFriendlyColor"]);
    whiteSquareDangerEnemyColor = hexstrToQColor(conf["white"]["squareDangerEnemyColor"]);
    whiteSquarePossibleColor = hexstrToQColor(conf["white"]["squarePossibleColor"]);

    blackSquareColor = hexstrToQColor(conf["black"]["squareColor"]);
    blackSquareSelectedColor = hexstrToQColor(conf["black"]["squareSelectedColor"]);
    blackSquareDangerFriendlyColor = hexstrToQColor(conf["black"]["squareDangerFriendlyColor"]);
    blackSquareDangerEnemyColor = hexstrToQColor(conf["black"]["squareDangerEnemyColor"]);
    blackSquarePossibleColor = hexstrToQColor(conf["black"]["squarePossibleColor"]);

    if (conf["global"]["borders"] == "true") {
      boardBorders = true;
    }
  } catch (const std::exception& e) {
    std::cerr << "I/O error: basic.ini was inaccessible. Continuing with default values..." << std::endl;
  }
}


QColor ChessScene::hexstrToQColor(const std::string& hex) {
  // regex to validate string.
  if (!std::regex_match(hex, std::regex("#?([a-fA-F0-9]){6}"))) {
    // If string isn't hex
    std::cerr << "The provided string \"" << hex
        << "\" is not a valid hex color code. Defaulting to #000000 for this value..." << std::endl;
    return {0, 0, 0};
  }

  // Valid hex code. Process into RGB

  // Remove hashtag
  std::string hexValue = hex;
  if (hexValue[0] == '#') {
    hexValue = hexValue.substr(1);
  }

  // Convert hexadecimal string to integer
  unsigned int value;
  std::stringstream ss;
  ss << std::hex << hexValue;
  ss >> value;

  // Extract individual color components
  // Shift and mask
  const unsigned int r = (value >> 16) & 0xFF;
  const unsigned int g = (value >> 8) & 0xFF;
  const unsigned int b = value & 0xFF;

  // Avoid implementation defined annoyances
  return {static_cast<int>(r), static_cast<int>(g), static_cast<int>(b)};
}


void ChessScene::initializeMarkingsMap() {
  for (auto& markingRow : markings) {
    for (auto& marking : markingRow) {
      marking = NONE;
    }
  }
}


void ChessScene::initializeImagesMap() {
  for (auto& imageRow : images) {
    for (auto& image : imageRow) {
      image = {EMPTY, NO_COLOR};
    }
  }
}


void ChessScene::setClickCallback(std::function<void(int, int)> callback) {
  clickCallback = std::move(callback);
}


void ChessScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  QGraphicsScene::mousePressEvent(event);
  // If button pressed is left button
  if (event->button() == Qt::LeftButton) {
    // Transform Qt scene coordinates to board coordinates [0; 7]
    const int x = static_cast<int>(std::ceil(event->scenePos().x() / cellWidth)) - 1;
    // flip y coordinate to conform to chess standards
    const int y = (9 - static_cast<int>(std::ceil(event->scenePos().y() / cellWidth))) - 1;

    // If callback is valid
    if (clickCallback) {
      // Callback to ChessWindow
      clickCallback(x, y);
    }
  }
}


void ChessScene::setCellMarkedSelected(int x, int y) {
  if (!(selected.x == x && selected.y == y)) {
    // Check if this operation will override a marking of lower precedence.
    // Remember the marking to be overwritten
      inactiveMarking = {{x, y}, markings[x][y]};


    // Mark cell as selected.
    selected = {x, y};
    markings[x][y] = SELECTED;
  }
}


void ChessScene::removeCellMarkedSelected() {

  const Coords c = inactiveMarking.first;
  markings[c.x][c.y] = inactiveMarking.second;
  isInactiveMarkingUsed = false;
  inactiveMarking = {{-1, -1}, NONE};
  selected = {-1, -1};
}


void ChessScene::removeAllMarkingsType(const BoardMarkingType type) {
  if (type == SELECTED) {
    removeCellMarkedSelected();
  }

  for (auto& markingRow : markings) {
    for (auto& marking : markingRow) {
      if (marking == type) {
        marking = NONE;
      }
    }
  }

  // Also remove inactive marking
  if (isInactiveMarkingUsed && inactiveMarking.second == type) {
    isInactiveMarkingUsed = false;
  }
}


void ChessScene::setCellMarkedType(const int x, const int y, const BoardMarkingType type) {
  // Enforce range
  if (x < 0 || x > 7 || y < 0 || y > 7) {
    throw std::out_of_range(
      "Fatal: setCellMarkedType(): x, y must be [0; 7]. Actual: (" +
      std::to_string(x) + ", " + std::to_string(y) + ")");
  }

  // If type is SELECTED, handle in specific function
  if (type == SELECTED) {
    setCellMarkedSelected(x, y);
  } else {
    // If not, add type to markings.
    // SELECTED already marked has priority.
    if (markings[x][y] != SELECTED) {
      markings[x][y] = type;
    } else {
      isInactiveMarkingUsed = true;
      inactiveMarking = {{x, y}, type};
    }
  }
}


void ChessScene::setCellPieceType(const int x, const int y, const ChessPieceType type, const ChessPieceColor color) {
  images[x][y] = {type, color};
}


void ChessScene::refreshImage(const int x, const int y) {
  if (images[x][y].first == EMPTY ||
    images[x][y].second == NO_COLOR) {
    return;
  }

  QString filename = getImageFileName(images[x][y].first, images[x][y].second);
  if (filename.isEmpty())
    return;

  const quint32 xQt = cellWidth * (x);
  const quint32 yQt = cellWidth * (7 - y);

  auto* item = new QGraphicsPixmapItem(QPixmap(filename));

  item->setPos(xQt, yQt);

  addItem(item);
}

void ChessScene::refreshBoard() {
  qDeleteAll(items());
  drawBoard();
  refreshImages();
}

void ChessScene::refreshImages() {
  for (int x = 0; x < BOARDSIZE; ++x) {
    for (int y = 0; y < BOARDSIZE; ++y) {
      refreshImage(x, y);
    }
  }
}

QString ChessScene::getImageFileName(const ChessPieceType type, const ChessPieceColor color) {
  // Start
  QString link = "../resources/";

  // Add color
  switch (color) {
    case BLACK: {
      link += "black";
      break;
    }
    case WHITE: {
      link += "white";

      break;
    }
    case ::NO_COLOR: {
      return "-1";
    }
  }

  // Connector
  link += "-";

  // Add type
  switch (type) {
    case ::KING: {
      link += "king";
      break;
    }
    case ::QUEEN: {
      link += "queen";
      break;
    }
    case ::ROOK: {
      link += "rook";
      break;
    }
    case ::BISHOP: {
      link += "bishop";
      break;
    }
    case ::KNIGHT: {
      link += "knight";
      break;
    }
    case ::PAWN: {
      link += "pawn";
      break;
    }
    case ::EMPTY: {
      return "-1";
    }
  }

  // Add extension and return
  return link += ".svg";
}


void ChessScene::clearGUI() {
  // Clear all variables
  for (int i = 0; i < BOARDSIZE; ++i) {
    for (int j = 0; j < BOARDSIZE; ++j) {
      markings[i][j] = NONE;
      images[i][j] = {EMPTY, NO_COLOR};
    }
  }

  isInactiveMarkingUsed = false;

  // Refresh
  refreshBoard();
}


QMessageBox::StandardButton ChessScene::saveQuitMsgBox() {
  QMessageBox msgBox;
  msgBox.setWindowTitle("Save");
  msgBox.setText("Do you want to save your changes?");
  msgBox.setInformativeText("Any unsaved changes will be lost.");
  msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
  msgBox.setDefaultButton(QMessageBox::Save);
  int result = msgBox.exec();

  return static_cast<QMessageBox::StandardButton>(result);
}

QMessageBox::StandardButton ChessScene::yesNoMsgBox(const std::string& title,
                                                    const std::string& header,
                                                    const std::string& subtext) {
  QMessageBox msgBox;
  msgBox.setWindowTitle(QString::fromStdString(title));
  msgBox.setText(QString::fromStdString(header));
  msgBox.setInformativeText(QString::fromStdString(subtext));
  msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  msgBox.setDefaultButton(QMessageBox::Cancel);
  int result = msgBox.exec();

  return static_cast<QMessageBox::StandardButton>(result);
}


void ChessScene::customMsgBox(const std::string& title, const std::string& header, const std::string& subtext) {
  QMessageBox msgBox;
  msgBox.setWindowTitle(QString::fromStdString(title));
  msgBox.setText(QString::fromStdString(header));
  msgBox.setInformativeText(QString::fromStdString(subtext));
  // TODO: fix icon
  msgBox.exec();
}

ChessPieceType ChessScene::promotionBox() {
  QMessageBox msgBox;
  msgBox.setWindowTitle("Pawn Promotion");
  msgBox.setText("What piece do you want to promote your pawn to?");
  auto* b1 = new QPushButton("Queen");
  auto* b2 = new QPushButton("Rook");
  auto* b3 = new QPushButton("Bishop");
  auto* b4 = new QPushButton("Knight");

  // Add buttons to the message box
  msgBox.addButton(b1, QMessageBox::ActionRole);
  msgBox.addButton(b2, QMessageBox::ActionRole);
  msgBox.addButton(b3, QMessageBox::ActionRole);
  msgBox.addButton(b4, QMessageBox::ActionRole);

  // Set QUEEN as the default button
  msgBox.setDefaultButton(b1);

  switch (msgBox.exec()) {
    case 1:
      return ROOK;
    case 2:
      return BISHOP;
    case 3:
      return KNIGHT;
    default:
      return QUEEN;
  }
}
