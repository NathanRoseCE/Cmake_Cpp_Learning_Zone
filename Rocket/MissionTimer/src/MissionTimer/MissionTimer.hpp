#pragma once
#include "Timer/Timer.hpp"

class MissionTimer {
    private:
        static MissionTimer missionTimer;
        Timer m_timer;
    public:
        static MissionTimer getInstance();
        void startTimer();
        float getMissionTime();
};