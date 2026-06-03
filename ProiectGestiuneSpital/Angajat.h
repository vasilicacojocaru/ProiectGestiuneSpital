#pragma once
#include <string>

using namespace std;

class Angajat
{
protected:
    int id;
    string nume;
    double salariu;

public:
    Angajat();
    Angajat(int id, string nume, double salariu);

    virtual double calculeazaCostServiciu() = 0;
    virtual void afisare();

    virtual ~Angajat();
};
