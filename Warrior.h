#ifndef WARRIOR_H
#define WARRIOR_H

#include "Role.h"     

class Warrior : public Role {
public:
    Warrior();              // Constructor for the Warrior class.
    void skill(Role& target) override;    // Declaration of the skill method.
    void ultimate(Role& target) override; // Declaration of the ultimate method.
};
#endif
