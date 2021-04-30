#include "GameExecutioner.h"
#include "Game.h"
#include "PlottingEngine.h"

void GameExecutioner::execute(int executionCount) {
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i < executionCount; ++i) {
        AnalyticalEngine analyticalEngine;
        Game game = Game(&analyticalEngine);
        game.loop();
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
        times_.push_back(elapsed.count());
        colors_ = game.getBoardColors();
        for (auto color: colors_) {
            waitingCount_[color].push_back(game.getAnalyticalEngine()->getWaitingCountValue(color));
            scoredGained_[color].push_back(game.getAnalyticalEngine()->getScoredGainedValue(color));
            scoreLost_[color].push_back(game.getAnalyticalEngine()->getScoreLostValue(color));
            distancePlayed_[color].push_back(game.getAnalyticalEngine()->getDistancePlayed(color));
            movingPieceInCount_[color].push_back(game.getAnalyticalEngine()->getMovingPieceInCountValue(color));
        }
    }
}

void GameExecutioner::plot() {
    PlottingEngine::plot("test", colors_, waitingCount_, times_);
}
