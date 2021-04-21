#include "Circle.h"

Circle::Circle(ColorModel *circleModel) : circleModel_(circleModel) {

}

Color Circle::getColor() {
    return circleModel_->getColor();
}
