#include "RocketState/RocketState.hpp"


int main() {

    RocketState::setAltitude(250);

    RocketState::setAcceleration({0.24, 0, 0});
    RocketState::setZeroAltitude();
    if(RocketState::getAltitude() == 0) {
        return 1;
    }

    RocketState::setAcceleration({5.6, 0, 0});
    RocketState::setZeroAltitude();
    if(RocketState::getAltitude() == 0) {
        return 1;
    }

    RocketState::setAcceleration({1.2, 0, 0});
    RocketState::setZeroAltitude();
    if(RocketState::getAltitude() == 0) {
        return 0;
    }
    return 1;
}