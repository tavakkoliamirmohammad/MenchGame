#include "GameFinishedDataCarrier.h"

GameFinishedGameCarrier::GameFinishedGameCarrier(Color winnerColor) : winnerColor_(winnerColor) {

}

DataCarrierType GameFinishedGameCarrier::getDataCarrierType() {
    return DataCarrierType::GameFinishedDataCarrier;
}
