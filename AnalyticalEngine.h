#ifndef MENSCH_ANALYTICALENGINE_H
#define MENSCH_ANALYTICALENGINE_H

#include <unordered_map>
#include "ColorModel.h"
#include "Observer.h"
#include "WaitingCountDataCarrier.h"
#include "MovingPieceInDataCarrier.h"
#include "DistanceCoveredDataCarrier.h"

using namespace std;

class AnalyticalEngine : public Observer {
public:
    void onNotify(DataCarrier *dataCarrier, GameEvent event) override;

private:
private:
    void updateWaitingCount(WaitingCountDataCarrier *waitingCountDataCarrier);

    void updateMovingPieceCount(MovingPieceInDataCarrier *movingPieceInDataCarrier);

    void updateDistanceCovered(DistanceCoveredDataCarrier *distanceCoveredDataCarrier);

    unordered_map<Color, int> waitingCount_;
    unordered_map<Color, int> movingPieceInCount_;
    unordered_map<Color, int> distancePlayed_;
};

#endif //MENSCH_ANALYTICALENGINE_H
