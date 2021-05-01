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

    if (event == GameEvent::PieceCollision &&
        dataCarrier->getDataCarrierType() == DataCarrierType::PieceCollisionDataCarrier) {
        updatePieceCollision(dynamic_cast<PieceCollisionDataCarrier *>(dataCarrier));
    }

    if (event == GameEvent::StepIntoTrap &&
        dataCarrier->getDataCarrierType() == DataCarrierType::StepIntoTrapDataCarrier) {
        updateStepIntoTrap(dynamic_cast<StepIntoTrapDataCarrier *>(dataCarrier));
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

void AnalyticalEngine::updatePieceCollision(PieceCollisionDataCarrier *pieceCollisionDataCarrier) {
    auto attackerPieceColor = pieceCollisionDataCarrier->getAttackerPiece()->getColor();
    auto attackedPieceColor = pieceCollisionDataCarrier->getAttackedPiece()->getColor();
    updateScoreGained(attackerPieceColor);
    updateScoreLost(attackedPieceColor);
}

int AnalyticalEngine::getWaitingCountValue(Color color) {
    return waitingCount_[color];
}

int AnalyticalEngine::getMovingPieceInCountValue(Color color) {
    return movingPieceInCount_[color];
}

int AnalyticalEngine::getDistancePlayed(Color color) {
    return distancePlayed_[color];
}

int AnalyticalEngine::getScoredGainedValue(Color color) {
    return scoredGained_[color];
}

int AnalyticalEngine::getScoreLostValue(Color color) {
    return scoreLost_[color];
}

void AnalyticalEngine::updateScoreGained(Color color) {
    if (scoredGained_.count(color) > 0) {
        scoredGained_[color] += 1;
    } else {
        scoredGained_[color] = 1;
    }
}

void AnalyticalEngine::updateScoreLost(Color color) {
    if (scoreLost_.count(color) > 0) {
        scoreLost_[color] += 1;
    } else {
        scoreLost_[color] = 1;
    }
}

void AnalyticalEngine::updateStepIntoTrap(StepIntoTrapDataCarrier *stepIntoTrapDataCarrier) {
    updateScoreLost(stepIntoTrapDataCarrier->getPiece()->getColor());
}
