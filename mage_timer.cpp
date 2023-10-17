#include "mage_timer.h"
#include <iostream>

Mage::Mage() : Role("Mage", 200, 100, 15, 30) {

    ultimateTimer = Timer();
    ultimateTimer.start(10);
}

void Mage::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "mana not enough, cannot use skill attack！" << std::endl;
        return;
    }
    Role::skill(target);
    target.setHP(target.getHP() - 55);
}

void Mage::ultimate(Role& target) {
    if (!ultimateTimer.isTimeUp()) {
        std::cout << "ultimate is not ready until： " << ultimateTimer.getTimeRemaining() << " seconds" << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "ultimate have been casted already! " << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << " using ultimate to " << getName() << " !" << std::endl;
        setHP(getHP() + 50);
        std::cout << "your ultimate succuss healing 50 Hp to "<< getName() << " !" << std::endl;
        setCountUlt(1);
    }
}
