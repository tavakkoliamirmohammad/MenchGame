#include "MoveCommand.h"
#include <iostream>

using namespace std;

MoveCommand::MoveCommand(Game *game, Piece *piece, Circle *circle) : game_(game), piece_(piece), circle_(circle) {

}


void MoveCommand::execute() {
    auto previousPosition = game_->getPiecePositionInfo(piece_);
    if (previousPosition != nullptr) {
        previousCircle_ = previousPosition->getCircle();
    }
    game_->movePiece(piece_, circle_);
    cout << "Moving piece " << piece_->getColor() << " to circle " << circle_->getColor() << endl;
}

void MoveCommand::undo() {
    if (previousCircle_ != nullptr) {
        game_->movePiece(piece_, previousCircle_);
    }
}

