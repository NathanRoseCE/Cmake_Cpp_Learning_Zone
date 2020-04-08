#pragma once
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
    public:
         static RocketState& getInstance();
         void setZeroAltitude();
        //  RocketState(const RocketState&) = delete;

    private:
        RocketState();
        ThreeDimensionFloat m_angle;
        ThreeDimensionFloat m_velocity;
        ThreeDimensionFloat m_acceleration;
        float m_altitude;
    public:
        //getter and setters
         ThreeDimensionFloat getAngle() const;
         ThreeDimensionFloat getVelocity() const;
         ThreeDimensionFloat getAcceleration() const;
         float getAltitude() const;

         void setAngle(ThreeDimensionFloat angle);
         void setVelocity(ThreeDimensionFloat velocity);
         void setAcceleration(ThreeDimensionFloat acceleration);
         void setAltitude(float altitude);

};