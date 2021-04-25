#ifndef MENSCH_OBSERVER_H
#define MENSCH_OBSERVER_H
enum class GameEvent {
    Finished
};

class Observer {
public:
    virtual ~Observer() = default;

    virtual void onNotify(GameEvent event) = 0;
};

#endif //MENSCH_OBSERVER_H
