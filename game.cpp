#include "Game.h"
using namespace std;
Game::Game() {
    srand(time(nullptr));
    initializePlayers();
}

Game::~Game() {
    delete player;
    delete computer;
}

void Game::initializePlayers() {
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
            std::cout << "无效的选择，游戏退出" << std::endl;
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

    cout << "您选择了 " << player->getName() << "，电脑选择了 " << computer->getName() <<endl;
}

void Game::playRound() {while (player->getHP() > 0 && computer->getHP() > 0) {
            int operation;
            bool validOperation;
            do {
                validOperation = true;
                cout << "请选择操作：1.进攻 2.技能 3.大招" << endl;
                cin >> operation;
                if (operation == 2 && player->getMana() < player->getSkillCost()) {
                    cout << "蓝量不足，无法使用技能！" << endl;
                    validOperation = false;
                } else if (operation != 1 && operation != 2) {
                    cout << "无效的操作" << endl;
                    validOperation = false;
                } else if (operation == 3 && )
            } while (!validOperation);

            if (operation == 1) {
                cout << player->getName() << " 攻击 " << computer->getName() << "!" << endl;
                computer->getHP() -= player->getAttack();
            } else {
                player->skill(*computer);
            }

            if (computer->getHP() <= 0) {
                cout << "您赢了！" << endl;
                break;
            }

            int computerOperation = computer->getMana() < computer->getSkillCost() ? 1 : rand() % 2 + 1;
            if (computerOperation == 1) {
                cout << computer->getName() << " 攻击 " << player->getName() << "!" << endl;
                player->getHP() -= computer->getAttack();
            } else {
                computer->skill(*player);
            }

            if (player->getHP() <= 0) {
                cout << "您输了！" << endl;
                break;
            }
        }
}
