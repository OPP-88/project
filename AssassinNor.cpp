#include "Assassin.h"

Assassin::Assassin() : Role("刺客", 120, 60, 25, 30) {}

void Assassin::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "蓝量不足，无法使用技能！" << std::endl;
        return;
    }
    Role::skill(target);
    std::cout << getName() << " 使用技能攻击 " << target.getName() << "!" << std::endl;
    target.setHP(target.getHP() - 45);
}
}
