#pragma once
#include <string>

class MissionLogger {
    public:
        enum LogLevel {
            ISSUES=0,
            EVENTS=1,
            STATUS=2
        };

        static MissionLogger getInstance();
        void setLogLevel(LogLevel logLevel);
        void logStatus(std::string message);
        void logEvent(std::string message);
        void logIssue(std::string message);

    private:
        static MissionLogger missionLogger;
        LogLevel m_logLevel;

};