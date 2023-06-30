#include <iostream>
#include <utility>

#include "Attack/Attack.h"
#include "Attack/Attack.cpp"

#include "Unit/Unit.h"
#include "Unit/Unit.cpp"

#include "Unit/Mage/Mage.h"
#include "Unit/Mage/Mage.cpp"

#include "Unit/Ranger/Ranger.h"
#include "Unit/Ranger/Ranger.cpp"

#include "Unit/Warrior/Warrior.h"
#include "Unit/Warrior/Warrior.cpp"


//TODO:
//do a factory: "ChampSelect"
//TB game with units
//teams of units ?


void duel (Unit * attacker, Unit * opponent) {
    Unit * buffer;
    attacker->info();
    opponent->info();
    while (attacker->isAlive() && opponent->isAlive())
    {
        attacker->attackVerbous(opponent);
        opponent->info();
        if (opponent->isDead()){
            std::cout<<"THE WINNER IS <"<<attacker->getClassName()<<" "<<attacker->getName()<<"> !!!\n";
            break;
        }
        buffer = attacker;
        attacker = opponent;
        opponent = buffer;
    }

}

int main(){

    Ranger r1("Robin Hood");
    Mage m1("Baltazar", "mage of destruction");
    
    duel(&r1, &m1);
    
    return 0;
}