#include "ColorModelFactory.h"

ColorModel *ColorModelFactory::createColorModel(Color color) {
    return new ColorModel(color);
}
