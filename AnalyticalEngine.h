#ifndef MENSCH_ANALYTICALENGINE_H
#define MENSCH_ANALYTICALENGINE_H

#include <unordered_map>
#include "ColorModel.h"
#include "Observer.h"
#include "WaitingCountDataCarrier.h"
#include "MovingPieceInDataCarrier.h"
#include "DistanceCoveredDataCarrier.h"
#include "PieceCollisionDataCarrier.h"
#include "StepIntoTrapDataCarrier.h"

using namespace std;

class AnalyticalEngine : public Observer {
public:
    void onNotify(DataCarrier *dataCarrier, GameEvent event) override;

    int getWaitingCountValue(Color color);

    int getMovingPieceInCountValue(Color color);

    int getDistancePlayed(Color color);

    int getScoredGainedValue(Color color);

    int getScoreLostValue(Color color);

private:
    void updateWaitingCount(WaitingCountDataCarrier *waitingCountDataCarrier);

    void updateMovingPieceCount(MovingPieceInDataCarrier *movingPieceInDataCarrier);

    void updateDistanceCovered(DistanceCoveredDataCarrier *distanceCoveredDataCarrier);

    void updatePieceCollision(PieceCollisionDataCarrier *pieceCollisionDataCarrier);

    void updateStepIntoTrap(StepIntoTrapDataCarrier *stepIntoTrapDataCarrier);

    void updateScoreGained(Color color);

    void updateScoreLost(Color color);

    unordered_map<Color, int> waitingCount_;
    unordered_map<Color, int> movingPieceInCount_;
    unordered_map<Color, int> distancePlayed_;
    unordered_map<Color, int> scoredGained_;
    unordered_map<Color, int> scoreLost_;
};

#endif //MENSCH_ANALYTICALENGINE_H
