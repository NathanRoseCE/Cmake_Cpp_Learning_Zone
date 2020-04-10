#include "Timer/Timer.hpp"
#include <ctime>

int main() {
    //checking the clock time to within
    Timer timer;

    timer.startTimer();
    float time;
    do {
        time = timer.readTime();
    }
    while(time < 1.0f);

    return 0;

}