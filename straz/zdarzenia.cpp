#include <iostream>
#include "pojazdy.h"

using namespace std;

int GlobalWaterAmount;
string LWSending;

FireTrucks gcba1("Mercedes ", "GCBA", 5000, 6);
FireTrucks gcba2("Scania ", "GCBA", 10000, 2);
FireTrucks gba("Man ", "GBA", 3000, 6);
FireTrucks gbart("Man ", "GBART", 2000, 6);
FireTrucks srt("Iveco ", "SRT", 0, 2);
FireTrucks sd("Mercedes ", "SD", 0, 2);
FireTrucks srchem("Volvo ", "SRCHEM", 0, 3);

    void Fire::setTypeFire(){

    int Type;

    cout << "\nRodzaj pozaru:" << endl;
    cout << "[1].Obiekty mieszkalne \n[2].Lasy,pola,trawy,stogi \n[3].Srodki transportu drogowego \n[4].Magazyny \n[5].Smietniki, wysypiska \n[6].Instytucje, obiekty uzytecznosci publicznej \n[7].Obiekty gospodarcze i inne rolnicze \n[8].Obiekty produkcyjne, instalacje "
            "technologiczne, rurociagi, urzadzenia"<< endl;

    cout << "Podaj numer rodzaju zdarzenia: ";
    cin >> Type;

    if (Type == 1) type = "Obiekty mieszkalne";
    if (Type == 2) type = "Lasy,pola,trawy,stogi";
    if (Type == 3) type = "Srodki transportu drogowego";
    if (Type == 4) type = "Magazyny";
    if (Type == 5) type = "Smietniki, wysypiska";
    if (Type == 6) type = "Instytucje, obiekty uzytecznosci publicznej";
    if (Type == 7) type = "Obiekty gospodarcze i inne rolnicze";
    if (Type == 8) type = "Obiekty produkcyjne, instalacje technologiczne, rurociagi, urzadzenia";
    if (Type == 9) type = "Inne pozary";
    if (Type == 0 || Type > 9) exit(0);

    }

    void Fire::setSmokeFire(){

        int Smoke;

        cout << "\nPodaj wystepujace zadymienie: " << endl;
        cout << "[1].Male \n[2].Duze" << endl;

        cout << "Podaj numer zadymienia: ";
        cin >> Smoke;

        if (Smoke == 1) smoke = "Male";
        if (Smoke == 2) smoke = "Duze";
        if (Smoke == 0 || Smoke > 2) exit(0);
    }

    void Fire::setAreaFire() {

        int Area;

        cout << "\nWybierz powierzchnie pozaru: " << endl;
        cout << "[1].Maly \n[2].Sredni \n[3].Duzy" <<endl;

        cout << "Podaj numer powierzchni: ";
        cin >> Area;

        if (Area == 1) area = "Maly";
        if (Area == 2) area = "Sredni";
        if (Area == 3) area = "Duzy";
        if (Area == 0 || Area > 3) exit(0);
    }

    int Fire::waterAmount()
    {
        int Water1;
        int Water2;
        int Water3;
        int WaterAmount;

        if(type=="Obiekty mieszkalne") Water1 = 5000;
        if(type=="Lasy,pola,trawy,stogi") Water1 = 3000;
        if(type=="Srodki transportu drogowego") Water1 = 3000;
        if(type=="Magazyny") Water1 = 5000;
        if(type=="Smietniki, wysypiska") Water1 = 5000;
        if(type=="Instytucje, obiekty uzytecznosci publicznej") Water1 = 3000;
        if(type=="Obiekty gospodarcze i inne rolnicze") Water1 = 3000;
        if(type=="Inne pozary") Water1 = 3000;
        if(type=="Obiekty produkcyjne, instalacje technologiczne, rurociagi, urzadzenia") Water1 = 3000;
        if(type=="Instytucje, obiekty uzytecznosci publicznej") Water1 = 3000;
        if(area=="Maly") Water2 = 3000;
        if(area=="Sredni") Water2 = 5000;
        if(area=="Duzy") Water2 = 8000;
        if(smoke=="Male") Water3 = 3000;
        if(smoke=="Duze") Water3 = 5000;

        WaterAmount = Water1 + Water3 + Water2;
        if(WaterAmount<=0) exit(0);
        WaterAmount = GlobalWaterAmount;

    }

    void Fire::fireBrigadeSending(){

    if(GlobalWaterAmount>5000 && GlobalWaterAmount<=11000)
    {

    }
    if(GlobalWaterAmount>11000 && GlobalWaterAmount<=15000)
    {

    }
    if(GlobalWaterAmount>15000)
    {

    }

}
    void Road::setRoad(){

    int Type;
    int Deadlock;

    cout << "\nRodzaj zdarzenia drogowego:" << endl;
    cout << "[1].Kolizja \n[2].Wypadek\n" << endl;

    cout << "Podaj numer rodzaju zdarzenia: ";
    cin >> Type;

    if(Type == 0 || Type > 2) exit(0);
    if(Type == 1) type = "Kolizja";
    if(Type == 2) type = "Wypadek";

    cout << "\nPodaj liczbe aut bioracych udzial w wypadku: ";

    cin >> cars;

    if(cars<=0) exit(0);

    cout << "\nPodaj liczbe osob poszkodowanych:";

    cin >> victims;

    if(victims<0) exit(0);

    if(type=="Wypadek")
    {
        cout << "\nCzy osoby w pojazdach sa zakleszczone?" << endl;
        cout << "[1].Tak \n[2].Nie" << endl;
        cout << "Podaj odpowiedz: ";

        cin >> deadlock;
    }

    if(Deadlock == 0 || Deadlock > 2) exit(0);
    if(Deadlock == 1) deadlock = "Tak";
    if(Deadlock == 2) deadlock = "Nie";
    }

    void Road::RoadFireBrigadeSending()
    {

    }

    void LocalWarning::setLocalWarning()
    {
        int Type;

        cout << "\n[1].Powalone drzewo \n[2].Zerwana linia energetyczna \n[3].Pomoc innym sluzbom \n[4].Zagrozenie chemiczne \n[5].Pomoc w otwarciu mieszkania \n[6].Budowlane" << endl;

        cout << "\nPodaj numer rodzaju zdarzenia: ";
        cin >> Type;

        if(Type == 0 || Type > 6) exit(0);
        if (Type == 1) type = "Powalone drzewo";
        if (Type == 2) type = "Zerwana linia energetyczna";
        if (Type == 3) type = "Pomoc innym sluzbom";
        if (Type == 4) type = "Zagrozenie chemiczne";
        if (Type == 5) type = "Pomoc w otwarciu mieszkania";
        if (Type == 6) type = "Budowlane";

    }

    void LocalWarning::LocalWarningFireBrigadeSending()
    {
        string Info = "Na miejsce zdarzenia dysponuje: ";
        string Info2 = " oraz ";

    if(type=="Powalone drzewo") LWSending = Info + sd.name + sd.type + Info2 + gba.name + gba.type;
    if(type=="Zerwana linia energetyczna") LWSending = Info + gbart.name + gba.type;
    if(type=="Pomoc innym sluzbom") LWSending = Info + gbart.name + gba.type;
    if(type=="Zagrozenie chemiczne") LWSending = Info + gcba1.name + gcba1.type + Info2 + srchem.name + srchem.type;
    if(type=="Pomoc w otwarciu mieszkania") LWSending = Info + gbart.name + gbart.type;
    if(type=="Budowlane") LWSending = Info + gbart.name + gbart.type;

    }

    void LocalWarning::LocalWarningInformation()
    {
        cout << "\n++++Informacja o zdarzeniu++++ " << endl;
        cout << "\nRodzaj miejscowego zdarzenia: " << type << endl;
        cout << LWSending;
    }