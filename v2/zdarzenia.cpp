#include <iostream>
#include "pojazdy.h"

using namespace std;

string LWSending;
string FSending;
string RSending;

FireTrucks gcba1("Man ", "GCBA", 5000, 6);
FireTrucks gcba2("Scania ", "GCBA", 10000, 2);
FireTrucks gbart("Man ", "GBART", 3000, 6);
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

    int Fire::getWaterAmount()
    {
        int Water1;
        int Water2;
        int Water3;
        int WaterAmount;

        if(type=="Obiekty mieszkalne") Water1 = 5000;
        if(type=="Lasy,pola,trawy,stogi") Water1 = 5000;
        if(type=="Srodki transportu drogowego") Water1 = 3000;
        if(type=="Magazyny") Water1 = 5000;
        if(type=="Smietniki, wysypiska") Water1 = 3000;
        if(type=="Instytucje, obiekty uzytecznosci publicznej") Water1 = 5000;
        if(type=="Obiekty gospodarcze i inne rolnicze") Water1 = 5000;
        if(type=="Obiekty produkcyjne, instalacje technologiczne, rurociagi, urzadzenia") Water1 = 3000;
        if(type=="Inne pozary") Water1 = 3000;
        if(area=="Maly") Water2 = 3000;
        if(area=="Sredni") Water2 = 5000;
        if(area=="Duzy") Water2 = 8000;
        if(smoke=="Male") Water3 = 3000;
        if(smoke=="Duze") Water3 = 5000;

        if(area=="Maly" && smoke=="Male") WaterAmount = Water1;
        else (WaterAmount = Water1 + Water3 + Water2);

        water = WaterAmount;
    }

    void Fire::fireBrigadeSending()
    {
        string Info = "Na miejsce zdarzenia dysponuje: ";

        if (water == 3000) FSending = Info + gbart.name + gbart.type;
        if (water == 5000) FSending = Info + gcba1.name + gcba1.type;
        if (water == 10000) FSending = Info + gcba2.name + gcba2.type;
        if (water == 13000) FSending = Info + gcba2.name + gcba2.type + " oraz " + gbart.name + gbart.type;
        if (water == 15000) FSending = Info + gcba1.name + gcba1.type + " oraz " + gcba2.name + gcba2.type;
        if (water == 18000 || water == 17000) FSending = Info + gcba1.name + gcba1.type + " oraz " + gcba2.name + gcba2.type + " oraz " + gbart.name + gbart.type;

    }

    void Fire::fireInformation()
    {
        string Info = "Na miejsce zdarzenia dysponuje: ";
        string housefire = gbart.name + gbart.type + " oraz " + gcba1.name + gcba1.type + "oraz" + gcba2.name + gcba2.type + " oraz " + sd.name + sd.type;

        cout << "\n++++Informacja o zdarzeniu++++ " << endl;
        cout << "\nRodzaj pozaru: " << type << endl;
        cout << "Powierzchnia: " << area << endl;
        cout << "Zadymienie: " << smoke << endl;
        cout << "Ilosc potrzebnej wody: " << water << " [L] " << endl;
        if(type=="Obiekty mieszkalne" || type=="Instytucje, obiekty uzytecznosci publicznej")
        {
         cout << Info + housefire << endl;
        } else cout << FSending << endl;

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

    if(type=="Kolizja")
    {
        cout << "\nPodaj liczbe aut bioracych udzial w kolizji: ";

        cin >> cars;

        if(cars<=0) exit(0);

        cout << "\nPodaj liczbe osob poszkodowanych:";

        cin >> victims;

        if(victims<0) exit(0);
    }

    if(type=="Wypadek")
    {
        cout << "\nPodaj liczbe aut bioracych udzial w wypadku: ";

        cin >> cars;

        if(cars<=0) exit(0);

        cout << "\nPodaj liczbe osob poszkodowanych:";

        cin >> victims;

        if(victims<0) exit(0);

        cout << "\nCzy osoby w pojazdach sa zakleszczone?" << endl;
        cout << "[1].Tak \n[2].Nie" << endl;
        cout << "Podaj odpowiedz: ";

        cin >> Deadlock;

        if(Deadlock == 1) deadlock = "Tak";
        if(Deadlock == 2) deadlock = "Nie";
        if(Deadlock == 0 || Deadlock > 2) exit(0);
    }

    }

    void Road::RoadFireBrigadeSending()
    {
        string Info = "Na miejsce zdarzenia dysponuje: ";

        if(type=="Kolizja")
        {
            RSending = Info + gbart.name + gbart.type;
        }
        else RSending = Info + gbart.name + gbart.type + " oraz " + srt.name + srt.type;

    }

    void Road::roadInformation() {

        cout << "\n++++Informacja o zdarzeniu++++ " << endl;
        cout << "\nRodzaj zdarzenia drogowego: " << type << endl;
        cout << "Liczba poszkodowanych: " << victims << endl;
        cout << "Liczba pojazdow: " << cars << endl;
        if(type=="Wypadek") cout << "Zakleszczenie: " << deadlock << endl;
        cout << RSending << endl;
}

    void LocalWarning::setLocalWarning()
    {
        int Type;

        cout << "\nWybierz rodzaj miejscowego zdarzenia: " << endl;

        cout << "\n[1].Powalone drzewo \n[2].Naderwany konar \n[3].Zerwana linia energetyczna \n[4].Pomoc innym sluzbom \n[5].Zagrozenie chemiczne \n[6].Pomoc w otwarciu mieszkania \n[7].Budowlane \n[8].Gniazdo owadow blonkoskrzydlych" << endl;

        cout << "\nPodaj numer rodzaju zdarzenia: ";
        cin >> Type;

        if(Type == 0 || Type > 8) exit(0);
        if (Type == 1) type = "Powalone drzewo";
        if (Type == 2) type = "Naderwany konar";
        if (Type == 3) type = "Zerwana linia energetyczna";
        if (Type == 4) type = "Pomoc innym sluzbom";
        if (Type == 5) type = "Zagrozenie chemiczne";
        if (Type == 6) type = "Pomoc w otwarciu mieszkania";
        if (Type == 7) type = "Budowlane";
        if (Type == 8) type = "Gniazdo owadow blonkoskrzydlych";
    }

    void LocalWarning::LocalWarningFireBrigadeSending() const
    {
        string Info = "Na miejsce zdarzenia dysponuje: ";
        string Info2 = " oraz ";

    if(type=="Powalone drzewo") LWSending = Info + gbart.name + gbart.type;
    if(type=="Naderwany konar") LWSending = Info + sd.name + sd.type + Info2 + gbart.name + gbart.type;
    if(type=="Zerwana linia energetyczna") LWSending = Info + gbart.name + gbart.type;
    if(type=="Pomoc innym sluzbom") LWSending = Info + gbart.name + gbart.type;
    if(type=="Zagrozenie chemiczne") LWSending = Info + gcba1.name + gcba1.type + Info2 + srchem.name + srchem.type;
    if(type=="Pomoc w otwarciu mieszkania") LWSending = Info + gbart.name + gbart.type;
    if(type=="Budowlane") LWSending = Info + gbart.name + gbart.type;
    if(type=="Gniazdo owadow blonkoskrzydlych") LWSending = Info + gbart.name + gbart.type;

    }

    void LocalWarning::LocalWarningInformation() const
    {
        cout << "\n++++Informacja o zdarzeniu++++ " << endl;
        cout << "\nRodzaj miejscowego zdarzenia: " << type << endl;
        cout << LWSending;
    }