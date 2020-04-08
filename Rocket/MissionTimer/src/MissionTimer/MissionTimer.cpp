#include "MissionTimer.hpp"

MissionTimer MissionTimer::getInstance() {
    static MissionTimer missionTimer;
    return missionTimer;
}
void MissionTimer::startTimer() {
    m_timer.startTimer();
}
float MissionTimer::getMissionTime() {
    return m_timer.readTime();
}