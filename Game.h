#ifndef MENSCH_GAME_H
#define MENSCH_GAME_H

#include "Board.h"
#include "Player.h"
#include "BoardCirclePieceInfo.h"

class Game {
public:
    Game();

    vector<Piece *> getPlayerPieces(Color color);

    Circle *getPiecePositionInBoard(Piece *piece);

    vector<Circle *> returnAvailablePositions(BoardCirclePieceInfo *boardCirclePieceInfo, int offset);

    Circle *getStartCircleByColor(Color color);

    BoardCirclePieceInfo *getPiecePositionInfo(Piece *piece);

    void movePiece(Piece *piece, Circle *newPosition);

    ~Game();

private:
    Board *board_;
    vector<Player *> players_;

    vector<Circle *> getAvailableCircleFromStart(BoardCirclePieceInfo *boardCirclePieceInfo, int offset);

    vector<BoardCirclePieceInfo *> boardCirclePieceInfo_;
};

#endif //MENSCH_GAME_H
