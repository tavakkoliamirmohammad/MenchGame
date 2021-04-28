#ifndef MENSCH_ANALYTICALENGINE_H
#define MENSCH_ANALYTICALENGINE_H

#include <unordered_map>
#include "ColorModel.h"
#include "Observer.h"
#include "WaitingCountDataCarrier.h"

using namespace std;

class AnalyticalEngine : public Observer {
public:
    void onNotify(DataCarrier *dataCarrier, GameEvent event) override;

private:
private:
    void updateWaitingCount(WaitingCountDataCarrier *waitingCountDataCarrier);

    unordered_map<Color, int> waitingCount_;
};

#endif //MENSCH_ANALYTICALENGINE_H
