#ifndef TANK_TIMER_H
#define TANK_TIMER_H

#include <string>
#include "timer.h"
#include "Role.h"


class Tank : public Role {
public:
    Tank();
    void skill(Role& target);
    void ultimate(Role& target);
    void update();

private:
    int countUlt;
    Timer ultimateTimer;
};

#endif
