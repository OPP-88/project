#include "timer.h" 
#include <ctime>   // Include the C library for handling time-related functions.

Timer::Timer() : timerStarted(false), startTime(0), duration(0) {
    // Constructor for the Timer class, initializing timer variables.
}

void Timer::start(int durationInSeconds) {
    timerStarted = true;         // Set the timer as started.
    startTime = time(nullptr);   // Record the current time as the start time.
    duration = durationInSeconds; // Set the timer duration in seconds.
}

bool Timer::isTimeUp() const {
    if (!timerStarted)
        return false; // If the timer was not started, it's not considered as time up.

    int currentTime = time(nullptr); // Get the current time.
    return (currentTime - startTime) >= duration; // Check if the timer duration has passed.
}

int Timer::getTimeRemaining() const {
    if (!timerStarted)
        return 0; // If the timer was not started, there's no time remaining.

    int currentTime = time(nullptr);  // Get the current time.
    int remainingTime = duration - (currentTime - startTime); // Calculate remaining time.
    return remainingTime > 0 ? remainingTime : 0; // Ensure a non-negative remaining time.
}

void Timer::update() {
    // An empty function, possibly for future use or extension.
}
