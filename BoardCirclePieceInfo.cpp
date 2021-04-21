#include "BoardCirclePieceInfo.h"

BoardCirclePieceInfo::BoardCirclePieceInfo(Piece *piece, Circle *circle) : circle_(circle), piece_(piece) {

}

Piece *BoardCirclePieceInfo::getPiece() {
    return piece_;
}

Circle *BoardCirclePieceInfo::getCircle() {
    return circle_;
}
