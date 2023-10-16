#ifndef GAME_H
#define GAME_H

#include "Role.h"
#include "Warrior.h"
#include "Assassin.h"
#include "Mage.h"
#include "Tank.h"
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
};

#endif
