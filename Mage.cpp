#include "Mage.h"
#include <iostream>

Mage::Mage() : Role("Mage", 100, 80, 15, 20) {
    // Constructor for the Mage class, setting initial values.
}

void Mage::skill(Role& target) {
    // Skill method for the Mage.
    if (getMana() < getSkillCost()) {
        // Check if there is enough mana to use the skill.
        std::cout << "Not enough mana to use the skill!" << std::endl;
        return;
    }
    Role::skill(target);
    // Call the skill method of the base class and execute it.
    std::cout << getName() << " uses the skill to attack " << target.getName() << "!" << std::endl;
    // Display a message indicating the skill usage.
    target.setHP(target.getHP() - 45);
    // Reduce the target's HP by 45.
}

void Mage::ultimate(Role& target) {
    // Ultimate method for the Mage.
    if (getCountRound() < 3) {
        // Check if the required number of rounds has passed to use the ultimate.
        std::cout << "Ultimate cannot be used now, please release it after Round 3!" << std::endl;
    } else if (getCountUlt() == 1) {
        // Check if the ultimate has already been used.
        std::cout << "Ultimate has already been used!" << std::endl;
    } else {
        Role::ultimate(target);
        // Call the ultimate method of the base class and execute it.
        std::cout << getName() << " uses the ultimate!" << std::endl;
        target.setHP(target.getHP() + 50);
        // Increase the target's HP by 50.
        setCountUlt(1);
        // Mark that the ultimate has been used.
    }
}
