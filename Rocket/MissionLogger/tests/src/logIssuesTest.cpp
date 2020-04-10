#include "MissionLogger/MissionLogger.hpp"
#include "MissionTimer/MissionTimer.hpp"
#include <string>

int main() {
    MissionTimer::startMissionTimer();
    MissionLogger::setLogLevel(MissionLogger::ISSUES);
    float expectedTime;
    std::string string;
    std::string expectedString;
    while(MissionTimer::getMissionTime() < 1.0f);

    //check that status prints
    expectedTime = MissionTimer::getMissionTime();
    string = MissionLogger::logStatus("Status");
    expectedString = "";
    if(string != expectedString) {
        return 1;
    }

    //check that Events prints
    expectedTime = MissionTimer::getMissionTime();
    string = MissionLogger::logEvent("Events");
    expectedString = "";
    if(string != expectedString) {
        return 1;
    }

    //check that Events prints
    expectedTime = MissionTimer::getMissionTime();
    string = MissionLogger::logIssue("Issues");
    expectedString = "<" + std::to_string(expectedTime) + "s>: Issues";
    if(string != expectedString) {
        return 1;
    }


    return 0;
}