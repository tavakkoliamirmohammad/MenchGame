#ifndef MENSCH_MOVINGPIECEINDATACARRIER_H
#define MENSCH_MOVINGPIECEINDATACARRIER_H

#include "DataCarrier.h"
#include "ColorModel.h"

struct MovingPieceInDataCarrier : public DataCarrier {
    explicit MovingPieceInDataCarrier(Color color);
    DataCarrierType getDataCarrierType() override;

    Color color_;
};

#endif //MENSCH_MOVINGPIECEINDATACARRIER_H
