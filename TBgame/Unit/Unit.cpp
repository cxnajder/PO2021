#ifndef UNIT_CPP_
#define UNIT_CPP_


#include <iostream>
#include <cstdlib>

#include "Unit.h"


Unit::Unit(std::string uname, std::string u_descr, std::vector<Attack> a):
    attks(a), unit_name(uname), unit_description(u_descr)
{ 
    hp = start_hp;
}

void Unit::info() const{

    std::string frame = "";
    int frame_len = 20;
    char frame_char = '.';
    for  (int i = 0; i < frame_len; ++i){
        frame += frame_char;
    }

    std::cout<<frame<<"\n";

    std::string  x = "";

    std::cout<<x<<"UNIT Name  : "<<unit_name<<"\n";
    std::cout<<x<<"UNIT Descr : "<<unit_description<<"\n";
    std::cout<<x<<"UNIT Class : "<<unit_class<<"\n";
    std::cout<<x<<"UNIT HP    : "<<hp<<" / "<<start_hp<<"\n";
    std::cout<<x<<"UNIT Attks : \n";

    for  (int i = 0; i < attks.size(); ++i){

        
        attks.at(i).info();
    }

}
std::string Unit::getName() const { return unit_name; }
bool Unit::isDead() const {
    if ( hp < 1 ) { return true; }
    return false;
}
std::vector<Attack> Unit::knownAttacks() const{
    return attks;
}
AttkStatus Unit::attack(Unit & u) {
    AttkStatus s;
    int totllyRandomNumber = std::rand() % attks.size();
    s.deltDmg = attks.at(totllyRandomNumber).use();
    s.attkName = attks.at(totllyRandomNumber).getName();

    u.hp -= s.deltDmg;

    return s;
}
void Unit::attackVerbous(Unit & u){
    AttkStatus move_status = attack(u);
    std::cout<<"<"<<unit_class<<" "<<unit_name<<"> attaks <"<<u.unit_class<<" "<<u.unit_name<<"> with ["<<move_status.attkName<<"] dealing {"<<move_status.deltDmg<<" dmg}\n";
}

#endif