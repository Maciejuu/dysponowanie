#include <iostream>
#include "zdarzenia.h"
using namespace std;

class FireTrucks : public Fire, public Road, public LocalWarning{

public:

    string name;
    string type;
    int watertank;
    int firemans;

    FireTrucks(string Name ,string Type ,int Watertank ,int Firemans);

    string getName();
    string getType();
    int getWatertank();
    int getFiremans();

};


