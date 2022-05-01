#include <iostream>
#include "pojazdy.h"

using namespace std;

int main(){

    cout << "---------------------------------" << endl;
    cout << "SYSTEM DYSPONOWANIA SIL I SRODKOW" << endl;
    cout << "---------------------------------" << endl;

    int Number;

    cout << "\nRodzaj zdarzenia: \n[1].Pozar \n[2].Drogowe \n[3].Miejscowe zagrozenie" << endl;

    cout << "Wpisz numer: ";
    cin >> Number;

    if (Number == 0 || Number > 3) {
        cout << "\nWystapil blad!" << endl;
        return 0;
    }
    if (Number == 1) {
        Fire p;
        p.setTypeFire();
        p.setAreaFire();
        p.setSmokeFire();
        p.getWaterAmount();
        p.fireBrigadeSending();
        p.fireInformation();
    }
    if (Number == 2) {
        Road r;
        r.setRoad();
        r.RoadFireBrigadeSending();
        r.roadInformation();
    }
    if (Number == 3) {
        LocalWarning lw;
        lw.setLocalWarning();
        lw.LocalWarningFireBrigadeSending();
        lw.LocalWarningInformation();
    }

    return 0;
}





