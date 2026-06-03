#include "Factura.h"
#include <iostream>
#include "Logger.h"

using namespace std;

Factura::Factura()
{
    idFactura = 0;
    cost = 0;
}

Factura::Factura(int idFactura, Pacient pacient, Medic medic)
{
    this->idFactura = idFactura;
    this->pacient = pacient;
    this->medic = medic;

    cost = calculeazaTotal();

    Logger::scrieLog("Factura emisa pentru pacientul: " + pacient.getNume());
}

double Factura::calculeazaTotal()
{
    return medic.calculeazaCostServiciu();
}

void Factura::afisare()
{
    cout << "===== FACTURA =====" << endl;
    cout << "ID Factura: " << idFactura << endl;

    cout << "Pacient: " << pacient.getNume() << endl;
    cout << "Total de plata: " << cost << " lei" << endl;
}