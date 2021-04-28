#ifndef MENSCH_MOVEPIECEOUTOFBOARD_H
#define MENSCH_MOVEPIECEOUTOFBOARD_H

#include "Command.h"
#include "Game.h"

class MovePieceOutOfBoard : public Command {
public:
    MovePieceOutOfBoard(Game *game, Piece *piece);

    void execute() override;

    void undo() override;

private:
    Game *game_;
    Piece *piece_;
    Circle* previousCircle_;
};

#endif //MENSCH_MOVEPIECEOUTOFBOARD_H
