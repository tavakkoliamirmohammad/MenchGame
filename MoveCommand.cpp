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
    int circlePosition = 0;
    for (int i = 0; i < game_->getCircleByColor(circle_->getColor()).size(); ++i) {
        if (game_->getCircleByColor(circle_->getColor())[i] == circle_) {
            circlePosition = i;
            break;
        }
    }
    int piecePosition = 0;
    for (int i = 0; i < game_->getPlayerPieces(piece_->getColor()).size(); ++i) {
        if (game_->getPlayerPieces(piece_->getColor())[i] == piece_) {
            piecePosition = i;
            break;
        }
    }
    cout << "Moving piece " << piece_->getColor() << " Position " << piecePosition << " to circle with color " << circle_->getColor() << " in position "
         << circlePosition << endl;
}

void MoveCommand::undo() {
    if (previousCircle_ != nullptr) {
        game_->movePiece(piece_, previousCircle_);
    }
}

