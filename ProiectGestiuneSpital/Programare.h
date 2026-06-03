#pragma once
#include <string>
#include "Pacient.h"
#include "Medic.h"

using namespace std;

class Programare
{
private:
    int id;
    Pacient pacient;
    Medic medic;
    string data;
    string ora;

public:
    Programare();
    Programare(int id, Pacient pacient, Medic medic, string data, string ora);

    void valideazaProgramare();
    void afisare();
};
