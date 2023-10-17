#include "mage_Test.h"

void MageTest::runTests() {
    testMageInitialization();
    testMageSkill();
    testMageUltimate();
}

void MageTest::testMageInitialization() {
    Mage mage;

    // Check if the Mage's initial values are set correctly
    assert(mage.getName() == "Mage");
    assert(mage.getHP() == 200);
    assert(mage.getMana() == 90);
    assert(mage.getAttack() == 15);
    assert(mage.getSkillCost() == 30);
    assert(mage.getCountRound() == 0);
    assert(mage.getCountUlt() == 0);
}

void MageTest::testMageSkill() {
    Mage mage;
    Role target("Target", 100, 50, 20, 20);

    // Simulate using the skill on the target
    mage.skill(target);

    // Check if the skill has the expected effect on the target and the Mage
   if (target.getHP() == 45) {
        std::cout << "skill correct" << target.getHP() << std::endl;
    } else {
        std::cout << "skill not correct" << target.getHP() << std::endl;
    }
}
