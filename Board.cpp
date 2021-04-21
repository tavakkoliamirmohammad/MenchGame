#include "Board.h"

#include <utility>

Board::Board(vector<ColorModel *> colorModels) : colorModels_(std::move(colorModels)) {
    for (auto colorModel : colorModels_) {
        vector<Circle *> circles;
        circles.reserve(14);
        for (int i = 0; i < 14; ++i) {
            circles.push_back(new Circle(colorModel));
        }
        circlesMap_[colorModel->getColor()] = circles;
        vector<Piece *> pieces;
        pieces.reserve(4);
        for (int i = 0; i < 4; ++i) {
            pieces.push_back(new Piece(colorModel));
        }
        piecesMap_[colorModel->getColor()] = pieces;
        colors_.push_back(colorModel->getColor());
    }
}

Board::~Board() {
    for (auto colorModel:colorModels_) {
        for (int i = 0; i < piecesMap_[colorModel->getColor()].size(); ++i) {
            delete piecesMap_[colorModel->getColor()][i];
        }
        for (int i = 0; i < circlesMap_[colorModel->getColor()].size(); ++i) {
            delete circlesMap_[colorModel->getColor()][i];
        }
    }
}

vector<Piece *> Board::getPiecesByColor(Color circleColor) {
    return piecesMap_[circleColor];
}

vector<Circle *> Board::getCirclesByColor(Color circleColor) {
    return this->circlesMap_[circleColor];
}

vector<Color> Board::getColors() {
    return colors_;
}

Color Board::getNextColor(Color color) {
    int originalColorPosition = 0;
    for (int i = 0; i < colors_.size(); ++i) {
        if (colors_[i] == color) {
            originalColorPosition = i;
        }
    }
    int nextColorPosition = (originalColorPosition + 1) % colors_.size();
    return colors_[nextColorPosition];
}
