#ifndef MENSCH_DICE_H
#define MENSCH_DICE_H

class Dice {
public:
    Dice();

    void roll();

    int getNumber();

private:
    int number_;
};

#endif //MENSCH_DICE_H
