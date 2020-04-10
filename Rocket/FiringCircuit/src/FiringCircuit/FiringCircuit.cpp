#include "FiringCircuit.hpp"
#include "MissionLogger/MissionLogger.hpp"
#include <string>

FiringCircuit::FiringCircuit(int channel) 
:m_channel(channel)
{}
bool FiringCircuit::hasFired() {
    return m_fired;
}
void FiringCircuit::fire() {
    if(m_fired == true) {
        return;
    }
    MissionLogger::logEvent("Channel fired");
    m_fired = true;
}
int FiringCircuit::getChannel() {
    return m_channel;
}