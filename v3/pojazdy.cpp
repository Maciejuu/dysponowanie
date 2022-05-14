#include <iostream>
#include "pojazdy.h"
#include <vector>

using namespace std;

FireTrucks::FireTrucks(string name, string type, int watertank, int firemans) : name(name), type(type), watertank(watertank), firemans(firemans){
}

string FireTrucks::getName()
{
    return name;
}
string FireTrucks::getType()
{
    return type;
}
int FireTrucks::getWatertank()
{
    return watertank;
}
int FireTrucks::getFiremans()
{
    return firemans;
}

