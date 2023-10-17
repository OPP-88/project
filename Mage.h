#ifndef MAGE_H
#define MAGE_H

#include "Role.h"       
#include <iostream>     

class Mage : public Role {
public:
    Mage();             // Constructor for the Mage class.
    void skill(Role& target) override;    // Declaration of the skill method.
    void ultimate(Role& target) override; // Declaration of the ultimate method.
};

#endif
