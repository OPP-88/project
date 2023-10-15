
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
