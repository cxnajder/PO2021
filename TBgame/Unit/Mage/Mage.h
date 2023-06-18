#ifndef MAGE_H_
#define MAGE_H_

#include "../Unit.h"
#include "../Unit.cpp"

class Mage: public Unit
{
public:
    explicit Mage(
        std::string uname = "The Unnamed",  
        std::string u_descr = "not very talkative",
        std::vector<Attack> a = {
            Attack(9,99,"FIRE BALL", "HOLLY SHIT IM ON FIRE...")
        }
    );
};

#endif
