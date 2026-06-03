#pragma once
#include "Pacient.h"
#include "Medic.h"

class Factura
{
private:
    int idFactura;
    Pacient pacient;
    Medic medic;
    double cost;

public:
    Factura();
    Factura(int idFactura, Pacient pacient, Medic medic);

    double calculeazaTotal();
    void afisare();
};
