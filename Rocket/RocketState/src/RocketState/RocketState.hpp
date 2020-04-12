#pragma once
#include "RocketInfo/RocketValues.hpp"
#include <cmath>

struct ThreeDimensionFloat {
    float x;
    float y;
    float z;
    float magnitude() const {return sqrt((x*x) + (y*y) + (z*z));}
    ThreeDimensionFloat operator+(ThreeDimensionFloat v2) const{
        return {(x + v2.x), (y + v2.y), (z + v2.z)};
    }
    ThreeDimensionFloat operator*(float scalar) const{
        return {x*scalar, y*scalar, z*scalar};
    }
    bool operator==(ThreeDimensionFloat v2) {return (x==v2.x) && (y==v2.y) && (z==v2.z);}
    bool operator!=(ThreeDimensionFloat v2) {return (x!=v2.x) || (y!=v2.y) || (z!=v2.z);}
};


class RocketState {
    private:
        static RocketState& getInstance();
        RocketState();
        ~RocketState();
        RocketState(const RocketState&) = delete;


        ThreeDimensionFloat m_angle;
        ThreeDimensionFloat m_velocity;
        ThreeDimensionFloat m_acceleration;
        float m_altitude;
        bool m_armed;
        bool m_launched;
        bool m_pastApogee;
        int m_DescentCounter;
        float m_descentAltitude;
        


        
        void setZeroAltitude_I();
        ThreeDimensionFloat getAngle_I();
        ThreeDimensionFloat getVelocity_I();
        ThreeDimensionFloat getAcceleration_I();
        float getAltitude_I();
        bool getArmed_I(); 
        bool getLaunched_I();
        bool getPastApogee_I();
        void setAngle_I(ThreeDimensionFloat angle);
        void setVelocity_I(ThreeDimensionFloat velocity);
        void setAcceleration_I(ThreeDimensionFloat acceleration);
        void setAltitude_I(float altitude);
        void setArmed_I(bool armed);
    public:
        //getter and setters
         static ThreeDimensionFloat getAngle();
         static ThreeDimensionFloat getVelocity();
         static ThreeDimensionFloat getAcceleration();
         static float getAltitude();
         static bool getArmed();
         static bool getLaunched();
         static bool getPastApogee();

         static void setAngle(ThreeDimensionFloat angle);
         static void setVelocity(ThreeDimensionFloat velocity);
         static void setAcceleration(ThreeDimensionFloat acceleration);
         static void setAltitude(float altitude);
         static void setZeroAltitude();
         static void setArmed(bool armed);

};