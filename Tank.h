#ifndef TANK
#define TANK
#include "Role.h"      
#include <iostream>     

class Tank : public Role {
public:
    Tank();              // Constructor for the Tank class.
    void skill(Role& target) override;    // Declaration of the skill method.
    void ultimate(Role& target) override; // Declaration of the ultimate method.
};
#endif
