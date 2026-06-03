#pragma once
#include "Angajat.h"

class Medic : public Angajat
{
private:
    string specializare;

public:
    Medic();
    Medic(int id, string nume, double salariu, string specializare);

    double calculeazaCostServiciu() override;
    void afisare() override;
};
