#include "Plansza.h"
#include <iostream>

Plansza::Plansza(int rozmiar){
    for(int i = 0; i < rozmiar; ++i){
        kreski.push_back(1+i*2);
    }
}
Plansza::Plansza(): Plansza::Plansza(4) {}

void Plansza::wyswietl() const
{
    for(size_t wiersz = 0; wiersz < kreski.size(); ++wiersz)
    {
        std::cout<<wiersz+1<<": ";
        for(int i =0; i < kreski[wiersz]; ++i)
        {
            std::cout<<"|";
        }
        std::cout<<std::endl;
    }
    std::cout << "----------------" << std::endl;
/*
    for(auto wiersz: kreski)
    {
        for(int i =0; i < wiersz; ++i)
        {
            std::cout<<"|";
        }
        std::cout<<std::endl;
    }
*/

}

bool Plansza::czyKonec() const
{
    for (auto wiersz: kreski)
    {
        if (wiersz > 0) return false;
    }
    return true;
}

bool Plansza::skresl(int wiersz, int ile)
{ 
    // zaczynamy od sprawdzenia parametrow wywolania
    if (wiersz < 1 || static_cast<size_t>(wiersz) > kreski.size()) return false; //wiersz {1,2,3,..., kreski.size()}
    if (ile < 1 || ile > kreski[wiersz-1]) return false;  //ile {1,..., max l. kresek}

    kreski[wiersz-1] = kreski[wiersz-1] - ile;
    return true;
}


void Plansza::czyscPlansze()
{
    for(size_t i = 0; i < kreski.size(); ++i)
    {
        kreski[i] = (1+i*2);
    }
}