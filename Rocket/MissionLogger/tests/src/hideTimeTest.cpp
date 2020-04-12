#include "MissionLogger/MissionLogger.hpp"
#include "MissionTimer/MissionTimer.hpp"

int main() {
    MissionTimer::startMissionTimer();
    MissionLogger::setLogLevel(MissionLogger::STATUS);
    MissionLogger::displayTime(false);
    float expectedTime;
    std::string string;
    std::string expectedString;
    while(MissionTimer::getMissionTime() < 1.0f);

    string = MissionLogger::logIssue("Issues");
    expectedString = "Issues";
    if(string != expectedString) {
        return 1;
    }


    return 0;
}