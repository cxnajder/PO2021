#ifndef MAGE_CPP_
#define MAGE_CPP_

#include "Mage.h"

Mage::Mage(std::string uname, std::string u_descr, std::vector<Attack> a): Unit(uname, u_descr, a)
{
    start_hp = 80;
    hp = start_hp;
    unit_class = "mage";
}

#endif
