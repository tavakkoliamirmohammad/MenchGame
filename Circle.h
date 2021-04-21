#ifndef MENSCH_CIRCLE_H
#define MENSCH_CIRCLE_H

#include "ColorModel.h"

class Circle {
public:
    Circle(ColorModel *);

    Color getColor();

private:
    ColorModel *circleModel_;
};

#endif //MENSCH_CIRCLE_H
