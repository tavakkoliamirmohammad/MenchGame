#include "Game.h"
#include <algorithm>

Game::Game() {
    vector<ColorModel *> colorModels;
//    TODO Factory method
    colorModels.emplace_back(new ColorModel(Color::Blue));
    colorModels.emplace_back(new ColorModel(Color::Green));
    colorModels.emplace_back(new ColorModel(Color::Yellow));
    colorModels.emplace_back(new ColorModel(Color::Red));
    this->board_ = new Board(colorModels);
    for (ColorModel *colorModel : colorModels) {
        this->players_.emplace_back(new Player(colorModel));
    }
    aiEngine_ = new AIEngine(this);
    turn_ = board_->getColors()[0];
    commandStream_ = new CommandStream();
}

vector<Piece *> Game::getPlayerPieces(Color color) {
    return board_->getPiecesByColor(color);
}

Circle *Game::getPiecePositionInBoard(Piece *piece) {
    for (auto pieceInfo : boardCirclePieceInfo_) {
        if (pieceInfo->getPiece() == piece) {
            return pieceInfo->getCircle();
        }
    }
    return nullptr;
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
    if (circlePosition + offset > circles.size() - 4) {
        // go to next color
        auto nextCircles = board_->getCirclesByColor(
                board_->getNextColor(boardCirclePieceInfo->getCircle()->getColor()));
        positionCircles.push_back(nextCircles[circlePosition + offset - (circles.size() - 4)]);
    } else {
        // stay in the same color
        positionCircles.push_back(circles[circlePosition + offset]);
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
        if (infos.empty() || infos.size() == 1) {
            // handle with different color TODO
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
    int i = 0;
    while (i < 1000) {
        auto command = aiEngine_->makeMove(turn_, rollDice());
        if (command != nullptr) {
            commandStream_->push(command);
        }
        --i;
    }
}

int Game::rollDice() {
    srand((unsigned) time(0));
    printf("Your dice has been rolled! You got: \n ");
    int diceNumber = 1 + (rand() % 6);
    printf("%d \n", diceNumber);
    return diceNumber;
}
