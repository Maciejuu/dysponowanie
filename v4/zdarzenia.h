#include <iostream>
#include <vector>

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
    void fireSending();
    void fireInformation();
    void createDatabase();
    void loadCreatedDatabase();
    void loadDatabase();
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
    void roadSending();
    void roadInformation();

};

class LocalWarning{

public:

    string type;
    string location;

    void setLocalWarning();
    void setLWLocation();
    void LocalWarningSending();
    void LocalWarningInformation();

};