#include "AIEngine.h"

AIEngine::AIEngine(Game *game) : game_(game) {

}

Command *AIEngine::makeMove(Color color, int diceNumber) {
    auto pieces = game_->getPlayerPieces(color);
    for (Piece *piece : pieces) {

    }
    return nullptr;
}
