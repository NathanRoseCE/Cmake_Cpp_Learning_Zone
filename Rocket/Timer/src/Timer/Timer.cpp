#include "Timer.hpp"

void Timer::startTimer() {
    m_startTime = clock();
    m_started = true;
}
float Timer::readTime() {
    if(m_started) {
        return (clock() - m_startTime)/CLOCKS_PER_SEC;
    }
    return 0;
}