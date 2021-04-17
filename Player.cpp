#include "Player.h"


Player::Player(ColorModel *colorModel) : colorModel_(colorModel) {

}

Color Player::getColor() {
    return colorModel_->getColor();
}
