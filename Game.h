#ifndef MENSCH_GAME_H
#define MENSCH_GAME_H

#include "Board.h"
#include "Player.h"
#include "BoardCirclePieceInfo.h"
#include "AIEngine.h"
#include "PhysicsEngine.h"
#include "CommandStream.h"
#include "Observer.h"

class Game : public Observer {
public:
    Game();

    vector<Piece *> getPlayerPieces(Color color);

    vector<Circle *> getCircleByColor(Color color);

    vector<Circle *> returnAvailablePositions(BoardCirclePieceInfo *boardCirclePieceInfo, int offset);

    Circle *getStartCircleByColor(Color color);

    BoardCirclePieceInfo *getPiecePositionInfo(Piece *piece);

    void movePiece(Piece *piece, Circle *newPosition);

    vector<BoardCirclePieceInfo *> getBoardCirclePieceInfos();

    vector<Color> getBoardColors();

    Command *popCommand();

    void pushCommand(Command *);

    void loop();

    void onNotify(GameEvent event) override;

    ~Game() override;

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
    bool isGameFinished_ = false;
};

#endif //MENSCH_GAME_H
