#ifndef WARRIOR_H
#define WARRIOR_H

#include "Role.h"

class Warrior : public Role {
public:
    Warrior();
    void skill(Role& target) override;
    void ultimate(Role& target) override;  
};
#endif 
