#include "PieceCollisionDataCarrier.h"


PieceCollisionDataCarrier::PieceCollisionDataCarrier(Piece *attackedPiece, Piece *attackerPiece) : attackedPiece_(
        attackedPiece), attackerPiece_(attackerPiece) {

}

DataCarrierType PieceCollisionDataCarrier::getDataCarrierType() {
    return DataCarrierType::PieceCollisionDataCarrier;
}

Piece *PieceCollisionDataCarrier::getAttackerPiece() {
    return attackerPiece_;
}

Piece *PieceCollisionDataCarrier::getAttackedPiece() {
    return attackedPiece_;
}
