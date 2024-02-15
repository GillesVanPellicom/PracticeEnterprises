// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessScene.cpp                                                    ║
// ║ Description  : Implementation of the game rendering                              ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝


#include "ChessScene.h"

ChessScene::ChessScene(QObject* parent)
    : QGraphicsScene(parent), inactiveMarking({Coords(-1, -1), BoardMarkingType::NONE}) {
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

void ChessScene::drawTile(int x, int y) {
  auto* rect = new QGraphicsRectItem(static_cast<int>(y * cellWidth),
                                     static_cast<int>((7 - x) * cellWidth),
                                     cellWidth,
                                     cellWidth);

  if (!boardBorders) {
    rect->setPen(Qt::NoPen);
  }

  if (x % 2 == y % 2) {
    // Qt and chess-actual coordinates are flipped.
    switch (markings[{y, x}]) {

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
    switch (markings[{y, x}]) {

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
  for (int x = 0; x < 8; ++x) {
    for (int y = 0; y < 8; ++y) {
      drawTile(x, y);
    }
  }
}


void ChessScene::readColorConfig() {
  try {
    // FIXME: hardcoded link
    mINI::INIFile file("../config/colorschemes/chess.com.ini");
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


QColor ChessScene::hexstrToQColor(std::string& hex) {
  // regex to validate string.
  std::regex pattern("#?([a-fA-F0-9]){6}");
  if (!std::regex_match(hex, pattern)) {
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
  unsigned int r = (value >> 16) & 0xFF;
  unsigned int g = (value >> 8) & 0xFF;
  unsigned int b = value & 0xFF;

  // Avoid implementation defined annoyances
  return {static_cast<int>(r), static_cast<int>(g), static_cast<int>(b)};
}


void ChessScene::initializeMarkingsMap() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      markings.insert({
                          Coords(i, j), BoardMarkingType::NONE});
    }
  }
}

void ChessScene::initializeImagesMap() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      images.insert({
                        Coords(i, j),
                        {ChessPieceType::EMPTY, ChessPieceColor::NO_COLOR}});
    }
  }
}


void ChessScene::setClickCallback(std::function<void(int, int)> callback) {
  clickCallback = std::move(callback);
}


void ChessScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  // If button pressed is left button
  if (event->button() == Qt::LeftButton) {
    // Transform Qt scene coordinates to board coordinates [0; 7]
    int x = ((int) ceil(event->scenePos().x() / cellWidth)) - 1;
    // flip y coordinate to conform to chess standards
    int y = (9 - (int) ceil(event->scenePos().y() / cellWidth)) - 1;

    // FIXME: remove following two lines for production
    setCellMarkedType(x, y, SELECTED);
    refreshBoard();

    // If callback is valid
    if (clickCallback) {
      // Callback to ChessWindow
      clickCallback(x, y);
    }
  }


  QGraphicsScene::mousePressEvent(event);
}


void ChessScene::setCellMarkedSelected(int x, int y) {

  removeAllMarkingsType(SELECTED);

  // If another marking was overridden, restore it
  if (isInactiveMarkingUsed) {
    isInactiveMarkingUsed = false;
    Coords c = inactiveMarking.first;
    markings[{c.x, c.y}] = inactiveMarking.second;

  }

  // Check if this operation will override a marking of lower precedence.
  if (markings[{x, y}] != BoardMarkingType::NONE) {
    // Remember the marking to be overwritten
    inactiveMarking = {{x, y}, markings[{x, y}]};
    isInactiveMarkingUsed = true;
  }

  // Mark cell as selected.
  markings[{x, y}] = BoardMarkingType::SELECTED;
}


void ChessScene::removeAllMarkingsType(BoardMarkingType type) {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (markings[{i, j}] == type) {
        markings[{i, j}] = BoardMarkingType::NONE;
      }
    }
  }

  // Also remove inactive marking
  if (isInactiveMarkingUsed && inactiveMarking.second == type) {
    isInactiveMarkingUsed = false;
  }
}


void ChessScene::setCellMarkedType(int x, int y, BoardMarkingType type) {
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
    if (markings[{x, y}] != SELECTED) {
      markings[{x, y}] = type;
    } else {
      isInactiveMarkingUsed = true;
      inactiveMarking = {{x, y}, type};
    }
  }
}


void ChessScene::setCellPieceType(int x, int y, ChessPieceType type, ChessPieceColor color) {
  images[{x, y}] = {type, color};
}


void ChessScene::refreshImage(int x, int y) {

  if (images[{x, y}].first == ChessPieceType::EMPTY ||
      images[{x, y}].second == ChessPieceColor::NO_COLOR) {
    return;
  }

  QString filename = getImageFileName(images[{x, y}].first, images[{x, y}].second);
  if (filename.isEmpty())
    return;

  quint32 xQt = cellWidth * (x);
  quint32 yQt = cellWidth * (7 - y);

  std::cout << xQt << " " << yQt << " " << x << " " << (7 - y) << std::endl;


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
  for (int x = 0; x < 8; ++x) {
    for (int y = 0; y < 8; ++y) {
      refreshImage(x, y);
    }
  }
}


QString ChessScene::getImageFileName(ChessPieceType type, ChessPieceColor color) {
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

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      markings[{i, j}] = BoardMarkingType::NONE;
      images[{i, j}] = {ChessPieceType::EMPTY, ChessPieceColor::NO_COLOR};
    }
  }

  isInactiveMarkingUsed = false;
  refreshBoard();
}






