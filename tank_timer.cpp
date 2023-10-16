#include "tank_timer.h"
#include "timer.h"
#include <iostream>
#include <cmath>

Tank::Tank() : Role("Tank", 300, 40, 10, 20) {
    ultimateTimer = Timer();
    ultimateTimer.start(16);
}

void Tank::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "mana not enough, cannot use skill attack" << std::endl;
        return;
    }
    Role::skill(target);
    target.setHP(target.getHP() - 45);
}

void Tank::ultimate(Role& target) {
    if (!ultimateTimer.isTimeUp()) {
std::cout << "ultimate is not ready until： " << ultimateTimer.getTimeRemaining() << " seconds " << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "ultimate have been casted already! " << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << "using ultimate to! " << std::endl;

        setHP(std::ceil(getHP() * 0.4));
        setAttack(getAttack() * 3);
        std::cout << "your ultimate succuss, you lost "<<(getHP()/0.4)-getHP()<< " but you attack increase to "<<getAttack() << std::endl;
        setCountUlt(1);
    }
}
