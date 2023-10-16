#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game() {
    srand(time(nullptr));
    initializePlayers();
    skillCooldownTimer.start(2);    
    ultimateCooldownTimer.start(4);  
}

Game::~Game() {
    delete player;
    delete computer;
}

void Game::initializePlayers() {
    int choice;
    std::cout << "please chose your role: 1.Warrior 2.Assassin 3.Mage 4.Tank" << std::endl;
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
            std::cout << "not identiable choice, game quit" << std::endl;
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

    std::cout << "you chose " << player->getName() << "，computer chose " << computer->getName() << std::endl;
}

void Game::playRound() {
    while (player->getHP() > 0 && computer->getHP() > 0) {
        int operation;
        bool validOperation;

        do {
            validOperation = true;
            std::cout << "please chose your action : 1.attack 2.skill attack 3.ultimate" << std::endl;
            std::cin >> operation;

            if (operation == 2 && player->getMana() < player->getSkillCost()) {
                std::cout << "mana not enough，not able to use skill！" << std::endl;
                validOperation = false;
            } else if (operation != 1 && operation != 2 && operation != 3) {
                std::cout << "undentified movement" << std::endl;
                validOperation = false;
            }
        } while (!validOperation);

        if (operation == 1) {
            computer->setHP(computer->getHP() - player->getAttack());
            std::cout <<"you have Attack " << computer->getName() <<"  opponent health: "<< computer ->getHP() << std::endl;
        } else if (operation == 2) {
            player->skill(*computer);
            std::cout <<"you have use skill Attack " << computer->getName() <<"  opponent health: "<< computer ->getHP() << "  your current mana: "<<player->getMana()<<std::endl;
        } else if (operation == 3) {
            player->ultimate(*computer);
        }

        if (computer->getHP() <= 0) {
            std::cout << "you win！" << std::endl;
            break;
        }

        int computerOperation;

        if (computer->getMana() < computer->getSkillCost()) {
            computerOperation = 1;
        } else  {
            computerOperation = rand() % 3 + 1;
        }

        if (computerOperation == 1) {
            player->setHP(player->getHP() - computer->getAttack());
            std::cout <<"you have been Attacked by " << computer->getName() <<"  your health: "<< player ->getHP() << std::endl;
        } else if (computerOperation == 2) {
            computer->skill(*player);
            std::cout <<"you have been skill Attacked by " << computer->getName() <<"  your health: "<< player ->getHP()<<std::endl;
        } else if (computerOperation == 3) {
            computer->ultimate(*player);
        }

        if (player->getHP() <= 0) {
            std::cout << "you lost！" << std::endl;
            break;
        }
    }
}
