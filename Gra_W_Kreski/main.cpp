/*
PLANSZA:
przechowuje kreski;
wyświrtla plansze;
pozwala wykonac ruch;
zwraca czy gra sie skoczyla;

GRACZ: /zaleznosc od Planszy
ma nickname;
wykonuje ruch / skresla kreske;

GRA: /zaleznosc od Gracza i Planszy
przechowuje graczy i plansze;
decyduje czyj ruch;
zwraca kto wygral;

*/

#include <iostream>
#include <cassert>
#include <vector>
#include "Plansza.h"
#include "Plansza.cpp"
#include "Gracz.h"
#include "Gracz.cpp"
#include "Gra.h"
#include "Gra.cpp"

void testPlanszy()
{
    // debugging / testing

    std::cout<<"DEBUGGING / TEST PLANSZY"<<std::endl;
    Plansza p;

    std::cout<<"czysta plansza startowa"<<std::endl;
    p.wyswietl(); 
    assert(p.czyKonec() == false); 

    p.skresl(1,1); 

    std::cout<<"plansza bez pierwszego rzedu"<<std::endl;
    p.wyswietl();

    assert(p.skresl(-1, 1) == false);
    assert(p.skresl(999,1) == false);
    assert(p.skresl(2, -1) == false);
    assert(p.skresl(2,  0) == false);
    assert(p.skresl(2,100) == false);

    std::cout<<"plansza bez zmian"<<std::endl;
    p.wyswietl(); 
    
    p.skresl(2,3); 
    p.skresl(3,5); 
    p.skresl(4,7); 

    std::cout<<"plansza bez czterech pierwszych rzedow"<<std::endl;
    p.wyswietl(); 
    assert(p.czyKonec() == true);
}

void testGracza()
{

    std::cout<<"DEBUGGING / TEST GRACZA"<<std::endl;

    std::cout<<"Nick gracz nr 1 : ";
    Gracz g1;
    std::cout<<g1.nazwa()<<std::endl;

    std::cout<<"Wyswietlanie i zwiekszanie wygranych"<<std::endl;
    std::cout<<g1.ileWygranych()<<std::endl;
    assert(g1.ileWygranych()==0);
    g1.zwiekszWygrana();

    std::cout<<g1.ileWygranych()<<std::endl;
    assert(g1.ileWygranych()==1);
    g1.zwiekszWygrana();

    std::cout<<g1.ileWygranych()<<std::endl;
    assert(g1.ileWygranych()==2);

    std::cout<<"Nick gracz nr 2 : ";
    Gracz g2;
    std::cout<<g2.nazwa()<<std::endl;

    std::cout<<"Nick gracz nr 3 : ";
    Gracz g3("cxnajder");
    std::cout<<g3.nazwa()<<std::endl;
}

void testGry() {
    Gracz gracz1, gracz2;

    std::vector<Gracz> gracze;
    gracze.push_back(gracz1);
    gracze.push_back(gracz2);

    Gra gra1(gracze);

    //gra1.rozpocznij();
    gra1.menu();
}

int main() 
{
    testGry();
    //testPlanszy();
    //testGracza();

    return 0;
}