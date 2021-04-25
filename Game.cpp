#include "Game.h"
#include <algorithm>
#include "ColorModelFactory.h"

Game::Game() {
    vector<ColorModel *> colorModels;
    colorModels.emplace_back(ColorModelFactory::createColorModel(Color::Blue));
    colorModels.emplace_back(ColorModelFactory::createColorModel(Color::Green));
    colorModels.emplace_back(ColorModelFactory::createColorModel(Color::Yellow));
    colorModels.emplace_back(ColorModelFactory::createColorModel(Color::Red));
    this->board_ = new Board(colorModels);
    for (ColorModel *colorModel : colorModels) {
        this->players_.emplace_back(new Player(colorModel));
    }
    aiEngine_ = new AIEngine(this);
    physicsEngine_ = new PhysicsEngine(this);
    turn_ = board_->getColors()[0];
    commandStream_ = new CommandStream();
}

vector<Piece *> Game::getPlayerPieces(Color color) {
    return board_->getPiecesByColor(color);
}

vector<Circle *> Game::getAvailableCircleFromStart(BoardCirclePieceInfo *boardCirclePieceInfo, int offset) {
    vector<Circle *> positionCircles;
    auto circles = board_->getCirclesByColor(boardCirclePieceInfo->getCircle()->getColor());
    auto colors = board_->getColors();
    int circlePosition = 0;
    for (int i = 0; i < circles.size(); ++i) {
        if (circles[i] == boardCirclePieceInfo->getCircle()) {
            circlePosition = i;
            break;
        }
    }
    if (circlePosition + offset >= circles.size() - 4 && circlePosition + offset < circles.size()) {
        if (circlePosition >= 10 &&
            boardCirclePieceInfo->getCircle()->getColor() == boardCirclePieceInfo->getPiece()->getColor()) {
            positionCircles.push_back(circles[circlePosition + offset]);
        } else if (circlePosition < 10 && board_->getNextColor(boardCirclePieceInfo->getCircle()->getColor()) ==
                                          boardCirclePieceInfo->getPiece()->getColor()) {
            auto nextCircles = board_->getCirclesByColor(
                    board_->getNextColor(boardCirclePieceInfo->getCircle()->getColor()));
            positionCircles.push_back(nextCircles[circlePosition + offset]);
        }
    }
    if (circlePosition < circles.size() - 4) {
        if (circlePosition + offset >= circles.size() - 4) {
            // go to next color
            auto nextCircles = board_->getCirclesByColor(
                    board_->getNextColor(boardCirclePieceInfo->getCircle()->getColor()));
            positionCircles.push_back(nextCircles[circlePosition + offset - (circles.size() - 4)]);
        } else {
            // stay in the same color
            positionCircles.push_back(circles[circlePosition + offset]);
        }
    }
    return positionCircles;
}

vector<Circle *> Game::returnAvailablePositions(BoardCirclePieceInfo *boardCirclePieceInfo, int offset) {
    vector<Circle *> circles = getAvailableCircleFromStart(boardCirclePieceInfo, offset);
    vector<Circle *> availableCircles;
    for (auto circle : circles) {
        vector<BoardCirclePieceInfo *> infos;
        for (auto info: boardCirclePieceInfo_) {
            if (info->getCircle() == circle) {
                infos.push_back(info);
            }
        }
//        TODO revert this
        if (infos.empty()) {
            // handle with different color TODO
            availableCircles.push_back(circle);
        } else if (infos.size() == 1 &&
                   infos[0]->getPiece()->getColor() == boardCirclePieceInfo->getPiece()->getColor() &&
                   !board_->isCircleHomeRow(infos[0]->getCircle())) {
            availableCircles.push_back(circle);
        }
    }
    return availableCircles;
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
    auto piecePositionInfo = getPiecePositionInfo(piece);
    if (piecePositionInfo != nullptr) {
        int position = -1;
        auto it = find(boardCirclePieceInfo_.begin(), boardCirclePieceInfo_.end(), piecePositionInfo);
        if (it != boardCirclePieceInfo_.cend()) {
            position = distance(boardCirclePieceInfo_.begin(), it);
        }
        if (position != -1) {
            boardCirclePieceInfo_.erase(boardCirclePieceInfo_.begin() + position);
        } else {
            std::putchar('N');
        }
    }
    boardCirclePieceInfo_.push_back(new BoardCirclePieceInfo(piece, newPosition));
}

void Game::loop() {
    int turn_count = 0;
    srand((unsigned) time(0));
    while (!isGameFinished_) {
        int diceNumber = rollDice();
        aiEngine_->run(turn_, diceNumber);
        physicsEngine_->run();
        if (diceNumber != 6) {
            turn_count = (turn_count + 1) % board_->getColors().size();
            turn_ = board_->getColors()[turn_count];
        }
    }
}

int Game::rollDice() {
    int diceNumber = 1 + (rand() % 6);
    return diceNumber;
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
    for (auto player : players_) {
        delete player;
    }
    for (auto info: boardCirclePieceInfo_) {
        delete info;
    }
}

void Game::onNotify(GameEvent event) {
    if (event == GameEvent::Finished) {
        isGameFinished_ = true;
    }
}

vector<BoardCirclePieceInfo *> Game::getBoardCirclePieceInfos() {
    return boardCirclePieceInfo_;
}

vector<Color> Game::getBoardColors() {
    return board_->getColors();
}
