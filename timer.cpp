#include "timer.h"
#include <ctime>

Timer::Timer() : timerStarted(false), startTime(0), duration(0) {}

void Timer::start(int durationInSeconds) {
    timerStarted = true;
    startTime = time(nullptr);
    duration = durationInSeconds;
}

bool Timer::isTimeUp() const {
    if (!timerStarted)
        return false;

    int currentTime = time(nullptr);
    return (currentTime - startTime) >= duration;
}

int Timer::getTimeRemaining() const {
    if (!timerStarted)
        return 0;

    int currentTime = time(nullptr);
    int remainingTime = duration - (currentTime - startTime);
    return remainingTime > 0 ? remainingTime : 0;
}

void Timer::update() {

}
