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
    PlottingEngine::plot("waiting_count", "Waiting Count", colors_, waitingCount_, times_, true);
    PlottingEngine::plot("score_gained", "Score Gained", colors_, scoredGained_, times_, true);
    PlottingEngine::plot("score_lost", "Score Lost", colors_, scoreLost_, times_, true);
    PlottingEngine::plot("distance_played", "Distance Played", colors_, distancePlayed_, times_, true);
    PlottingEngine::plot("moving_piece_in_count", "Moving Piece In Count", colors_, movingPieceInCount_, times_, true);
}
