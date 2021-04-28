#include "PhysicsEngine.h"
#include "Game.h"
#include "GameFinishedDataCarrier.h"
#include "AnalyticalEngine.h"
#include "MovePieceOutOfBoard.h"
#include "PieceCollisionDataCarrier.h"

PhysicsEngine::PhysicsEngine(Game *game) : game_(game) {
    addObserver(game_);
    addObserver(new AnalyticalEngine());
}


void PhysicsEngine::run() {
    Command *command = game_->popCommand();
    while (command != nullptr) {
        command->execute();
        command = game_->popCommand();
        checkIsGameFinished();
        countWaitingTimesWhenAllPiecesAreOut();
        checkCollision();
    }

}

void PhysicsEngine::checkIsGameFinished() {
    auto colors = game_->getBoardColors();
    for (auto color : colors) {
        auto circles = game_->getCircleByColor(color);
        int count = 0;
        vector<int> pos;
        for (int i = circles.size() - 4; i < circles.size(); ++i) {
            for (auto info: game_->getBoardCirclePieceInfos()) {
                if (info->getCircle() == circles[i] && circles[i]->getColor() == info->getPiece()->getColor()) {
                    ++count;
                    pos.push_back(i);
                }
            }
        }
        if (count == 4) {
            GameFinishedGameCarrier gameFinishedGameCarrier = GameFinishedGameCarrier(game_->getTurnColor());
            notify(&gameFinishedGameCarrier, GameEvent::Finished);
        }
    }
}

void PhysicsEngine::countWaitingTimesWhenAllPiecesAreOut() {
    auto colors = game_->getBoardColors();
    for (auto color : colors) {
        bool pieceIsInBoard = false;
        for (auto piece: game_->getPlayerPieces(color)) {
            if (pieceIsInBoard) break;
            for (auto info: game_->getBoardCirclePieceInfos()) {
                if (info->getPiece() == piece) {
                    pieceIsInBoard = true;
                    break;
                }
            }
        }
        WaitingCountDataCarrier waitingCountDataCarrier = WaitingCountDataCarrier(color, pieceIsInBoard);
        notify(&waitingCountDataCarrier, GameEvent::UpdateWaitCount);
    }
}

void PhysicsEngine::checkCollision() {
    auto boardCirclePieceInfos = game_->getBoardCirclePieceInfos();
    for (int i = 0; i < boardCirclePieceInfos.size(); ++i) {
        for (int j = i + 1; j < boardCirclePieceInfos.size(); ++j) {
            if (boardCirclePieceInfos[i]->getCircle() == boardCirclePieceInfos[j]->getCircle() &&
                boardCirclePieceInfos[i]->getPiece()->getColor() != boardCirclePieceInfos[j]->getPiece()->getColor()) {
                auto attackedPiece = boardCirclePieceInfos[i]->getPiece()->getColor() != game_->getTurnColor()
                                     ? boardCirclePieceInfos[i]->getPiece() : boardCirclePieceInfos[j]->getPiece();
                auto attackerPiece = boardCirclePieceInfos[i]->getPiece()->getColor() == game_->getTurnColor()
                                     ? boardCirclePieceInfos[i]->getPiece() : boardCirclePieceInfos[j]->getPiece();
                game_->pushCommand(new MovePieceOutOfBoard(game_, attackedPiece));
                PieceCollisionDataCarrier pieceCollisionDataCarrier = PieceCollisionDataCarrier(attackedPiece,
                                                                                                attackerPiece);
                notify(&pieceCollisionDataCarrier, GameEvent::PieceCollision);
            }
        }
    }

}
