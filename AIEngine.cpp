#include "AIEngine.h"
#include "MoveCommand.h"

AIEngine::AIEngine(Game *game) : game_(game) {

}

Command *AIEngine::makeMove(Color color, int diceNumber) {
    auto pieces = game_->getPlayerPieces(color);
    for (Piece *piece : pieces) {
        BoardCirclePieceInfo *boardCirclePieceInfo = game_->getPiecePositionInfo(piece);
        if (boardCirclePieceInfo == nullptr) {
            // check multiple entering
            if (diceNumber == 6) return new MoveCommand(game_, piece, game_->getStartCircleByColor(color));
        } else {
            auto positions = game_->returnAvailablePositions(boardCirclePieceInfo, diceNumber);
            if (positions.size() > 1) {
                return new MoveCommand(game_, piece, positions[0]);
            }
        }
    }
    return nullptr;
}