#pragma once
#include <string>
#include "Pacient.h"

using namespace std;

class Internare
{
private:
    int idInternare;
    Pacient pacient;
    string dataInternare;
    int salon;

public:
    Internare();
    Internare(int idInternare, Pacient pacient, string dataInternare, int salon);

    void afisare();
};
