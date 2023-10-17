#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Role class representing a character in the game.
class Role {
public:
    string name;
    int hp;
    int mp;
    int attack;

    Role(string name, int hp, int mp, int attack): name(name), hp(hp), mp(mp), attack(attack) {}

    virtual void skill(Role& target) = 0;
};

// Warrior class, a subclass of Role.
class Warrior: public Role {
public:
    Warrior(): Role("Warrior", 100, 50, 20) {}

    void skill(Role& target) override {
        cout << name << " uses a skill to attack " << target.name << "!" << endl;
        target.hp -= 40;
    }
};

// Assassin class, a subclass of Role.
class Assassin: public Role {
public:
    Assassin(): Role("Assassin", 80, 60, 25) {}

    void skill(Role& target) override {
        cout << name << " uses a skill to attack " << target.name << "!" << endl;
        target.hp -= 50;
    }
};

// Mage class, a subclass of Role.
class Mage: public Role {
public:
    Mage(): Role("Mage", 70, 80, 15) {}

    void skill(Role& target) override {
        cout << name << " uses a skill to attack " << target.name << "!" << endl;
        target.hp -= 45;
    }
};

// Tank class, a subclass of Role.
class Tank: public Role {
public:
    Tank(): Role("Tank", 120, 40, 10) {}

    void skill(Role& target) override {
        cout << name << " uses a skill to attack " << target.name << "!" << endl;
        target.hp -= 30;
    }
};

// Game class for controlling the game flow.
class Game {
public:
    Role* player;
    Role* computer;

    Game() {
        srand(time(nullptr));
        int choice;
        cout << "Choose your class: 1. Warrior 2. Assassin 3. Mage 4. Tank" << endl;
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
            cout << "Invalid choice. Exiting the game." << endl;
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

        cout << "You chose " << player->name << ", and the computer chose " << computer->name << endl;
    }

    void start() {
        while (player->hp > 0 && computer->hp > 0) {
            cout << "Choose an action: 1. Attack 2. Skill" << endl;
            int operation;
            cin >> operation;
            switch (operation) {
            case 1:
                cout << player->name << " attacks " << computer->name << "!" << endl;
                computer->hp -= player->attack;
                break;
            case 2:
                player->skill(*computer);
                break;
            default:
                cout << "Invalid action" << endl;
                continue;
            }

            if (computer->hp <= 0) {
                cout << "You win!" << endl;
                break;
            }

            int computerOperation = rand() % 2 + 1;
            if (computerOperation == 1) {
                cout << computer->name << " attacks " << player->name << "!" << endl;
                player->hp -= computer->attack;
            } else {
                computer->skill(*player);
            }

            if (player->hp <= 0) {
                cout << "You lose!" << endl;
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
