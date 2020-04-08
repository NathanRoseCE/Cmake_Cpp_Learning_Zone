#include "RocketState/RocketState.hpp"
#include <iostream>


int main() {
    RocketState rocket = RocketState::getInstance();
    ThreeDimensionFloat angle = {4, 5, 6};
    ThreeDimensionFloat velocity = {6, -5, 16};
    ThreeDimensionFloat acceleration = {9, 8, 12};
    float altitude = 16486.261;

    rocket.setAngle(angle);
    rocket.setVelocity(velocity);
    rocket.setAcceleration(acceleration);
    rocket.setAltitude(altitude);

    if(rocket.getAngle() != angle) {
        std::cout << "FAILED ANGLE" << std::endl;
        std::cout << "Expected: " << "<" << angle.x << ", " 
        << angle.y <<", " << angle.z << ">" << std::endl;
        std::cout << "Recieved: " << "<" << rocket.getAngle().x << ", " 
        << rocket.getAngle().y <<", " << rocket.getAngle().z << ">" << std::endl;
        return 1;
    }
    if(rocket.getVelocity() != velocity) {
        std::cout << "FAILED VELOCITY" << std::endl;
        return 1;
    }
    if(rocket.getAcceleration() != acceleration) {
        std::cout << "FAILED ACCELERATION" << std::endl;
        return 1;
    }
    if(rocket.getAltitude() != altitude) {
        std::cout << "FAILED ALTITUDE" << std::endl;
        return 1;
    }

    return 0;
}