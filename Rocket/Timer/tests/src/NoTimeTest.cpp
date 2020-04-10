#include "Timer/Timer.hpp"

int main() {
    Timer timer;

    if(timer.readTime() == 0) {
        return 0;
    }
    return 1;
}