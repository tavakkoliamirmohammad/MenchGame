#include "PhysicsEngine.h"
#include "Game.h"

PhysicsEngine::PhysicsEngine(Game *game) : game_(game) {

}


void PhysicsEngine::run() {
    Command *command = game_->popCommand();
    if (command != nullptr) {
        command->execute();
    }
}

