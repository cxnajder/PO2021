#include "Gra.h"
#include "Plansza.h"
#include "Gracz.h"

#include<iostream>
#include <utility>

Gra::Gra(std::vector<Gracz> & lista_graczy): gracze(lista_graczy)
{nr_gracza_z_ruchem=0;}

void Gra::rozpocznij()
{
    plansza.czyscPlansze();

    do
    {
        plansza.wyswietl();

        std::cout << "Ruch wykonuje : " << gracze.at(nr_gracza_z_ruchem).nazwa() << std::endl;
        
        bool prawidlowy_ruch = false;
        while (prawidlowy_ruch != true)
        {
            std::pair<int,int> wybor = gracze.at(nr_gracza_z_ruchem).wybierzRuch();
            prawidlowy_ruch = plansza.skresl(wybor.first, wybor.second);
            if(prawidlowy_ruch != true) { std::cout << "Nieprawidlowy ruch, sproboj jeszcze raz" << std::endl; }
        }
        if(plansza.czyKonec() == false) {
            nr_gracza_z_ruchem += 1;
            if(nr_gracza_z_ruchem == gracze.size()) {nr_gracza_z_ruchem=0;}
        }
    } while (plansza.czyKonec() == false);

    std::cout << "Wygrywa : " << gracze.at(nr_gracza_z_ruchem).nazwa() << std::endl;
    gracze.at(nr_gracza_z_ruchem).zwiekszWygrana();
    wyswietlWyniki();
}

void Gra::wyswietlWyniki() const 
{
    std::cout << "----------------------" <<std::endl;

    for (auto g: gracze){
        std::cout << g.nazwa() << " - wygrane : " << g.ileWygranych() <<std::endl;

        std::cout << "----------------------" <<std::endl;
    }
}

void Gra::menu()
{
    int wybor = 3;

    do
    {
        std::cout << "1. graj" <<std::endl;
        std::cout << "2. wyniki" <<std::endl;
        std::cout << "3. przerwij" <<std::endl;

        std::cin >> wybor;

        switch (wybor)
        {
        case 1:
            rozpocznij();
            break;
        case 2:
            wyswietlWyniki();
            break;
        default:
            wybor = 3;
            break;
        }
    } while (wybor != 3);
}