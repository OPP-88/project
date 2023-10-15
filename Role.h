#ifndef ROLE_H
#define ROLE_H

#include <string>
#include <iostream>

using namespace std;

class Role {
private:
    string name;
    int hp;
    int mana;
    int attack;
    int skillCost;
    int countRound;
    int countUlt;

public:
    string getName() const {
        return name;
    }

    int getHP() const {
        return hp;
    }

    int getMana() const {
        return mana;
    }

    int getAttack() const {
        return attack;
    }

    int getSkillCost() const {
        return skillCost;
    }

    void setHP(int newHP) {
        hp = newHP;
    }

    int getCountRound() const {
        return countRound;
    }

    int getCountUlt() const {
        return countUlt;
    }

    void setCountUlt(int newCountUlt) {
        countUlt = newCountUlt;
    }

    void setMana(int newMana) {
        mana = newMana;
    }

    void setAttack(int newAttack) {
        attack = newAttack;
    }

    Role(string name, int hp, int mana, int attack, int skillCost)
        : name(name), hp(hp), mana(mana), attack(attack), skillCost(skillCost), countRound(0), countUlt(0) {}

    virtual void skill(Role& target) {
        if (mana < skillCost) {
            cout << "蓝量不足，无法使用技能！" << endl;
            return;
        }
        mana -= skillCost;
    }

    virtual void ultimate(Role& target) {
        if (countRound < 3) {
            cout << "大招无法现在使用，请在第3回合之后释放!" << endl;
        } else if (countUlt == 1) {
            cout << "大招已经被使用了!" << endl;
        } else {
            countUlt += 1;
        }
    }
};

#endif

