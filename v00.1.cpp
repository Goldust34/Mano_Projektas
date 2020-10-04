#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

struct Stud
{
    string vardas;
    string pavarde;
    vector<int> ndbalai;
    int egzbalas;
    float gr;

    void print()
    {
        cout << vardas << " " << pavarde << " - " << gr << endl;
    }
};

float gal_paz_vid(Stud mokinys)  // Apskaiciuoja pazymiu ir egz.vidurki
{
    float rez = 0;
    for (int i = 0; i < mokinys.ndbalai.size(); i++)
    {
        rez += mokinys.ndbalai[i];
    }
    rez /= mokinys.ndbalai.size();
    rez *= 0.4f;
    rez += mokinys.egzbalas * 0.6f;
    return rez;
}

float gal_paz_med(Stud mokinys)    // Apskaiciuoja pazymiu ir egz.mediana
{
    int n = mokinys.ndbalai.size();
    float rez = 0;

    if (n % 2 == 1)
        rez = mokinys.ndbalai[n / 2];
    else
        rez = (mokinys.ndbalai[n / 2] + mokinys.ndbalai[n / 2 - 1]) / 2.0f;

    rez *= 0.4f;
    rez += mokinys.egzbalas * 0.6f;
    return rez;
}

void generuoti(Stud& mokinys)       // Su pointeriais sugeneruoja nd skaiciu
{
    int ndkiekis;
    cin >> ndkiekis;

    srand(time(0));
    for (int i = 0; i < ndkiekis; i++)
    {
        mokinys.ndbalai.push_back(rand() % 10 + 1);
    }
}

int main()
{
    Stud mokinys;

    cout << "Iveskite varda, pavarde, nd skaiciu ir egz. bala: ";

    cin >> mokinys.vardas >> mokinys.pavarde;

    generuoti(mokinys);

    cin >> mokinys.egzbalas;

    while (true)
    {
        cout << "Iveskite vid jei norite apskaiciuti vidurki arba med jei norite apskaiciuti mediana: ";
        string pasirinkimas;
        cin >> pasirinkimas;
        if (pasirinkimas == "vid")
        {
            mokinys.gr = gal_paz_vid(mokinys);
            mokinys.print();
            break;
        }
        else if (pasirinkimas == "med")
        {
            mokinys.gr = gal_paz_med(mokinys);
            mokinys.print();
            break;
        }
    }

    return 0;
}
