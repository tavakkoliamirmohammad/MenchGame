//
// Created by amir on 4/28/21.
//

#include "MovingPieceInDataCarrier.h"

MovingPieceInDataCarrier::MovingPieceInDataCarrier(Color color) : color_(color) {

}

DataCarrierType MovingPieceInDataCarrier::getDataCarrierType() {
    return DataCarrierType::MovingInPieceCountDataCarrier;
}
