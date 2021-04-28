#ifndef MENSCH_WAITINGCOUNTDATACARRIER_H
#define MENSCH_WAITINGCOUNTDATACARRIER_H

#include "ColorModel.h"
#include "DataCarrier.h"

struct WaitingCountDataCarrier : DataCarrier {
    WaitingCountDataCarrier(Color color, bool piecePresent);

    DataCarrierType getDataCarrierType() override;

    Color color_;
    bool piecePresent_;
};

#endif //MENSCH_WAITINGCOUNTDATACARRIER_H
