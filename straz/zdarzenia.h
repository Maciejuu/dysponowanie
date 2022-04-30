#include <iostream>

using namespace std;

class Fire{
public:
    string type;
    string smoke;
    string area;

    void setTypeFire();
    void setSmokeFire();
    void setAreaFire();
    int waterAmount();
    void fireBrigadeSending();
};

class Road{
public:
    string type;
    string deadlock;
    int victims;
    int cars;
    int rescuers;

    void setRoad();
    void RoadFireBrigadeSending();

};

class LocalWarning{
public:
    string type;

    void setLocalWarning();
    void LocalWarningFireBrigadeSending();
    void LocalWarningInformation();

};



