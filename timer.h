#ifndef TIMER_H
#define TIMER_H

// Define the Timer class, which manages time-related functionality.
class Timer {
public:
    Timer();                 // Constructor for the Timer class.
    void start(int durationInSeconds); // Start the timer with a specified duration in seconds.
    bool isTimeUp() const;     // Check if the timer has reached its specified duration.
    int getTimeRemaining() const; // Get the remaining time on the timer.
    void update();            // Function for updating the timer's state (may be used for future purposes).

private:
    bool timerStarted; // Flag indicating if the timer is started.
    int startTime;     // The time when the timer was started.
    int duration;      // The specified duration of the timer in seconds.
};

#endif
