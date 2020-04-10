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

    float missionTime = (int)(MissionTimer::getMissionTime());
    float times = (int)(timer.readTime());

    int missionInt = (int)(missionTime);
    int timeInt = (int)(times);
    
    if(missionInt == timeInt) {
        return 0;
    }
    return 1;


}