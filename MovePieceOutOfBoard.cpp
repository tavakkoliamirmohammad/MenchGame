#include "MovePieceOutOfBoard.h"

MovePieceOutOfBoard::MovePieceOutOfBoard(Game *game, Piece *piece) : piece_(piece), game_(game) {
    auto piecePositionInfo = game_->getPiecePositionInfo(piece);
    previousCircle_ = piecePositionInfo->getCircle();
}

void MovePieceOutOfBoard::execute() {
    game_->movePieceToOutsideOfBoard(piece_);
}

void MovePieceOutOfBoard::undo() {
    game_->movePiece(piece_, previousCircle_);
}
