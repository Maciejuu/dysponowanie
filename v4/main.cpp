#include <iostream>
#include "pojazdy.h"

using namespace std;

void Report(int Number)
{
    if (Number <= 0 || Number > 3) {
        cout << "\nWystapil blad!" << endl;
        exit(0);
    }
    if (Number == 1) {
        Fire p;
        p.setTypeFire();
        p.setLocationFire();
        p.setAreaFire();
        p.setSmokeFire();
        p.getWaterAmount();
        p.fireSending();
        p.fireInformation();
    }
    if (Number == 2) {
        Road r;
        r.setRoad();
        r.setLocationRoad();
        r.getRescuersAmount();
        r.roadSending();
        r.roadInformation();
    }
    if (Number == 3) {
        LocalWarning lw;
        lw.setLocalWarning();
        lw.setLWLocation();
        lw.LocalWarningSending();
        lw.LocalWarningInformation();
    }
}
void DataBase()
{
    int Number;

    cout << "\n[1].Stworz wlasna baze pojazdow" << endl;
    cout << "[2].Wczytaj poprzednio utworzona baze danych" << endl;
    cout << "[3].Wczytaj baze pojazdow z pliku" << endl;
    cout << "[4].Wyjdz z programu" << endl;
    cout << "\nPodaj opcje programu:";
    while(!(cin>>Number)) //sprawdzenie poprawnosci wprowadzonej zmiennej
    {
        cout << "Wprowadziles bledna wartosc!";
        cout << "\nPodaj wartosc jeszcze raz: ";
        cin.clear();
        cin.sync();
    }

    switch (Number)
    {
        case 1:
        {
            Fire p;
            p.createDatabase();
            break;
        }
        case 2:
        {
            Fire p;
            p.loadCreatedDatabase();
            break;
        }
        case 3:
        {
            Fire p;
            p.loadDatabase();
            break;
        }
        default: exit(0);
    }
}

int main(){

    cout << "Witaj w systemie dysponowania sil i srodkow!" << endl;
    cout << "\nNa poczatku stworz lub eksportuj baze danych." << endl;

    DataBase();

    cout << "\nGotowe! Teraz mozesz dysponowac sily do zdarzen!" << endl;

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "++++++SYSTEM DYSPONOWANIA SIL I SRODKOW++++++" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

        int number;
        string New;

        cout << "\nRodzaj zdarzenia: \n[1].Pozar \n[2].Drogowe \n[3].Miejscowe zagrozenie" << endl;

        cout << "Wpisz numer:";
        while(!(cin>>number)) //sprawdzenie poprawnosci wprowadzonej zmiennej
        {
            cout << "Wprowadziles bledna wartosc!";
            cout << "\nPodaj wartosc jeszcze raz: ";
            cin.clear();
            cin.sync();
        }

        Report(number);

        cout << "\n\nCzy chcesz dodac kolejne zgloszenie? \n[T/N]:";
        cin >> New;

        if(New=="T")
        {
            int number2;

            while(New!="N")
            {
                cout << "\nRodzaj zdarzenia: \n[1].Pozar \n[2].Drogowe \n[3].Miejscowe zagrozenie" << endl;

                cout << "Wpisz numer: ";
                while(!(cin>>number2)) //sprawdzenie poprawnosci wprowadzonej zmiennej
                {
                    cout << "Wprowadziles bledna wartosc!";
                    cout << "\nPodaj wartosc jeszcze raz: ";
                    cin.clear();
                    cin.sync();
                }

                Report(number2);

                cout << "\nCzy chcesz dodac kolejne zgloszenie? \n[T/N]: ";
                cin >> New;

            }
        }
        if(New=="N")
        {
            exit(0);
        }

        return 0;
}