#include "Warrior.h"
#include <iostream>

Warrior::Warrior() : Role("Warrior", 200, 50, 20, 25) {
    // Constructor for the Warrior class, initializing attributes.
}

void Warrior::skill(Role& target) {
    // Skill method for the Warrior.
    if (getMana() < getSkillCost()) {
        // Check if there is enough mana to use the skill.
        std::cout << "Not enough mana to use the skill!" << std::endl;
        return;
    }
    Role::skill(target);
    // Call the skill method of the base class and execute it.
    std::cout << getName() << " uses the skill to attack " << target.getName() << "!" << std::endl;
    // Display a message indicating the skill usage.
    target.setHP(target.getHP() - 40);
    // Reduce the target's HP by 40.
}

void Warrior::ultimate(Role& target) {
    // Ultimate method for the Warrior.
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
        target.setMana(0);
        // Set the target's mana to 0.
        setCountUlt(1);
        // Mark that the ultimate has been used.
    }
}
