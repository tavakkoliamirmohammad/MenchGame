#ifndef MENSCH_AIENGINE_H
#define MENSCH_AIENGINE_H

#include "Command.h"
#include "ColorModel.h"

class Game;

class AIEngine {
public:
    AIEngine(Game *game);

    void run(Color color, int diceNumber);

private:
    Command *makeMove(Color color, int diceNumber);

    Game *game_;
};

#endif //MENSCH_AIENGINE_H
