#include "tank_timer.h" // Include the tank_timer header file.
#include "timer.h"      // Include the timer header file.
#include <iostream>     // Include the standard input/output stream library.
#include <cmath>        // Include the math library.

Tank::Tank() : Role("Tank", 200, 40, 20, 20) {
    ultimateTimer = Timer(); // Create an instance of the Timer class for the tank's ultimate ability cooldown.
    ultimateTimer.start(16); // Start the cooldown timer with a duration of 16 seconds.
}

void Tank::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "mana not enough, cannot use skill attack" << std::endl;
        return; // Check if the tank's mana is sufficient for the skill; if not, print an error message and return.
    }
    Role::skill(target); // Call the base class (Role) skill function on the target.
    target.setHP(target.getHP() - 25); // Reduce the target's HP by 25.
}

void Tank::ultimate(Role& target) {
    if (!ultimateTimer.isTimeUp()) {
        std::cout << "ultimate is not ready until: " << ultimateTimer.getTimeRemaining() << " seconds " << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "ultimate has already been cast! " << std::endl;
    } else {
        Role::ultimate(target); // Call the base class (Role) ultimate function on the target.
        std::cout << getName() << " using ultimate! " << std::endl;

        setHP(std::ceil(getHP() * 0.6)); // Increase the tank's HP by 60% (rounding up).
        setAttack(getAttack() * 3);     // Triple the tank's attack power.
        std::cout << "Your ultimate was successful. You lost " << (getHP() / 0.6) - getHP() << " HP, but your attack increased to " << getAttack() << std::endl;
        setCountUlt(1); // Set the ultimate count to 1, indicating that the ultimate has been cast.
    }
}
