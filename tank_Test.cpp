#include "tank_Test.h"

void TankTest::runTests() {
    testTankInitialization();
    testTankSkill();
    testTankUltimate();
}

void TankTest::testTankInitialization() {
    Tank tank;

    // Check if the Tank's initial values are set correctly
    assert(tank.getName() == "Tank");
    assert(tank.getHP() == 200);
    assert(tank.getMana() == 90);
    assert(tank.getAttack() == 15);
    assert(tank.getSkillCost() == 30);
    assert(tank.getCountRound() == 0);
    assert(tank.getCountUlt() == 0);
}

void TankTest::testTankSkill() {
    Tank tank;
    Role target("Target", 100, 50, 20, 20);

    // Simulate using the skill on the target
    tank.skill(target);

    // Check if the skill has the expected effect on the target and the Tank
   if (target.getHP() == 45) {
        std::cout << "skill correct" << target.getHP() << std::endl;
    } else {
        std::cout << "skill not correct" << target.getHP() << std::endl;
    }
}
