#ifndef MAGE_TEST_H
#define MAGE_TEST_H

#include <iostream>
#include "mage_timer.h"

class MageTest {
public:
    void runTests();

private:
    void testMageInitialization();
    void testMageSkill();
    void testMageUltimate();
};
#endif
