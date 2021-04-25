#include "GamePlay.h"
#include "Game.h"


GamePlay::GamePlay(Game *game) : game_(game) {
}


vector<Circle *> GamePlay::getAvailableCircleFromStart(BoardCirclePieceInfo *boardCirclePieceInfo, int offset) {
    vector<Circle *> positionCircles;
    auto circles = game_->getCircleByColor(boardCirclePieceInfo->getCircle()->getColor());
    auto colors = game_->getBoardColors();
    int circlePosition = 0;
    for (int i = 0; i < circles.size(); ++i) {
        if (circles[i] == boardCirclePieceInfo->getCircle()) {
            circlePosition = i;
            break;
        }
    }
    if (circlePosition + offset >= circles.size() - 4 && circlePosition + offset < circles.size()) {
        if (circlePosition >= 10 &&
            boardCirclePieceInfo->getCircle()->getColor() == boardCirclePieceInfo->getPiece()->getColor()) {
            positionCircles.push_back(circles[circlePosition + offset]);
        } else if (circlePosition < 10 && game_->getNextColor(boardCirclePieceInfo->getCircle()->getColor()) ==
                                          boardCirclePieceInfo->getPiece()->getColor()) {
            auto nextCircles = game_->getCircleByColor(
                    game_->getNextColor(boardCirclePieceInfo->getCircle()->getColor()));
            positionCircles.push_back(nextCircles[circlePosition + offset]);
        }
    }
    if (circlePosition < circles.size() - 4) {
        if (circlePosition + offset >= circles.size() - 4) {
            // go to next color
            auto nextCircles = game_->getCircleByColor(
                    game_->getNextColor(boardCirclePieceInfo->getCircle()->getColor()));
            positionCircles.push_back(nextCircles[circlePosition + offset - (circles.size() - 4)]);
        } else {
            // stay in the same color
            positionCircles.push_back(circles[circlePosition + offset]);
        }
    }
    return positionCircles;
}

vector<Circle *> GamePlay::returnAvailablePositions(BoardCirclePieceInfo *boardCirclePieceInfo, int offset) {
    vector<Circle *> circles = getAvailableCircleFromStart(boardCirclePieceInfo, offset);
    vector<Circle *> availableCircles;
    for (auto circle : circles) {
        vector<BoardCirclePieceInfo *> infos;
        for (auto info: game_->getBoardCirclePieceInfos()) {
            if (info->getCircle() == circle) {
                infos.push_back(info);
            }
        }
//        TODO revert this
        if (infos.empty()) {
            availableCircles.push_back(circle);
        } else if (infos.size() == 1 &&
                   infos[0]->getPiece()->getColor() == boardCirclePieceInfo->getPiece()->getColor() &&
                   !game_->isCircleHomeRow(infos[0]->getCircle())) {
            availableCircles.push_back(circle);
        }
    }
    return availableCircles;
}
