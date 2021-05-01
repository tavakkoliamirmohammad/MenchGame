#include "MovePieceOutOfBoardCommand.h"

MovePieceOutOfBoardCommand::MovePieceOutOfBoardCommand(Game *game, Piece *piece) : piece_(piece), game_(game) {
    auto piecePositionInfo = game_->getPiecePositionInfo(piece);
    previousCircle_ = piecePositionInfo->getCircle();
}

void MovePieceOutOfBoardCommand::execute() {
    game_->movePieceToOutsideOfBoard(piece_);
}

void MovePieceOutOfBoardCommand::undo() {
    game_->movePiece(piece_, previousCircle_);
}
