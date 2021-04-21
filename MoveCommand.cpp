#include "MoveCommand.h"

MoveCommand::MoveCommand(Game *game, Piece *piece, Circle *circle) : game_(game), piece_(piece), circle_(circle) {

}


void MoveCommand::execute() {
    auto previousPosition = game_->getPiecePositionInfo(piece_);
    if (previousPosition != nullptr) {
        previousCircle_ = previousPosition->getCircle();
    }
    game_->movePiece(piece_, circle_);
}

void MoveCommand::undo() {
    if (previousCircle_ != nullptr) {
        game_->movePiece(piece_, previousCircle_);
    }
}

MoveCommand::~MoveCommand() = default;
