#ifndef MENSCH_PHYSICSENGINE_H
#define MENSCH_PHYSICSENGINE_H

#include "Subject.h"
#include "AnalyticalEngine.h"

class Game;


class PhysicsEngine : public Subject {
public:
    explicit PhysicsEngine(Game *game);

    void run();

private:
    void checkIsGameFinished();

    void countWaitingTimesWhenAllPiecesAreOut();

    void checkCollision();

    void checkTrap();

    Game *game_;
};

#endif //MENSCH_PHYSICSENGINE_H
