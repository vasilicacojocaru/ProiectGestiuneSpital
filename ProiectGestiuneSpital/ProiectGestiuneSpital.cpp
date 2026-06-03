#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <fstream>

#include "Pacient.h"
#include "Medic.h"
#include "Asistent.h"
#include "Programare.h"
#include "Exceptii.h"
#include "Factura.h"
#include "Internare.h"
#include "FacturaFactory.h"

using namespace std;

void seteazaCuloare(int culoare)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), culoare);
}

void pauza()
{
    seteazaCuloare(14);
    cout << endl << "Apasa Enter pentru a continua...";
    seteazaCuloare(15);
    cin.ignore(1000, '\n');
    cin.get();
}

void curataEcran()
{
    system("cls");
}

void afiseazaTitlu()
{
    seteazaCuloare(11);
    cout << "==================================================" << endl;
    cout << "              GESTIUNE SPITAL                     " << endl;
    cout << "==================================================" << endl;
    seteazaCuloare(15);
}

void afiseazaMeniu()
{
    curataEcran();
    afiseazaTitlu();

    cout << endl;
    cout << "  DATE PRINCIPALE" << endl;
    cout << "  [1] Afisare pacienti" << endl;
    cout << "  [2] Afisare medici" << endl;
    cout << "  [3] Afisare asistenti" << endl;

    cout << endl;
    cout << "  OPERATIUNI SPITAL" << endl;
    cout << "  [4] Afisare programari" << endl;
    cout << "  [5] Afisare internari" << endl;
    cout << "  [6] Afisare facturi" << endl;

    cout << endl;
    cout << "  GESTIONARE DATE" << endl;
    cout << "  [7] Adaugare pacient" << endl;
    cout << "  [8] Creare programare" << endl;
    cout << "  [9] Emitere factura" << endl;
    cout << "  [10] Internare pacient" << endl;
    cout << "  [11] Filtrare pacienti dupa diagnostic" << endl;
    cout << "  [12] Statistici spital" << endl;
    cout << "  [13] Adaugare medic" << endl;
    cout << "  [14] Adaugare asistent" << endl;

    cout << endl;
    seteazaCuloare(12);
    cout << "  [0] Iesire" << endl;
    seteazaCuloare(15);

    cout << endl;
    seteazaCuloare(11);
    cout << "==================================================" << endl;
    seteazaCuloare(15);
    cout << "Alege optiunea: ";
}

void salveazaPacienti(vector<Pacient> pacienti)
{
    ofstream fisier("pacienti.txt");

    for (int i = 0; i < pacienti.size(); i++)
    {
        fisier << pacienti[i].getId() << endl;
        fisier << pacienti[i].getNume() << endl;
        fisier << pacienti[i].getVarsta() << endl;
        fisier << pacienti[i].getDiagnostic() << endl;
    }

    fisier.close();
}

int main()
{
    vector<Pacient> pacienti;
    vector<Medic> medici;
    vector<Asistent> asistenti;
    vector<Programare> programari;
    vector<Internare> internari;
    vector<Factura> facturi;

    pacienti.push_back(Pacient(1, "Ion Popescu", 35, "Gripa"));
    pacienti.push_back(Pacient(2, "Maria Stan", 42, "Diabet"));
    pacienti.push_back(Pacient(3, "Andrei Ionescu", 29, "Gripa"));

    medici.push_back(Medic(1, "Dr. Maria Ionescu", 6000, "Cardiologie"));
    medici.push_back(Medic(2, "Dr. Andrei Popescu", 6500, "Neurologie"));
    medici.push_back(Medic(3, "Dr. Elena Stan", 7000, "Pediatrie"));

    asistenti.push_back(Asistent(1, "Ana Georgescu", 3500, "Urgente"));
    asistenti.push_back(Asistent(2, "Mihai Rusu", 3400, "Pediatrie"));
    asistenti.push_back(Asistent(3, "Cristina Moldovan", 3600, "Cardiologie"));

    int optiune;

    do
    {
        afiseazaMeniu();
        cin >> optiune;

        curataEcran();
        afiseazaTitlu();

        switch (optiune)
        {
        case 1:
            cout << endl << "LISTA PACIENTI" << endl;
            cout << "--------------------------------------------------" << endl;

            for (int i = 0; i < pacienti.size(); i++)
            {
                pacienti[i].afisare();
                cout << "--------------------------------------------------" << endl;
            }

            pauza();
            break;

        case 2:
            cout << endl << "LISTA MEDICI" << endl;
            cout << "--------------------------------------------------" << endl;

            for (int i = 0; i < medici.size(); i++)
            {
                medici[i].afisare();
                cout << "--------------------------------------------------" << endl;
            }

            pauza();
            break;

        case 3:
            cout << endl << "LISTA ASISTENTI" << endl;
            cout << "--------------------------------------------------" << endl;

            for (int i = 0; i < asistenti.size(); i++)
            {
                asistenti[i].afisare();
                cout << "--------------------------------------------------" << endl;
            }

            pauza();
            break;

        case 4:
            cout << endl << "LISTA PROGRAMARI" << endl;
            cout << "--------------------------------------------------" << endl;

            if (programari.size() == 0)
            {
                cout << "Nu exista programari." << endl;
            }
            else
            {
                for (int i = 0; i < programari.size(); i++)
                {
                    programari[i].afisare();
                    cout << "--------------------------------------------------" << endl;
                }
            }

            pauza();
            break;

        case 5:
            cout << endl << "LISTA INTERNARI" << endl;
            cout << "--------------------------------------------------" << endl;

            if (internari.size() == 0)
            {
                cout << "Nu exista internari." << endl;
            }
            else
            {
                for (int i = 0; i < internari.size(); i++)
                {
                    internari[i].afisare();
                    cout << "--------------------------------------------------" << endl;
                }
            }

            pauza();
            break;

        case 6:
            cout << endl << "LISTA FACTURI" << endl;
            cout << "--------------------------------------------------" << endl;

            if (facturi.size() == 0)
            {
                cout << "Nu exista facturi." << endl;
            }
            else
            {
                for (int i = 0; i < facturi.size(); i++)
                {
                    facturi[i].afisare();
                    cout << "--------------------------------------------------" << endl;
                }
            }

            pauza();
            break;

        case 7:
        {
            int id, varsta;
            string nume, diagnostic;

            cout << endl << "ADAUGARE PACIENT" << endl;
            cout << "--------------------------------------------------" << endl;

            cout << "ID pacient: ";
            cin >> id;

            cin.ignore(1000, '\n');

            cout << "Nume pacient: ";
            getline(cin, nume);

            cout << "Varsta: ";
            cin >> varsta;

            cout << "Diagnostic: ";
            cin >> diagnostic;

            Pacient pacientNou(id, nume, varsta, diagnostic);
            pacienti.push_back(pacientNou);
            salveazaPacienti(pacienti);

            seteazaCuloare(10);
            cout << endl << "Pacient adaugat cu succes!" << endl;
            seteazaCuloare(15);

            pauza();
            break;
        }

        case 8:
        {
            int indexPacient, indexMedic;
            string data, ora;

            cout << endl << "CREARE PROGRAMARE" << endl;
            cout << "--------------------------------------------------" << endl;

            cout << "Pacienti disponibili:" << endl;
            for (int i = 0; i < pacienti.size(); i++)
            {
                cout << i + 1 << ". " << pacienti[i].getNume() << endl;
            }

            cout << "Alege pacientul: ";
            cin >> indexPacient;

            cout << endl << "Medici disponibili:" << endl;
            for (int i = 0; i < medici.size(); i++)
            {
                cout << i + 1 << ". ";
                medici[i].afisare();
                cout << endl;
            }

            cout << "Alege medicul: ";
            cin >> indexMedic;

            cout << "Data programarii: ";
            cin >> data;

            cout << "Ora programarii: ";
            cin >> ora;

            if (indexPacient < 1 || indexPacient > pacienti.size() || indexMedic < 1 || indexMedic > medici.size())
            {
                seteazaCuloare(12);
                cout << "Pacient sau medic invalid!" << endl;
                seteazaCuloare(15);
            }
            else
            {
                try
                {
                    Programare pr(programari.size() + 1,
                        pacienti[indexPacient - 1],
                        medici[indexMedic - 1],
                        data,
                        ora);

                    programari.push_back(pr);

                    seteazaCuloare(10);
                    cout << endl << "Programare creata cu succes!" << endl;
                    seteazaCuloare(15);
                }
                catch (ProgramareInvalidaException& e)
                {
                    seteazaCuloare(12);
                    cout << "Eroare: " << e.what() << endl;
                    seteazaCuloare(15);
                }
            }

            pauza();
            break;
        }

        case 9:
        {
            int indexPacient, indexMedic;

            cout << endl << "EMITERE FACTURA" << endl;
            cout << "--------------------------------------------------" << endl;

            cout << "Pacienti disponibili:" << endl;
            for (int i = 0; i < pacienti.size(); i++)
            {
                cout << i + 1 << ". " << pacienti[i].getNume() << endl;
            }

            cout << "Alege pacientul: ";
            cin >> indexPacient;

            cout << endl << "Medici disponibili:" << endl;
            for (int i = 0; i < medici.size(); i++)
            {
                cout << i + 1 << ". ";
                medici[i].afisare();
                cout << endl;
            }

            cout << "Alege medicul: ";
            cin >> indexMedic;

            if (indexPacient < 1 || indexPacient > pacienti.size() || indexMedic < 1 || indexMedic > medici.size())
            {
                seteazaCuloare(12);
                cout << "Pacient sau medic invalid!" << endl;
                seteazaCuloare(15);
            }
            else
            {
                Factura f = FacturaFactory::creeazaFactura(facturi.size() + 1,
                    pacienti[indexPacient - 1],
                    medici[indexMedic - 1]);

                facturi.push_back(f);

                seteazaCuloare(10);
                cout << endl << "Factura emisa cu succes!" << endl;
                seteazaCuloare(15);

                f.afisare();
            }

            pauza();
            break;
        }

        case 10:
        {
            int indexPacient;
            string data;
            int salon;

            cout << endl << "INTERNARE PACIENT" << endl;
            cout << "--------------------------------------------------" << endl;

            cout << "Pacienti disponibili:" << endl;
            for (int i = 0; i < pacienti.size(); i++)
            {
                cout << i + 1 << ". " << pacienti[i].getNume() << endl;
            }

            cout << "Alege pacientul: ";
            cin >> indexPacient;

            cout << "Data internarii: ";
            cin >> data;

            cout << "Numar salon: ";
            cin >> salon;

            if (indexPacient < 1 || indexPacient > pacienti.size())
            {
                seteazaCuloare(12);
                cout << "Pacient invalid!" << endl;
                seteazaCuloare(15);
            }
            else
            {
                Internare internareNoua(internari.size() + 1,
                    pacienti[indexPacient - 1],
                    data,
                    salon);

                internari.push_back(internareNoua);

                seteazaCuloare(10);
                cout << endl << "Pacient internat cu succes!" << endl;
                seteazaCuloare(15);

                internareNoua.afisare();
            }

            pauza();
            break;
        }

        case 11:
        {
            string diagnostic;
            bool gasit = false;

            cout << endl << "FILTRARE PACIENTI DUPA DIAGNOSTIC" << endl;
            cout << "--------------------------------------------------" << endl;

            cout << "Introdu diagnosticul cautat: ";
            cin >> diagnostic;

            cout << endl << "REZULTATE GASITE" << endl;
            cout << "--------------------------------------------------" << endl;

            for (int i = 0; i < pacienti.size(); i++)
            {
                if (pacienti[i].getDiagnostic() == diagnostic)
                {
                    pacienti[i].afisare();
                    cout << "--------------------------------------------------" << endl;
                    gasit = true;
                }
            }

            if (!gasit)
            {
                seteazaCuloare(12);
                cout << "Nu exista pacienti cu acest diagnostic." << endl;
                seteazaCuloare(15);
            }

            pauza();
            break;
        }

        case 12:
            cout << endl << "STATISTICI SPITAL" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "Numar pacienti: " << pacienti.size() << endl;
            cout << "Numar medici: " << medici.size() << endl;
            cout << "Numar asistenti: " << asistenti.size() << endl;
            cout << "Numar programari: " << programari.size() << endl;
            cout << "Numar internari: " << internari.size() << endl;
            cout << "Numar facturi: " << facturi.size() << endl;
            pauza();
            break;

        case 13:
        {
            int id;
            double salariu;
            string nume, specializare;

            cout << endl << "ADAUGARE MEDIC" << endl;
            cout << "--------------------------------------------------" << endl;

            cout << "ID medic: ";
            cin >> id;

            cin.ignore(1000, '\n');

            cout << "Nume medic: ";
            getline(cin, nume);

            cout << "Salariu: ";
            cin >> salariu;

            cout << "Specializare: ";
            cin >> specializare;

            Medic medicNou(id, nume, salariu, specializare);
            medici.push_back(medicNou);

            seteazaCuloare(10);
            cout << endl << "Medic adaugat cu succes!" << endl;
            seteazaCuloare(15);

            pauza();
            break;
        }

        case 14:
        {
            int id;
            double salariu;
            string nume, sectie;

            cout << endl << "ADAUGARE ASISTENT" << endl;
            cout << "--------------------------------------------------" << endl;

            cout << "ID asistent: ";
            cin >> id;

            cin.ignore(1000, '\n');

            cout << "Nume asistent: ";
            getline(cin, nume);

            cout << "Salariu: ";
            cin >> salariu;

            cout << "Sectie: ";
            cin >> sectie;

            Asistent asistentNou(id, nume, salariu, sectie);
            asistenti.push_back(asistentNou);

            seteazaCuloare(10);
            cout << endl << "Asistent adaugat cu succes!" << endl;
            seteazaCuloare(15);

            pauza();
            break;
        }

        case 0:
            seteazaCuloare(10);
            cout << endl << "Aplicatia se inchide..." << endl;
            seteazaCuloare(15);
            break;

        default:
            seteazaCuloare(12);
            cout << endl << "Optiune invalida!" << endl;
            seteazaCuloare(15);
            pauza();
        }

    } while (optiune != 0);

    return 0;
}