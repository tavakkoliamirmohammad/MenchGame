#ifndef MENSCH_DATACARRIER_H
#define MENSCH_DATACARRIER_H

enum class DataCarrierType {
    GameFinishedDataCarrier,
    WaitingCountDataCarrier,
    MovingInPieceCountDataCarrier,
    DistanceCoveredDataCarrier,
    PieceCollisionDataCarrier,
    StepIntoTrapDataCarrier
};

struct DataCarrier {
    virtual DataCarrierType getDataCarrierType() = 0;
};

#endif //MENSCH_DATACARRIER_H
