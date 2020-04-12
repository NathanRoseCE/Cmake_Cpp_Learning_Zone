#pragma once

#include "RocketState/RocketState.hpp"
#include "FiringCircuit/FiringCircuit.hpp"
#include "Timer/Timer.hpp"

class StateMachine {
    public:
        enum States {
            SAFE,
            ARMED,
            FIRST_STAGE_POWERED,
            INTERMEDIATE_COAST,
            SECOND_STAGE_POWERED,
            COAST_TO_DROGUE,
            DROGUE_DESCENT,
            MAIN_DESCENT,
            LANDED,
            ABORT
        };
        void runLoop();
    private:
        RocketState m_rocketState;
        States m_currentState;
        States m_previousState;
        Timer m_stageTimer;
        FiringCircuit m_firingCircuit[3];
    public:
        States getCurrentState();
        States getPreviousState();
    private:
        StateMachine();
        ~StateMachine();
        void runSafe();
        void runArmed();
        void runFirstStagePowered();
        void runIntermediateCoast();
        void runSecondStagePowered();
        void runCoastToDrogue();
        void runDrogueDescent();
        void runMainDescent();
        void runLanded();
        void runAbort();

        void switchToSafe();
        void switchToArmed();
        void switchToFirstStagePowered();
        void switchToIntermediateCoast();
        void switchToSecondStagePowered();
        void switchToCoastToDrogue();
        void switchToDrogueDescent();
        void switchToMainDescent();
        void switchToLanded();
        void switchToAbort();

};