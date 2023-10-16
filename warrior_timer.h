#ifndef WARRIOR_TIMER_H
#define WARRIOR_TIMER_H

#include "Role.h"
#include "timer.h"
#include <iostream>
#include <chrono> // 引入 <chrono> 库

class Warrior : public Role {
public:
    Warrior();
    void skill(Role& target) override;
    void ultimate(Role& target) override;
private:
    std::chrono::time_point<std::chrono::steady_clock> lastUltimateTime;
};

#endif
