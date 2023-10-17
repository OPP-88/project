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
    // Getter for the name attribute.
    string getName() const {
        return name;
    }

    // Getter for the hp attribute.
    int getHP() const {
        return hp;
    }

    // Getter for the mana attribute.
    int getMana() const {
        return mana;
    }

    // Getter for the attack attribute.
    int getAttack() const {
        return attack;
    }

    // Getter for the skillCost attribute.
    int getSkillCost() const {
        return skillCost;
    }

    // Setter for the hp attribute.
    void setHP(int newHP) {
        hp = newHP;
    }

    // Getter for the countRound attribute.
    int getCountRound() const {
        return countRound;
    }

    // Getter for the countUlt attribute.
    int getCountUlt() const {
        return countUlt;
    }

    // Setter for the countUlt attribute.
    void setCountUlt(int newCountUlt) {
        countUlt = newCountUlt;
    }

    // Setter for the mana attribute.
    void setMana(int newMana) {
        mana = newMana;
    }

    // Setter for the attack attribute.
    void setAttack(int newAttack) {
        attack = newAttack;
    }

    // Constructor for the Role class, initializing attributes.
    Role(string name, int hp, int mana, int attack, int skillCost)
        : name(name), hp(hp), mana(mana), attack(attack), skillCost(skillCost), countRound(0), countUlt(0) {}

    // Virtual method for using a skill.
    virtual void skill(Role& target) {
        if (mana < skillCost) {
            cout << "Not enough mana to use the skill!" << endl;
            return;
        }
        mana -= skillCost;
    }

    // Virtual method for using an ultimate ability.
    virtual void ultimate(Role& target) {
        if (countRound < 3) {
            cout << "Ultimate cannot be used now, please release it after Round 3!" << endl;
        } else if (countUlt == 1) {
            cout << "Ultimate has already been used!" << endl;
        } else {
            countUlt += 1;
        }
    }
};

#endif
