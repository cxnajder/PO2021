#ifndef RANGER_CPP_
#define RANGER_CPP_

#include "Ranger.h"

Ranger::Ranger(std::string uname, std::string u_descr, std::vector<Attack> a): Unit(uname, u_descr, a)
{
    start_hp = 100;
    hp = start_hp;
    class_name = UNIT_CLASSNAME_::R;
}

#endif