#include "Game.h"

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
}

vector<Piece *> Game::getPlayerPieces(Color color) {
    return board_->getPiecesByColor(color);
}

