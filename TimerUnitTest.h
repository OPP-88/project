#ifndef TIMER_UNIT_TEST_H
#define TIMER_UNIT_TEST_H

#include <iostream>
#include "timer.h"

class TimerUnitTest {
public:
    void runTests() {
        testTimerStart();
    }

private:
    void testTimerStart() {
        Timer timer;

        // Start the timer with a duration of 5 seconds
        timer.start(5);

        // Check if the timer is started
        if (!timer.isTimeUp()) {
            std::cout << "Test Timer Start: Passed" << std::endl;
        } else {
            std::cout << "Test Timer Start: Failed" << std::endl;
        }
    }
};

#endif
