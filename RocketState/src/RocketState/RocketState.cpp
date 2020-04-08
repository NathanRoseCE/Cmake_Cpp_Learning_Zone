#include "RocketState.hpp"
#include "RocketValues.hpp"

RocketState::RocketState() {
    m_angle = {0, 0, 0};
    m_velocity = {0, 0, 0};
    m_acceleration = {0, 0, 0};
    m_altitude = 0;
}
RocketState& RocketState::getInstance() {
    static RocketState instance;
    return instance;
}
void RocketState::setZeroAltitude() {
    //acceleration mangitude is between 0.5g and 1.5g
    //to make sure it is not feeling a force downward
    if( (m_acceleration.magnitude() < 1.5) && (m_acceleration.magnitude() > 0.5) ) {
        m_altitude = 0;
    }
}

ThreeDimensionFloat RocketState::getAngle() const{
    return m_angle;
}
ThreeDimensionFloat RocketState::getVelocity() const{
    return m_velocity;
}
ThreeDimensionFloat RocketState::getAcceleration() const{
    return m_acceleration;
}
float RocketState::getAltitude() const{
    return m_altitude;
}

void RocketState::setAngle(ThreeDimensionFloat angle) {
#ifdef TESTING
    m_angle = angle;
#endif
}
void RocketState::setVelocity(ThreeDimensionFloat velocity) {
#ifdef TESTING
    m_velocity = velocity;
#endif
}
void RocketState::setAcceleration(ThreeDimensionFloat acceleration) {
#ifdef TESTING
    m_acceleration = acceleration;
#endif
}
void RocketState::setAltitude(float altitude) {
#ifdef TESTING
    m_altitude = altitude;
#endif
}