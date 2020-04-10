#pragma once
#include <ctime>

class Timer {
    public:
        void startTimer();
        float readTime();
    private:
        clock_t m_startTime;
        bool m_started = false;
};