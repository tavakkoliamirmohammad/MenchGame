#ifndef MENSCH_COLORMODELFACTORY_H
#define MENSCH_COLORMODELFACTORY_H

#include "ColorModel.h"

class ColorModelFactory {
public:
    static ColorModel *createColorModel(Color color);
};

#endif //MENSCH_COLORMODELFACTORY_H
