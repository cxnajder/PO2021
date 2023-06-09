#ifndef PLANSZA_H_
#define PLANSZA_H_

#include <vector>

class Plansza {
    //int kreski[4];
    //std::arresy<int, 4> kreski;
    std::vector<int> kreski;

public:
    explicit Plansza(int rozmiar);
    Plansza();
    void wyswietl() const;
    bool czyKonec() const;
    bool skresl(int wiersz, int ile);
    void czyscPlansze();
};

#endif