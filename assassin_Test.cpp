#include "assassin_Test.h"

void AssassinTest::runTests() {
    testAssassinInitialization();
    testAssassinSkill();
}

void AssassinTest::testAssassinInitialization() {
    Assassin assassin;

    // Check if the Assassin's initial values are set correctly
    assert(assassin.getName() == "Assassin");
    assert(assassin.getHP() == 180);
    assert(assassin.getMana() == 90);
    assert(assassin.getAttack() == 30);
    assert(assassin.getSkillCost() == 30);
    assert(assassin.getCountRound() == 0);
    assert(assassin.getCountUlt() == 0);
}

void AssassinTest::testAssassinSkill() {
    Assassin assassin;
    Role target("Target", 100, 50, 20, 20);

    // Simulate using the skill on the target
    assassin.skill(target);

    // Check if the skill has the expected effect on the target and the assassin
   if (target.getHP() == 50) {
        std::cout << "skill correct" << target.getHP() << std::endl;
    } else {
        std::cout << "skill not correct" << target.getHP() << std::endl;
    }
}
