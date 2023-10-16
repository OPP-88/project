#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// 角色
class Role {
public:
    string name;
    int hp;
    int mp;
    int attack;

    Role(string name, int hp, int mp, int attack): name(name), hp(hp), mp(mp), attack(attack) {}

    virtual void skill(Role& target) = 0;
};

// 战士
class Warrior: public Role {
public:
    Warrior(): Role("战士", 100, 50, 20) {}

    void skill(Role& target) override {
        cout << name << " 使用技能攻击 " << target.name << "!" << endl;
        target.hp -= 40;
    }
};

// 刺客
class Assassin: public Role {
public:
    Assassin(): Role("刺客", 80, 60, 25) {}

    void skill(Role& target) override {
        cout << name << " 使用技能攻击 " << target.name << "!" << endl;
        target.hp -= 50;
    }
};

// 法师
class Mage: public Role {
public:
    Mage(): Role("法师", 70, 80, 15) {}

    void skill(Role& target) override {
        cout << name << " 使用技能攻击 " << target.name << "!" << endl;
        target.hp -= 45;
    }
};

// 坦克
class Tank: public Role {
public:
    Tank(): Role("坦克", 120, 40, 10) {}

    void skill(Role& target) override {
        cout << name << " 使用技能攻击 " << target.name << "!" << endl;
        target.hp -= 30;
    }
};

// 游戏
class Game {
public:
    Role* player;
    Role* computer;

    Game() {
        srand(time(nullptr));
        int choice;
        cout << "请选择职业：1.战士 2.刺客 3.法师 4.坦克" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            player = new Warrior();
            break;
        case 2:
            player = new Assassin();
            break;
        case 3:
            player = new Mage();
            break;
        case 4:
            player = new Tank();
            break;
        default:
            cout << "无效的选择，游戏退出" << endl;
            exit(0);
        }

        int computerChoice = rand() % 4 + 1;
        switch (computerChoice) {
        case 1:
            computer = new Warrior();
            break;
        case 2:
            computer = new Assassin();
            break;
        case 3:
            computer = new Mage();
            break;
        case 4:
            computer = new Tank();
            break;
        }

        cout << "您选择了 " << player->name << "，电脑选择了 " << computer->name << endl;
    }

    void start() {
        while (player->hp > 0 && computer->hp > 0) {
            cout << "请选择操作：1.进攻 2.技能" << endl;
            int operation;
            cin >> operation;
            switch (operation) {
            case 1:
                cout << player->name << " 攻击 " << computer->name << "!" << endl;
                computer->hp -= player->attack;
                break;
            case 2:
                player->skill(*computer);
                break;
            default:
                cout << "无效的操作" << endl;
                continue;
            }

            if (computer->hp <= 0) {
                cout << "您赢了！" << endl;
                break;
            }

            int computerOperation = rand() % 2 + 1;
            if (computerOperation == 1) {
                cout << computer->name << " 攻击 " << player->name << "!" << endl;
                player->hp -= computer->attack;
            } else {
                computer->skill(*player);
            }

            if (player->hp <= 0) {
                cout << "您输了！" << endl;
                break;
            }
        }
    }
};

int main() {
    Game game;
    game.start();
    return 0;
}
