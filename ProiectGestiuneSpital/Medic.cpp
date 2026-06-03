#include "Medic.h"
#include <iostream>

using namespace std;

Medic::Medic() : Angajat()
{
    specializare = "";
}

Medic::Medic(int id, string nume, double salariu, string specializare)
    : Angajat(id, nume, salariu)
{
    this->specializare = specializare;
}

double Medic::calculeazaCostServiciu()
{
    return 200;
}

void Medic::afisare()
{
    cout << "ID medic: " << id << endl;
    cout << "Nume: " << nume << endl;
    cout << "Specializare: " << specializare << endl;
    cout << "Cost consultatie: " << calculeazaCostServiciu() << " lei" << endl;
}