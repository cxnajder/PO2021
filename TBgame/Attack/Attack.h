#ifndef ATTACK_H_
#define ATTACK_H_

#include <string>

class AttkStatus {
    public:
    int deltDmg;
    std::string attkName;
};


class Attack {
    int min_dmg;
    int max_dmg;
    std::string attk_name;
    std::string attk_description;
public:
    Attack(int min_d, int max_d, std::string name, std::string descr);
    void info() const;
    std::string getName() const;
    int use() const;

};

#endif