#ifndef GRACZ_H_
#define GRACZ_H_

#include <string>
#include <utility>

class Gracz {

    static int LiczbaGraczy;

    const std::string nickname;
    const int nrGracza;
    int liczbaWygranych;

public:

    explicit Gracz(const std::string & nick);
    Gracz();
    std::pair<int,int> wybierzRuch() const;
    int ileWygranych() const;
    void zwiekszWygrana();
    std::string nazwa() const;

};

#endif