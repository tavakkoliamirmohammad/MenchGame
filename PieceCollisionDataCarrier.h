#ifndef MENSCH_PIECECOLLISIONDATACARRIER_H
#define MENSCH_PIECECOLLISIONDATACARRIER_H

#include "DataCarrier.h"
#include "Piece.h"

class PieceCollisionDataCarrier : public DataCarrier {
public:
    PieceCollisionDataCarrier(Piece *attackedPiece, Piece *attackerPiece);

    DataCarrierType getDataCarrierType() override;

    Piece *getAttackerPiece();

    Piece *getAttackedPiece();

private:
    Piece *attackedPiece_;
    Piece *attackerPiece_;
};

#endif //MENSCH_PIECECOLLISIONDATACARRIER_H
