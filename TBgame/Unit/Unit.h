#ifndef UNIT_H_
#define UNIT_H_

#include <string>
#include <vector>

#include "../Attack/Attack.h"


class Unit{
    std::vector<Attack> attks;
    const std::string unit_name;
    const std::string unit_description;
protected:
    int start_hp = 50;
    int hp;
    std::string unit_class = "pessant"; 
public:
    explicit Unit(
        std::string uname = "The Unnamed",  
        std::string u_descr = "not very talkative",
        std::vector<Attack> a = {
            Attack(1, 5, "basic punch", "The simpliest punch - even your mother could throw it"),
            Attack(2, 3, "bite", "Uff... there will be scare")
        }
    );
    void info() const;
    std::string getName() const;
    bool isDead() const;
    std::vector<Attack> knownAttacks() const;
    AttkStatus attack(Unit & u);
    void attackVerbous(Unit & u);
};

#endif
