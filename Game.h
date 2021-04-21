#ifndef MENSCH_GAME_H
#define MENSCH_GAME_H

#include "Board.h"
#include "Player.h"

class Game {
    Game();

    vector<Piece *> getPlayerPieces(Color color);

    Player *getPlayerByPiece(Piece *);

    ~Game();

private:
    Board *board_;
    vector<Player *> players_;
};

#endif //MENSCH_GAME_H
