#ifndef GAME_H
#define GAME_H

#include "warrior_timer.h"
#include "assassin_timer.h"
#include "mage_timer.h"
#include "tank_timer.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Game {
public:
    Role* player; // Player character pointer
    Role* computer; // Computer character pointer

    Game(); // Constructor to initialize the game
    ~Game(); // Destructor to clean up memory

    void playRound(); // Main game loop function

private:
    void initializePlayers(); // Initialize player characters
    Timer skillCooldownTimer; // Timer for skill cooldown
    Timer ultimateCooldownTimer; // Timer for ultimate cooldown
};

#endif
