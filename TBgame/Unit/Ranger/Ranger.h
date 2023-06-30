#ifndef RANGER_H_
#define RANGER_H_

#include "../Unit.h"
#include "../Unit.cpp"

class Ranger: public Unit
{
public:
    explicit Ranger(
        std::string uname = "The Unnamed",  
        std::string u_descr = "not very talkative",
        std::vector<Attack> a = {
            Attack(40,50,"SILVER BOLT", "Good for Werwolfs and stuff")
        }
    );
};

#endif