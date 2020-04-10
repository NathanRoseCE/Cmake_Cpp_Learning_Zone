#include "RocketState/RocketState.hpp"
#include <cmath>


int main() {
    ThreeDimensionFloat v1 = {3.4, 4.5, 9.8};
    float expectedMagnitude = sqrt((3.4*3.4)+(4.5*4.5)+(9.8*9.8));
    if(v1.magnitude() == expectedMagnitude) {
        return 0;
        
    }
    return 1;
}