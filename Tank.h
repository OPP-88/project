#ifndef TANK
#define TANK
#include "Role.h"
#include <iostream>
class Tank : public Role {
public:
    Tank();
    void skill(Role& target) override;
    void ultimate(Role& target) override;
};
#endif
