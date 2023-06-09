#ifndef GRA_H_
#define GRA_H_

#include "Plansza.h"
#include "Gracz.h"
#include <vector>
#include <string>

class Gra {
    Plansza plansza;
    std::vector<Gracz> & gracze;
    int nr_gracza_z_ruchem;

    //dwoch graczy 
    //wskaznik na gracza wykonujacego ruch?
public:
    Gra(std::vector<Gracz> & lista_graczy);
    void rozpocznij();
    void wyswietlWyniki() const;
    void menu();
};

#endif