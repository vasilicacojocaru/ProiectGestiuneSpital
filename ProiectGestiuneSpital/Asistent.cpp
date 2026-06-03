#include "Asistent.h"
#include <iostream>

using namespace std;

Asistent::Asistent() : Angajat()
{
    sectie = "";
}

Asistent::Asistent(int id, string nume, double salariu, string sectie)
    : Angajat(id, nume, salariu)
{
    this->sectie = sectie;
}

double Asistent::calculeazaCostServiciu()
{
    return 80;
}

void Asistent::afisare()
{
    cout << "ID asistent: " << id << endl;
    cout << "Nume: " << nume << endl;
    cout << "Sectie: " << sectie << endl;
    cout << "Cost serviciu asistent: " << calculeazaCostServiciu() << " lei" << endl;
}