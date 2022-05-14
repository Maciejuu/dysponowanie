#include <iostream>

using namespace std;

class Fire{

public:

    string type;
    string smoke;
    string area;
    string location;
    int water;

    void setLocationFire();
    void setTypeFire();
    void setSmokeFire();
    void setAreaFire();
    void getWaterAmount();
    void testSending();
    void fireInformation() ;
};

class Road{

public:

    string type;
    string deadlock;
    string location;
    int victims;
    int cars;
    int rescuers;

    void setLocationRoad();
    void setRoad();
    void getRescuersAmount();
    void RoadFireBrigadeSending();
    void RoadTestSending();
    void roadInformation();

};

class LocalWarning{

public:

    string type;
    string location;

    void setLocalWarning();
    void setLWLocation();
    void LocalWarningFireBrigadeSending() const;
    void LocalWarningInformation() const;

};



