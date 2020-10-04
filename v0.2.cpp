#include <iostream>
#include <iomanip>
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
    float gr = 0.0f;

    void print()
    {
        cout << vardas << " " << pavarde << " : ";
        for (int i = 0; i < ndbalai.size(); i++)
        {
            cout << ndbalai[i] << " ";
        }
        cout << egzbalas << " " << gr << endl;
    }
};

float gal_paz_vid(Stud mokinys)
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

float gal_paz_med(Stud mokinys)
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

void nuskaitimas(vector<Stud>& mokiniai)
{
    ifstream in("input.txt");

    string s;
    in >> s >> s;

    int col = 0;
    while (true)
    {
        string str;
        in >> str;

        if (str == "Egz.")
        {
            break;
        }
        col++;
    }

    while (!in.eof())
    {
        Stud mokinys;
        in >> mokinys.vardas;
        in >> mokinys.pavarde;
        for (int i = 0; i < col; i++)
        {
            int balas;
            in >> balas;
            mokinys.ndbalai.push_back(balas);
        }
        in >> mokinys.egzbalas;

        mokiniai.push_back(mokinys);
    }

    in.close();
}

int main()
{

    vector<Stud> mokiniai;
    nuskaitimas(mokiniai);


    while (true)
    {
        cout << "Iveskite vid jei norite apskaiciuti vidurki arba med jei norite apskaiciuti mediana: ";
        string pasirinkimas;
        cin >> pasirinkimas;
        if (pasirinkimas == "vid")
        {
            for (int i = 0; i < mokiniai.size(); i++)
            {
                mokiniai[i].gr = gal_paz_vid(mokiniai[i]);
            }
            break;
        }
        else if (pasirinkimas == "med")
        {

            for (int i = 0; i < mokiniai.size(); i++)
            {
                mokiniai[i].gr = gal_paz_med(mokiniai[i]);
            }
            break;
        }
    }

    for (int i = 0; i < mokiniai.size(); i++)
    {
        mokiniai[i].print();
    }

    return 0;
}

