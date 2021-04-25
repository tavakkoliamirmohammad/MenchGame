#ifndef MENSCH_GAMEPLAY_H
#define MENSCH_GAMEPLAY_H

#include <vector>
#include "BoardCirclePieceInfo.h"

using namespace std;

class Game;

class GamePlay {
public:
    explicit GamePlay(Game *game);

    vector<Circle *> returnAvailablePositions(BoardCirclePieceInfo *boardCirclePieceInfo, int offset);


private:
    vector<Circle *> getAvailableCircleFromStart(BoardCirclePieceInfo *boardCirclePieceInfo, int offset);

    Game *game_;
};

#endif //MENSCH_GAMEPLAY_H
