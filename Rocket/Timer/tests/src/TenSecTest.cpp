#include "Timer/Timer.hpp"
#include <iostream>
#include <ctime>

int main() {
    //checking the clock time to within
    Timer timer;

    std::cout << "START TEST" << std::endl;
    timer.startTimer();
    float time;
    do {
        time = timer.readTime();
    }
    while(time < 10.0f);

    return 0;

}