#include "Assassin.h"  // Include the header file for the Assassin class.

Assassin::Assassin() : Role("Assassin", 120, 10000, 25, 30) {
    // Constructor for the Assassin class, setting initial values.
}

void Assassin::skill(Role& target) {
    // Skill method for the Assassin.
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
