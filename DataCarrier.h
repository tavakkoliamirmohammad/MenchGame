#ifndef MENSCH_DATACARRIER_H
#define MENSCH_DATACARRIER_H

enum class DataCarrierType {
    GameFinishedDataCarrier
};

struct DataCarrier {
    virtual DataCarrierType getDataCarrierType() = 0;
};

#endif //MENSCH_DATACARRIER_H
