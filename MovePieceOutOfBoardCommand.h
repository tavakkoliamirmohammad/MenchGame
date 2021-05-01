#ifndef MENSCH_MOVEPIECEOUTOFBOARDCOMMAND_H
#define MENSCH_MOVEPIECEOUTOFBOARDCOMMAND_H

#include "Command.h"
#include "Game.h"

class MovePieceOutOfBoardCommand : public Command {
public:
    MovePieceOutOfBoardCommand(Game *game, Piece *piece);

    void execute() override;

    void undo() override;

private:
    Game *game_;
    Piece *piece_;
    Circle* previousCircle_;
};

#endif //MENSCH_MOVEPIECEOUTOFBOARDCOMMAND_H
