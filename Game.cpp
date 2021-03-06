#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <random>
#include "Game.h"
#include "ColorModelFactory.h"
#include "GameFinishedDataCarrier.h"

using namespace std;

Game::Game(AnalyticalEngine *analyticalEngine) : analyticalEngine_(analyticalEngine) {
    vector<ColorModel *> colorModels;
    colorModels.emplace_back(ColorModelFactory::createColorModel(Color::Blue));
    colorModels.emplace_back(ColorModelFactory::createColorModel(Color::Green));
    colorModels.emplace_back(ColorModelFactory::createColorModel(Color::Yellow));
    colorModels.emplace_back(ColorModelFactory::createColorModel(Color::Red));
    this->board_ = new Board(colorModels);
    dice_ = new Dice();
    for (ColorModel *colorModel : colorModels) {
        this->players_.emplace_back(new Player(colorModel));
    }
    aiEngine_ = new AIEngine(this);
    physicsEngine_ = new PhysicsEngine(this);
    turn_ = board_->getColors()[0];
    commandStream_ = new CommandStream();
    gamePlay_ = new GamePlay(this);
}

vector<Piece *> Game::getPlayerPieces(Color color) {
    return board_->getPiecesByColor(color);
}


vector<Circle *> Game::returnAvailablePositions(BoardCirclePieceInfo *boardCirclePieceInfo, int offset) {
    return gamePlay_->returnAvailablePositions(boardCirclePieceInfo, offset);
}

BoardCirclePieceInfo *Game::getPiecePositionInfo(Piece *piece) {
    for (auto info: boardCirclePieceInfo_) {
        if (info->getPiece() == piece) {
            return info;
        }
    }
    return nullptr;
}

Circle *Game::getStartCircleByColor(Color color) {
    return board_->getCirclesByColor(color)[0];
}

void Game::movePiece(Piece *piece, Circle *newPosition) {
    removePiecePositionFromBoard(piece);
    boardCirclePieceInfo_.push_back(new BoardCirclePieceInfo(piece, newPosition));
}

void Game::loop() {
    int turn_count = 0;
    while (!isGameFinished_) {
        dice_->roll();
        int diceNumber = dice_->getNumber();
        aiEngine_->run(turn_, diceNumber);
        physicsEngine_->run();
        if (diceNumber != 6) {
            turn_count = (turn_count + 1) % board_->getColors().size();
            turn_ = board_->getColors()[turn_count];
        }
        usleep(10 * 1000);
    }
}

void Game::pushCommand(Command *command) {
    commandStream_->push(command);
}

Command *Game::popCommand() {
    return commandStream_->pop();
}

vector<Circle *> Game::getCircleByColor(Color color) {
    return board_->getCirclesByColor(color);
}

Game::~Game() {
    delete board_;
    delete physicsEngine_;
    delete aiEngine_;
    delete commandStream_;
    delete dice_;
    for (auto player : players_) {
        delete player;
    }
    for (auto info: boardCirclePieceInfo_) {
        delete info;
    }
}

void Game::onNotify(DataCarrier *dataCarrier, GameEvent event) {
    if (event == GameEvent::Finished) {
        isGameFinished_ = true;
        if (dataCarrier->getDataCarrierType() == DataCarrierType::GameFinishedDataCarrier) {
            auto gameFinishedDataCarrier = dynamic_cast<GameFinishedGameCarrier *>(dataCarrier);
            if (gameFinishedDataCarrier) {
                winnerColor_ = gameFinishedDataCarrier->winnerColor_;
            }
        }
    }
}

vector<BoardCirclePieceInfo *> Game::getBoardCirclePieceInfos() {
    return boardCirclePieceInfo_;
}

vector<Color> Game::getBoardColors() {
    return board_->getColors();
}

Color Game::getNextColor(Color color) {
    return board_->getNextColor(color);
}

bool Game::isCircleHomeRow(Circle *circle) {
    return board_->isCircleHomeRow(circle);
}

Color Game::getTurnColor() {
    return turn_;
}

PhysicsEngine *Game::getPhysicsEngine() {
    return physicsEngine_;
}

int Game::getDiceNumber() {
    return dice_->getNumber();
}

vector<BoardCirclePieceInfo *> Game::getCirclePositionInfo(Circle *circle) {
    vector<BoardCirclePieceInfo *> result;
    for (auto info: boardCirclePieceInfo_) {
        if (info->getCircle() == circle) {
            result.push_back(info);
        }
    }
    return result;
}

void Game::findAndRemoveBoardCirclePieceInfo(BoardCirclePieceInfo *boardCirclePieceInfo) {
    int position = -1;
    auto it = find(boardCirclePieceInfo_.begin(), boardCirclePieceInfo_.end(), boardCirclePieceInfo);
    if (it != boardCirclePieceInfo_.cend()) {
        position = distance(boardCirclePieceInfo_.begin(), it);
    }
    if (position != -1) {
        boardCirclePieceInfo_.erase(boardCirclePieceInfo_.begin() + position);
    } else {
        std::putchar('N');
    }
}

void Game::removePiecePositionFromBoard(Piece *piece) {
    auto piecePositionInfo = getPiecePositionInfo(piece);
    if (piecePositionInfo != nullptr) {
        findAndRemoveBoardCirclePieceInfo(piecePositionInfo);
    }
}

void Game::movePieceToOutsideOfBoard(Piece *piece) {
    removePiecePositionFromBoard(piece);
}

AnalyticalEngine *Game::getAnalyticalEngine() {
    return analyticalEngine_;
}

vector<Circle *> Game::getTraps() {
    return board_->getTraps();
}
