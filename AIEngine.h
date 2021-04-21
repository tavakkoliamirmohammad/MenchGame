#ifndef MENSCH_AIENGINE_H
#define MENSCH_AIENGINE_H

#include "Command.h"
#include "ColorModel.h"
#include "Game.h"

class AIEngine {
public:
    AIEngine(Game *game);

    Command *makeMove(Color color, int diceNumber);

private:
    Game *game_;
};

#endif //MENSCH_AIENGINE_H
