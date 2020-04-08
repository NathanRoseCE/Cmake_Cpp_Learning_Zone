#include "RocketState/RocketState.hpp"
#include <iostream>

int main() {
    ThreeDimensionFloat vector = {4.5, 6.6, 9.1};
    float scalar = 2.3;
    
    ThreeDimensionFloat result = vector * scalar;
    ThreeDimensionFloat expectedResult = {4.5f*2.3f, 6.6f*2.3f, 9.1f*2.3f};
    
    if(result == expectedResult) {
        return 0;
    }
    return 1;
}