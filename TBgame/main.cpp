#include <iostream>

#include "Attack/Attack.h"
#include "Attack/Attack.cpp"

#include "Unit/Unit.h"
#include "Unit/Unit.cpp"

#include "Unit/Mage/Mage.h"
#include "Unit/Mage/Mage.cpp"



void debugging_test_1(){
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

    u4.attackVerbous(u3);
    u3.info();
    u3.attackVerbous(u4);
    u4.info();
}


int main(){

    debugging_test_1();


    
    return 0;
}