#include "warrior_Test.h"

int main() {
    // Run tests
    WarriorTest warriorTest;
    warriorTest.runTests();

    // Create an instance of the Warrior class and perform actions
    Warrior warrior;

    // Example: Using skill on a target
    Role target("Target", 100, 50, 20, 20);
    warrior.skill(target);

    // Example: Using ultimate on a target
    warrior.ultimate(target);

    return 0;
}
