#pragma once
#include "Factura.h"
#include "Pacient.h"
#include "Medic.h"

class FacturaFactory
{
public:
    static Factura creeazaFactura(int id, Pacient pacient, Medic medic);
};
