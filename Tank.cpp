#include "Tank.h"
#include <cmath>

Tank::Tank() : Role("Tank", 300, 40, 10, 20) {
    // Constructor for the Tank class, initializing attributes.
}

void Tank::skill(Role& target) {
    // Skill method for the Tank.
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

void Tank::ultimate(Role& target) {
    // Ultimate method for the Tank.
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
        target.setHP(ceil(300 * 0.2)); // Increase target's HP by 20% of Tank's HP.
        target.setAttack(getAttack() * 3); // Increase target's attack by 3 times.
        setCountUlt(1);
        // Mark that the ultimate has been used.
    }
}
