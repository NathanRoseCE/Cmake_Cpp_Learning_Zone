#include "RocketState.hpp"

RocketState::RocketState() {
    m_angle = {0, 0, 0};
    m_velocity = {0, 0, 0};
    m_acceleration = {0, 0, 0};
    m_altitude = 0;
    m_armed = false;
}
RocketState::~RocketState() {

}
RocketState& RocketState::getInstance() {
    static RocketState instance;
    return instance;
}
void RocketState::setZeroAltitude_I() {
    //acceleration mangitude is between 0.5g and 1.5g
    //to make sure it is not feeling a force downward
    if( (m_acceleration.magnitude() < 1.5) && (m_acceleration.magnitude() > 0.5) ) {
        m_altitude = 0;
    }
}
void RocketState::setZeroAltitude() {
    RocketState::getInstance().setZeroAltitude_I();
}

ThreeDimensionFloat RocketState::getAngle_I() {
    return m_angle;
}
ThreeDimensionFloat RocketState::getAngle() {
    return RocketState::getInstance().getAngle_I();
}

ThreeDimensionFloat RocketState::getVelocity_I() {
    return m_velocity;
}
ThreeDimensionFloat RocketState::getVelocity() {
    return RocketState::getInstance().getVelocity_I();
}

ThreeDimensionFloat RocketState::getAcceleration_I() {
    return m_acceleration;
}
ThreeDimensionFloat RocketState::getAcceleration() {
    return RocketState::getInstance().getAcceleration_I();
}
float RocketState::getAltitude_I() {
    return m_altitude;
}
float RocketState::getAltitude() {
    return RocketState::getInstance().getAltitude_I();
}

void RocketState::setAngle_I(ThreeDimensionFloat angle) {
    m_angle = angle;
}
void RocketState::setAngle(ThreeDimensionFloat angle) {
    RocketState::getInstance().setAngle_I(angle);
}

void RocketState::setVelocity_I(ThreeDimensionFloat velocity) {
    m_velocity = velocity;
}
void RocketState::setVelocity(ThreeDimensionFloat velocity) {
    RocketState::getInstance().setVelocity_I(velocity);
}

void RocketState::setAcceleration_I(ThreeDimensionFloat acceleration) {
    m_acceleration = acceleration;
    if(m_armed && (acceleration.magnitude() > ROCKET_LAUNCH_THRESHOLD)) {
        m_launched = true;
    }
}
void RocketState::setAcceleration(ThreeDimensionFloat acceleration) {
    RocketState::getInstance().setAcceleration_I(acceleration);
}

void RocketState::setAltitude_I(float altitude) {
    if(m_DescentCounter == -1) {
        if(m_launched && (m_altitude > altitude)) {
            m_DescentCounter = LOGGING_FREQUENCY * APOGEE_DELAY_TIME;
            m_descentAltitude = m_altitude;
        }
    }
    else if(m_DescentCounter > 0) {
        m_DescentCounter--;
    }
    else {
        m_descentAltitude > m_altitude;
        m_pastApogee = true;
    }

    
    m_altitude = altitude;
}
void RocketState::setAltitude(float altitude) {
    RocketState::getInstance().setAltitude_I(altitude);
}
bool RocketState::getArmed() {
    return RocketState::getInstance().getArmed_I();
}
bool RocketState::getArmed_I() {
    return m_armed;
}
void RocketState::setArmed(bool armed) {
    RocketState::getInstance().setArmed_I(armed);
}
void RocketState::setArmed_I(bool armed) {
    m_armed = armed;
}

bool RocketState::getLaunched_I() {
    return m_launched;
}
bool RocketState::getLaunched() {
    return RocketState::getInstance().getLaunched_I();
}
bool RocketState::getPastApogee_I() {
    return m_pastApogee;
}
bool RocketState::getPastApogee() {
    return RocketState::getInstance().getLaunched_I();
}
