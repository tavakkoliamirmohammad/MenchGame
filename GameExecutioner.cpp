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
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - begin);
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
    PlottingEngine plottingEngine(1200, 780);
    plottingEngine.cumulativePlot("waiting_count", "Waiting Count", colors_, waitingCount_, times_);
    plottingEngine.cumulativePlot("score_gained", "Score Gained", colors_, scoredGained_, times_);
    plottingEngine.cumulativePlot("score_lost", "Score Lost", colors_, scoreLost_, times_);
    plottingEngine.cumulativePlot("distance_played", "Distance Played", colors_, distancePlayed_, times_);
    plottingEngine.cumulativePlot("moving_piece_in_count", "Moving Piece In Count", colors_, movingPieceInCount_,
                                  times_);
    int interval = 2;
    plottingEngine.windowedPlot("waiting_count", "Waiting Count", colors_, waitingCount_, times_, interval);
    plottingEngine.windowedPlot("score_gained", "Score Gained", colors_, scoredGained_, times_, interval);
    plottingEngine.windowedPlot("score_lost", "Score Lost", colors_, scoreLost_, times_, interval);
    plottingEngine.windowedPlot("distance_played", "Distance Played", colors_, distancePlayed_, times_, interval);
    plottingEngine.windowedPlot("moving_piece_in_count", "Moving Piece In Count", colors_, movingPieceInCount_,
                                times_, interval);
}
