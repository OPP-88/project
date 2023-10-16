// Mage_timer.cpp
#include "mage_timer.h"
#include <iostream>

Mage::Mage() : Role("法师", 100, 80, 15, 20) {
    // 初始化法师的大招计时器，持续时间为10秒
    ultimateTimer = Timer();
    ultimateTimer.start(10);
}

void Mage::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "蓝量不足，无法使用技能！" << std::endl;
        return;
    }
    Role::skill(target);
    std::cout << getName() << " 使用技能攻击 " << target.getName() << "!" << std::endl;
    target.setHP(target.getHP() - 45);
}

void Mage::ultimate(Role& target) {
    if (!ultimateTimer.isTimeUp()) {
        std::cout << "大招还未准备好，剩余时间：" << ultimateTimer.getTimeRemaining() << "秒" << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "大招已经被使用了!" << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << " 使用大招 " << target.getName() << "!" << std::endl;
        target.setHP(target.getHP() + 50);
        setCountUlt(1);
    }
}
