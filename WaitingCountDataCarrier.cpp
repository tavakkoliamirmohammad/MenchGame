#include "WaitingCountDataCarrier.h"

WaitingCountDataCarrier::WaitingCountDataCarrier(Color color, bool piecePresent) : color_(color),
                                                                                   piecePresent_(piecePresent) {
}

DataCarrierType WaitingCountDataCarrier::getDataCarrierType() {
    return DataCarrierType::WaitingCountDataCarrier;
}
