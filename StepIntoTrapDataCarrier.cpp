#include "StepIntoTrapDataCarrier.h"

StepIntoTrapDataCarrier::StepIntoTrapDataCarrier(Piece *piece) : piece_(piece) {

}

DataCarrierType StepIntoTrapDataCarrier::getDataCarrierType() {
    return DataCarrierType::StepIntoTrapDataCarrier;
}


Piece *StepIntoTrapDataCarrier::getPiece() {
    return piece_;
}
