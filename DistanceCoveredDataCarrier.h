#ifndef MENSCH_DISTANCECOVEREDDATACARRIER_H
#define MENSCH_DISTANCECOVEREDDATACARRIER_H

#include "ColorModel.h"
#include "DataCarrier.h"

struct DistanceCoveredDataCarrier : public DataCarrier {
    DistanceCoveredDataCarrier(int distance, Color color);

    DataCarrierType getDataCarrierType() override;

    int distance_;
    Color color_;
};

#endif //MENSCH_DISTANCECOVEREDDATACARRIER_H
