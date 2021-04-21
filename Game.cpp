#include "Game.h"

Game::Game() {
    vector<ColorModel *> colorModels;
//    TODO Factory method
    colorModels.emplace_back(new ColorModel(Color::Blue));
    colorModels.emplace_back(new ColorModel(Color::Green));
    colorModels.emplace_back(new ColorModel(Color::Yellow));
    colorModels.emplace_back(new ColorModel(Color::Red));
    this->board_ = new Board(colorModels);
    for (ColorModel *colorModel : colorModels) {
        this->players_.emplace_back(new Player(colorModel));
    }
}

vector<Piece *> Game::getPlayerPieces(Color color) {
    return board_->getPiecesByColor(color);
}

Circle *Game::getPiecePositionInBoard(Piece *piece) {
    for (auto pieceInfo : boardCirclePieceInfo_) {
        if (pieceInfo->getPiece() == piece) {
            return pieceInfo->getCircle();
        }
    }
    return nullptr;
}

vector<Circle *> Game::getAvailableCircleFromStart(BoardCirclePieceInfo *boardCirclePieceInfo, int offset) {
    vector<Circle *> positionCircles;
    auto circles = board_->getCirclesByColor(boardCirclePieceInfo->getCircle()->getColor());
    auto colors = board_->getColors();
    int circlePosition = 0;
    for (int i = 0; i < circles.size(); ++i) {
        if (circles[i] == boardCirclePieceInfo->getCircle()) {
            circlePosition = i;
            break;
        }
    }
    int originalColorPosition = 0;
    for (int i = 0; i < colors.size(); ++i) {
        if (colors[i] == boardCirclePieceInfo->getCircle()->getColor()) {
            originalColorPosition = i;
        }
    }
    if (circlePosition + offset > circles.size() - 4) {
        // go to next color
        int nextColorPosition = (originalColorPosition + 1) % colors.size();
        auto nextCircles = board_->getCirclesByColor(colors[nextColorPosition]);
        positionCircles.push_back(nextCircles[circlePosition + offset - (circles.size() - 4)]);
    } else {
        // stay in the same color
        positionCircles.push_back(circles[circlePosition + offset]);
    }
    return positionCircles;
}

vector<Circle *> Game::returnAvailablePositions(BoardCirclePieceInfo *boardCirclePieceInfo, int offset) {
    vector<Circle *> circles = getAvailableCircleFromStart(boardCirclePieceInfo, offset);
    vector<Circle *> availableCircles;
    for (auto circle : circles) {
        vector<BoardCirclePieceInfo *> infos;
        for (auto info: boardCirclePieceInfo_) {
            if (info->getCircle() == circle) {
                infos.push_back(info);
            }
        }
        if (infos.empty() || infos.size() == 1) {
            // handle with different color TODO
            availableCircles.push_back(circle);
        }
    }
    return availableCircles;
}