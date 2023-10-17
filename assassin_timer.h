#ifndef ASSASSIN_TIMER_H
#define ASSASSIN_TIMER_H

#include "Role.h"    // Include the header for the Role class.
#include "timer.h"   // Include the header for the timer class.

class Assassin : public Role {
public:
    Assassin();              // Constructor for the Assassin class.
    void skill(Role& target) override;    // Declaration of the skill method.
    void ultimate(Role& target) override; // Declaration of the ultimate method.

private:
    Timer ultimateTimer;   // Timer used for the Assassin's ultimate ability.
};

#endif
