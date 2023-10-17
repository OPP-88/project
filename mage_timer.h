#ifndef MAGE_TIMER_H
#define MAGE_TIMER_H

#include "Role.h"
#include "timer.h"

class Mage : public Role {
public:
    Mage(); // Constructor for the Mage class
    void skill(Role& target) override; // Skill function to perform an attack on the target
    void ultimate(Role& target) override; // Ultimate function for a powerful attack

private:
    Timer ultimateTimer; // Timer to manage the cooldown of the ultimate ability
};

#endif
