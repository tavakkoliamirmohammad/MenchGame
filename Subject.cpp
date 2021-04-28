#include "Subject.h"

void Subject::notify(DataCarrier *dataCarrier, GameEvent event) {
    for (auto &_observer : _observers) {
        _observer->onNotify(dataCarrier, event);
    }
}

void Subject::addObserver(Observer *observer) {
    this->_observers.push_back(observer);
}

void Subject::removeObserver(Observer *observer) {
    for (auto it = _observers.begin(); it != _observers.end(); it++) {
        if (*it == observer) {
            this->_observers.erase(it);
            return;
        }
    }
}
