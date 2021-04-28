#include "Carte.h"
#include "Persoana.h"
#include <iostream>


int main()
{
    Carte c;
    cin >> c;

    cout << c;

    Persoana p("test");

    cout << p.scrieReview(c,10);
}
