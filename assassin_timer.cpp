#include "warrior_timer.h"  // Include the header for the warrior_timer class.
#include <chrono>          // Include the header for time-related operations.

Warrior::Warrior() : Role("Warrior", 200, 50, 20, 25) {
    lastUltimateTime = std::chrono::steady_clock::now();
    // Initialize the lastUltimateTime with the current time using the steady clock.
}

void Warrior::skill(Role& target) {
    // Skill method for the Warrior.
    if (getMana() < getSkillCost()) {
        // Check if there is enough mana to use the skill.
        std::cout << "Mana not enough, not able to use the skill!" << std::endl;
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
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastUltimateTime);

    if (getCountRound() < 3) {
        // Check if the required number of rounds has passed to use the ultimate.
        std::cout << "Ultimate cannot be used now, please release it after Round 3" << std::endl;
    } else if (getCountUlt() == 1) {
        // Check if the ultimate has already been used.
        std::cout << "Ultimate has been used already!!" << std::endl;
    } else if (elapsed.count() < 12) { // 12 seconds cooldown time
        // Check if the ultimate is still cooling down and display the remaining time.
        std::cout << "Ultimate is still cooling, please wait " << 12 - elapsed.count() << " seconds before you can use it!" << std::endl;
    } else {
        Role::ultimate(target);
        // Call the ultimate method of the base class and execute it.
        std::cout << getName() << " uses the ultimate " << target.getName() << "!" << std::endl;
        target.setMana(0);
        // Set the target's mana to 0.
        setCountUlt(1);
        // Mark that the ultimate has been used.
        lastUltimateTime = currentTime;
        // Update the lastUltimateTime to the current time.
    }
}
