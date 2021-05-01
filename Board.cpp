#include <utility>
#include <numeric>
#include <algorithm>
#include <random>

#include "Board.h"

using namespace std;

Board::Board(vector<ColorModel *> colorModels) : colorModels_(std::move(colorModels)) {
    vector<Circle *> trapCircles;
    for (auto colorModel : colorModels_) {
        vector<Circle *> circles;
        circles.reserve(14);
        auto *coloredCircle = new Circle(colorModel);
        for (int i = 0; i < 14; ++i) {
            auto c = coloredCircle->clone();
            circles.push_back(c);
            if (i < 10) {
                trapCircles.push_back(c);
            }
        }
        delete coloredCircle;

        auto *coloredPiece = new Piece(colorModel);
        circlesMap_[colorModel->getColor()] = circles;
        vector<Piece *> pieces;
        pieces.reserve(4);
        for (int i = 0; i < 4; ++i) {
            pieces.push_back(coloredPiece->clone());
        }
        delete coloredPiece;
        piecesMap_[colorModel->getColor()] = pieces;
        colors_.push_back(colorModel->getColor());
    }
    vector<int> random_numbers(trapCircles.size());
    iota(random_numbers.begin(), random_numbers.end(), 1);

    shuffle(random_numbers.begin(), random_numbers.end(), mt19937(random_device()()));
    for (int i = 0; i < 8; ++i) {
        traps_.push_back(trapCircles[random_numbers[i]]);
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
    int originalColorPosition = -1;
    for (int i = 0; i < colors_.size(); ++i) {
        if (colors_[i] == color) {
            originalColorPosition = i;
        }
    }
    int nextColorPosition = (originalColorPosition + 1) % colors_.size();
    return colors_[nextColorPosition];
}

bool Board::isCircleHomeRow(Circle *circle) {
    auto circles = getCirclesByColor(circle->getColor());
    int circlePosition = -1;
    for (int i = 0; i < circles.size(); ++i) {
        if (circles[i] == circle) {
            circlePosition = i;
            break;
        }
    }
    return circlePosition >= 10;
}

vector<Circle *> Board::getTraps() {
    return traps_;
}
