#include "RocketState/RocketState.hpp"
#include <iostream>

int main() {
    RocketState& stateOne = RocketState::getInstance();
    RocketState& stateTwo = RocketState::getInstance();

    float altitude = 664494;
    ThreeDimensionFloat acc = {432, 4324, 553};
    ThreeDimensionFloat vel = {6486.098, 87.64, 4946.015};
    ThreeDimensionFloat ang = {546, 453, 9063};

    stateOne.setAltitude(altitude);
    stateOne.setAcceleration(acc);
    stateOne.setVelocity(vel);
    stateOne.setAngle(ang);

    if(stateTwo.getAltitude() != altitude) {
        std::cout << "Two Altitude: " << stateOne.getAltitude() << std::endl;
        std::cout << "Two Altitude: " << stateTwo.getAltitude() << std::endl;
        return 1;
    }
    if(stateTwo.getAcceleration() != acc) {
        return 1;
    }
    if(stateTwo.getVelocity() != vel) {
        return 1;
    }
    if(stateTwo.getAngle() != ang) {
        return 1;
    }

    return 0;

}