#include "MissionLogger/MissionLogger.hpp"
#include "MissionTimer/MissionTimer.hpp"
#include <string>

int main() {
    MissionTimer::startMissionTimer();
    MissionLogger::setLogLevel(MissionLogger::EVENTS);


    while(MissionTimer::getMissionTime() < 1.0f);

    float expectedTime = MissionTimer::getMissionTime();
    std::string string = MissionLogger::logEvent("Event");

    std::string expectedString = "<" + std::to_string(expectedTime) + "s>: Event";

    if(string == expectedString) {
        return 0;
    }
    return 1;
}