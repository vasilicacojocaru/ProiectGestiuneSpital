#pragma once
#include "Angajat.h"

class Asistent : public Angajat
{
private:
    string sectie;

public:
    Asistent();
    Asistent(int id, string nume, double salariu, string sectie);

    double calculeazaCostServiciu() override;
    void afisare() override;
};
