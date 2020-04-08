#include "FiringCircuit.hpp"

int main() {
    FiringCircuit channelOne(1);
    FiringCircuit channelTwo(2);

    if(channelOne.hasFired()) {
        return 1;
    }
    
    channelOne.fire();

    if(!channelOne.hasFired()) {
        return 1;
    }

    if(channelTwo.hasFired()) {
        return 1;
    }

    return 0;
}