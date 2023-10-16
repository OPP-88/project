#include "tank_timer.h"
#include "timer.h"
#include <iostream>
#include <cmath>

Tank::Tank() : Role("坦克", 300, 40, 10, 20) {
    ultimateTimer = Timer();
    ultimateTimer.start(16); // 设置大招计时器的持续时间，单位为秒
}

void Tank::skill(Role& target) {
    if (getMana() < getSkillCost()) {
        std::cout << "蓝量不足，无法使用技能！" << std::endl;
        return;
    }
    Role::skill(target);
    std::cout << getName() << " 使用技能攻击 " << target.getName() << "!" << std::endl;
    target.setHP(target.getHP() - 45);
}

void Tank::ultimate(Role& target) {
    if (!ultimateTimer.isTimeUp()) {
        std::cout << "大招无法现在使用，请在计时结束后释放!" << std::endl;
    } else if (getCountUlt() == 1) {
        std::cout << "大招已经被使用了!" << std::endl;
    } else {
        Role::ultimate(target);
        std::cout << getName() << " 使用大招!" << std::endl;

        // 大招的逻辑，根据你提供的代码来实现
        target.setHP(std::ceil(target.getHP() * 0.2));
        target.setAttack(target.getAttack() * 3);
        setCountUlt(1);
    }
}

void Tank::update() {
    ultimateTimer.update();
}
