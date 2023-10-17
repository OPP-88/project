// Mage_Timer.h
#ifndef MAGE_TIMER_H
#define MAGE_TIMER_H

#include "Role.h"
#include "timer.h"

class Mage: public Role {
public:
    Mage();
    void skill(Role& target) override;
    void ultimate(Role& target) override;

private:
    Timer ultimateTimer;
};

#endif
