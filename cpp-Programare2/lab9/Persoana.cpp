#include "Persoana.h"
#include <cstring>
#include <sstream>
using namespace std;


Persoana::Persoana() {
    this->nume = nullptr;
}

Persoana::Persoana(char *nume) {
    if(nume) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }
}

Persoana::Persoana(const Persoana &persoana) {
    if(persoana.nume != nullptr) {
        this->nume = new char[strlen(persoana.nume) + 1];
    }
}

Persoana::~Persoana(){
    if(this->nume != nullptr)
        delete[] this->nume;
}

Persoana &Persoana::operator=(const Persoana &persoana) {
    if(&persoana == this){
        return *this;
    }
    if(this->nume != nullptr) {
        delete [] this->nume;
    }
    if(persoana.nume != nullptr) {
        this->nume = new char[strlen(persoana.nume) + 1];
        strcpy(this->nume, persoana.nume);
    }
}

ostream &operator<<(ostream &out, const Persoana &persoana) {
    out << persoana.nume << "\n";
}

istream &operator>>(istream &in, Persoana &persoana) {
    persoana.nume = new char[50];
    in.getline(persoana.nume, 49);
}

char * Persoana::scrieReview(const Carte &c, int numarZile) {
    stringstream ss;
    
    ss << "Reviewul pentru cartrea" << c.titlu <<  "trebuie terminat in " << numarZile << "zile\n";
    
    string s = ss.str();
    int n = s.length() + 1;
    
    char *result = new char[n];
    strcpy(result, s.c_str());
    return result;
}