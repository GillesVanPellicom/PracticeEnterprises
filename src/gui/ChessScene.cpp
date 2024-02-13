// ╔══════════════════════════════════════════════════════════════════════════════════╗
// ║ Name         : ChessScene.cpp                                                    ║
// ║ Description  : Implementation of the game rendering                              ║
// ║ Author(s)    : "Gilles Van pellicom" <r0997008@student.thomasmore.be>            ║
// ║ Date         : 2024/02/11                                                        ║
// ║ Version      : 1.0                                                               ║
// ║ License      : GPL-3.0                                                           ║
// ╚══════════════════════════════════════════════════════════════════════════════════╝

#include "ChessScene.h"

#include <utility>

ChessScene::ChessScene(QObject* parent) : QGraphicsScene(parent) {
  // Measurements in px
  cellWidth = 50;
  boardMargin = 0;

  // Read colorscheme.ini and populate variables
  readColorConfig();

  drawBoard();
}

void ChessScene::drawTile(int x, int y) {
  auto* rect = new QGraphicsRectItem(y * cellWidth, x * cellWidth, cellWidth, cellWidth);

  // TODO: implement visualization masks
  if (x % 2 == y % 2) {
    rect->setBrush(QBrush(whiteSquareColor, Qt::SolidPattern));

  } else {
    rect->setBrush(QBrush(blackSquareColor, Qt::SolidPattern));

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
    mINI::INIFile file("../config/colorscheme.ini");
    mINI::INIStructure conf;
    file.read(conf);

    whiteSquareColor = hexstrToQColor(conf["white"]["squareColor"]);
    whiteSquareSelectedColor = hexstrToQColor(conf["white"]["squareSelectedColor"]);
    whiteSquareDangerColor = hexstrToQColor(conf["white"]["squareDangerColor"]);
    whiteSquarePossibleColor = hexstrToQColor(conf["white"]["squarePossibleColor"]);

    blackSquareColor = hexstrToQColor(conf["black"]["squareColor"]);
    blackSquareSelectedColor = hexstrToQColor(conf["black"]["squareSelectedColor"]);
    blackSquareDangerColor = hexstrToQColor(conf["black"]["squareDangerColor"]);
    blackSquarePossibleColor = hexstrToQColor(conf["black"]["squarePossibleColor"]);

  } catch (const std::exception& e) {
    std::cerr << "I/O error: colorscheme.ini was inaccessible. Continuing with default values..." << std::endl;
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

void ChessScene::setClickCallback(std::function<void(int, int)> callback) {
  clickCallback = std::move(callback);
}

void ChessScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  // If button pressed is left button
  if (event->button() == Qt::LeftButton) {
    // Transform Qt scene coordinates to board coordinates [0; 7]
    int cellX = ((int) ceil(event->scenePos().x() / cellWidth)) - 1;
    // flip y coordinate to conform to chess standards
    int cellY = (9 - (int) ceil(event->scenePos().y() / cellWidth)) - 1;

    // Set current focus
    focusX = cellX;
    focusY = cellY;

    // If callback is valid
    if (clickCallback) {
      // Callback to ChessWindow
      clickCallback(cellX, cellY);
    }
  }
  QGraphicsScene::mousePressEvent(event);
}





