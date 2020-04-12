#pragma once
#include <string>

class MissionLogger {
    public:
        enum LogLevel {
            ISSUES=0,
            EVENTS=1,
            STATUS=2
        };

        
        
        static std::string logStatus(std::string message);
        static std::string logEvent(std::string message);
        static std::string logIssue(std::string message);
        static void setLogLevel(LogLevel logLevel);
        static void displayTime(bool display);
        static LogLevel getLogLevel();

    private:
        static MissionLogger& getInstance();
        MissionLogger(const MissionLogger&) = delete;
        MissionLogger& operator=(MissionLogger const& missionLogger);
        MissionLogger();
        std::string logStatus_I(std::string message);
        std::string logEvent_I(std::string message);
        std::string logIssue_I(std::string message);
        void setLogLevel_I(LogLevel logLevel);
        LogLevel getLogLevel_I();    
        void displayTime_I(bool display);

    private:
        LogLevel m_logLevel;
        bool m_showTime;
    
        

};