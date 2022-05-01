#include <iostream>

using namespace std;

class Fire{
public:
    string type;
    string smoke;
    string area;
    int water;

    void setTypeFire();
    void setSmokeFire();
    void setAreaFire();
    int getWaterAmount();
    void fireBrigadeSending() ;
    void fireInformation() ;
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
    void roadInformation();

};

class LocalWarning{
public:
    string type;

    void setLocalWarning();
    void LocalWarningFireBrigadeSending() const;
    void LocalWarningInformation() const;

};



