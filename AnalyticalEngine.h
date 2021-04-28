#ifndef MENSCH_ANALYTICALENGINE_H
#define MENSCH_ANALYTICALENGINE_H

#include "Observer.h"

class AnalyticalEngine : Observer {
public:
    void onNotify(DataCarrier* dataCarrier, GameEvent event) override;
};

#endif //MENSCH_ANALYTICALENGINE_H
