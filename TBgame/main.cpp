#include <iostream>
#include <string>
#include <vector>

//class 0 -attack status
class AttkStatus {
    public:
    int deltDmg;
    std::string attkName;
};


//class 1 - attack
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
    int totllyRandomNumber = 15;
    return totllyRandomNumber;
}

//cLass 2 - unit with attack
class Unit{
    std::vector<Attack> attks;
    int start_hp = 100;
    int hp;
    std::string unit_name;
    std::string unit_description;
    std::string unit_class = "pessant"; 
public:
    explicit Unit(
        std::string uname = "The Unnamed",  
        std::string u_descr = "not very talkative",
        std::vector<Attack> a = {Attack(1, 10, "basic punch", "The simpliest punch - even your mother could throw it")}
    );
    void info() const;
    std::string getName() const;
    bool isDead() const;
    std::vector<Attack> knownAttacks() const;
    AttkStatus attack(Unit & u);
    void attackVerbous(Unit & u);
};
Unit::Unit(std::string uname, std::string u_descr, std::vector<Attack> a):
    attks(a)
{ 
    hp = start_hp;
    unit_name = uname; 
    unit_description = u_descr; 
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
    int totllyRandomNumber = attks.size()-1;
    s.deltDmg = attks.at(totllyRandomNumber).use();
    s.attkName = attks.at(totllyRandomNumber).getName();

    u.hp -= s.deltDmg;

    return s;
}
void Unit::attackVerbous(Unit & u){
    AttkStatus move_status = attack(u);
    std::cout<<unit_name<<" "<<unit_class<<" attaks "<<u.unit_name<<" "<<u.unit_class<<" with "<<move_status.attkName<<" dealing "<<move_status.deltDmg<<" dmg.\n";
}


//Class 3 - Team of units

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

    std::vector<Attack> a = {a1};
    Unit u4("Baltazar", "MadMage", a);
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