#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "Role.h"          
#include <iostream>        
#include <cstdlib>         // For random number generation.
#include <ctime>           // For seeding the random number generator.

class Assassin : public Role {
public:
    Assassin();            // Constructor for the Assassin class.

    void skill(Role& target) override;     // Declaration of the skill method.
    void ultimate(Role& target) override;  // Declaration of the ultimate method.
};

#endif
