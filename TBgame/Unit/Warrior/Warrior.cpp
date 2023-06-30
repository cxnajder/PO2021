#ifndef WARRIOR_CPP_
#define WARRIOR_CPP_

#include "Warrior.h"

Warrior::Warrior(std::string uname, std::string u_descr, std::vector<Attack> a): Unit(uname, u_descr, a)
{
    start_hp = 130;
    hp = start_hp;
    class_name = UNIT_CLASSNAME_::W;
}

#endif