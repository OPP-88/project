#include <iostream>
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
    int skillCost;

    Role(string name, int hp, int mp, int attack, int skillCost)
        : name(name), hp(hp), mp(mp), attack(attack), skillCost(skillCost) {}

    // Virtual function for using a skill.
    virtual void skill(Role& target) {
        if (mp < skillCost) {
            cout << "Not enough mana to use the skill!" << endl;
            return;
        }
        mp -= skillCost;
    }
};

// Warrior class, a subclass of Role.
class Warrior: public Role {
public:
    Warrior(): Role("Warrior", 200, 50, 20, 25) {}

    // Override the skill function for the Warrior class.
    void skill(Role& target) override {
        if (mp < skillCost) {
            cout << "Not enough mana to use the skill!" << endl;
            return;
        }
        Role::skill(target);
        cout << name << " uses a skill to attack " << target.name << "!" << endl;
        target.hp -= 40;
    }
};

// Assassin class, a subclass of Role.
class Assassin: public Role {
public:
    Assassin(): Role("Assassin", 120, 60, 25, 30) {}

    // Override the skill function for the Assassin class.
    void skill(Role& target) override {
        if (mp < skillCost) {
            cout << "Not enough mana to use the skill!" << endl;
            return;
        }
        Role::skill(target);
        cout << name << " uses a skill to attack " << target.name << "!" << endl;
        target.hp -= 50;
    }
};

// Mage class, a subclass of Role.
class Mage: public Role {
public:
    Mage(): Role("Mage", 100, 80, 15, 20) {}

    // Override the skill function for the Mage class.
    void skill(Role& target) override {
        if (mp < skillCost) {
            cout << "Not enough mana to use the skill!" << endl;
            return;
        }
        Role::skill(target);
        cout << name << " uses a skill to attack " << target.name << "!" << endl;
        target.hp -= 45;
    }
};

// Tank class, a subclass of Role.
class Tank: public Role {
public:
    Tank(): Role("Tank", 300, 40, 10, 20) {}

    // Override the skill function for the Tank class.
    void skill(Role& target) override {
        if (mp < skillCost) {
            cout << "Not enough mana to use the skill!" << endl;
            return;
        }
        Role::skill(target);
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

    // Start the game loop.
    void start() {
        while (player->hp > 0 && computer->hp > 0) {
            int operation;
            bool validOperation;
            do {
                validOperation = true;
                cout << "Choose an action: 1. Attack 2. Skill" << endl;
                cin >> operation;
                if (operation == 2 && player->mp < player->skillCost) {
                    cout << "Not enough mana to use the skill!" << endl;
                    validOperation = false;
                } else if (operation != 1 && operation != 2) {
                    cout << "Invalid action" << endl;
                    validOperation = false;
                }
            } while (!validOperation);

            if (operation == 1) {
                cout << player->name << " attacks " << computer->name << "!" << endl;
                computer->hp -= player->attack;
            } else {
                player->skill(*computer);
            }

            if (computer->hp <= 0) {
                cout << "You win!" << endl;
                break;
            }

            int computerOperation = computer->mp < computer->skillCost ? 1 : rand() % 2 + 1;
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

    ~Game() {
        delete player;
        delete computer;
    }
};

int main() {
    Game game;
    game.start();
    return 
