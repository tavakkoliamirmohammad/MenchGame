#ifndef MENSCH_SUBJECT_H
#define MENSCH_SUBJECT_H

#include <vector>
#include "Observer.h"

using namespace std;


class Subject {
public:

    void addObserver(Observer *observer);

    void removeObserver(Observer *observer);

protected:

    void notify(GameEvent event);

private:

    vector<Observer *> _observers;
};

#endif //MENSCH_SUBJECT_H
