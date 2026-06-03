#pragma once
#include <string>

using namespace std;

class Pacient
{
private:
    int id;
    string nume;
    int varsta;
    string diagnostic;

public:
    Pacient();
    Pacient(int id, string nume, int varsta, string diagnostic);

    int getId();
    string getNume();
    int getVarsta();
    string getDiagnostic();

    void afisare();
};
