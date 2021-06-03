#include <iostream>
#include <cstring>
#include "Carte.h"

using namespace std;

Carte::Carte(char *titlu, char *autor)
{
    if (titlu != nullptr)
    {
        this->titlu = new char[strlen(titlu) + 1];
        strcpy(this->titlu, titlu);
    }
    if (autor != nullptr)
    {
        this->autor = new char[strlen(autor) + 1];
        strcpy(this->autor, autor);
    }
}

Carte::Carte(const Carte &c)
{
    if (titlu != nullptr)
    {
        titlu = new char[strlen(c.titlu) + 1];
        strcpy(titlu, c.titlu);
    }
    if (autor != nullptr)
    {
        autor = new char[strlen(c.autor) + 1];
        strcpy(autor, c.autor);
    }
}

Carte::~Carte()
{
    if (titlu != nullptr)
    {
        delete[] titlu;
    }
    if (autor != nullptr)
    {
        delete[] autor;
    }
}

Carte &Carte::operator=(const Carte &c)
{
    if (this == &c)
        return *this;

    if (this->autor != nullptr)
    {
        delete[] this->autor;
    }
    if (this->titlu != nullptr)
    {
        delete[] this->titlu;
    }

    if (c.titlu != nullptr)
    {
        this->titlu = new char[strlen(c.titlu) + 1];
        strcpy(this->titlu, c.titlu);
    }
    if (c.autor != nullptr)
    {
        this->autor = new char[strlen(c.autor) + 1];
        strcpy(this->autor, c.autor);
    }
    return *this;
}

istream &operator>>(istream &in, Carte &c)
{
    c.titlu = new char[50];
    c.autor = new char[50];
    in >> c.titlu;
    in.ignore();
    in >> c.autor;
    in.ignore();
    return in;
}

ostream &operator<<(ostream &out, Carte &c)
{
    out << c.titlu << endl
        << c.autor;
    return out;
}