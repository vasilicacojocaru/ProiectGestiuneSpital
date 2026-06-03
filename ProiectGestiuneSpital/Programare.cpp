#include "Programare.h"
#include "Exceptii.h"
#include <iostream>

using namespace std;

Programare::Programare()
{
    id = 0;
    data = "";
    ora = "";
}

Programare::Programare(int id, Pacient pacient, Medic medic, string data, string ora)
{
    this->id = id;
    this->pacient = pacient;
    this->medic = medic;
    this->data = data;
    this->ora = ora;

    valideazaProgramare();
}

void Programare::valideazaProgramare()
{
    if (data == "")
    {
        throw ProgramareInvalidaException("Data programarii nu poate fi goala!");
    }

    if (ora == "")
    {
        throw ProgramareInvalidaException("Ora programarii nu poate fi goala!");
    }

    if (ora < "08:00" || ora > "18:00")
    {
        throw ProgramareInvalidaException("Programarea trebuie sa fie intre 08:00 si 18:00!");
    }
}

void Programare::afisare()
{
    cout << "ID programare: " << id << endl;
    cout << "Data: " << data << endl;
    cout << "Ora: " << ora << endl;

    cout << "Pacient:" << endl;
    pacient.afisare();

    cout << "Medic:" << endl;
    medic.afisare();
}