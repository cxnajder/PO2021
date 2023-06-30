#include <iostream>

#include "Attack/Attack.h"
#include "Attack/Attack.cpp"

#include "Unit/Unit.h"
#include "Unit/Unit.cpp"

#include "Unit/Mage/Mage.h"
#include "Unit/Mage/Mage.cpp"
//##########################
#include "Unit/Ranger/Ranger.h"
#include "Unit/Ranger/Ranger.cpp"
//##########################
#include "Unit/Warrior/Warrior.h"
#include "Unit/Warrior/Warrior.cpp"


//TODO:
//do a factory: "ChampSelect"
//TB game with units
//teams of units ?

void debug_test_1(){
    Attack a1(100,110,"FIRE BALL", "HOLLY SHIT IM ON FIRE...");
    a1.info();

    std::cout<<"\n"; 
    
    Unit u1;
    u1.info();

    Unit u2("Billy");
    u2.info();

    Unit u3("Joe", "The Ripper");
    u3.info();

    Mage u4("Baltazar", "MadMage");
    u4.info();

    u4.attackVerbous(&u3);
    u3.info();
    u3.attackVerbous(&u4);
    u4.info();
}

void debug_test_2(){
    Unit p1("Hilly Billy", "likes apples");
    p1.info();

    Mage m1("Gandalf","Pretty old wize man with long grey beard");
    m1.info();

    Ranger r1("Robbin Hood");
    r1.info();

    Warrior w1;
    w1.info();

    w1.attackVerbous(&p1);
    p1.info();

    w1.attackVerbous(&m1);
    m1.info();

    w1.attackVerbous(&r1);
    r1.info();

    w1.attackVerbous(&w1); //should this be allowed ??
    w1.info();
}

int main(){

    //debug_test_1();
    debug_test_2();


    
    return 0;
}