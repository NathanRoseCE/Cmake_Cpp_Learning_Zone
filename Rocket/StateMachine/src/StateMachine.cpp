#include "StateMachine.hpp"
#include "MissionLogger/MissionLogger.hpp"
#include "MissionTimer/MissionTimer.hpp"
#include "RocketInfo/RocketValues.hpp"

StateMachine::StateMachine() {
    m_firingCircuit = { 
        FiringCircuit::FiringCircuit(1),
        FiringCircuit(2),
        FiringCircuit(3)
    };
}

StateMachine::~StateMachine() {

}

void StateMachine::runLoop() {

}

StateMachine::States StateMachine::getCurrentState() {

}
StateMachine::States StateMachine::getPreviousState() {

}

void StateMachine::runSafe() {
    if(!RocketState::getArmed()) {
        //just waiting to be armed
        //update arm code and resend it semi-frequently
    }
    else {
        switchToArmed();
    }
}
void StateMachine::runArmed() {
    if(RocketState::getAcceleration().magnitude() < ROCKET_LAUNCH_THRESHOLD) {
        //wait for rocket to launch
    }
    else {
        switchToFirstStagePowered();
    }
}
void StateMachine::runFirstStagePowered() {
    if(!RocketState::getAcceleration().magnitude() > ROCKET_COAST_THRESHOLD) {
        //wait for rocket motor to cutout
    }
    else {
#if TWO_STAGE_ROCKET == true
    switchToIntermediateCoast();
#else
    switchToCoastToDrogue();
#endif
    }

}
void StateMachine::runIntermediateCoast() {
    bool firstStageCondition = false;
    bool secondStageCondition = false;
    switch((FireConditions)SECOND_STAGE_FIRST_CONDITION) {
    case NONE:
        firstStageCondition = true;
        break;
    case APOGEE: 
        if(RocketState::getPastApogee()) {
            firstStageCondition = true;
        }
        break;
    case TIME_DELAY: 
        if(m_stageTimer.readTime() >= SECOND_STAGE_FIRST_VALUE) {
            firstStageCondition = true;
        }
        break;
    case VELOCITY_MIN: 
        if(RocketState::getVelocity().magnitude() <= SECOND_STAGE_FIRST_VALUE) {
            firstStageCondition = true;
        }
        break;
    case VELOCITY_MAX:
        if(RocketState::getVelocity().magnitude() >= SECOND_STAGE_FIRST_VALUE) {
            firstStageCondition = true;
        }
        break;
    }

    switch((FireConditions)SECOND_STAGE_SECOND_CONDITION) {
    case NONE:
        secondStageCondition = true;
        break;
    case APOGEE: 
        if(RocketState::getPastApogee()) {
            secondStageCondition = true;
        }
        break;
    case TIME_DELAY: 
        if(m_stageTimer.readTime() >= SECOND_STAGE_FIRST_VALUE) {
            secondStageCondition = true;
        }
        break;
    case VELOCITY_MIN: 
        if(RocketState::getVelocity().magnitude() <= SECOND_STAGE_FIRST_VALUE) {
            secondStageCondition = true;
        }
        break;
    case VELOCITY_MAX:
        if(RocketState::getVelocity().magnitude() >= SECOND_STAGE_FIRST_VALUE) {
            secondStageCondition = true;
        }
        break;
    }

    ThreeDimensionFloat angleVector = RocketState::getAngle();

    
#if TILT_LOCK
    if(firstStageCondition && secondStageCondition) {
        float phi = sqrt( (angleVector.x*angleVector.x) + (angleVector.y*angleVector.y) );
        if(phi > TILT_LOCK_ANGLE) {
            switchToCoastToDrogue();
        }
    }
#else
    if(firstStageCondition && secondStageCondition) {
        switchToSecondStagePowered();
    }
#endif
}
void StateMachine::runSecondStagePowered() {

}
void StateMachine::runCoastToDrogue() {

}
void StateMachine::runDrogueDescent() {

}
void StateMachine::runMainDescent() {

}
void StateMachine::runLanded() {

}
void StateMachine::runAbort() {

}

void StateMachine::switchToSafe() {
    MissionLogger::logStatus("Switching to Safe State");
    StateMachine::m_previousState = StateMachine::m_currentState;
    StateMachine::m_currentState = StateMachine::SAFE;
    StateMachine::m_stageTimer.startTimer();
}
void StateMachine::switchToArmed() {
    MissionLogger::logStatus("Switching to Armed State");
    StateMachine::m_previousState = StateMachine::m_currentState;
    StateMachine::m_currentState = StateMachine::ARMED;
    StateMachine::m_stageTimer.startTimer();
}
void StateMachine::switchToFirstStagePowered() {
    MissionLogger::logStatus("Switching to First Stage Powered State");
    StateMachine::m_previousState = StateMachine::m_currentState;
    StateMachine::m_currentState = StateMachine::FIRST_STAGE_POWERED;
    StateMachine::m_stageTimer.startTimer();
}
void StateMachine::switchToIntermediateCoast() {
    MissionLogger::logStatus("Switching to Intermediate Coast State");
    StateMachine::m_previousState = StateMachine::m_currentState;
    StateMachine::m_currentState = StateMachine::INTERMEDIATE_COAST;
    StateMachine::m_stageTimer.startTimer();
}
void StateMachine::switchToSecondStagePowered() {
    MissionLogger::logStatus("Switching to Second Stage Powered State");
    StateMachine::m_previousState = StateMachine::m_currentState;
    StateMachine::m_currentState = StateMachine::SECOND_STAGE_POWERED;
    StateMachine::m_stageTimer.startTimer();

}
void StateMachine::switchToCoastToDrogue() {
    MissionLogger::logStatus("Switching to Coast to Drogue State");
    StateMachine::m_previousState = StateMachine::m_currentState;
    StateMachine::m_currentState = StateMachine::COAST_TO_DROGUE;
    StateMachine::m_stageTimer.startTimer();
}
void StateMachine::switchToDrogueDescent() {
    MissionLogger::logStatus("Switching to Drogue Descent State");
    StateMachine::m_previousState = StateMachine::m_currentState;
    StateMachine::m_currentState = StateMachine::DROGUE_DESCENT;
    StateMachine::m_stageTimer.startTimer();
}
void StateMachine::switchToMainDescent() {
    MissionLogger::logStatus("Switching to Main Descent State");
    StateMachine::m_previousState = StateMachine::m_currentState;
    StateMachine::m_currentState = StateMachine::MAIN_DESCENT;
    StateMachine::m_stageTimer.startTimer();
}
void StateMachine::switchToLanded() {
    MissionLogger::logStatus("Switching to Landed State");
    StateMachine::m_previousState = StateMachine::m_currentState;
    StateMachine::m_currentState = StateMachine::LANDED;
    StateMachine::m_stageTimer.startTimer();
}
void StateMachine::switchToAbort() {
    MissionLogger::logStatus("Switching to Abort State");
    StateMachine::m_previousState = StateMachine::m_currentState;
    StateMachine::m_currentState = StateMachine::ABORT;
    StateMachine::m_stageTimer.startTimer();
}