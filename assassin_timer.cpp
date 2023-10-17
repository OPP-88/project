#include "assassin_timer.h"  
#include "assassin.h"       
#include <iostream>
#include <cstdlib>
#include <ctime>

Assassin::Assassin() : Role("Assassin", 120, 60, 25, 30) {
    // Constructor for the Assassin class, initializing attributes.
    ultimateTimer = Timer();
    ultimateTimer.start(14); // Set the ultimate timer's duration in seconds.
}

void Assassin::skill(Role& target) {
    // Skill method for the Assassin.
    if (getMana() < getSkillCost()) {
        // Check if there is enough mana to use the skill.
        std::cout << "Mana not enough, not able to use the skill" << std::endl;
        return;
    }
    Role::skill(target);
    // Call the skill method of the base class and execute it.
    std::cout << getName() << " uses the skill to attack " << target.getName() << "!" << std::endl;
    // Display a message indicating the skill usage.
    target.setHP(target.getHP() - 45);
    // Reduce the target's HP by 45.
}

void Assassin::ultimate(Role& target) {
    // Ultimate method for the Assassin.
    if (!ultimateTimer.isTimeUp()) {
        // Check if the ultimate timer has not expired.
        std::cout << "Ultimate cannot be used now, please release it after the timer ends!" << std::endl;
    } else if (getCountUlt() == 1) {
        // Check if the ultimate has already been used.
        std::cout << "Ultimate has been used already!" << std::endl;
    } else {
        Role::ultimate(target);
        // Call the ultimate method of the base class and execute it.
        std::cout << getName() << " uses ultimate " << target.getName() << "!" << std::endl;

        srand(static_cast<unsigned int>(time(nullptr)));
        // Initialize the random number generator with the current time.
        int randomNumber = rand() % 10 + 1;
        // Generate a random number between 1 and 10.

        if (randomNumber <= 8) {
            // Check if the ultimate result is unsuccessful.
            std::cout << getName() << " Your ultimate goes wrong. You threw it " << randomNumber << "!" << std::endl;
        } else {
            // The ultimate result is successful.
            std::cout << getName() << " Your ultimate goes successful. You threw it " << randomNumber << "!" << std::endl;
            target.setHP(0);
            // Set the target's HP to 0.
        }
        setCountUlt(1);
        // Mark that the ultimate has been used.
    }
}
