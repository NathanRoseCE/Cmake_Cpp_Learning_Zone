#include "RocketState/RocketState.hpp"
#include <iostream>

int main() {
    float altitude = 664494;
    ThreeDimensionFloat acc = {432, 4324, 553};
    ThreeDimensionFloat vel = {6486.098, 87.64, 4946.015};
    ThreeDimensionFloat ang = {546, 453, 9063};

    RocketState::setAltitude(altitude);
    RocketState::setAcceleration(acc);
    RocketState::setVelocity(vel);
    RocketState::setAngle(ang);

    if(RocketState::getAltitude() != altitude) {
        std::cout << "Two Altitude: " << RocketState::getAltitude() << std::endl;
        std::cout << "Two Altitude: " << RocketState::getAltitude() << std::endl;
        return 1;
    }
    if(RocketState::getAcceleration() != acc) {
        return 1;
    }
    if(RocketState::getVelocity() != vel) {
        return 1;
    }
    if(RocketState::getAngle() != ang) {
        return 1;
    }

    return 0;

}