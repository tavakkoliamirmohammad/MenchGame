#include "AnalyticalEngine.h"

void AnalyticalEngine::onNotify(DataCarrier *dataCarrier, GameEvent event) {
    if (event == GameEvent::Finished) {

    }
    if (event == GameEvent::UpdateWaitCount &&
        dataCarrier->getDataCarrierType() == DataCarrierType::WaitingCountDataCarrier) {
        updateWaitingCount(dynamic_cast<WaitingCountDataCarrier *>(dataCarrier));
    }
    if (event == GameEvent::UpdateMovingPieceIn &&
        dataCarrier->getDataCarrierType() == DataCarrierType::MovingInPieceCountDataCarrier) {
        updateMovingPieceCount(dynamic_cast<MovingPieceInDataCarrier *>(dataCarrier));
    }
    if (event == GameEvent::UpdateDistanceCovered &&
        dataCarrier->getDataCarrierType() == DataCarrierType::DistanceCoveredDataCarrier) {
        updateDistanceCovered(dynamic_cast<DistanceCoveredDataCarrier *>(dataCarrier));
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

void AnalyticalEngine::updateDistanceCovered(DistanceCoveredDataCarrier *distanceCoveredDataCarrier) {
    if (distancePlayed_.count(distanceCoveredDataCarrier->color_) > 0) {
        distancePlayed_[distanceCoveredDataCarrier->color_] += distanceCoveredDataCarrier->distance_;
    } else {
        distancePlayed_[distanceCoveredDataCarrier->color_] = distanceCoveredDataCarrier->distance_;
    }
}