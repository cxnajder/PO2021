#ifndef ATTACK_CPP_
#define ATTACK_CPP_

#include "Attack.h"
#include <iostream>
#include <cstdlib>

Attack::Attack(int min_d, int max_d, std::string name, std::string descr): 
    min_dmg(min_d), 
    max_dmg(max_d)
{
    attk_name = name;
    attk_description = descr;
}
void Attack::info() const {

    std::string x = ":";

    std::cout<<x<<"ATTK Name : "<<attk_name<<"\n";
    std::cout<<x<<"ATTK Descr: "<<attk_description<<"\n";
    std::cout<<x<<"ATTK Range: "<<min_dmg<<" - "<<max_dmg<<"\n";
    std::cout<<"\n";
}
std::string Attack::getName() const { return attk_name; }
int Attack::use() const {
    int totllyRandomNumber = (std::rand() % (max_dmg - min_dmg + 1)) + min_dmg;
    return totllyRandomNumber;
}

#endif