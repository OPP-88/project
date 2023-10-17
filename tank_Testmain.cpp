#include "tank_Test.h"

int main() {
    // Run tests
    TankTest tankTest;
    tankTest.runTests();

    // Create an instance of the Tank class and perform actions
    Tank tank;

    // Example: Using skill on a target
    Role target("Target", 100, 50, 20, 20);
    tank.skill(target);

    // Example: Using ultimate on a target
    tank.ultimate(target);

    return 0;
}
