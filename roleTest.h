// UnitTest.h

#ifndef UNITTEST_H
#define UNITTEST_H

#include <iostream>
#include "Role.h"

class UnitTest {
public:
    void runTests() {
        testSkill();
        testUltimate();
    }

private:
    void testSkill() {
        Role role("TestRole", 100, 50, 20, 10); // Create a test role
        Role target("TargetRole", 100, 50, 20, 10); // Create a target role

        role.skill(target);

        // Check if skill reduced mana correctly
        if (role.getMana() != 40) {
            std::cout << "Skill test failed: Incorrect mana after using skill!" << std::endl;
        }
    }

    void testUltimate() {
        Role role("TestRole", 100, 50, 20, 10); // Create a test role

        // Set countRound to 3 to enable ultimate
        role.setCountRound(3);

        // Test when ultimate is not available
        role.ultimate(role); // Try to use ultimate without enough rounds
        if (role.getCountUlt() != 0) {
            std::cout << "Ultimate test failed: Ultimate used when not available!" << std::endl;
        }

        // Set countRound to 3 to enable ultimate
        role.setCountRound(3);

        // Use ultimate for the first time
        role.ultimate(role);
        if (role.getCountUlt() != 1) {
            std::cout << "Ultimate test failed: Unable to use ultimate!" << std::endl;
        }

        // Try to use ultimate again
        role.ultimate(role);
        if (role.getCountUlt() != 1) {
            std::cout << "Ultimate test failed: Ultimate used more than once!" << std::endl;
        }
    }
};

#endif // UNITTEST_H
