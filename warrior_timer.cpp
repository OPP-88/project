#include "warrior_timer.h"
#include <iostream>

Warrior::Warrior() : Role("Warrior", 250, 75, 20, 25) {
    ultimateTimer = Timer();
    ultimateTimer.start(12);
}

void Warrior::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "mana not enough, cannot use skill attack! " << std::endl;
        return;
    }
    Role::skill(target);
    target.setHP(target.getHP() - 30);
}

void Warrior::ultimate(Role& target) {
 if (!ultimateTimer.isTimeUp()) {
std::cout << "ultimate is not ready until： " << ultimateTimer.getTimeRemaining() << " seconds " << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "ultimate have been casted already! " << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << "using ultimate to youself and " << target.getName() << " !" << std::endl;
        target.setMana(0);
        setMana(0);
        setCountUlt(1);
    }
}
