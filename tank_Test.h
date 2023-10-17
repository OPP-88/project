#ifndef TANK_TEST_H
#define TANK_TEST_H

#include <iostream>
#include "tank_timer.h"

class TankTest {
public:
    void runTests();

private:
    void testTankInitialization();
    void testTankSkill();
    void testTankUltimate();
};
#endif
