#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructor for the Game class.
Game::Game() {
    srand(time(nullptr));
    initializePlayers();
    skillCooldownTimer.start(2);
    ultimateCooldownTimer.start(4);
}

// Destructor for the Game class.
Game::~Game() {
    delete player;
    delete computer;
}

// Initialize player characters based on user choice and random computer character.
void Game::initializePlayers() {
    int choice;
    std::cout << "Please choose your role: 1. Warrior 2. Assassin 3. Mage 4. Tank" << std::endl;
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
            std::cout << "Unidentifiable choice" << std::endl;
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

    std::cout << "You chose " << player->getName() << " and the computer chose " << computer->getName() << std::endl;
    std::cout << "Your stats: " << player->getHP() << " (HP), " << player->getAttack() << " (Attack), " << player->getMana() << " (Mana), " << player->getSkillCost() << " (Mana cost)." << std::endl;
}

// Start the game's main loop.
void Game::playRound() {
    while (player->getHP() > 0 && computer->getHP() > 0) {
        int operation;
        bool validOperation;
        do {
            validOperation = true;
            std::cout << "Please choose your action: 1. Attack 2. Skill attack 3. Ultimate 4. Check stats" << std::endl;
            std::cin >> operation;

            if (operation == 2 && player->getMana() < player->getSkillCost()) {
                std::cout << "Not enough mana, unable to use the skill!" << std::endl;
                validOperation = false;
            } else if (operation != 1 && operation != 2 && operation != 3 && operation != 4) {
                std::cout << "Unidentified action" << std::endl;
                validOperation = false;
            }
        } while (!validOperation);

        if (operation == 1) {
            computer->setHP(computer->getHP() - player->getAttack());
            std::cout << "You have attacked " << computer->getName() << ". Opponent's health: " << computer->getHP() << std::endl;
        } else if (operation == 2) {
            player->skill(*computer);
            std::cout << "You have used a skill to attack " << computer->getName() << ". Opponent's health: " << computer->getHP() << " Your current mana: " << player->getMana() << std::endl;
        } else if (operation == 3) {
            player->ultimate(*computer);
        } else if (operation == 4) {
            std::cout << "Your stats: " << player->getHP() << " (HP), " << player->getAttack() << " (Attack), " << player->getMana() << " (Mana), " << player->getSkillCost() << " (Mana cost)." << std::endl;
        }

        if (computer->getHP() <= 0) {
            std::cout << "You win!" << std::endl;
            break;
        }

        int computerOperation;

        if (computer->getMana() < computer->getSkillCost()) {
            computerOperation = 1;
        } else if (operation == 4) {
            continue;
        } else {
            computerOperation = rand() % 3 + 1;
        }

        if (computerOperation == 1) {
            player->setHP(player->getHP() - computer->getAttack());
            std::cout << "You have been attacked by " << computer->getName() << ". Your health: " << player->getHP() << std::endl;
        } else if (computerOperation == 2) {
            computer->skill(*player);
            std::cout << "You have been skill attacked by " << computer->getName() << ". Your health: " << player->getHP() << std::endl;
        } else if (computerOperation == 3) {
            computer->ultimate(*player);
        }

        if (player->getHP() <= 0) {
            std::cout << "You lost!" << std::endl;
            break;
        }
    }
}
