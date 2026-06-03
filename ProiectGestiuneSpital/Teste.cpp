#include <iostream>
#include <cassert>
#include "Pacient.h"
#include "Medic.h"
#include "Programare.h"
#include "Factura.h"
#include "Exceptii.h"

using namespace std;

void testProgramareValida()
{
    Pacient p(1, "Ion Popescu", 35, "Gripa");
    Medic m(1, "Dr. Maria Ionescu", 6000, "Cardiologie");

    Programare pr(1, p, m, "12.06.2026", "10:30");

    cout << "Test programare valida trecut." << endl;
}

void testProgramareInvalida()
{
    Pacient p(1, "Ion Popescu", 35, "Gripa");
    Medic m(1, "Dr. Maria Ionescu", 6000, "Cardiologie");

    try
    {
        Programare pr(1, p, m, "12.06.2026", "20:00");
        assert(false);
    }
    catch (ProgramareInvalidaException& e)
    {
        cout << "Test programare invalida trecut." << endl;
    }
}

void testCalculFactura()
{
    Pacient p(1, "Ion Popescu", 35, "Gripa");
    Medic m(1, "Dr. Maria Ionescu", 6000, "Cardiologie");

    Factura f(1, p, m);

    assert(f.calculeazaTotal() == 200);

    cout << "Test calcul factura trecut." << endl;
}