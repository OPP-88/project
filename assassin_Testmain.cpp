#include "assassin_Test.h"

int main() {
    // Run tests
    AssassinTest assassinTest;
    assassinTest.runTests();

    // Create an instance of the Assassin class and perform actions
    Assassin assassin;

    // Example: Using skill on a target
    Role target("Target", 100, 50, 20, 20);
    assassin.skill(target);


    return 0;
}
