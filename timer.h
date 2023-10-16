// Timer.h
#ifndef TIMER_H
#define TIMER_H

class Timer {
public:
    Timer();
    void start(int durationInSeconds);
    bool isTimeUp() const;
    int getTimeRemaining() const; // 声明获取剩余时间的函数
    void update();

private:
    bool timerStarted;
    int startTime;
    int duration;
};

#endif

