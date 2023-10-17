#include "mage_timer.h"
#include <iostream>

Mage::Mage() : Role("Mage", 200, 90, 15, 30) {
    // Initialize the ultimateTimer with a duration of 10 seconds
    ultimateTimer = Timer();
    ultimateTimer.start(10);
}

void Mage::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "Mana is not enough, cannot use the skill attack!" << std::endl;
        return;
    }
    Role::skill(target); // Call the base class skill function
    target.setHP(target.getHP() - 55); // Reduce the target's HP by 55
}

void Mage::ultimate(Role& target) {
    if (!ultimateTimer.isTimeUp()) {
        // Check if the ultimate is not ready and display the remaining time
        std::cout << "Ultimate is not ready. Remaining time: " << ultimateTimer.getTimeRemaining() << " seconds" << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "Ultimate has already been cast!" << std::endl;
    } else {
        Role::ultimate(target); // Call the base class ultimate function
        std::cout << getName() << " is using the ultimate on " << getName() << "!" << std::endl;
        setHP(getHP() + 50); // Heal yourself by adding 50 HP
        std::cout << "Your ultimate successfully heals 50 HP to " << getName() << "!" << std::endl;
        setCountUlt(1); // Mark that the ultimate has been cast
    }
}
