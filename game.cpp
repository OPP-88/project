#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game() {
    // Seed the random number generator with the current time
    srand(time(nullptr));

    // Initialize players and set cooldown timers
    initializePlayers();
    skillCooldownTimer.start(2);
    ultimateCooldownTimer.start(4);
}

// Destructor
Game::~Game() {
    // Clean up dynamically allocated player and computer objects
    delete player;
    delete computer;
}

// Player initialization method
void Game::initializePlayers() {
    int choice;

    // Prompt the user to choose a role
    std::cout << "Please choose your role: 1.Warrior 2.Assassin 3.Mage 4.Tank" << std::endl;
    std::cin >> choice;

    // Create player object based on user's choice
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
            // Handle invalid choice
            std::cout << "Not identifiable choice" << std::endl;
            exit(0);
    }

    // Randomly choose a role for the computer
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

    // Display chosen roles and player stats
    std::cout << "You chose " << player->getName() << ", computer chose " << computer->getName() << std::endl;
    std::cout << "Your stats: " << player->getHP() << "(HP), " << player->getAttack() << "(attack), "
              << player->getMana() << "(Mana), " << player->getSkillCost() << "(mana cost)." << std::endl;
}

// Method to play a round of the game
void Game::playRound() {
    while (player->getHP() > 0 && computer->getHP() > 0) {
        int operation;
        bool validOperation;

        // Get player's action choice
        do {
            validOperation = true;
            std::cout << "Please choose your action: 1.attack 2.skill attack 3.ultimate 4.check stat" << std::endl;
            std::cin >> operation;

            // Validate input
            if (operation == 2 && player->getMana() < player->getSkillCost()) {
                std::cout << "Mana not enough, not able to use skill!" << std::endl;
                validOperation = false;
            } else if (operation != 1 && operation != 2 && operation != 3 && operation != 4) {
                std::cout << "Unidentified movement" << std::endl;
                validOperation = false;
                return;
            }
        } while (!validOperation);

        // Execute player's chosen action
        if (operation == 1) {
            computer->setHP(computer->getHP() - player->getAttack());
            std::cout << "You have attacked " << computer->getName() << ". Opponent health: " << computer->getHP() << std::endl;
        } else if (operation == 2) {
            player->skill(*computer);
            std::cout << "You have used skill attack on " << computer->getName() << ". Opponent health: " << computer->getHP()
                      << " Your current mana: " << player->getMana() << std::endl;
        } else if (operation == 3) {
            player->ultimate(*computer);
        } else if (operation == 4) {
            std::cout << "Your stats: " << player->getHP() << "(HP), " << player->getAttack() << "(attack), "
                      << player->getMana() << "(Mana), " << player->getSkillCost() << "(mana cost)." << std::endl;
        }

        // Check if player won
        if (computer->getHP() <= 0) {
            std::cout << "You win!" << std::endl;
            break;
        }

        int computerOperation;

        // Determine computer's action
        if (computer->getMana() < computer->getSkillCost()) {
            computerOperation = 1;
        } else if (operation == 4) {
            continue;
        } else {
            computerOperation = rand() % 3 + 1;
        }

        // Execute computer's chosen action
        if (computerOperation == 1) {
            player->setHP(player->getHP() - computer->getAttack());
            std::cout << "You have been attacked by " << computer->getName() << ". Your health: " << player->getHP() << std::endl;
        } else if (computerOperation == 2) {
            computer->skill(*player);
            std::cout << "You have been skill attacked by " << computer->getName() << ". Your health: " << player->getHP() << std::endl;
        } else if (computerOperation == 3) {
            computer->ultimate(*player);
        }

        // Check if player lost
        if (player->getHP() <= 0) {
            std::cout << "You lost!" << std::endl;
            break;
        }
    }
}
