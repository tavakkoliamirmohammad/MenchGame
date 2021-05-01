#ifndef MENSCH_STEPINTOTRAPDATACARRIER_H
#define MENSCH_STEPINTOTRAPDATACARRIER_H

#include "DataCarrier.h"
#include "Piece.h"

class StepIntoTrapDataCarrier : public DataCarrier {
public:
    explicit StepIntoTrapDataCarrier(Piece *piece);

    DataCarrierType getDataCarrierType() override;

    Piece *getPiece();

private:
    Piece *piece_;
};

#endif //MENSCH_STEPINTOTRAPDATACARRIER_H
