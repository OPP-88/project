#include "Assassin.h"

// Constructor for the Assassin class, setting initial values.
Assassin::Assassin() : Role("Assassin", 120, 60, 25, 30) {}

// Skill method for the Assassin.
void Assassin::skill(Role& target) {
    // Check if there is enough mana to use the skill.
    if (getMana() < getSkillCost()) {
        std::cout << "Not enough mana to use the skill!" << std::endl;
        return;
    }
    Role::skill(target);
    std::cout << getName() << " uses the skill to attack " << target.getName() << "!" << std::endl;
    // Reduce the target's HP by 45.
    target.setHP(target.getHP() - 45);
}

// Ultimate method for the Assassin.
void Assassin::ultimate(Role& target) {
    // Check if the required number of rounds has passed to use the ultimate.
    if (getCountRound() < 3) {
        std::cout << "Ultimate cannot be used now, please release it after Round 3!" << std::endl;
    } else if (getCountUlt() == 1) {
        // Check if the ultimate has already been used.
        std::cout << "Ultimate has already been used!" << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << " uses the ultimate on " << target.getName() << "!" << std::endl;

        // Generate a random number between 1 and 10.
        srand(static_cast<unsigned int>(time(nullptr)));
        int randomNumber = rand() % 10 + 1;

        if (randomNumber <= 8) {
            // Handle the case where the ultimate fails.
            std::cout << getName() << " Your ultimate failed, you rolled a " << randomNumber << "!" << std::endl;
        } else {
            // Handle the case where the ultimate succeeds.
            std::cout << getName() << " Your ultimate succeeded, you rolled a " << randomNumber << "!" << std::endl;
            // Set the target's HP to 0, indicating a successful ultimate attack.
            target.setHP(0);
        }
        // Mark that the ultimate has been used.
        setCountUlt(1);
    }
}
