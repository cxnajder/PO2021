#ifndef UNIT_H_
#define UNIT_H_

#include <string>
#include <vector>
#include <map>

#include "../Attack/Attack.h"



enum class UNIT_CLASSNAME_ { P, M,  R, W};


class Unit{ 
    std::vector<Attack> attks;
    const std::string unit_name;
    const std::string unit_description;
protected:
    UNIT_CLASSNAME_ class_name = UNIT_CLASSNAME_::P;
    int start_hp = 50;
    int hp;
public:
    explicit Unit(
        std::string uname = "The Unnamed",  
        std::string u_descr = "not very talkative",
        std::vector<Attack> a = {
            Attack(1, 5, "basic punch", "The simpliest punch - even your mailman could throw it"),
            Attack(2, 3, "bite", "Uff... there will be scare")
        }
    );
    std::string getClassName() const;
    void info() const;
    std::string getName() const;
    bool isDead() const;
    std::vector<Attack> knownAttacks() const;
    AttkStatus attack(Unit * u);
    void attackVerbous(Unit * u);
};

#endif
