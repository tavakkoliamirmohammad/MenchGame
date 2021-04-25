#include "PhysicsEngine.h"
#include "Game.h"

PhysicsEngine::PhysicsEngine(Game *game) : game_(game) {
    addObserver(game_);
}


void PhysicsEngine::run() {
    Command *command = game_->popCommand();
    if (command != nullptr) {
        command->execute();
    }
    checkIsGameFinished();
}

void PhysicsEngine::checkIsGameFinished() {
    auto colors = game_->getBoardColors();
    for (auto color : colors) {
        auto circles = game_->getCircleByColor(color);
        int count = 0;
        vector<int> pos;
        for (int i = circles.size() - 4; i < circles.size(); ++i) {
            for (auto info: game_->getBoardCirclePieceInfos()) {
                if (info->getCircle() == circles[i] && circles[i]->getColor() == info->getPiece()->getColor()) {
                    ++count;
                    pos.push_back(i);
                }
            }
        }
        if (count == 4) {
            notify(GameEvent::Finished);
        }
    }
}

