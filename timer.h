#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <thread>
#include <functional>
#include <atomic>

class Timer {
public:
    Timer() : isRunning(false), isStopped(false) {}

    // 开始定时器
    void start(int durationInSeconds, std::function<void()> callback) {
        isRunning = true;
        isStopped = false;

        // 使用线程来执行计时任务
        std::thread([=]() {
            while (durationInSeconds > 0 && !isStopped) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                durationInSeconds--;

                if (!isStopped) {
                    if (durationInSeconds == 0) {
                        // 计时完成，执行回调函数
                        callback();
                        isRunning = false;
                    }
                }
            }
        }).detach();
    }

    // 停止定时器
    void stop() {
        isRunning = false;
        isStopped = true;
    }

    // 检查定时器是否正在运行
    bool running() const {
        return isRunning;
    }

private:
    std::atomic<bool> isRunning;
    std::atomic<bool> isStopped;
};

#endif // TIMER_H
