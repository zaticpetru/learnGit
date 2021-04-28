#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <cstring>

using namespace std;

    class Carte{
        char *autor = nullptr;

        public:
            char *titlu = nullptr;
            Carte(char * = nullptr, char * = nullptr);

            Carte(const Carte &);

            ~Carte();

            Carte &operator=(const Carte &);

            friend istream &operator>>(istream &, Carte &);

            friend ostream &operator<<(ostream &, Carte &);
    };
#endif  