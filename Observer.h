#ifndef MENSCH_OBSERVER_H
#define MENSCH_OBSERVER_H

#include "DataCarrier.h"

enum class GameEvent {
    Finished,
    UpdateWaitCount,
    UpdateMovingPieceIn,
    UpdateDistanceCovered,
    PieceCollision,
    StepIntoTrap
};

class Observer {
public:
    virtual ~Observer() = default;

    virtual void onNotify(DataCarrier *dataCarrier, GameEvent event) = 0;
};

#endif //MENSCH_OBSERVER_H
