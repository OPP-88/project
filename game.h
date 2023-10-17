#ifndef GAME_H
#define GAME_H

#include "warrior_timer.h"   
#include "assassin_timer.h" 
#include "mage_timer.h"     
#include "tank_timer.h"     
#include <cstdlib>           // Include the standard library for utility functions.
#include <ctime>             // Include the standard library for time functions.
#include <iostream>        

class Game {
public:
    Role* player;            // Pointer to the player's role.
    Role* computer;          // Pointer to the computer's role.

    Game();                  // Constructor for the Game class.
    ~Game();                 // Destructor for the Game class.

    void playRound();        // Method to play a round of the game.

private:
    void initializePlayers(); // Method to initialize player roles.
    Timer skillCooldownTimer;   // Timer for tracking skill cooldown.
    Timer ultimateCooldownTimer; // Timer for tracking ultimate ability cooldown.
};

#endif
