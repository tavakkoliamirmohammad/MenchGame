#include <algorithm>
#include <iostream>
#include "Dice.h"

Dice::Dice() {
    srand((unsigned) time(0));
}

void Dice::roll() {
    number_ = 1 + (rand() % 6);
}

int Dice::getNumber() {
    return number_;
}
