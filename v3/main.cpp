#include <iostream>
#include "pojazdy.h"

using namespace std;

void Report(int Number)
{
    if (Number == 0 || Number > 3) {
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
        p.testSending();
        p.fireInformation();
    }
    if (Number == 2) {
        Road r;
        r.setRoad();
        r.setLocationRoad();
        r.getRescuersAmount();
        r.RoadTestSending();
        r.roadInformation();
    }
    if (Number == 3) {
        LocalWarning lw;
        lw.setLocalWarning();
        lw.setLWLocation();
        lw.LocalWarningFireBrigadeSending();
        lw.LocalWarningInformation();
    }
}

int main(){

    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "++++++SYSTEM DYSPONOWANIA SIL I SRODKOW++++++" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

        int number;
        string New;

        cout << "\nRodzaj zdarzenia: \n[1].Pozar \n[2].Drogowe \n[3].Miejscowe zagrozenie" << endl;

        cout << "Wpisz numer: ";
        cin >> number;

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
                cin >> number2;

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





