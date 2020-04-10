#include "MissionTimer/MissionTimer.hpp"
#include "Timer/Timer.hpp"
#include <iostream>

int main() {
    Timer timer;

    timer.startTimer();
    float time;
    do {
        time = timer.readTime();
    }
    while(time < 1.0f);

    if(MissionTimer::getMissionTime() != 0) {
        std::cout << "START EARLY" << std::endl;
        std::cout << MissionTimer::getMissionTime() << std::endl;
        return 1;
    }



    timer.startTimer();
    MissionTimer::startMissionTimer();
    do {
        time = timer.readTime();
    }
    while(time < 1.0f);
    if(MissionTimer::getMissionTime() != 0) {
        return 0;
    }
    std::cout << "DID NOT START" << std::endl;
    std::cout << MissionTimer::getMissionTime() << std::endl;
    return 1;

}