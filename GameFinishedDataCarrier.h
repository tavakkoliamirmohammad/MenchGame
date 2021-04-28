#ifndef MENSCH_GAMEFINISHEDDATACARRIER_H
#define MENSCH_GAMEFINISHEDDATACARRIER_H

#include "ColorModel.h"
#include "DataCarrier.h"

struct GameFinishedGameCarrier : DataCarrier {
    explicit GameFinishedGameCarrier(Color winnerColor);

    DataCarrierType getDataCarrierType() override;

    Color winnerColor_;
};

#endif //MENSCH_GAMEFINISHEDDATACARRIER_H
