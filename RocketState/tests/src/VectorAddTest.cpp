#include "RocketState/RocketState.hpp"


int main() {
    ThreeDimensionFloat vectorOne;
    ThreeDimensionFloat vectorTwo;
    vectorOne.x = 2.0;
    vectorOne.y = 3.0;
    vectorOne.z = 6.0;

    vectorTwo.x = 4.5;
    vectorTwo.y = -7.3;
    vectorTwo.z = 12;

    ThreeDimensionFloat result = vectorOne + vectorTwo;
    ThreeDimensionFloat expectedResult;
    expectedResult = {2.0f+4.5f, 3.0f-7.3f, 12+6.0f};

    if(result == expectedResult) {
        return 0;
    }
    return 1;
}