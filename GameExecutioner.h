#ifndef MENSCH_GAMEEXECUTIONER_H
#define MENSCH_GAMEEXECUTIONER_H

#include <chrono>
#include <vector>
#include <unordered_map>
#include "ColorModel.h"

using namespace std;

class GameExecutioner {
public:
    void execute(int executionCount);

    void plot();

private:
    unordered_map<Color, vector<int>> waitingCount_;
    unordered_map<Color, vector<int>> movingPieceInCount_;
    unordered_map<Color, vector<int>> distancePlayed_;
    unordered_map<Color, vector<int>> scoredGained_;
    unordered_map<Color, vector<int>> scoreLost_;
    vector<Color> colors_;
    vector<double> times_;
};

#endif //MENSCH_GAMEEXECUTIONER_H
