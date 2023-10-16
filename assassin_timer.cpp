#include "assassin_timer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Assassin::Assassin() : Role("Assassin", 120, 60, 25, 30) {
    ultimateTimer = Timer();
    ultimateTimer.start(14);
}

void Assassin::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "mana not enough, cannot use skill attack！" << std::endl;
        return;
    }
    Role::skill(target);
    target.setHP(target.getHP() - 45);
}

void Assassin::ultimate(Role& target) {
    if (!ultimateTimer.isTimeUp()) {
        std::cout << "ultimate is not ready until：" << ultimateTimer.getTimeRemaining() << " seconds" << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "ultimate have been casted already!" << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << " using ultimate to " << target.getName() << "!" << std::endl;

        srand(static_cast<unsigned int>(time(nullptr)));
        int randomNumber = rand() % 10 + 1;

        if (randomNumber <= 8) {
            std::cout << getName() << " your ultimate failed, you have roled: " << randomNumber << " !" << std::endl;
        } else {
            std::cout << getName() << " your ultimate succuss, you have roled: " << randomNumber << " !" << std::endl;
            target.setHP(0);
        }
        setCountUlt(1);
    }
}
