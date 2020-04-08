#include "Timer.hpp"

void Timer::startTimer() {
    m_startTime = clock();
}
float Timer::readTime() {
    return (clock() - m_startTime)/CLOCKS_PER_SEC;
}