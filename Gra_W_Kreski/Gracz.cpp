#include "Gracz.h"

#include <iostream>

int Gracz::LiczbaGraczy = 0;

Gracz::Gracz(const std::string & nick) : nickname(nick), nrGracza(LiczbaGraczy+1) {LiczbaGraczy += 1; liczbaWygranych = 0;}
Gracz::Gracz(): Gracz::Gracz("Gracz" + std::to_string(LiczbaGraczy+1)) {}

std::pair<int,int> Gracz::wybierzRuch() const
{
    int wiersz;
    int l_kresek;
    /*
     0. Wyswietl plansze ?? <- wole wyswietlac w grze
     1. Pobrać rzad i liczbe kresek
     2. Sprawdzic czy ruch jest valid // <- to tez niech robi gra!!
        TAK - wykonaj ruch
        NIe - wroc do krok 1.
    */
    std::cout<<"Podaj wiersz i liczbe kresek: ";
    std::cin >> wiersz >> l_kresek;

    return std::make_pair(wiersz, l_kresek);
}

int Gracz::ileWygranych() const {return liczbaWygranych;}
void Gracz::zwiekszWygrana() {liczbaWygranych+=1;}
std::string Gracz::nazwa() const {return nickname;}