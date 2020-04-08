#include "RocketState/RocketState.hpp"
int main() {
    ThreeDimensionFloat v1 = {3, 2, 1};
    ThreeDimensionFloat v2 = {3, 2, 1};
    if(!(v1 == v2)) {
        return 1;
    }

    ThreeDimensionFloat v3 = {1, 2, 3};
    if(v1 == v3) {
        return 1;
    }

    return 0;
}