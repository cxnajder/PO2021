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
    std::cout<<x<<"UNIT Class : "<<getClassName()<<"\n";
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
AttkStatus Unit::attack(Unit * u) {
    AttkStatus s;
    if (this->isDead()==true){
        s.deltDmg = 0;
        s.attkName = "nothing (is dead)";
        return s;
    }
    int totllyRandomNumber = std::rand() % attks.size();
    s.deltDmg = attks.at(totllyRandomNumber).use();
    s.attkName = attks.at(totllyRandomNumber).getName();

    if ( u->hp <= s.deltDmg ){ 
        u->hp = 0; 
    }else{
        u->hp -= s.deltDmg;
    }

    return s;
}
void Unit::attackVerbous(Unit * u){
    AttkStatus move_status = attack(u);
    std::cout<<"<"<<getClassName()<<" "<<unit_name<<"> attaks <"<<u->getClassName()<<" "<<u->unit_name<<"> with ["<<move_status.attkName<<"] dealing {"<<move_status.deltDmg<<" dmg}\n";
}

std::string Unit::getClassName() const{
    static std::map<UNIT_CLASSNAME_, std::string> ClassNameMap{
        {UNIT_CLASSNAME_::P, "pessant"},
        {UNIT_CLASSNAME_::M, "mage"},
        {UNIT_CLASSNAME_::R, "ranger"},
        {UNIT_CLASSNAME_::W, "warrior"},
    };

    auto record = ClassNameMap.find(class_name);
    if (record != ClassNameMap.end()) {
        return record->second;
    }
    
    return "unknown";
}
#endif