#include "RocketState/RocketState.hpp"

int main() {
    RocketState::setArmed(true);

    if(RocketState::getArmed() == true) {
        return 0;
    }
    return 1;
}