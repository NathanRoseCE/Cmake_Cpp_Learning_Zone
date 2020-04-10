#include "MissionLogger/MissionLogger.hpp"
#include "MissionTimer/MissionTimer.hpp"

MissionLogger::MissionLogger(){

}
MissionLogger& MissionLogger::operator=(MissionLogger const& missionLogger) {
    return (MissionLogger&)missionLogger;
}
MissionLogger& MissionLogger::getInstance() {
    static MissionLogger m_instance;
    return m_instance;
}

void MissionLogger::setLogLevel_I(LogLevel logLevel) {
    m_logLevel = logLevel;
}
void MissionLogger::setLogLevel(LogLevel logLevel) {
    MissionLogger::getInstance().setLogLevel_I(logLevel);
}
MissionLogger::LogLevel MissionLogger::getLogLevel_I() {
    return m_logLevel;
}
MissionLogger::LogLevel MissionLogger::getLogLevel() {
    return MissionLogger::getInstance().getLogLevel_I();
}


std::string MissionLogger::logStatus_I(std::string message) {
    std::string returnString = "";
    if(m_logLevel >= LogLevel::STATUS) {
        returnString = "<" + std::to_string(MissionTimer::getMissionTime()) + "s>: " +
        message;
    }
    return returnString;
}
std::string MissionLogger::logStatus(std::string message) {
    return MissionLogger::getInstance().logStatus_I(message);
}
std::string MissionLogger::logEvent_I(std::string message) {
    std::string returnString;
    if(m_logLevel >= LogLevel::EVENTS) {
        returnString = "<" + std::to_string(MissionTimer::getMissionTime()) + "s>: " +
        message;
    }
    return returnString;
}
std::string MissionLogger::logEvent(std::string message) {
    return MissionLogger::getInstance().logEvent_I(message);
}
std::string MissionLogger::logIssue_I(std::string message) {
    std::string returnString;
    if(m_logLevel >= LogLevel::ISSUES) {
        returnString = "<" + std::to_string(MissionTimer::getMissionTime()) + "s>: " +
        message;
    }
    return returnString;
}
std::string MissionLogger::logIssue(std::string message) {
    return MissionLogger::getInstance().logIssue_I(message);
}