#include "AnalyticalEngine.h"

void AnalyticalEngine::onNotify(DataCarrier *dataCarrier, GameEvent event) {
    if (event == GameEvent::Finished) {

    }
    if (event == GameEvent::UpdateWaitCount &&
        dataCarrier->getDataCarrierType() == DataCarrierType::WaitingCountDataCarrier) {
        updateWaitingCount(dynamic_cast<WaitingCountDataCarrier *>(dataCarrier));
    }
    if (event == GameEvent::UpdateMovingPieceIn &&
        dataCarrier->getDataCarrierType() == DataCarrierType::MovingPieceountDataCarrier) {
        updateMovingPieceCount(dynamic_cast<MovingPieceInDataCarrier *>(dataCarrier));
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

void AnalyticalEngine::updateMovingPieceCount(MovingPieceInDataCarrier *movingPieceInDataCarrier) {
    if (movingPieceInCount_.count(movingPieceInDataCarrier->color_) > 0) {
        movingPieceInCount_[movingPieceInDataCarrier->color_]++;
    } else {
        movingPieceInCount_[movingPieceInDataCarrier->color_] = 1;
    }
}
