#ifndef ROLE_H
#define ROLE_H

#include <string>
#include <iostream>
#include "timer.h"
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
    Timer ultimateTimer;
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
    void setCountRound(int newCountRound){
        countRound =newCountRound;
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
            cout << "mana not enough, cannot use skill" << endl;
            return;
        }
        mana -= skillCost;
    }

    virtual void ultimate(Role& target) {
        if (!ultimateTimer.isTimeUp()) {
        std::cout << "ultimate is not ready until：" << ultimateTimer.getTimeRemaining() << " seconds" << std::endl;
    }   else if (getCountUlt() == 1) {
        std::cout << "ultimate have been casted already!" << std::endl;
        } else {
            countUlt += 1;
        }
    }
};

#endif
