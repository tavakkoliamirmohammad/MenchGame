#include "DistanceCoveredDataCarrier.h"

DistanceCoveredDataCarrier::DistanceCoveredDataCarrier(int distance, Color color) : distance_(distance), color_(color) {

}

DataCarrierType DistanceCoveredDataCarrier::getDataCarrierType() {
    return DataCarrierType::DistanceCoveredDataCarrier;
}
