#ifndef ASSASSIN_TIMER_H
#define ASSASSIN_TIMER_H

#include "Role.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Assassin : public Role {
public:
    Assassin();

    void skill(Role& target) override;
    void ultimate(Role& target) override;
};

#endif
