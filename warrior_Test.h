#ifndef WARRIOR_TEST_H
#define WARRIOR_TEST_H

#include <iostream>
#include "warrior_timer.h"

class WarriorTest {
public:
    void runTests();

private:
    void testWarriorInitialization();
    void testWarriorSkill();
    void testWarriorUltimate();
};
#endif
