#include "warrior_Test.h"

void WarriorTest::runTests() {
    testWarriorInitialization();
    testWarriorSkill();
    testWarriorUltimate();
}

void WarriorTest::testWarriorInitialization() {
    Warrior warrior;

    // Check if the Warrior's initial values are set correctly
    assert(warrior.getName() == "Warrior");
    assert(warrior.getHP() == 200);
    assert(warrior.getMana() == 90);
    assert(warrior.getAttack() == 15);
    assert(warrior.getSkillCost() == 30);
    assert(warrior.getCountRound() == 0);
    assert(warrior.getCountUlt() == 0);
}

void WarriorTest::testWarriorSkill() {
    Warrior warrior;
    Role target("Target", 100, 50, 20, 20);

    // Simulate using the skill on the target
    warrior.skill(target);

    // Check if the skill has the expected effect on the target and the Warrior
   if (target.getHP() == 45) {
        std::cout << "skill correct" << target.getHP() << std::endl;
    } else {
        std::cout << "skill not correct" << target.getHP() << std::endl;
    }
}
