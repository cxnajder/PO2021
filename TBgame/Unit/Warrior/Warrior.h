#ifndef WARRIOR_H_
#define WARRIOR_H_

#include "../Unit.h"
#include "../Unit.cpp"

class Warrior: public Unit
{
public:
    explicit Warrior(
        std::string uname = "The Unnamed",  
        std::string u_descr = "not very talkative",
        std::vector<Attack> a = {
            Attack(50,60,"AXE SWING",   "U better duck..."),
            Attack(10,20,"SHIELD BASH", "MOVEEE!"),
            Attack( 5,10,"HEAD BUMP",   "ouch...")
        }
    );
};

#endif