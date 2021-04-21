#ifndef MENSCH_BOARDCIRCLEPIECEINFO_H
#define MENSCH_BOARDCIRCLEPIECEINFO_H

#include "Piece.h"
#include "Circle.h"

class BoardCirclePieceInfo {
public:
    BoardCirclePieceInfo(Piece *piece, Circle *circle);

    Piece *getPiece();

    Circle *getCircle();

private:
    Piece *piece_;
    Circle *circle_;
};

#endif //MENSCH_BOARDCIRCLEPIECEINFO_H
