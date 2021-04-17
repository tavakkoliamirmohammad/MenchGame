#include "ColorModel.h"

ColorModel::ColorModel(Color color) : color_(color) {

}

Color ColorModel::getColor() {
    return this->color_;
}
