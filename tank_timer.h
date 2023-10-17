#ifndef TANK_TIMER_H
#define TANK_TIMER_H

#include <string>
#include "timer.h"  // Include the timer header file for managing timers.
#include "Role.h"   // Include the Role class header file for inheritance.

// Define the Tank class, which is a subclass of the Role class.
class Tank : public Role {
public:
    Tank();  // Constructor for the Tank class.
    void skill(Role& target);    // Function to perform a skill attack on the target.
    void ultimate(Role& target); // Function to perform the tank's ultimate ability on the target.
    void update(); // Function for updating the tank's state or properties (possibly for future use).

private:
    Timer ultimateTimer; // Timer object for managing the cooldown of the tank's ultimate ability.
};

#endif
