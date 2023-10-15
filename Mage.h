#ifndef MAGE_H
#define MAGE_H

#include "Role.h"
#include <iostream>

class Mage : public Role {
public:
    Mage();
    void skill(Role& target) override;
    void ultimate(Role& target) override;
};

#endif
