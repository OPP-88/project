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

void Assassin::ultimate(Role& target) {
    if (getCountRound() < 3) {
        std::cout << "大招无法现在使用，请在第3回合之后释放!" << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "大招已经被使用了!" << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << " 使用大招 " << target.getName() << "!" << std::endl;

        srand(static_cast<unsigned int>(time(nullptr)));
        int randomNumber = rand() % 10 + 1;

        if (randomNumber <= 8) {
            std::cout << getName() << " 你的大招失误了，你掷出了 " << randomNumber << "!" << std::endl;
        } else {
            std::cout << getName() << " 你的大招成功了，你掷出了 " << randomNumber << "!" << std::endl;
            target.setHP(0);
        }
        setCountUlt(1);
    }
}
