#include "Angajat.h"
#include <iostream>

using namespace std;

Angajat::Angajat()
{
    id = 0;
    nume = "";
    salariu = 0;
}

Angajat::Angajat(int id, string nume, double salariu)
{
    this->id = id;
    this->nume = nume;
    this->salariu = salariu;
}

void Angajat::afisare()
{
    cout << "ID angajat: " << id << endl;
    cout << "Nume: " << nume << endl;
    cout << "Salariu: " << salariu << endl;
}

Angajat::~Angajat()
{
}