#ifndef MENSCH_GAME_H
#define MENSCH_GAME_H

#include "Board.h"
#include "Player.h"
#include "BoardCirclePieceInfo.h"
#include "AIEngine.h"
#include "PhysicsEngine.h"
#include "CommandStream.h"
#include "Observer.h"
#include "GamePlay.h"
#include "Dice.h"

class Game : public Observer {
public:
    explicit Game(AnalyticalEngine *analyticalEngine);

    vector<Piece *> getPlayerPieces(Color color);

    vector<Circle *> getCircleByColor(Color color);

    vector<Circle *> returnAvailablePositions(BoardCirclePieceInfo *boardCirclePieceInfo, int offset);

    bool isCircleHomeRow(Circle *circle);

    Circle *getStartCircleByColor(Color color);

    BoardCirclePieceInfo *getPiecePositionInfo(Piece *piece);

    vector<BoardCirclePieceInfo *> getCirclePositionInfo(Circle *circle);

    void movePiece(Piece *piece, Circle *newPosition);

    vector<BoardCirclePieceInfo *> getBoardCirclePieceInfos();

    vector<Color> getBoardColors();

    Command *popCommand();

    void pushCommand(Command *);

    void loop();

    void onNotify(DataCarrier *dataCarrier, GameEvent event) override;

    Color getNextColor(Color color);

    Color getTurnColor();

    PhysicsEngine *getPhysicsEngine();

    int getDiceNumber();

    void movePieceToOutsideOfBoard(Piece *piece);

    AnalyticalEngine *getAnalyticalEngine();

    ~Game() override;

private:

    void findAndRemoveBoardCirclePieceInfo(BoardCirclePieceInfo *boardCirclePieceInfo);

    void removePiecePositionFromBoard(Piece *piece);

    Board *board_;
    vector<Player *> players_;
    AIEngine *aiEngine_;
    PhysicsEngine *physicsEngine_;
    Color turn_;
    AnalyticalEngine *analyticalEngine_;
    Color winnerColor_;
    CommandStream *commandStream_;
    GamePlay *gamePlay_;
    vector<BoardCirclePieceInfo *> boardCirclePieceInfo_;
    Dice *dice_;
    bool isGameFinished_ = false;
};

#endif //MENSCH_GAME_H
