#include "RocketState/RocketState.hpp"
#include <iostream>


int main() {
    ThreeDimensionFloat angle = {4, 5, 6};
    ThreeDimensionFloat velocity = {6, -5, 16};
    ThreeDimensionFloat acceleration = {9, 8, 12};
    float altitude = 16486.261;

    RocketState::setAngle(angle);
    RocketState::setVelocity(velocity);
    RocketState::setAcceleration(acceleration);
    RocketState::setAltitude(altitude);

    if(RocketState::getAngle() != angle) {
        std::cout << "FAILED ANGLE" << std::endl;
        std::cout << "Expected: " << "<" << angle.x << ", " 
        << angle.y <<", " << angle.z << ">" << std::endl;
        std::cout << "Recieved: " << "<" << RocketState::getAngle().x << ", " 
        << RocketState::getAngle().y <<", " << RocketState::getAngle().z << ">" << std::endl;
        return 1;
    }
    if(RocketState::getVelocity() != velocity) {
        std::cout << "FAILED VELOCITY" << std::endl;
        return 1;
    }
    if(RocketState::getAcceleration() != acceleration) {
        std::cout << "FAILED ACCELERATION" << std::endl;
        return 1;
    }
    if(RocketState::getAltitude() != altitude) {
        std::cout << "FAILED ALTITUDE" << std::endl;
        return 1;
    }

    return 0;
}