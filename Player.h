
#ifndef MENSCH_PLAYER_H
#define MENSCH_PLAYER_H

#include <string>
#include "ColorModel.h"

class Player {
public:
    Player(ColorModel *colorModel);

    Color getColor();


private:
    ColorModel *colorModel_;
};

#endif //MENSCH_PLAYER_H
