#ifndef TANK_H
#define TANK_H

#include <string>
#include "Timer.h"
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
