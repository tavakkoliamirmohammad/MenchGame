#include "Piece.h"

Piece::Piece(ColorModel *colorModel) : colorModel_(colorModel) {

}

Color Piece::getColor() {
    return colorModel_->getColor();
}
