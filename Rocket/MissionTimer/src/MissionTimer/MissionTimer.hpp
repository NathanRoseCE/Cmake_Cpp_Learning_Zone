#pragma once
#include "Timer/Timer.hpp"

class MissionTimer {
    public:
        static void startMissionTimer();
        static float getMissionTime();
    private:
        Timer m_timer;
        MissionTimer();
        MissionTimer(const MissionTimer&) = delete;
        static MissionTimer& getInstance();
        void startMissionTimer_I();
        float getMissionTime_I();
};