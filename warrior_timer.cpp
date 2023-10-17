#include "warrior_timer.h" 
#include <iostream>         

Warrior::Warrior() : Role("Warrior", 250, 75, 20, 25) {
    ultimateTimer = Timer();    // Create an instance of the Timer class for the warrior's ultimate ability cooldown.
    ultimateTimer.start(12);    // Start the cooldown timer with a duration of 12 seconds.
}

void Warrior::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "Mana not enough, cannot use skill attack! " << std::endl;
        return; // Check if the warrior's mana is sufficient for the skill; if not, print an error message and return.
    }
    Role::skill(target); // Call the base class (Role) skill function on the target.
    target.setHP(target.getHP() - 30); // Reduce the target's HP by 30.
}

void Warrior::ultimate(Role& target) {
    if (!ultimateTimer.isTimeUp()) {
        std::cout << "Ultimate is not ready until: " << ultimateTimer.getTimeRemaining() << " seconds " << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "Ultimate has already been casted! " << std::endl;
    } else {
        Role::ultimate(target); // Call the base class (Role) ultimate function on the target.
        std::cout << getName() << " using ultimate on yourself and " << target.getName() << "!" << std::endl;

        target.setMana(0); // Set the target's mana to 0.
        setMana(0);        // Set the warrior's mana to 0.
        setCountUlt(1);    // Set the ultimate count to 1, indicating that the ultimate has been cast.
    }
}
