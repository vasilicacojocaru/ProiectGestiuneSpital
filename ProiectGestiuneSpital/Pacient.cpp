#include "Pacient.h"
#include <iostream>

using namespace std;

Pacient::Pacient()
{
    id = 0;
    nume = "";
    varsta = 0;
    diagnostic = "";
}

Pacient::Pacient(int id, string nume, int varsta, string diagnostic)
{
    this->id = id;
    this->nume = nume;
    this->varsta = varsta;
    this->diagnostic = diagnostic;
}

int Pacient::getId()
{
    return id;
}

string Pacient::getNume()
{
    return nume;
}

int Pacient::getVarsta()
{
    return varsta;
}

string Pacient::getDiagnostic()
{
    return diagnostic;
}

void Pacient::afisare()
{
    cout << "ID: " << id << endl;
    cout << "Nume: " << nume << endl;
    cout << "Varsta: " << varsta << endl;
    cout << "Diagnostic: " << diagnostic << endl;
}