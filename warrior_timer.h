#ifndef WARRIOR_TIMER_H
#define WARRIOR_TIMER_H

#include "Role.h"
#include "timer.h"
#include <iostream>
#include <chrono>

class Warrior : public Role {
public:
    Warrior();
    void skill(Role& target) override;
    void ultimate(Role& target) override;
private:
    Timer ultimateTimer;
};

#endif
