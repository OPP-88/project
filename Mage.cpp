#include "Mage.h"
#include <iostream>

Mage::Mage() : Role("法师", 100, 80, 15, 20) {}

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
    if (getCountRound() < 3) {
        std::cout << "大招无法现在使用，请在第3回合之后释放!" << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "大招已经被使用了!" << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << " 使用大招!" << std::endl;
        target.setHP(target.getHP() + 50);
        setCountUlt(1);
    }
}
