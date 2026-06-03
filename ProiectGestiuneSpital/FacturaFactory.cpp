#include "FacturaFactory.h"

Factura FacturaFactory::creeazaFactura(int id, Pacient pacient, Medic medic)
{
    return Factura(id, pacient, medic);
}