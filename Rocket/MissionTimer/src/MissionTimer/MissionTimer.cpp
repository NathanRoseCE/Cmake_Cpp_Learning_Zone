#include "MissionTimer/MissionTimer.hpp"
#include "Timer/Timer.hpp"

MissionTimer::MissionTimer(){}

MissionTimer& MissionTimer::getInstance() {
    static MissionTimer m_instance;
    return m_instance;
}
void MissionTimer::startMissionTimer() {
    MissionTimer::getInstance().startMissionTimer_I();
}
void MissionTimer::startMissionTimer_I() {
    m_timer.startTimer();
}

float MissionTimer::getMissionTime_I() {
    return m_timer.readTime();
}
float MissionTimer::getMissionTime() {
    return MissionTimer::getInstance().getMissionTime_I();
}