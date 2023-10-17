#ifndef ASSASSIN_TIMER_H
#define ASSASSIN_TIMER_H

#include "Role.h"
#include "timer.h"

class Assassin : public Role {
public:
    Assassin();

    void skill(Role& target) override;
    void ultimate(Role& target) override;

private:
    Timer ultimateTimer;
};

#endif
