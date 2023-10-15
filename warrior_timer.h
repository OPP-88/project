#ifndef WARRIOR_H
#define WARRIOR_H

#include "Role.h"
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
