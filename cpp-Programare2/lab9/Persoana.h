#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include <cstring>
#include "Carte.h"

    using namespace std;
    class Persoana {
    public:
        char *nume;
        Persoana();

        Persoana(char *nume);

        Persoana(const Persoana &);

        Persoana& operator =(const Persoana&);

        ~Persoana();

        friend istream & operator>>(istream &, Persoana&);
        friend ostream & operator<<(ostream &, const Persoana&);

        char *scrieReview(const Carte &c, int numarZile);
    };

#endif