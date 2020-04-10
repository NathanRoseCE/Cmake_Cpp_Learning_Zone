#include "MissionTimer/MissionTimer.hpp"
#include "Timer/Timer.hpp"

int main() {
    Timer timer;

    MissionTimer::startMissionTimer();
    timer.startTimer();

    float time;
    do {
        time = timer.readTime();
    }
    while(time < 1.0f);

    if(MissionTimer::getMissionTime() != 0) {
        return 0;
    }
    return 1;


}