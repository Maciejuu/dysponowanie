#include <iostream>
#include "pojazdy.h"


using namespace std;

FireTrucks::FireTrucks(string Name, string Type, int Watertank, int Firemans)
{
    if (watertank < 0 && firemans < 0)
        cout << "Wystapil blad!" << endl;
    else {
        name = Name;
        type = Type;
        watertank = Watertank;
        firemans = Firemans;
    }
}


