#ifndef MENSCH_PIECE_H
#define MENSCH_PIECE_H

#include "GameActor.h"
#include "ColorModel.h"

class Piece : public GameActor {
public:
    Piece(ColorModel *);

private:
    ColorModel *colorModel_;
};

#endif //MENSCH_PIECE_H
