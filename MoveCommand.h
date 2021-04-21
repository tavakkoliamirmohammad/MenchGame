#ifndef MENSCH_MOVECOMMAND_H
#define MENSCH_MOVECOMMAND_H

#include "Game.h"
#include "Command.h"

class MoveCommand : public Command {
public:
    MoveCommand(Game *game, Piece *piece, Circle *circle);

    void execute() override;

    void undo() override;

private:
    Piece *piece_;
    Circle *circle_;
    Game *game_;
    Circle* previousCircle_;
};

#endif //MENSCH_MOVECOMMAND_H
