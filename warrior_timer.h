#ifndef WARRIOR_TIMER_H
#define WARRIOR_TIMER_H

#include "Role.h"  
#include "timer.h" 
#include <iostream> 
#include <chrono>  // Include the C++ library for time-related functions.

// Define the Warrior class, which is a subclass of the Role class.
class Warrior : public Role {
public:
    Warrior(); // Constructor for the Warrior class.
    void skill(Role& target) override;    // Function to perform a skill attack on the target (override from Role).
    void ultimate(Role& target) override; // Function to perform the warrior's ultimate ability on the target (override from Role).

private:
    Timer ultimateTimer; // Timer object for managing the cooldown of the warrior's ultimate ability.
};

#endif
