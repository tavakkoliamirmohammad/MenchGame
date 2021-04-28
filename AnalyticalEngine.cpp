#include "AnalyticalEngine.h"

void AnalyticalEngine::onNotify(DataCarrier *dataCarrier, GameEvent event) {
    if (event == GameEvent::UpdateWaitCount &&
        dataCarrier->getDataCarrierType() == DataCarrierType::WaitingCountDataCarrier) {
        updateWaitingCount(dynamic_cast<WaitingCountDataCarrier *>(dataCarrier));
    }
}

void AnalyticalEngine::updateWaitingCount(WaitingCountDataCarrier *waitingCountDataCarrier) {
    if (waitingCountDataCarrier->piecePresent_) return;
    if (waitingCount_.count(waitingCountDataCarrier->color_) > 0) {
        waitingCount_[waitingCountDataCarrier->color_]++;
    } else {
        waitingCount_[waitingCountDataCarrier->color_] = 1;
    }
}
