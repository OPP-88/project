#include "warrior_timer.h"
#include <chrono>

Warrior::Warrior() : Role("战士", 200, 50, 20, 25) {
    lastUltimateTime = std::chrono::steady_clock::now();
}

void Warrior::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "蓝量不足，无法使用技能！" << std::endl;
        return;
    }
    Role::skill(target);
    std::cout << getName() << " 使用技能攻击 " << target.getName() << "!" << std::endl;
    target.setHP(target.getHP() - 40);
}

void Warrior::ultimate(Role& target) {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastUltimateTime);

    if (getCountRound() < 3) {
        std::cout << "大招无法现在使用, 请在第3回合之后释放!" << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "大招已经被使用了!" << std::endl;
    } else if (elapsed.count() < 12) { // 12 秒冷却时间
        std::cout << "大招还在冷却中，请等待 " << 12 - elapsed.count() << " 秒后释放!" << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << " 使用大招 " << target.getName() << "!" << std::endl;
        target.setMana(0);
        setCountUlt(1);
        lastUltimateTime = currentTime;
    }
}
