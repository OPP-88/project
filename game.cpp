#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game() {
    srand(time(nullptr));
    initializePlayers();
    skillCooldownTimer.start(2);      // 设置技能冷却时间为5秒
    ultimateCooldownTimer.start(4);  // 设置大招冷却时间为10秒
}

Game::~Game() {
    delete player;
    delete computer;
}

void Game::initializePlayers() {
    int choice;
    std::cout << "请选择职业: 1.战士 2.刺客 3.法师 4.坦克" << std::endl;
    std::cin >> choice;

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

    std::cout << "您选择了 " << player->getName() << "，电脑选择了 " << computer->getName() << std::endl;
}

void Game::playRound() {
    while (player->getHP() > 0 && computer->getHP() > 0) {
        int operation;
        bool validOperation;

        do {
            validOperation = true;
            std::cout << "请选择操作：1.进攻 2.技能 3.大招" << std::endl;
            std::cin >> operation;

            if (operation == 2 && player->getMana() < player->getSkillCost()) {
                std::cout << "蓝量不足，无法使用技能！" << std::endl;
                validOperation = false;
            } else if (operation != 1 && operation != 2 && operation != 3) {
                std::cout << "无效的操作" << std::endl;
                validOperation = false;
            }
        } while (!validOperation);

        if (operation == 1) {
            std::cout << player->getName() << " 攻击 " << computer->getName() << "!" << std::endl;
            computer->setHP(computer->getHP() - player->getAttack());
        } else if (operation == 2) {
            player->skill(*computer);
        } else if (operation == 3) {
            player->ultimate(*computer);
        }

        if (computer->getHP() <= 0) {
            std::cout << "您赢了！" << std::endl;
            break;
        }

        int computerOperation;

        if (computer->getMana() < computer->getSkillCost()) {
            computerOperation = 1;
        } else {
            computerOperation = rand() % 2 + 1;
        }

        if (computerOperation == 1) {
            std::cout << computer->getName() << " 攻击 " << player->getName() << "!" << std::endl;
            player->setHP(player->getHP() - computer->getAttack());
        } else if (computerOperation == 2) {
            computer->skill(*player);
        } else if (computerOperation == 3) {
            computer->ultimate(*player);
        }

        if (player->getHP() <= 0) {
            std::cout << "您输了！" << std::endl;
            break;
        }
    }
}
