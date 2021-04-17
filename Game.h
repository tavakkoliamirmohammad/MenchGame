#ifndef MENSCH_GAME_H
#define MENSCH_GAME_H

#include "Board.h"
#include "Player.h"

class Game {
    Game();

    ~Game();

private:
    Board *Board_;
    vector<Player *> players_;
};

#endif //MENSCH_GAME_H
