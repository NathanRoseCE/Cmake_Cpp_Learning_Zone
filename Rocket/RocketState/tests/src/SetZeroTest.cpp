#include "RocketState/RocketState.hpp"


int main() {
    RocketState& rocketState = RocketState::getInstance();

    rocketState.setAltitude(250);

    rocketState.setAcceleration({0.24, 0, 0});
    rocketState.setZeroAltitude();
    if(rocketState.getAltitude() == 0) {
        return 1;
    }

    rocketState.setAcceleration({5.6, 0, 0});
    rocketState.setZeroAltitude();
    if(rocketState.getAltitude() == 0) {
        return 1;
    }

    rocketState.setAcceleration({1.2, 0, 0});
    rocketState.setZeroAltitude();
    if(rocketState.getAltitude() == 0) {
        
        return 0;
    }
    return 1;
}