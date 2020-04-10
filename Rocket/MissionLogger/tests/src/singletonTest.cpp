#include "MissionLogger/MissionLogger.hpp"
#include <iostream>

int main() {
    //ensure mission logger is in ISSUES log level
    MissionLogger::setLogLevel(MissionLogger::ISSUES);

    //switch to events log level

    if(MissionLogger::getLogLevel() == MissionLogger::ISSUES) {
        return 0;
    }
    return 1;
}