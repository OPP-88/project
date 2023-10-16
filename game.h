#ifndef GAME_H
#define GAME_H

#include "Role.h"
#include "warrior_timer.h"
#include "assassin_timer.h"
#include "mage_timer.h"
#include "tank_timer.h"
#include <cstdlib>
#include <ctime>
#include <iostream>



class Game {
public:
    Role* player;
    Role* computer;

    Game();
    ~Game();

    void playRound();

private:
    void initializePlayers();
    Timer skillCooldownTimer;
    Timer ultimateCooldownTimer;
};


#endif
