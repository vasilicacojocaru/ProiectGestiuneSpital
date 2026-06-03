#include "Internare.h"
#include "Logger.h"
#include <iostream>

using namespace std;

Internare::Internare()
{
    idInternare = 0;
    dataInternare = "";
    salon = 0;
}

Internare::Internare(int idInternare, Pacient pacient, string dataInternare, int salon)
{
    this->idInternare = idInternare;
    this->pacient = pacient;
    this->dataInternare = dataInternare;
    this->salon = salon;

    Logger::scrieLog("Pacient internat: " + pacient.getNume());
}

void Internare::afisare()
{
    cout << "===== INTERNARE =====" << endl;
    cout << "ID Internare: " << idInternare << endl;
    cout << "Pacient: " << pacient.getNume() << endl;
    cout << "Data internare: " << dataInternare << endl;
    cout << "Salon: " << salon << endl;
}