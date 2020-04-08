#include "MissionLogger.hpp"
#include "MissionTimer/MissionTimer.hpp"
#include <iostream>

MissionLogger getInstance() {
    static MissionLogger missionLogger;
    return missionLogger;
}

void MissionLogger::setLogLevel(LogLevel logLevel) {
    m_logLevel = logLevel;
}
void MissionLogger::logStatus(std::string message) {
    if(m_logLevel >= LogLevel::STATUS) {
        std::cout << "<" << MissionTimer::getInstance().getMissionTime() << "s>: " <<
        message << std::endl;
    }
}
void MissionLogger::logEvent(std::string message) {
    if(m_logLevel >= LogLevel::EVENTS) {
        std::cout << "<" << MissionTimer::getInstance().getMissionTime() << "s>: " <<
        message << std::endl;
    }
}
void MissionLogger::logIssue(std::string message) {
    if(m_logLevel >= LogLevel::ISSUES) {
        std::cout << "<" << MissionTimer::getInstance().getMissionTime() << "s>: " <<
        message << std::endl;
    }
}