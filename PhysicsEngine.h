#ifndef MENSCH_PHYSICSENGINE_H
#define MENSCH_PHYSICSENGINE_H

class Game;


class PhysicsEngine {
public:
    PhysicsEngine(Game *game);

    void run();

private:
    Game *game_;
};

#endif //MENSCH_PHYSICSENGINE_H
