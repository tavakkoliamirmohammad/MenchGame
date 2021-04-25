#ifndef MENSCH_GAME_H
#define MENSCH_GAME_H

#include "Board.h"
#include "Player.h"
#include "BoardCirclePieceInfo.h"
#include "AIEngine.h"
#include "PhysicsEngine.h"
#include "CommandStream.h"

class Game {
public:
    Game();

    vector<Piece *> getPlayerPieces(Color color);

    vector<Circle *> getCircleByColor(Color color);

    Circle *getPiecePositionInBoard(Piece *piece);

    vector<Circle *> returnAvailablePositions(BoardCirclePieceInfo *boardCirclePieceInfo, int offset);

    Circle *getStartCircleByColor(Color color);

    BoardCirclePieceInfo *getPiecePositionInfo(Piece *piece);

    void movePiece(Piece *piece, Circle *newPosition);

    Command *popCommand();

    void pushCommand(Command *);

    void loop();

    ~Game();

private:

    vector<Circle *> getAvailableCircleFromStart(BoardCirclePieceInfo *boardCirclePieceInfo, int offset);

    static int rollDice();

    Board *board_;
    vector<Player *> players_;
    AIEngine *aiEngine_;
    PhysicsEngine *physicsEngine_;
    Color turn_;
    CommandStream *commandStream_;
    vector<BoardCirclePieceInfo *> boardCirclePieceInfo_;
};

#endif //MENSCH_GAME_H
